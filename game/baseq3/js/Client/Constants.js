Constants = {
	Team : {
		Free : 0,
		Red : 1,
		Blue : 2,
		Spectator : 3
	},
	
	Class : {
	    None : 0,
	    Captain : 1,
	    Bodyguard : 2,
	    Sniper : 3,
	    Soldier : 4,
	    Berzerker : 5,
	    Infiltrator : 6,
	    Kamikazee : 7,
	    Nurse : 8,
	    Scientist : 9
	},

	Persistant : {
		Score : 0,
		Hits : 1,
		Rank : 2,
		Team : 3,
		Class : 4,
		Level : 5,
		SpawnCount : 6,
		PlayerEvents : 7,
		Attacker : 8,
		Killed : 9,
		ImpressiveCount : 10,
		ExcellentCount : 11,
		DefendCount : 12,
		AssistCount : 13,
		GauntletFragCount : 14,
		Captures : 15
	},

	Stats : {
		Health : 0,
		HoldableItem : 1,
		Key : 2,
		Weapons : 3,
		Armor : 4,
		DeadYaw : 5,
		ClientsReady : 6,
		MaxHealth : 7,
		MaxArmor : 8
	},

	Powerups : {
		None : 0,
		Quad : 1,
		Battlesuit : 2,
		Haste : 3,
		Invis : 4,
		Regen : 5,
		Flight : 6,
		RedFlag : 7,
		BlueFlag : 8,
		NeutralFlag : 9,
		Scout : 10,
		Guard : 11,
		Doubler : 12,
		AmmoRegen : 13,
		Invulnerability : 14
	},
	
	ItemType : {
	    Bad : 0,
	    Weapon : 1,
	    Ammo : 2,
	    Armor : 3,
	    Health : 4,
	    Powerup : 5,
	    Holdable : 6,
	    PersistantPowerup : 7,
	    Team : 8,
	    Key : 9	
	},
	
	Weapons : {
	    None : 0,
	    Gauntlet : 1,
	    Machinegun : 2,
	    Shotgun : 3,
	    GrenadeLauncher : 4,
	    RocketLauncher : 5,
	    Lightning : 6,
	    Railgun : 7,
	    Plasmagun : 8,
	    BFG : 9,
	    GrapplingHook : 10,
	    Stinger : 11
	},
	
	Hud : {
	    Alignment : {
	        Left : 0,
	        Center : 1,
	        Right : 2
	    },
		SmallChar : {
		    Width : 8,
		    Height : 16
		},
		BigChar : {
		    Width : 16,
		    Height : 16  
		},	
		Char : {
			Width : 32,
			Height : 48
		},
		Icon : {
			Space : 4,
			Size : 48
		}
	},

	PMType : {
		Normal : 0,
		NoClip : 1,
		Spectator : 2,
		Dead : 3,
		Freeze : 4,
		Intermission : 5,
		SPIntermission : 6
	},

	ArmorProtection : 0.66,

	RefEntityType : {
		Model : 0,
		Poly : 1,
		Sprite : 2,
		Beam : 3,
		RailCore : 4,
		RailRings : 5,
		Lightning : 6,
		PortalSurface : 7
	},
	
	RefDefFlag : {
		NoWorldModel : 1,
		Hyperspace : 4
	},

	RenderFx : {
		MinLight : 1,
		ThirdPerson : 2,
		FirstPerson : 4,
		DepthHack : 8,
		Crosshair : 16,
		NoShadow : 64,
		LightingOrigin : 128,
		ShadowPlane : 256,
		WrapFrames : 512
	},

	Snapshot : {
		RateDelayed : 1,
		NotActive : 2,
		ServerCount : 4
	},
	
	ConfigStrings : {
	    Scores1 : 6,
	    Scores2 : 7
	}  
};