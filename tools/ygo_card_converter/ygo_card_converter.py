import requests
import json
import os
import subprocess
from PIL import Image
import re
import textwrap

f = open("YGOProDeck_Card_Info.json", "w")
url = "https://db.ygoprodeck.com/api/v7/cardinfo.php?misc=yes"
res = requests.get(url)
data = json.dumps(res.json(), indent=4)
f.write(data)
f.close()

formats = ['Yugi-Kaiba', 'Critter', 'Treasure', 'Imperial', 'Android', 'Joey-Pegasus', 'Fiber', 'Yata', 'Scientist', 'Vampire', 'Chaos', 'Warrior', 'Goat', 'Cyber', 'Reaper']

highest_usage = {}
for format in formats:
   highest_usage[format] = 0

with open('FL.json', 'r') as f:
    data = json.load(f)
    for card in data:
        if card['Format'] in formats and card['Usage (Weighted)'] > highest_usage[card['Format']]:
           highest_usage[card['Format']] = card['Usage (Weighted)']

def move_palette_color(img, old_index, new_index):
    """
    Moves a color at old_index in the image_cropped's palette to new_index.

    Args:
        image_cropped_path: Path to the paletted image_cropped.
        old_index: Index of the color to move.
        new_index: Index to move the color to.
    """
    if img.mode != "P":
        raise ValueError("Image must be in paletted (P) mode.")

    palette = img.getpalette()
    if palette is None:
      raise ValueError("Image must have a palette.")

    # Extract the color to move
    color_to_move = [57, 255, 20]

    # Remove the color from its old position
    del palette[old_index * 3: old_index * 3 + 3]

    # Insert the color at the new position
    palette[new_index * 3: new_index * 3] = color_to_move

    # Update the palette
    img.putpalette(palette)

    # If old_index < new_index, shift pixel values down
    if old_index < new_index:
      for x in range(img.width):
        for y in range(img.height):
          if img.getpixel((x, y)) == old_index:
            img.putpixel((x, y), 256 if new_index == 256 else new_index)
          elif img.getpixel((x,y)) > old_index and img.getpixel((x,y)) <= new_index:
            img.putpixel((x, y), img.getpixel((x,y)) - 1)
    # If old_index > new_index, shift pixel values up
    elif old_index > new_index:
      for x in range(img.width):
        for y in range(img.height):
          if img.getpixel((x, y)) == old_index:
            img.putpixel((x, y), new_index)
          elif img.getpixel((x,y)) >= new_index and img.getpixel((x,y)) < old_index:
            img.putpixel((x, y), img.getpixel((x,y)) + 1)
    
    return img

card_names = [
    'Dark Magician',
    'Blue-Eyes White Dragon',
    'Red-Eyes Black Dragon',
    'Flame Swordsman',
    'Gaia The Fierce Knight',
    'Trap Hole',
    'Polymerization',
    'Pot of Greed',
    'Exodia the Forbidden One',
    'Left Arm of the Forbidden One',
    'Left Leg of the Forbidden One',
    'Right Arm of the Forbidden One',
    'Right Leg of the Forbidden One',
    'Change of Heart',
    'Dark Hole',
    'Fissure',
    'Monster Reborn',
    'Raigeki',
    'Swords of Revealing Light',
    'Giant Soldier of Stone',
    'Summoned Skull',
    'Soul Exchange',
    'Wall of Illusion',
    'Ultimate Offering',
    'Aqua Madoor',
    'Gaia the Dragon Champion',
    'Just Desserts',
    'Mystical Elf',
	'Heavy Storm',
	'Mirror Force',
	'Sangan',
	'Witch of the Black Forest',
	'Magician of Faith',
	'Muka Muka',
	'Solemn Judgment',
	'Thunder Dragon',
	'Seven Tools of the Bandit',
	'Masked Sorcerer',
	'Last Will',
	"Robbin' Goblin",
	'Twin-Headed Thunder Dragon',
	'Black Skull Dragon',
	'Cannon Soldier',
	'Bickuribox',
	'Labyrinth Tank',
	'Jirai Gumo',
	'Magic Jammer',
	'White Magical Hat',
	'7 Colored Fish',
	'Dark Elf',
	'Giga-Tech Wolf',
	'Kuriboh',
	'Man-Eater Bug',
	'La Jinn the Mystical Genie of the Lamp',
	'Reinforcements',
	'Battle Ox',
	'Neo the Magic Swordsman',
	'Waboku',
	'Judge Man',
	'Skull Knight',
    'Crass Clown',
    'Tribute to the Doomed',
    'Mask of Darkness',
    'Ookazi',
    'Dream Clown',
]

