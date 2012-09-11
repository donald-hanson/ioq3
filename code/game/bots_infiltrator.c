#include "g_local.h"

typedef struct infiltratorState_s {
	class_t disguiseClass;
	team_t disguiseTeam;
} infiltratorState_t;

infiltratorState_t infiltratorStates[MAX_CLIENTS];

infiltratorState_t *BOTS_Infiltrator_GetState(int clientNum)
{
	return &infiltratorStates[clientNum];
}

void BOTS_Infiltrator_AdjustClientSkin(gentity_t *ent, team_t *team, class_t *cls)
{
	infiltratorState_t *state = NULL;
	if (ent->bots_class == CLASS_INFILTRATOR)
	{
		state = BOTS_Infiltrator_GetState(ent->s.clientNum);

		if (state->disguiseTeam == TEAM_RED || state->disguiseTeam == TEAM_BLUE)
			*team = state->disguiseTeam;
		
		if (state->disguiseClass > CLASS_NONE && state->disguiseClass < CLASS_NUM_CLASSES)
			*cls = state->disguiseClass;
	}
}

void BOTS_Infiltrator_ApplyDisguise(int clientNum, team_t team, class_t cls)
{
	infiltratorState_t *state = BOTS_Infiltrator_GetState(clientNum);

	qboolean skinChanged = qfalse;

	if (state->disguiseTeam != team || state->disguiseClass != cls)
		skinChanged = qtrue;

	state->disguiseTeam = team;
	state->disguiseClass = cls;

	if (skinChanged)
		ClientUserinfoChanged(clientNum);
}

void BOTS_InfiltratorCommand_Disguise(int clientNum)
{
	char firstCommand[MAX_TOKEN_CHARS];
	char secondCommand[MAX_TOKEN_CHARS];
	gentity_t *ent = g_entities + clientNum;
	infiltratorState_t *state = BOTS_Infiltrator_GetState(clientNum);
	int pLevel = ent->client->ps.persistant[PERS_LEVEL];
	class_t	cls = state->disguiseClass;
	team_t team = state->disguiseTeam;
	qboolean skinChanged = qfalse;
	char teamName[32];
	char className[32];

	if (trap_Argc() == 3)
	{
		memset(&firstCommand, 0, sizeof(firstCommand));
		memset(&secondCommand, 0, sizeof(secondCommand));
		trap_Argv( 1, firstCommand, sizeof( firstCommand ) );
		trap_Argv( 2, secondCommand, sizeof( secondCommand ) );

		team = BOTS_TeamNumber(firstCommand);
		if (team == TEAM_FREE)
		{
			BOTS_Print(clientNum, "invalid disguise team\n");
			return;
		}
		else if (team == ent->bots_team && pLevel < 1)
		{
			BOTS_Print(clientNum, "must be level 1 to disguise as your team\n");
			return;
		}
		else if (team != ent->bots_team && pLevel < 2)
		{
			BOTS_Print(clientNum, "must be level 2 to disguise as the enemy\n");
			return;
		}

		cls = BOTS_ClassNumber(secondCommand);
		if (cls == CLASS_NONE)
		{
			BOTS_Print(clientNum, "invalid disguise class\n");
			return;
		}
	}
	else if (trap_Argc() == 2)
	{
		memset(&firstCommand, 0, sizeof(firstCommand));
		trap_Argv( 1, firstCommand, sizeof( firstCommand ) );
		if (Q_stricmp(firstCommand, "clear") == 0)
		{
			cls = CLASS_NONE;
			team = TEAM_FREE;
		}
		else
		{
			BOTS_Print(clientNum, "invalid disguise\n");
			return;
		}
	}

	if (cls == CLASS_NONE && team == TEAM_FREE)
		BOTS_Print(clientNum, "Disguised removed\n");
	else
	{
		memset(&teamName, 0, 32);
		memcpy(&teamName, TeamName(team), 32);
		
		memset(&className, 0, 32);
		memcpy(&className, BOTS_ClassName(cls), 32);

		Q_strlwr(teamName);
		Q_strlwr(className);

		BOTS_Print(clientNum, va("Disguised as %s %s\n", teamName, className));
	}

	BOTS_Infiltrator_ApplyDisguise(clientNum, team, cls);
}

qboolean BOTS_Infiltrator_FireWeapon(gentity_t *ent)
{
	int pLevel = ent->client->ps.persistant[PERS_LEVEL];
	if (pLevel < 4)
		BOTS_Infiltrator_ApplyDisguise(ent->s.clientNum, TEAM_FREE, CLASS_NONE);
	return qfalse;
}