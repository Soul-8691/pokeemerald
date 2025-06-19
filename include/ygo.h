#ifndef GUARD_YGO_H
#define GUARD_YGO_H

struct CardInfo
{
    /* 0x00 */ const u8 *name;
    /* 0x04 */ const u8 *description;
    /* 0x08 */ const u8 *password;
    /* 0x0C */ const u32 *picLarge;
    /* 0x10 */ const u32 *picSmall;
    /* 0x14 */ const u32 *iconSquare;
    /* 0x18 */ const u32 *iconLarge;
    /* 0x1C */ const u32 *iconSmall;
    /* 0x20 */ u16 effects[16];
    /* 0x40 */ u32 type:3;
    /* 0x40 */ u32 attribute:3;
    /* 0x40 */ u32 level:4;
    /* 0x41 */ u32 atk:9;
    /* 0x42 */ u32 def:9;
    /* 0x44 */ u8 race;
    /* 0x45 */ u16 id;
};

extern const struct CardInfo gCardInfo[];

#endif // GUARD_YGO_H