card_info_data = open('YGOProDeck_Card_Info.json')
card_info_data = json.load(card_info_data)
card_info = {}
gCardInfo = ''
YGO = ''
YGO_Graphics = ''
ItemIconTable = ''
YGO_Graphics_C = ''
YGO_Constants = ''
Item_Constants = ''
Items = ''
YGO_C = ''
UI_Menu = ''
Scripts = ''
Graphics_File_Rules = ''
card_counter = 1
for data in card_info_data['data']:
    card_name = data['name']
    if card_name in card_names:
        gCardInfo += ('const u8 gCardName_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + card_name + '");\n'
                  + 'const u8 gCardNameShort_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
         + card_name[:22] + '");\n')
        YGO_C += 'const u8 gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + textwrap.fill(data['desc'].replace('"', '').replace('\r\n', '').replace('\n', '').replace("''", ''), width=30).replace('\n', '\\n') + '");\n'
        YGO += 'extern const u8 gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
        YGO_Graphics += ('extern const u32 gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big[];\n'
                     + 'extern const u16 gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
                     + 'extern const u32 gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
                     + 'extern const u32 gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
                     + 'extern const u32 gCardIconLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
                     + 'extern const u32 gCardIconLargePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
                     + 'extern const u32 gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
                     + 'extern const u32 gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n')
        ItemIconTable += '\t[ITEM_' + re.sub(r'\W+', '_', data['name']).upper() + '] = {gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ', gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '},\n'
        Scripts += '\tadditem ITEM_' + re.sub(r'\W+', '_', data['name']).upper() + '\n'
        YGO_Graphics_C += ('const u32 gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.8bpp.lz");\n'
                      + 'const u16 gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U16("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.gbapal");\n'
                      + 'const u32 gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_tiny.4bpp.lz");\n'
                      + 'const u32 gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_tiny.gbapal.lz");\n'
                      + 'const u32 gCardIconLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_large.4bpp.lz");\n'
                      + 'const u32 gCardIconLargePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_large.gbapal.lz");\n'
                      + 'const u32 gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.4bpp.lz");\n'
                      + 'const u32 gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.gbapal.lz");\n')
        YGO_Constants += '#define CARD_' + re.sub(r'\W+', '_', data['name']).upper() + ' ' + str(card_counter) + '\n'
        Item_Constants += '#define ITEM_' + re.sub(r'\W+', '_', data['name']).upper() + ' ' + str(card_counter + 376) + '\n'
        card_counter += 1
        Items += '''\t[ITEM_''' + re.sub(r'\W+', '_', data['name']).upper() + '''] =
    {
        .name = _("''' + re.sub(r'[^a-zA-Z0-9]', '', data['name'])[:13] + '''"),
        .itemId = ITEM_''' + re.sub(r'\W+', '_', data['name']).upper() + ''',
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },\n
'''
        UI_Menu += '''    {
        .data = gCardPicLarge_''' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '''_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },\n'''
        Graphics_File_Rules += 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '''/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64\n\n'''

