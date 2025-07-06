#include "global.h"
#include "decompress.h"
#include "graphics.h"
#include "item_icon.h"
#include "malloc.h"
#include "sprite.h"
#include "constants/items.h"
#include "ygo.h"
#include "ygo_graphics.h"
#include "constants/ygo.h"
#include "constants/characters.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"

// EWRAM vars
EWRAM_DATA u8 *gItemIconDecompressionBuffer = NULL;
EWRAM_DATA u8 *gItemIcon4x4Buffer = NULL;

// const rom data
#include "data/item_icon_table.h"

static const struct OamData sOamData_ItemIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 2,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_ItemIcon[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_ItemIcon[] =
{
    sSpriteAnim_ItemIcon
};

const struct SpriteTemplate gItemIconSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_ItemIcon,
    .anims = sSpriteAnimTable_ItemIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// code
bool8 AllocItemIconTemporaryBuffers(void)
{
    if (VarGet(VAR_YGO_ICON) == 2)
        gItemIconDecompressionBuffer = Alloc(0x600);
    else
        gItemIconDecompressionBuffer = Alloc(0x200);

    if (gItemIconDecompressionBuffer == NULL)
    {
        Free(gItemIconDecompressionBuffer);
        return FALSE;
    }

    if (VarGet(VAR_YGO_ICON) == 2)
        gItemIcon4x4Buffer = AllocZeroed(0x800);
    else
        gItemIcon4x4Buffer = AllocZeroed(0x200);
    if (gItemIcon4x4Buffer == NULL)
    {
        Free(gItemIcon4x4Buffer);
        return FALSE;
    }

    return TRUE;
}

void FreeItemIconTemporaryBuffers(void)
{
    Free(gItemIconDecompressionBuffer);
    Free(gItemIcon4x4Buffer);
}

void CopyItemIconPicTo4x4Buffer(const void *src, void *dest, u16 itemId)
{
    u8 i;
    u16 card = CardIdMapping[itemId];

    if (VarGet(VAR_YGO_ICON) == 1)
    {
        for (i = 0; i < 4; i++)
            CpuCopy16(src + i * 64, dest + i * 128, 0x40);
    }
    // else if (VarGet(VAR_YGO_ICON) == 2)
    // {
    //     for (i = 0; i < 4; i++)
    //         CpuCopy16(src + i * 96, dest + i * 128, 0x60);
    // }
    else if ((card < NUM_CARDS + 1 && card != 0) || VarGet(VAR_YGO_ICON) == 2)
    {
        for (i = 0; i < 4; i++)
            CpuCopy16(src + i * 128, dest + i * 128, 0x80);
    }
    else
    {
        for (i = 0; i < 3; i++)
            CpuCopy16(src + i * 96, dest + i * 128, 0x60);
    }
}

u8 AddItemIconSprite(u16 tilesTag, u16 paletteTag, u16 itemId)
{
    if (!AllocItemIconTemporaryBuffers())
    {
        return MAX_SPRITES;
    }
    else
    {
        u8 spriteId;
        struct SpriteSheet spriteSheet;
        struct CompressedSpritePalette spritePalette;
        struct SpriteTemplate *spriteTemplate;
        u16 card = CardIdMapping[itemId];

        LZDecompressWram(GetItemIconPicOrPalette(itemId, 0), gItemIconDecompressionBuffer);
        CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer, itemId);
        spriteSheet.data = gItemIcon4x4Buffer;
        spriteSheet.size = 0x200;
        spriteSheet.tag = tilesTag;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetItemIconPicOrPalette(itemId, 1);
        spritePalette.tag = paletteTag;
        LoadCompressedSpritePalette(&spritePalette);

        spriteTemplate = Alloc(sizeof(*spriteTemplate));
        CpuCopy16(&gItemIconSpriteTemplate, spriteTemplate, sizeof(*spriteTemplate));
        spriteTemplate->tileTag = tilesTag;
        spriteTemplate->paletteTag = paletteTag;
        spriteId = CreateSprite(spriteTemplate, 0, 0, 0);

        FreeItemIconTemporaryBuffers();
        Free(spriteTemplate);

        return spriteId;
    }
}

u8 AddCustomItemIconSprite(const struct SpriteTemplate *customSpriteTemplate, u16 tilesTag, u16 paletteTag, u16 itemId)
{
    if (!AllocItemIconTemporaryBuffers())
    {
        return MAX_SPRITES;
    }
    else
    {
        u8 spriteId;
        struct SpriteSheet spriteSheet;
        struct CompressedSpritePalette spritePalette;
        struct SpriteTemplate *spriteTemplate;
        u16 card = CardIdMapping[itemId];

        LZDecompressWram(GetItemIconPicOrPalette(itemId, 0), gItemIconDecompressionBuffer);
        CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer, itemId);
        spriteSheet.data = gItemIcon4x4Buffer;
        spriteSheet.size = 0x200;
        spriteSheet.tag = tilesTag;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetItemIconPicOrPalette(itemId, 1);
        spritePalette.tag = paletteTag;
        LoadCompressedSpritePalette(&spritePalette);

        spriteTemplate = Alloc(sizeof(*spriteTemplate));
        CpuCopy16(customSpriteTemplate, spriteTemplate, sizeof(*spriteTemplate));
        spriteTemplate->tileTag = tilesTag;
        spriteTemplate->paletteTag = paletteTag;
        spriteId = CreateSprite(spriteTemplate, 0, 0, 0);

        FreeItemIconTemporaryBuffers();
        Free(spriteTemplate);

        return spriteId;
    }
}

const void *GetItemIconPicOrPalette(u16 itemId, u8 which)
{
    u16 card = CardIdMapping[itemId];
    if (itemId == ITEM_LIST_END)
        itemId = ITEMS_COUNT; // Use last icon, the "return to field" arrow
    else if (itemId >= ITEMS_COUNT)
        itemId = 0;

    if (VarGet(VAR_YGO_ICON) == 1)
    {
        if (which == 0)
            return gCardInfo[card].iconTiny;
        else
            return gCardInfo[card].palIconTiny;
    }
    // else if (VarGet(VAR_YGO_ICON) == 2)
    // {
    //     if (which == 0)
    //         return gCardInfo[card].iconLarge;
    //     else
    //         return gCardInfo[card].palIconLarge;
    // }

    return gItemIconTable[itemId][which];
}
