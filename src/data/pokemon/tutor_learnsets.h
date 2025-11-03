const u16 gTutorMoves[TUTOR_MOVE_COUNT] =
{
    [TUTOR_MOVE_HEADBUTT] = MOVE_HEADBUTT,
    [TUTOR_MOVE_BITE] = MOVE_BITE,
};

#define TUTOR(move) (1u << (TUTOR_##move))

static const u32 sTutorLearnsets[] =
{
    [SPECIES_NONE]             = (0),


    [SPECIES_BULBASAUR]        = (0),

    [SPECIES_IVYSAUR]          = (0),

    [SPECIES_VENUSAUR]         = (0),

    [SPECIES_CHARMANDER]       = (TUTOR(MOVE_BITE)),

    [SPECIES_CHARMELEON]       = (TUTOR(MOVE_BITE)),

    [SPECIES_CHARIZARD]        = (TUTOR(MOVE_BITE)),

    [SPECIES_SQUIRTLE]         = (TUTOR(MOVE_BITE)),

    [SPECIES_WARTORTLE]        = (TUTOR(MOVE_BITE)),

    [SPECIES_BLASTOISE]        = (TUTOR(MOVE_BITE)),

    [SPECIES_CATERPIE]         = (0),

    [SPECIES_METAPOD]          = (0),

    [SPECIES_BUTTERFREE]       = (0),

    [SPECIES_WEEDLE]           = (0),

    [SPECIES_KAKUNA]           = (0),

    [SPECIES_BEEDRILL]         = (0),

    [SPECIES_PIDGEY]           = (0),

    [SPECIES_PIDGEOTTO]        = (0),

    [SPECIES_PIDGEOT]          = (0),

    [SPECIES_RATTATA]          = (TUTOR(MOVE_BITE)),

    [SPECIES_RATICATE]         = (TUTOR(MOVE_BITE)),

    [SPECIES_SPEAROW]          = (0),

    [SPECIES_FEAROW]           = (0),

    [SPECIES_EKANS]            = (TUTOR(MOVE_BITE)),

    [SPECIES_ARBOK]            = (TUTOR(MOVE_BITE)),

    [SPECIES_PIKACHU]          = (0),

    [SPECIES_RAICHU]           = (0),

    [SPECIES_SANDSHREW]        = (0),

    [SPECIES_SANDSLASH]        = (0),

    [SPECIES_NIDORAN_F]        = (TUTOR(MOVE_BITE)),

    [SPECIES_NIDORINA]         = (TUTOR(MOVE_BITE)),

    [SPECIES_NIDOQUEEN]        = (0),

    [SPECIES_NIDORAN_M]        = (0),

    [SPECIES_NIDORINO]         = (0),

    [SPECIES_NIDOKING]         = (0),

    [SPECIES_CLEFAIRY]         = (0),

    [SPECIES_CLEFABLE]         = (0),

    [SPECIES_VULPIX]           = (0),

    [SPECIES_NINETALES]        = (0),

    [SPECIES_JIGGLYPUFF]       = (0),

    [SPECIES_WIGGLYTUFF]       = (0),

    [SPECIES_ZUBAT]            = (TUTOR(MOVE_BITE)),

    [SPECIES_GOLBAT]           = (TUTOR(MOVE_BITE)),

    [SPECIES_ODDISH]           = (0),

    [SPECIES_GLOOM]            = (0),

    [SPECIES_VILEPLUME]        = (0),

    [SPECIES_PARAS]            = (0),

    [SPECIES_PARASECT]         = (0),

    [SPECIES_VENONAT]          = (0),

    [SPECIES_VENOMOTH]         = (0),

    [SPECIES_DIGLETT]          = (0),

    [SPECIES_DUGTRIO]          = (0),

    [SPECIES_MEOWTH]           = (TUTOR(MOVE_BITE)),

    [SPECIES_PERSIAN]          = (TUTOR(MOVE_BITE)),

    [SPECIES_PSYDUCK]          = (0),

    [SPECIES_GOLDUCK]          = (0),

    [SPECIES_MANKEY]           = (0),

    [SPECIES_PRIMEAPE]         = (0),

    [SPECIES_GROWLITHE]        = (TUTOR(MOVE_BITE)),

    [SPECIES_ARCANINE]         = (TUTOR(MOVE_BITE)),

    [SPECIES_POLIWAG]          = (0),

    [SPECIES_POLIWHIRL]        = (0),

    [SPECIES_POLIWRATH]        = (0),

    [SPECIES_ABRA]             = (0),

    [SPECIES_KADABRA]          = (0),

    [SPECIES_ALAKAZAM]         = (0),

    [SPECIES_MACHOP]           = (0),

    [SPECIES_MACHOKE]          = (0),

    [SPECIES_MACHAMP]          = (0),

    [SPECIES_BELLSPROUT]       = (0),

    [SPECIES_WEEPINBELL]       = (0),

    [SPECIES_VICTREEBEL]       = (0),

    [SPECIES_TENTACOOL]        = (0),

    [SPECIES_TENTACRUEL]       = (0),

    [SPECIES_GEODUDE]          = (0),

    [SPECIES_GRAVELER]         = (0),

    [SPECIES_GOLEM]            = (0),

    [SPECIES_PONYTA]           = (0),

    [SPECIES_RAPIDASH]         = (0),

    [SPECIES_SLOWPOKE]         = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_SLOWBRO]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_MAGNEMITE]        = (0),

    [SPECIES_MAGNETON]         = (0),

    [SPECIES_FARFETCHD]        = (0),

    [SPECIES_DODUO]            = (0),

    [SPECIES_DODRIO]           = (0),

    [SPECIES_SEEL]             = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_DEWGONG]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_GRIMER]           = (0),

    [SPECIES_MUK]              = (0),

    [SPECIES_SHELLDER]         = (0),

    [SPECIES_CLOYSTER]         = (0),

    [SPECIES_GASTLY]           = (0),

    [SPECIES_HAUNTER]          = (0),

    [SPECIES_GENGAR]           = (0),

    [SPECIES_ONIX]             = (0),

    [SPECIES_DROWZEE]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_HYPNO]            = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_KRABBY]           = (0),

    [SPECIES_KINGLER]          = (0),

    [SPECIES_VOLTORB]          = (0),

    [SPECIES_ELECTRODE]        = (0),

    [SPECIES_EXEGGCUTE]        = (0),

    [SPECIES_EXEGGUTOR]        = (0),

    [SPECIES_CUBONE]           = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_MAROWAK]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_HITMONLEE]        = (0),

    [SPECIES_HITMONCHAN]       = (0),

    [SPECIES_LICKITUNG]        = (0),

    [SPECIES_KOFFING]          = (0),

    [SPECIES_WEEZING]          = (0),

    [SPECIES_RHYHORN]          = (0),

    [SPECIES_RHYDON]           = (0),

    [SPECIES_CHANSEY]          = (0),

    [SPECIES_TANGELA]          = (0),

    [SPECIES_KANGASKHAN]       = (TUTOR(MOVE_BITE)),

    [SPECIES_HORSEA]           = (0),

    [SPECIES_SEADRA]           = (0),

    [SPECIES_GOLDEEN]          = (0),

    [SPECIES_SEAKING]          = (0),

    [SPECIES_STARYU]           = (0),

    [SPECIES_STARMIE]          = (0),

    [SPECIES_MR_MIME]          = (0),

    [SPECIES_SCYTHER]          = (0),

    [SPECIES_JYNX]             = (0),

    [SPECIES_ELECTABUZZ]       = (0),

    [SPECIES_MAGMAR]           = (0),

    [SPECIES_PINSIR]           = (0),

    [SPECIES_TAUROS]           = (0),

    [SPECIES_MAGIKARP]         = (0),

    [SPECIES_GYARADOS]         = (TUTOR(MOVE_BITE)),

    [SPECIES_LAPRAS]           = (0),

    [SPECIES_DITTO]            = (0),

    [SPECIES_EEVEE]            = (TUTOR(MOVE_BITE)),

    [SPECIES_VAPOREON]         = (TUTOR(MOVE_BITE)),

    [SPECIES_JOLTEON]          = (0),

    [SPECIES_FLAREON]          = (TUTOR(MOVE_BITE)),

    [SPECIES_PORYGON]          = (0),

    [SPECIES_OMANYTE]          = (TUTOR(MOVE_BITE)),

    [SPECIES_OMASTAR]          = (TUTOR(MOVE_BITE)),

    [SPECIES_KABUTO]           = (0),

    [SPECIES_KABUTOPS]         = (0),

    [SPECIES_AERODACTYL]       = (TUTOR(MOVE_BITE)),

    [SPECIES_SNORLAX]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_ARTICUNO]         = (0),

    [SPECIES_ZAPDOS]           = (0),

    [SPECIES_MOLTRES]          = (0),

    [SPECIES_DRATINI]          = (0),

    [SPECIES_DRAGONAIR]        = (0),

    [SPECIES_DRAGONITE]        = (0),

    [SPECIES_MEWTWO]           = (0),

    [SPECIES_MEW]              = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_CHIKORITA]        = (0),

    [SPECIES_BAYLEEF]          = (0),

    [SPECIES_MEGANIUM]         = (0),

    [SPECIES_CYNDAQUIL]        = (0),

    [SPECIES_QUILAVA]          = (0),

    [SPECIES_TYPHLOSION]       = (0),

    [SPECIES_TOTODILE]         = (TUTOR(MOVE_BITE)),

    [SPECIES_CROCONAW]         = (TUTOR(MOVE_BITE)),

    [SPECIES_FERALIGATR]       = (TUTOR(MOVE_BITE)),

    [SPECIES_SENTRET]          = (0),

    [SPECIES_FURRET]           = (0),

    [SPECIES_HOOTHOOT]         = (0),

    [SPECIES_NOCTOWL]          = (0),

    [SPECIES_LEDYBA]           = (0),

    [SPECIES_LEDIAN]           = (0),

    [SPECIES_SPINARAK]         = (0),

    [SPECIES_ARIADOS]          = (0),

    [SPECIES_CROBAT]           = (TUTOR(MOVE_BITE)),

    [SPECIES_CHINCHOU]         = (0),

    [SPECIES_LANTURN]          = (0),

    [SPECIES_PICHU]            = (0),

    [SPECIES_CLEFFA]           = (0),

    [SPECIES_IGGLYBUFF]        = (0),

    [SPECIES_TOGEPI]           = (0),

    [SPECIES_TOGETIC]          = (0),

    [SPECIES_NATU]             = (0),

    [SPECIES_XATU]             = (0),

    [SPECIES_MAREEP]           = (0),

    [SPECIES_FLAAFFY]          = (0),

    [SPECIES_AMPHAROS]         = (0),

    [SPECIES_BELLOSSOM]        = (0),

    [SPECIES_MARILL]           = (0),

    [SPECIES_AZUMARILL]        = (0),

    [SPECIES_SUDOWOODO]        = (0),

    [SPECIES_POLITOED]         = (0),

    [SPECIES_HOPPIP]           = (0),

    [SPECIES_SKIPLOOM]         = (0),

    [SPECIES_JUMPLUFF]         = (0),

    [SPECIES_AIPOM]            = (0),

    [SPECIES_SUNKERN]          = (0),

    [SPECIES_SUNFLORA]         = (0),

    [SPECIES_YANMA]            = (0),

    [SPECIES_WOOPER]           = (0),

    [SPECIES_QUAGSIRE]         = (0),

    [SPECIES_ESPEON]           = (0),

    [SPECIES_UMBREON]          = (0),

    [SPECIES_MURKROW]          = (0),

    [SPECIES_SLOWKING]         = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_MISDREAVUS]       = (0),

    [SPECIES_UNOWN]            = (0),

    [SPECIES_WOBBUFFET]        = (0),

    [SPECIES_GIRAFARIG]        = (0),

    [SPECIES_PINECO]           = (0),

    [SPECIES_FORRETRESS]       = (0),

    [SPECIES_DUNSPARCE]        = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_GLIGAR]           = (0),

    [SPECIES_STEELIX]          = (0),

    [SPECIES_SNUBBULL]         = (TUTOR(MOVE_BITE)),

    [SPECIES_GRANBULL]         = (TUTOR(MOVE_BITE)),

    [SPECIES_QWILFISH]         = (0),

    [SPECIES_SCIZOR]           = (0),

    [SPECIES_SHUCKLE]          = (0),

    [SPECIES_HERACROSS]        = (0),

    [SPECIES_SNEASEL]          = (TUTOR(MOVE_BITE)),

    [SPECIES_TEDDIURSA]        = (0),

    [SPECIES_URSARING]         = (0),

    [SPECIES_SLUGMA]           = (0),

    [SPECIES_MAGCARGO]         = (0),

    [SPECIES_SWINUB]           = (TUTOR(MOVE_BITE)),

    [SPECIES_PILOSWINE]        = (TUTOR(MOVE_BITE)),

    [SPECIES_CORSOLA]          = (0),

    [SPECIES_REMORAID]         = (0),

    [SPECIES_OCTILLERY]        = (0),

    [SPECIES_DELIBIRD]         = (0),

    [SPECIES_MANTINE]          = (0),

    [SPECIES_SKARMORY]         = (0),

    [SPECIES_HOUNDOUR]         = (TUTOR(MOVE_BITE)),

    [SPECIES_HOUNDOOM]         = (TUTOR(MOVE_BITE)),

    [SPECIES_KINGDRA]          = (0),

    [SPECIES_PHANPY]           = (0),

    [SPECIES_DONPHAN]          = (0),

    [SPECIES_PORYGON2]         = (0),

    [SPECIES_STANTLER]         = (TUTOR(MOVE_BITE)),

    [SPECIES_SMEARGLE]         = (0),

    [SPECIES_TYROGUE]          = (0),

    [SPECIES_HITMONTOP]        = (0),

    [SPECIES_SMOOCHUM]         = (0),

    [SPECIES_ELEKID]           = (0),

    [SPECIES_MAGBY]            = (0),

    [SPECIES_MILTANK]          = (0),

    [SPECIES_BLISSEY]          = (0),

    [SPECIES_RAIKOU]           = (TUTOR(MOVE_BITE)),

    [SPECIES_ENTEI]            = (TUTOR(MOVE_BITE)),

    [SPECIES_SUICUNE]          = (TUTOR(MOVE_BITE)),

    [SPECIES_LARVITAR]         = (TUTOR(MOVE_BITE)),

    [SPECIES_PUPITAR]          = (TUTOR(MOVE_BITE)),

    [SPECIES_TYRANITAR]        = (TUTOR(MOVE_BITE)),

    [SPECIES_LUGIA]            = (0),

    [SPECIES_HO_OH]            = (0),

    [SPECIES_CELEBI]           = (0),

    [SPECIES_TREECKO]          = (0),

    [SPECIES_GROVYLE]          = (0),

    [SPECIES_SCEPTILE]         = (0),

    [SPECIES_TORCHIC]          = (0),

    [SPECIES_COMBUSKEN]        = (0),

    [SPECIES_BLAZIKEN]         = (0),

    [SPECIES_MUDKIP]           = (0),

    [SPECIES_MARSHTOMP]        = (0),

    [SPECIES_SWAMPERT]         = (0),

    [SPECIES_POOCHYENA]        = (TUTOR(MOVE_BITE)),

    [SPECIES_MIGHTYENA]        = (TUTOR(MOVE_BITE)),

    [SPECIES_ZIGZAGOON]        = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_LINOONE]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_WURMPLE]          = (0),

    [SPECIES_SILCOON]          = (0),

    [SPECIES_BEAUTIFLY]        = (0),

    [SPECIES_CASCOON]          = (0),

    [SPECIES_DUSTOX]           = (0),

    [SPECIES_LOTAD]            = (0),

    [SPECIES_LOMBRE]           = (0),

    [SPECIES_LUDICOLO]         = (0),

    [SPECIES_SEEDOT]           = (0),

    [SPECIES_NUZLEAF]          = (0),

    [SPECIES_SHIFTRY]          = (0),

    [SPECIES_TAILLOW]          = (0),

    [SPECIES_SWELLOW]          = (0),

    [SPECIES_WINGULL]          = (0),

    [SPECIES_PELIPPER]         = (0),

    [SPECIES_RALTS]            = (0),

    [SPECIES_KIRLIA]           = (0),

    [SPECIES_GARDEVOIR]        = (0),

    [SPECIES_SURSKIT]          = (0),

    [SPECIES_MASQUERAIN]       = (0),

    [SPECIES_SHROOMISH]        = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_BRELOOM]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_SLAKOTH]          = (0),

    [SPECIES_VIGOROTH]         = (0),

    [SPECIES_SLAKING]          = (0),

    [SPECIES_NINCADA]          = (0),

    [SPECIES_NINJASK]          = (0),

    [SPECIES_SHEDINJA]         = (0),

    [SPECIES_WHISMUR]          = (0),

    [SPECIES_LOUDRED]          = (0),

    [SPECIES_EXPLOUD]          = (0),

    [SPECIES_MAKUHITA]         = (0),

    [SPECIES_HARIYAMA]         = (0),

    [SPECIES_AZURILL]          = (0),

    [SPECIES_NOSEPASS]         = (0),

    [SPECIES_SKITTY]           = (0),

    [SPECIES_DELCATTY]         = (0),

    [SPECIES_SABLEYE]          = (0),

    [SPECIES_MAWILE]           = (TUTOR(MOVE_BITE)),

    [SPECIES_ARON]             = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_LAIRON]           = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_AGGRON]           = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_MEDITITE]         = (0),

    [SPECIES_MEDICHAM]         = (0),

    [SPECIES_ELECTRIKE]        = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_MANECTRIC]        = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_PLUSLE]           = (0),

    [SPECIES_MINUN]            = (0),

    [SPECIES_VOLBEAT]          = (0),

    [SPECIES_ILLUMISE]         = (0),

    [SPECIES_ROSELIA]          = (0),

    [SPECIES_GULPIN]           = (0),

    [SPECIES_SWALOT]           = (0),

    [SPECIES_CARVANHA]         = (TUTOR(MOVE_BITE)),

    [SPECIES_SHARPEDO]         = (TUTOR(MOVE_BITE)),

    [SPECIES_WAILMER]          = (0),

    [SPECIES_WAILORD]          = (0),

    [SPECIES_NUMEL]            = (0),

    [SPECIES_CAMERUPT]         = (0),

    [SPECIES_TORKOAL]          = (0),

    [SPECIES_SPOINK]           = (0),

    [SPECIES_GRUMPIG]          = (0),

    [SPECIES_SPINDA]           = (0),

    [SPECIES_TRAPINCH]         = (TUTOR(MOVE_BITE)),

    [SPECIES_VIBRAVA]          = (TUTOR(MOVE_BITE)),

    [SPECIES_FLYGON]           = (TUTOR(MOVE_BITE)),

    [SPECIES_CACNEA]           = (0),

    [SPECIES_CACTURNE]         = (0),

    [SPECIES_SWABLU]           = (0),

    [SPECIES_ALTARIA]          = (0),

    [SPECIES_ZANGOOSE]         = (0),

    [SPECIES_SEVIPER]          = (TUTOR(MOVE_BITE)),

    [SPECIES_LUNATONE]         = (0),

    [SPECIES_SOLROCK]          = (0),

    [SPECIES_BARBOACH]         = (0),

    [SPECIES_WHISCASH]         = (0),

    [SPECIES_CORPHISH]         = (0),

    [SPECIES_CRAWDAUNT]        = (0),

    [SPECIES_BALTOY]           = (0),

    [SPECIES_CLAYDOL]          = (0),

    [SPECIES_LILEEP]           = (0),

    [SPECIES_CRADILY]          = (0),

    [SPECIES_ANORITH]          = (0),

    [SPECIES_ARMALDO]          = (0),

    [SPECIES_FEEBAS]           = (0),

    [SPECIES_MILOTIC]          = (0),

    [SPECIES_CASTFORM]         = (0),

    [SPECIES_KECLEON]          = (0),

    [SPECIES_SHUPPET]          = (0),

    [SPECIES_BANETTE]          = (0),

    [SPECIES_DUSKULL]          = (0),

    [SPECIES_DUSCLOPS]         = (0),

    [SPECIES_TROPIUS]          = (TUTOR(MOVE_HEADBUTT)),

    [SPECIES_CHIMECHO]         = (0),

    [SPECIES_ABSOL]            = (TUTOR(MOVE_BITE)),

    [SPECIES_WYNAUT]           = (0),

    [SPECIES_SNORUNT]          = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_GLALIE]           = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_SPHEAL]           = (0),

    [SPECIES_SEALEO]           = (0),

    [SPECIES_WALREIN]          = (0),

    [SPECIES_CLAMPERL]         = (0),

    [SPECIES_HUNTAIL]          = (TUTOR(MOVE_BITE)),

    [SPECIES_GOREBYSS]         = (0),

    [SPECIES_RELICANTH]        = (0),

    [SPECIES_LUVDISC]          = (0),

    [SPECIES_BAGON]            = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_SHELGON]          = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_SALAMENCE]        = (TUTOR(MOVE_HEADBUTT)
                                | TUTOR(MOVE_BITE)),

    [SPECIES_BELDUM]           = (0),

    [SPECIES_METANG]           = (0),

    [SPECIES_METAGROSS]        = (0),

    [SPECIES_REGIROCK]         = (0),

    [SPECIES_REGICE]           = (0),

    [SPECIES_REGISTEEL]        = (0),

    [SPECIES_LATIAS]           = (0),

    [SPECIES_LATIOS]           = (0),

    [SPECIES_KYOGRE]           = (0),

    [SPECIES_GROUDON]          = (0),

    [SPECIES_RAYQUAZA]         = (0),

    [SPECIES_JIRACHI]          = (0),

};