gCardInfo += '\n'
YGO_C += '\n'
card_counter = 1
for data in card_info_data['data']:
    card_name = data['name']
    if card_name in card_names:
        for card_image_cropped in data['card_images']:
            card_id = str(card_image_cropped['id'])
            image_cropped_url = 'https://images.ygoprodeck.com/images/cards/' + card_id + '.jpg'
            image_cropped_url_cropped = 'https://images.ygoprodeck.com/images/cards_cropped/' + card_id + '.jpg'
            res = requests.get(image_cropped_url)
            image = 'Artwork/' + card_name + '_' + card_id + '.jpg'
            if not os.path.exists(image):
                with open(image, 'wb') as file:
                    file.write(res.content)
            res = requests.get(image_cropped_url_cropped)
            image_cropped = 'Artwork/' + card_name + '_' + card_id + '_Cropped.jpg'
            if not os.path.exists(image_cropped):
                with open(image_cropped, 'wb') as file:
                    file.write(res.content)
            folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
            if not os.path.exists(folder_path):
                os.mkdir(folder_path)
            outfile = folder_path + '/pic_large_big.png'
            if not os.path.exists(outfile):
                size = 80, 80
                im = Image.open(image_cropped)
                im.thumbnail(size, Image.Resampling.LANCZOS)
                im = im.convert(
                    "P", palette=Image.ADAPTIVE, colors=63
                )
                im = move_palette_color(im, 63, 0)
                im.save(outfile, "PNG")
                subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.8bpp')])
                subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.pal')])
                subprocess.run(['../gbagfx/gbagfx', outfile.replace('.png', '.8bpp'), outfile.replace('.png', '.8bpp')])
                subprocess.run(['../gbagfx/gbagfx', outfile.replace('.png', '.8bpp'), outfile.replace('.png', '.png'), '-palette', outfile.replace('.png', '.pal'), '-mwidth', '10'])
            size = 32, 32
            folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
            if not os.path.exists(folder_path):
                os.mkdir(folder_path)
            outfile = folder_path + '/pic_tiny.png'
            if not os.path.exists(outfile):
                im = Image.open(image_cropped)
                im.thumbnail(size, Image.Resampling.LANCZOS)
                im = im.convert(
                    "P", palette=Image.ADAPTIVE, colors=15
                )
                im = move_palette_color(im, 15, 0)
                im.save(outfile, "PNG")
            size = 32, 46
            master = Image.new(
                mode='RGBA',
                size=(32, 48),
                color=(57,255,20,0))
            folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
            if not os.path.exists(folder_path):
                os.mkdir(folder_path)
            outfile = folder_path + '/icon_large.png'
            if not os.path.exists(outfile):
                im = Image.open(image)
                im.thumbnail(size, Image.Resampling.LANCZOS)
                master.paste(im, box=(0,1))
                master.save(outfile, "PNG")
                master = Image.open(outfile)
                master = master.convert(
                    "P", palette=Image.ADAPTIVE, colors=15
                )
                master = move_palette_color(master, 15, 0)
                master.save(outfile, "PNG")
                subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
            size = 22, 32
            master = Image.new(
                mode='RGBA',
                size=(24, 32),
                color=(57,255,20,0))
            folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
            if not os.path.exists(folder_path):
                os.mkdir(folder_path)
            outfile = folder_path + '/icon_small.png'
            if not os.path.exists(outfile):
                im = Image.open(image)
                im.thumbnail(size, Image.Resampling.LANCZOS)
                master.paste(im, box=(1,0))
                master.save(outfile, "PNG")
                master = Image.open(outfile)
                master = master.convert(
                    "P", palette=Image.ADAPTIVE, colors=15
                )
                master = move_palette_color(master, 15, 0)
                master.save(outfile, "PNG")
                subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
        card = data['name']
        gCardInfo += ("\t[CARD_" + re.sub(r'\W+', '_', data['name']).upper() + "] =\n"
                  + "\t{\n"
                  + '\t\t.name = gCardName_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.nameShort = gCardNameShort_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.description = gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.password = _("' + str(data['id']) + '"),\n'
                  + '\t\t.pic = gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big,\n'
                  + '\t\t.pal = gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.iconSquare = gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.iconLarge = gCardIconLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.iconSmall = gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
                  + '\t\t.effects = {EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE},\n'
                  + ("\t\t.type = TYPE_" + re.sub(r'\W+', '_', data['type']).upper() + ",\n"))
        try:
            gCardInfo += ("\t\t.attribute = ATTRIBUTE_" + data['attribute'] + ",\n"
                       + "\t\t.level = " + str(data['level']) + ",\n"
                       + "\t\t.atk = " + str(int(data['atk']/10)) + ",\n"
                       + "\t\t.def = " + str(int(data['def']/10)) + ",\n"
                       + "\t\t.race = RACE_" + re.sub(r'\W+', '_', data['race']).upper() + ",\n")
        except:
            gCardInfo += ("\t\t.attribute = ATTRIBUTE_NONE,\n"
                      + "\t\t.level = 0,\n"
                      +  "\t\t.atk = 0,\n"
                      + "\t\t.def = 0,\n"
                      + "\t\t.race = RACE_NONE,\n")
        gCardInfo += ("\t\t.id = " + str(data['misc_info'][0]['konami_id']) + ",\n"
                      + "\t\t.archetypesSeries = {ARCHETYPE_NONE, ARCHETYPE_NONE, ARCHETYPE_NONE},\n")
        with open('FL.json', 'r') as f:
            data_ = json.load(f)
            for card_ in data_:
                if card_['Card'] == card and card_['Format'] == 'Yugi-Kaiba':
                      gCardInfo += "\t\t.priceYK = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
        gCardInfo += ("\t\t.priceCritter = 0,\n"
                      + "\t\t.priceTreasure = 0,\n"
                      + "\t\t.priceImperial = 0,\n"
                      + "\t\t.priceAndroid = 0,\n"
                      + "\t\t.priceJoeyPegasus = 0,\n"
                      + "\t\t.priceFiber = 0,\n"
                      + "\t\t.priceYata = 0,\n"
                      + "\t\t.priceScientist = 0,\n"
                      + "\t\t.priceVampire = 0,\n"
                      + "\t\t.priceChaos = 0,\n"
                      + "\t\t.priceWarrior = 0,\n"
                      + "\t\t.priceGoat = 0,\n"
                      + "\t\t.priceCyber = 0,\n"
                      + "\t\t.priceReaper = 0,\n"
                      + "\t\t.price1 = 0,\n"
                      + "\t\t.price2 = 0,\n"
                      + "\t\t.price3 = 0,\n"
                      + '\t},\n')
        YGO_C += '    [ITEM_' + re.sub(r'\W+', '_', data['name']).upper() + '] = ' + str(card_counter) + ',\n'
        card_counter += 1

