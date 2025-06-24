#ifndef GUARD_YGO_H
#define GUARD_YGO_H

struct CardInfo
{
    /* 0x00 */ const u8 *name;
    /* 0x04 */ const u8 *nameShort;
    /* 0x08 */ const u8 *description;
    /* 0x0C */ const u8 password[9];
    /* 0x14 */ const u32 *pic;
    /* 0x18 */ const u16 *pal;
    /* 0x1C */ const u32 *iconSquare;
    /* 0x20 */ const u32 *iconLarge;
    /* 0x24 */ const u32 *iconSmall;
    /* 0x28 */ u16 effects[8];
    /* 0x38 */ u32 type:5;
    /* 0x38 */ u32 attribute:3;
    /* 0x39 */ u32 level:4;
    /* 0x39 */ u32 atk:9;
    /* 0x3A */ u32 def:9;
    /* 0x3B */ u8 race;
    /* 0x3C */ u16 id;
    /* 0x3E */ u16 archetypesSeries[3];
};

extern const struct CardInfo gCardInfo[];
extern const u8 gCardDescription_AquaMadoor[];
extern const u8 gCardDescription_BlueEyesWhiteDragon[];
extern const u8 gCardDescription_ChangeofHeart[];
extern const u8 gCardDescription_DarkHole[];
extern const u8 gCardDescription_DarkMagician[];
extern const u8 gCardDescription_ExodiatheForbiddenOne[];
extern const u8 gCardDescription_Fissure[];
extern const u8 gCardDescription_FlameSwordsman[];
extern const u8 gCardDescription_GaiatheDragonChampion[];
extern const u8 gCardDescription_GaiaTheFierceKnight[];
extern const u8 gCardDescription_GiantSoldierofStone[];
extern const u8 gCardDescription_JustDesserts[];
extern const u8 gCardDescription_LeftArmoftheForbiddenOne[];
extern const u8 gCardDescription_LeftLegoftheForbiddenOne[];
extern const u8 gCardDescription_MonsterReborn[];
extern const u8 gCardDescription_MysticalElf[];
extern const u8 gCardDescription_Polymerization[];
extern const u8 gCardDescription_PotofGreed[];
extern const u8 gCardDescription_Raigeki[];
extern const u8 gCardDescription_RedEyesBlackDragon[];
extern const u8 gCardDescription_RightArmoftheForbiddenOne[];
extern const u8 gCardDescription_RightLegoftheForbiddenOne[];
extern const u8 gCardDescription_SoulExchange[];
extern const u8 gCardDescription_SummonedSkull[];
extern const u8 gCardDescription_SwordsofRevealingLight[];
extern const u8 gCardDescription_TrapHole[];
extern const u8 gCardDescription_UltimateOffering[];
extern const u8 gCardDescription_WallofIllusion[];
extern const u8 CardIdMapping[];

#endif // GUARD_YGO_H