gCardInfo_Output = open('include/card_info.h', 'w')
gCardInfo_Output.write(gCardInfo)
YGO_Output = open('include/ygo.h', 'w')
YGO_Output.write(YGO)
YGO_Graphics_Output = open('include/ygo_graphics.h', 'w')
YGO_Graphics_Output.write(YGO_Graphics)
ItemIconTable_Output = open('src/data/item_icon_table.h', 'w')
ItemIconTable_Output.write(ItemIconTable)
YGO_Graphics_C_Output = open('src/ygo_graphics.c', 'w')
YGO_Graphics_C_Output.write(YGO_Graphics_C)
YGO_Constants_Output = open('include/constants/ygo.h', 'w')
YGO_Constants_Output.write(YGO_Constants)
Item_Constants_Output = open('include/constants/items.h', 'w')
Item_Constants_Output.write(Item_Constants)
Items_Output = open('src/data/items.h', 'w')
Items_Output.write(Items)
YGO_C_Output = open('src/ygo.c', 'w')
YGO_C_Output.write(YGO_C)
UI_Menu_Output = open('src/ui_menu.c', 'w')
UI_Menu_Output.write(UI_Menu)
Scripts_Output = open('scripts.inc', 'w')
Scripts_Output.write(Scripts)
Graphics_File_Rules_Output = open('graphics_file_rules.mk', 'w')
Graphics_File_Rules_Output.write(Graphics_File_Rules)