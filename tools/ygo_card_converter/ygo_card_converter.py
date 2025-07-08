import requests
import json
import os
import subprocess
from PIL import Image
import re
import textwrap
from tqdm import tqdm

# f = open("YGOProDeck_Card_Info.json", "w")
# url = "https://db.ygoprodeck.com/api/v7/cardinfo.php?misc=yes"
# res = requests.get(url)
# data = json.dumps(res.json(), indent=4)
# f.write(data)
# f.close()
# url = 'https://dawnbrandbots.github.io/yaml-yugi/cards.json'  # Example URL for a JSON endpoint

# try:
#     response = requests.get(url)
#     response.raise_for_status()  # Raise an exception for bad status codes (4xx or 5xx)

#     json_data = response.json()  # Automatically parses the JSON response into a Python dictionary or list

#     # Option 1: Process the JSON data in Python
#     print("Fetched JSON data:")
#     # print(json_data)

#     # Option 2: Save the JSON data to a file
#     file_path = 'bastion.json'
#     with open(file_path, 'w', encoding='utf-8') as f:
#         json.dump(json_data, f, indent=4)  # `indent=4` for pretty-printing
#     print(f"\nJSON data successfully saved to '{file_path}'")

# except requests.exceptions.RequestException as e:
#     print(f"Error fetching data from URL: {e}")
# except json.JSONDecodeError as e:
#     print(f"Error decoding JSON response: {e}")

formats = ['Yugi-Kaiba', 'Critter', 'Treasure', 'Imperial', 'Android', 'Joey-Pegasus', 'Fiber', 'Yata', 'Scientist', 'Vampire', 'Chaos', 'Warrior', 'Goat', 'Cyber', 'Reaper', 'Chaos Return', 'Demise', 'Trooper', 'Zombie', 'Perfect Circle', 'DAD Return', 'Gladiator', 'TeleDAD', 'Cat', 'Edison', 'Frog', 'Starstrike', 'Tengu', 'Dino Rabbit', 'Wind-Up', 'Miami', 'Meadowlands', 'Baby Ruler', 'Ravine Ruler', 'Fire-Water', 'HAT', 'Vegas']

highest_usage = {}
cards_by_format = {}
for format in formats:
   highest_usage[format] = 0
   cards_by_format[format] = {}

cards_by_pack = dict()
packs = set()
with open('bastion.json', 'r') as f:
	data = json.load(f)
	for card in data:
		cards_by_pack[card['name']['en']] = card
		try:
			for set_tcg in card['sets']['en']:
				packs.add('TCG_' + set_tcg['set_name'])
		except:
			pass
		try:
			for set_ocg in card['sets']['ja']:
				packs.add('OCG_' + set_ocg['set_name'])
		except:
			pass

packs = sorted(list(packs))

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

# with open('ocg_sets.json', 'r') as f:
# 	data = json.load(f)
# 	for series in tqdm(data):
# 		for set_ in tqdm(packs):
# 			print(set_)
# 			try:
# 				set_url = data[series][set_[4:]]['image_url']
# 				res = requests.get(set_url)
# 				image = 'Sets/' + set_ + '.jpg'
# 				if not os.path.exists(image):
# 					with open(image, 'wb') as file:
# 						file.write(res.content)
# 						print(set_ + ' image written')
# 				outfile = 'Sets/Icons/' + re.sub(r'\W+', '_', set_).lower() + '_icon.jpg'
# 				if not os.path.exists(outfile):
# 					master = Image.new(
# 						mode='RGBA',
# 						size=(32, 32),
# 						color=(57,255,20,0))
# 					size = 32, 32
# 					im = Image.open(image)
# 					im.thumbnail(size, Image.Resampling.LANCZOS)
# 					pillow_width, pillow_height = im.size
# 					# Calculate the top-left coordinates for pasting
# 					paste_x = (32 - pillow_width) // 2
# 					paste_y = (32 - pillow_height) // 2
# 					master.paste(im, box=(paste_x,paste_y))
# 					master.save(outfile, "PNG")
# 					master = Image.open(outfile)
# 					master = master.convert(
# 						"P", palette=Image.ADAPTIVE, colors=15
# 					)
# 					master = move_palette_color(master, 15, 0)
# 					master.save(outfile, "PNG")
# 					subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
# 					print(set_ + ' icon written')
# 			except:
# 				pass

with open('FL.json', 'r') as f:
    data = json.load(f)
    for card in data:
        if card['Format'] in formats:
            cards_by_format[card['Format']][card['Card']] = card['Usage']
            if card['Usage (Weighted)'] > highest_usage[card['Format']]:
            	highest_usage[card['Format']] = card['Usage (Weighted)']

wct06_ranks = {}
with open('wct06.json', 'r') as f:
    data = json.load(f)
    for card in data:
        wct06_ranks[card['Card']] = 1
        if card['Rank']:
           wct06_ranks[card['Card']] = card['Rank']

card_names = [

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
SRCDataItemDescs = ''
card_counter = 1
pack_counter = 2044
description_lines = dict()

ItemUse = ''
Item = ''
for format_ in formats:
    Item += '''    else if (VarGet(VAR_YGO_SHOP) == BANLIST_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ''')
    {
        if (gCardInfo[card].ban''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''')
            return gCardInfo[card].ban''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''';
        else
            return 3;
    }\n'''
    ItemUse += '''    else if (pack == PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ''')
    {
        u16 cards[NUM_CARDS];
        for (i = 0; i < NUM_CARDS; i++)
        {
            if (gCardInfo[i].price''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''')
            {
                j += 1000 - gCardInfo[i].price''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''';
                cards[length] = i;
                length += 1;
            }
        }
        for (k = 0; k < 5; k++)
        {
            random = Random() % j;
            l = random;
            for (i = 0; i < length; i++)
            {
                u16 rarity = 1000 - gCardInfo[cards[i]].price''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''';
                u16 card = cards[i];
                l -= rarity;
                if (l <= rarity)
                {
                    if (k == 0)
                        gSpecialVar_0x8004 = card + 376;
                    else if (k == 1)
                        gSpecialVar_0x8005 = card + 376;
                    else if (k == 2)
                        gSpecialVar_0x8006 = card + 376;
                    else if (k == 3)
                        gSpecialVar_0x8007 = card + 376;
                    else if (k == 4)
                        gSpecialVar_0x8008 = card + 376;
                    break;
                }
            }
        }
    }\n'''

ItemPrinter = open('src/item.c', 'w', encoding='utf-8')
ItemPrinter.write(Item)
ItemPrinter.close()
print('src/item.c written')
ItemUsePrinter = open('src/item_use.c', 'w', encoding='utf-8')
ItemUsePrinter.write(ItemUse)
ItemUsePrinter.close()
print('src/item_use.c written')

tcg_sets = set()
for data in card_info_data['data']:
	try:
		for set_ in data['card_sets']:
			tcg_sets.add(set_['set_name'])
	except:
		pass

# Set_Writer = open('sets.json', 'w', encoding='utf-8')
# sets_write = {}
# for set_ in tqdm(packs):
#     print(set_)
#     sets_write[set_] = {}
#     for card in cards_by_pack:
#         try:
#             for set__ in cards_by_pack[card]['sets']['ja']:
#                 if set_[4:] == set__['set_name']:
#                     for rarity in set__['rarities']:
#                         sets_write[set_][card] = rarity
#         except:
#             pass
#         try:
#             for set__ in cards_by_pack[card]['sets']['en']:
#                 if set_[4:] == set__['set_name']:
#                     for rarity in set__['rarities']:
#                         sets_write[set_][card] = rarity
#         except:
#             pass

# json.dump(dict(sorted(sets_write.items())), Set_Writer, indent=4)
# Set_Writer.close()
# print('sets.json written')

# sets_print = ''
# for set_ in tqdm(packs):
# 	print(set_)
# 	if set_[0:3] == 'TCG':
# 		sets_print += 'const struct PackContents gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + '[] =\n{\n'
# 		for card in cards_by_pack:
# 			if card in card_names:
# 				try:
# 					for set__ in cards_by_pack[card]['sets']['en']:
# 						if set__['set_name'] == set_[4:]:
# 							for rarity in set__['rarities']:
# 								sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', rarity).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '},\n'
# 				except:
# 					pass
# 		sets_print += '};\n\n'
# 	if set_[0:3] == 'OCG':
# 		sets_print += 'const struct PackContents gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + '[] =\n{\n'
# 		for card in cards_by_pack:
# 			if card in card_names:
# 				try:
# 					for set__ in cards_by_pack[card]['sets']['en']:
# 						if set__['set_name'] == set_[4:]:
# 							for rarity in set__['rarities']:
# 								sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', rarity).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '},\n'
# 				except:
# 					pass
# 		sets_print += '};\n\n'

# with open('tcg_sets.json', 'r') as f:
#     data = json.load(f)
#     for set_ in data:
#         sets_print += 'const struct PackContents gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '[] =\n{\n'
#         for card in data[set_]:
#             if card in card_names:
#                 sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', data[set_][card]).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '},\n'
#         sets_print += '};\n\n'

# with open('ocg_sets.json', 'r') as f:
# 	data = json.load(f)
# 	for series in data:
# 		for set_ in data[series]:
# 			sets_print += 'const struct PackContents gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '[] =\n{\n'
# 			for card in data[series][set_]['cards']:
# 				if card in card_names:
# 					sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ', RARITY_COMMON},\n'
# 			sets_print += '};\n\n'

for set_ in packs:
    Scripts += '\tadditem ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' 10\n' 
Scripts += '\n'

YGO_C += '\nconst u16 PackIdMapping[] = \n{\n'
for set_ in packs:
	YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = ' + str(packs.index(set_)) + ',\n'

for format_ in formats:
    YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = ' + str(pack_counter) + ',\n'
    pack_counter += 1

YGO_C += '};\n\n'

# sets_print += '\nconst struct Pack gPacks[] =\n{\n'
# card_count = 0
# with open('sets.json', 'r') as f:
# 	data = json.load(f)
# 	for set_ in packs:
# 		if set_[0:3] == 'TCG':
# 			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] =\n\t{\n        .pack = gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + ',\n        .length = '
# 		else:
# 			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] =\n\t{\n        .pack = gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + ',\n        .length = '
# 		for card in data[set_]:
# 			if card in card_names:
# 				card_count += 1
# 		sets_print += str(card_count)
# 		sets_print += ',\n\t},\n'
# 		card_count = 0

# with open('ocg_sets.json', 'r') as f:
# 	data = json.load(f)
# 	for series in data:
# 		for set_ in data[series]:
# 			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] =\n\t{\n        .pack = gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_) + ',\n        .length = '
# 			for card in data[series][set_]['cards']:
# 				if card in card_names:
# 					card_count += 1
# 			sets_print += str(card_count)
# 			sets_print += ',\n\t},\n'
# 			card_count = 0

# sets_print += '};\n'
# PacksWrite = open('src/data/ygo/packs.h', 'w', encoding='utf-8')
# PacksWrite.write(sets_print)
# PacksWrite.close()
# print('src/data/ygo/packs.h written')

card_count = 0
for set_ in packs:
	SRCDataItemDescs += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', set_) + 'Desc[] = _(\n    "' + textwrap.fill(set_[4:].replace('"', ''), width=16).replace('\n', '\\n"\n    "') + '.");\n\n'

for format_ in formats:
    SRCDataItemDescs += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', format_) + 'Desc[] = _("' + textwrap.fill(format_, width=20).replace('\n', '\\n') + '.");\n\n'

SRCDataItemDescsWrite = open('src/data/text/item_descriptions.h', 'w', encoding='utf-8')
SRCDataItemDescsWrite.write(SRCDataItemDescs)
SRCDataItemDescsWrite.close()
print('src/data/text/item_descriptions.h written')

for card_name in card_names:
	for data in card_info_data['data']:
		description_lines[card_name] = 1
		if card_name == data['name']:
			gCardInfo += ('const u8 gCardName_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + card_name.replace('#', '') + '");\n'
					+ 'const u8 gCardNameShort_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
			+ card_name[:19].replace('#', '').replace('"', '') + '");\n'
					+ 'const u8 gCardNameShortBag_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
			+ card_name[:26].replace('#', '').replace('"', '') + '");\n')
			YGO_C += 'const u8 gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + textwrap.fill(data['desc'].replace('"', '').replace('\r\n', '').replace('\n', '').replace("''", ''), width=30).replace('\n', '\\n').replace('●', '-').replace('#', '') + '");\n'
			for line in range(textwrap.fill(data['desc'].replace('"', '').replace('\r\n', '').replace('\n', '').replace("''", ''), width=30).replace('\n', '\\n').count('\\n')):
				description_lines[card_name] += 1
			YGO += 'extern const u8 gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
			YGO_Graphics += ('extern const u32 gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big[];\n'
						+ 'extern const u16 gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
						+ 'extern const u32 gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
						+ 'extern const u32 gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
						+ 'extern const u32 gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
						+ 'extern const u32 gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
						+ 'extern const u32 gCardIconTiny_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n'
						+ 'extern const u32 gCardIconTinyPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[];\n')
			ItemIconTable += '\t[ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = {gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ', gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '},\n'
			Scripts += '\tadditem ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'
			YGO_Graphics_C += ('const u32 gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.8bpp.lz");\n'
						+ 'const u16 gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U16("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.gbapal");\n'
						+ 'const u32 gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_small.4bpp.lz");\n'
						+ 'const u32 gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_small.gbapal.lz");\n'
						+ 'const u32 gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.4bpp.lz");\n'
						+ 'const u32 gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.gbapal.lz");\n'
						+ 'const u32 gCardIconTiny_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_tiny.4bpp.lz");\n'
						+ 'const u32 gCardIconTinyPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_tiny.gbapal.lz");\n')
			YGO_Constants += '#define CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(card_counter) + '\n'
			Item_Constants += '#define ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(card_counter + 376) + '\n'
			card_counter += 1
			Items += '''\t[ITEM_CARD_''' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '''] =
	{
		.name = _("''' + re.sub(r'[^a-zA-Z0-9]', '', data['name'])[:13] + '''"),
		.itemId = ITEM_CARD_''' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ''',
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},\n
'''
			UI_Menu += '''    {
		.data = gCardPicLarge_''' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '''_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},\n'''
			Graphics_File_Rules += 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '''/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64\n\n'''

Item_Constants += '\n'
sets_count = 2432
for set_ in packs:
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(sets_count) + '\n'
    sets_count += 1
Item_Constants += '\n'

pack_counter = 4809
for format_ in formats:
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(pack_counter) + '\n'
    pack_counter += 1

for set_ in packs:
    Items += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '''] =
    {
        .name = _("''' + set_[4:17] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''
Items += '\n'

for format_ in formats:
    Items += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '''] =
    {
        .name = _("''' + format_[:13] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''

ItemIconTable += '\n'
for set_ in packs:
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'
    sets_count += 1

ItemIconTable += '\n'
for format_ in formats:
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'

YGO_Constants += '\n'
for set_ in packs:
    YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(packs.index(set_)) + '\n'

YGO_Constants += '\n'
pack_counter = 2377
for format_ in formats:
    YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(pack_counter) + '\n'
    pack_counter += 1

YGO_Output = open('include/ygo.h', 'w')
YGO_Output.write(YGO)
YGO_Output.close()
print('include/ygo.h written')
YGO_Graphics_Output = open('include/ygo_graphics.h', 'w')
YGO_Graphics_Output.write(YGO_Graphics)
YGO_Graphics_Output.close()
print('include/ygo_graphics.h written')
ItemIconTable_Output = open('src/data/item_icon_table.h', 'w')
ItemIconTable_Output.write(ItemIconTable)
ItemIconTable_Output.close()
print('src/data/item_icon_table.h written')
YGO_Graphics_C_Output = open('src/ygo_graphics.c', 'w')
YGO_Graphics_C_Output.write(YGO_Graphics_C)
YGO_Graphics_C_Output.close()
print('src/ygo_graphics.c written')
YGO_Constants_Output = open('include/constants/ygo.h', 'w')
YGO_Constants_Output.write(YGO_Constants)
YGO_Constants_Output.close()
print('include/constants/ygo.h written')
Item_Constants_Output = open('include/constants/items.h', 'w')
Item_Constants_Output.write(Item_Constants)
Item_Constants_Output.close()
print('include/constants/items.h written')
Items_Output = open('src/data/items.h', 'w')
Items_Output.write(Items)
Items_Output.close()
print('src/data/items.h written')
UI_Menu_Output = open('src/ui_menu.c', 'w')
UI_Menu_Output.write(UI_Menu)
UI_Menu_Output.close()
print('src/ui_menu.c written')
Graphics_File_Rules_Output = open('graphics_file_rules.mk', 'w')
Graphics_File_Rules_Output.write(Graphics_File_Rules)
Graphics_File_Rules_Output.close()
print('graphics_file_rules.mk written')

gCardInfo += '\n'
YGO_C += '\n'
Scripts += '\n'
for format in cards_by_format:
	Scripts += '''InsideOfTruck_EventScript_Clerk_''' + re.sub(r'\W+', '', format) + '''::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_''' + re.sub(r'\W+', '_', format).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '''
	message gText_''' + re.sub(r'\W+', '', format) + '''Clerk
	waitmessage
	pokemart InsideOfTruck_Pokemart''' + re.sub(r'\W+', '', format) + '''
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	setvar VAR_YGO_SHOP, 0
	release
	end

	.align 2
InsideOfTruck_Pokemart''' + re.sub(r'\W+', '', format) + ''':\n'''
	for data in card_info_data['data']:
		card_name = data['name']
		if card_name in card_names:
			for card_ in cards_by_format[format]:
				if card_ == card_name and cards_by_format[format][card_]:
					Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'
	Scripts += '\tpokemartlistend\n\n'

for format in cards_by_format:
	Scripts += '''InsideOfTruck_Text_''' + re.sub(r'\W+', '', format) + ''':
	.string "''' + format + '''$"\n\n'''

Scripts += '\n\n'
for format in cards_by_format:
	Scripts += '''InsideOfTruck_Text_''' + re.sub(r'\W+', '', format) + '''Banlist:
	.string "''' + format + ''' banlist$"\n\n'''

for format in cards_by_format:
	Scripts += '''gText_''' + re.sub(r'\W+', '', format) + '''Clerk::
	.string "Welcome!\\p"
	.string "I'm the ''' + re.sub(r'\W+', '', format) + ''' clerk.\\n"
	.string "How may I serve you?$"\n\n'''
	
for format in cards_by_format:
	Scripts += '''gText_''' + re.sub(r'\W+', '', format) + '''BanlistClerk::
	.string "Welcome!\\p"
	.string "I'm the ''' + re.sub(r'\W+', '', format) + ''' banlist clerk.\\n"
	.string "How may I serve you?$"\n\n'''

with open('FL.json', 'r') as f:
	data_ = json.load(f)
	for format in tqdm(cards_by_format):
		print(format)
		Scripts += '''InsideOfTruck_EventScript_Clerk_''' + re.sub(r'\W+', '', format) + '''Banlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_''' + re.sub(r'\W+', '_', format).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '''
	message gText_''' + re.sub(r'\W+', '', format) + '''BanlistClerk
	waitmessage
	pokemart InsideOfTruck_Pokemart''' + re.sub(r'\W+', '', format) + '''Banlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	setvar VAR_YGO_SHOP, 0
	release
	end

	.align 2
InsideOfTruck_Pokemart''' + re.sub(r'\W+', '', format) + '''Banlist:\n'''
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] == 'Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] == 'Semi-Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] != 'Limited' and card__['Banlist'] != 'Semi-Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'
		Scripts += '\tpokemartlistend\n\n'

for set_ in packs:
	Scripts += '\t.2byte  ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'
Scripts += '\tpokemartlistend\n\n'

for card in card_names:
	Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '\n'

Scripts_Output = open('data/scripts/scripts.inc', 'w')
Scripts_Output.write(Scripts)
Scripts_Output.close()
print('data/scripts/scripts.inc written')

# Image conversion
card_counter = 1
for card_name in tqdm(card_names):
	print(card_name)
	for data in card_info_data['data']:
		if card_name == data['name']:
			for card_image_cropped in data['card_images']:
				card_id = str(card_image_cropped['id'])
				image_cropped_url = 'https://images.ygoprodeck.com/images/cards/' + card_id + '.jpg'
				image_cropped_url_cropped = 'https://images.ygoprodeck.com/images/cards_cropped/' + card_id + '.jpg'
				res = requests.get(image_cropped_url)
				image = 'Artwork/' + card_name + '_' + card_id + '.jpg'
				if not os.path.exists(image):
					try:
						with open(image, 'wb') as file:
							file.write(res.content)
							print(card_name + ' image written')
					except:
						continue
				res = requests.get(image_cropped_url_cropped)
				image_cropped = 'Artwork/' + card_name + '_' + card_id + '_Cropped.jpg'
				if not os.path.exists(image_cropped):
					with open(image_cropped, 'wb') as file:
						file.write(res.content)
						print(card_name + ' art written')
				folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
				if not os.path.exists(folder_path):
					os.mkdir(folder_path)
				# Special format used by GBA for 80x80 sprite stitch
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
					pillow_width, pillow_height = im.size
					print(card_name, pillow_width, pillow_height)
					if pillow_width != 80 or pillow_height != 80:
						master = Image.new(
							mode='RGBA',
							size=(80, 80),
							color=(57,255,20,0))
						master.paste(im, box=((80 - pillow_width) // 2,(80 - pillow_height) // 2))
						master.save(outfile, "PNG")
						master = Image.open(outfile)
						master = master.convert(
							"P", palette=Image.ADAPTIVE, colors=63
						)
						master = move_palette_color(master, 63, 0)
						master.save(outfile, "PNG")
						subprocess.run(['./magick', outfile, '-colors', "64", '-define', 'png:exclude-chunk=bKGD', outfile])
					subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.8bpp')])
					subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.pal')])
					subprocess.run(['../gbagfx/gbagfx', outfile.replace('.png', '.8bpp'), outfile.replace('.png', '.8bpp')])
					subprocess.run(['../gbagfx/gbagfx', outfile.replace('.png', '.8bpp'), outfile.replace('.png', '.png'), '-palette', outfile.replace('.png', '.pal'), '-mwidth', '10'])
					print(card_name + ' 80x80 written')
				size = 32, 32
				folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
				if not os.path.exists(folder_path):
					os.mkdir(folder_path)
				outfile = folder_path + '/pic_small.png'
				if not os.path.exists(outfile):
					im = Image.open(image_cropped)
					im.thumbnail(size, Image.Resampling.LANCZOS)
					im = im.convert(
						"P", palette=Image.ADAPTIVE, colors=15
					)
					im = move_palette_color(im, 15, 0)
					im.save(outfile, "PNG")
					pillow_width, pillow_height = im.size
					if pillow_width != 32 or pillow_height != 32:
						master = Image.new(
							mode='RGBA',
							size=(32, 32),
							color=(57,255,20,0))
						master.paste(im, box=((32 - pillow_width) // 2,(32 - pillow_height) // 2))
						master.save(outfile, "PNG")
						master = Image.open(outfile)
						master = master.convert(
							"P", palette=Image.ADAPTIVE, colors=15
						)
						master = move_palette_color(master, 15, 0)
						master.save(outfile, "PNG")
						subprocess.run(['./magick', outfile, '-colors', "15", '-define', 'png:exclude-chunk=bKGD', outfile])
				size = 16, 16
				master = Image.new(
					mode='RGBA',
					size=(16, 24),
					color=(57,255,20,0))
				folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
				if not os.path.exists(folder_path):
					os.mkdir(folder_path)
				outfile = folder_path + '/icon_tiny.png'
				if not os.path.exists(outfile):
					im = Image.open(image_cropped)
					im.thumbnail(size, Image.Resampling.LANCZOS)
					master.paste(im, box=(0,4))
					master.save(outfile, "PNG")
					master = Image.open(outfile)
					master = master.convert(
						"P", palette=Image.ADAPTIVE, colors=15
					)
					master = move_palette_color(master, 15, 0)
					master.save(outfile, "PNG")
					subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
				size = 24, 24
				master = Image.new(
					mode='RGBA',
					size=(24, 32),
					color=(57,255,20,0))
				folder_path = 'graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower()
				if not os.path.exists(folder_path):
					os.mkdir(folder_path)
				outfile = folder_path + '/icon_small.png'
				if not os.path.exists(outfile):
					im = Image.open(image_cropped)
					im.thumbnail(size, Image.Resampling.LANCZOS)
					master.paste(im, box=(0,4))
					master.save(outfile, "PNG")
					master = Image.open(outfile)
					master = master.convert(
						"P", palette=Image.ADAPTIVE, colors=15
					)
					master = move_palette_color(master, 15, 0)
					master.save(outfile, "PNG")
					subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
			card = data['name']
			gCardInfo += ("\t[CARD_" + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + "] =\n"
					+ "\t{\n"
					+ '\t\t.name = gCardName_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.nameShort = gCardNameShort_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.nameShortBag = gCardNameShortBag_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.description = gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					# + "\t\t.descriptionLines = " + str(description_lines[card]) + ",\n"
					+ '\t\t.password = _("' + str(data['id']) + '"),\n'
					+ '\t\t.pic = gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big,\n'
					+ '\t\t.pal = gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.iconSquare = gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.iconSmall = gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.palIconSmall = gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.iconTiny = gCardIconTiny_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.palIconTiny = gCardIconTinyPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
					+ '\t\t.effects = {EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE},\n'
					+ ("\t\t.type = TYPE_" + re.sub(r'\W+', '_', data['type']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ",\n"))
			try:
				gCardInfo += ("\t\t.attribute = ATTRIBUTE_" + data['attribute'] + ",\n"
						+ "\t\t.level = " + str(data['level']) + ",\n"
						+ "\t\t.atk = " + str(int(data['atk']/10)) + ",\n"
						+ "\t\t.def = " + str(int(data['def']/10)) + ",\n"
						+ "\t\t.race = RACE_" + re.sub(r'\W+', '_', data['race']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ",\n")
			except:
				gCardInfo += ("\t\t.attribute = ATTRIBUTE_NONE,\n"
						+ "\t\t.level = 0,\n"
						+  "\t\t.atk = 0,\n"
						+ "\t\t.def = 0,\n"
						+ "\t\t.race = RACE_NONE,\n")
			gCardInfo += ("\t\t.id = " + str(data['misc_info'][0]['konami_id']) + ",\n"
						+ "\t\t.archetypesSeries = {ARCHETYPE_SERIES_NONE, ARCHETYPE_SERIES_NONE, ARCHETYPE_SERIES_NONE},\n")
			with open('FL.json', 'r') as f:
				data_ = json.load(f)
				for card_ in data_:
					if card_['Card'] == card and card_['Format'] == 'Yugi-Kaiba':
						gCardInfo += "\t\t.priceYK = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banYK = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banYK = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Critter':
						gCardInfo += "\t\t.priceCritter = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banCritter = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banCritter = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Treasure':
						gCardInfo += "\t\t.priceTreasure = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banTreasure = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banTreasure = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Imperial':
						gCardInfo += "\t\t.priceImperial = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banImperial = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banImperial = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Android':
						gCardInfo += "\t\t.priceAndroid = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banAndroid = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banAndroid = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Joey-Pegasus':
						gCardInfo += "\t\t.priceJoeyPegasus = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banJoeyPegasus = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banJoeyPegasus = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Fiber':
						gCardInfo += "\t\t.priceFiber = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banFiber = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banFiber = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Yata':
						gCardInfo += "\t\t.priceYata = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banYata = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banYata = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Scientist':
						gCardInfo += "\t\t.priceScientist = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banScientist = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banScientist = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Vampire':
						gCardInfo += "\t\t.priceVampire = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banVampire = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banVampire = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Chaos':
						gCardInfo += "\t\t.priceChaos = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banChaos = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banChaos = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Warrior':
						gCardInfo += "\t\t.priceWarrior = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banWarrior = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banWarrior = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Goat':
						gCardInfo += "\t\t.priceGoat = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banGoat = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banGoat = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Cyber':
						gCardInfo += "\t\t.priceCyber = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banCyber = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banCyber = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Reaper':
						gCardInfo += "\t\t.priceReaper = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banReaper = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banReaper = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Chaos Return':
						gCardInfo += "\t\t.priceChaosReturn = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banChaosReturn = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banChaosReturn = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Demise':
						gCardInfo += "\t\t.priceDemise = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banDemise = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banDemise = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Trooper':
						gCardInfo += "\t\t.priceTrooper = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banTrooper = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banTrooper = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Zombie':
						gCardInfo += "\t\t.priceZombie = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banZombie = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banZombie = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Perfect Circle':
						gCardInfo += "\t\t.pricePerfectCircle = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banPerfectCircle = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banPerfectCircle = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'DAD Return':
						gCardInfo += "\t\t.priceDADReturn = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banDADReturn = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banDADReturn = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Gladiator':
						gCardInfo += "\t\t.priceGladiator = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banGladiator = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banGladiator = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'TeleDAD':
						gCardInfo += "\t\t.priceTeleDAD = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banTeleDAD = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banTeleDAD = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Cat':
						gCardInfo += "\t\t.priceCat = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banCat = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banCat = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Edison':
						gCardInfo += "\t\t.priceEdison = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banEdison = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banEdison = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Frog':
						gCardInfo += "\t\t.priceFrog = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banFrog = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banFrog = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Starstrike':
						gCardInfo += "\t\t.priceStarstrike = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banStarstrike = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banStarstrike = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Tengu':
						gCardInfo += "\t\t.priceTengu = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banTengu = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banTengu = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Dino Rabbit':
						gCardInfo += "\t\t.priceDinoRabbit = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banDinoRabbit = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banDinoRabbit = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Wind-Up':
						gCardInfo += "\t\t.priceWindUp = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banWindUp = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banWindUp = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Miami':
						gCardInfo += "\t\t.priceMiami = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banMiami = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banMiami = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Meadowlands':
						gCardInfo += "\t\t.priceMeadowlands = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banMeadowlands = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banMeadowlands = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Baby Ruler':
						gCardInfo += "\t\t.priceBabyRuler = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banBabyRuler = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banBabyRuler = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Ravine Ruler':
						gCardInfo += "\t\t.priceRavineRuler = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banRavineRuler = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banRavineRuler = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Fire-Water':
						gCardInfo += "\t\t.priceFireWater = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banFireWater = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banFireWater = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'HAT':
						gCardInfo += "\t\t.priceHAT = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banHAT = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banHAT = 2,\n"
					if card_['Card'] == card and card_['Format'] == 'Vegas':
						gCardInfo += "\t\t.priceVegas = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
						if (card_['Banlist'] == 'Limited'):
							gCardInfo += "\t\t.banVegas = 1,\n"
						elif (card_['Banlist'] == 'Semi-Limited'):
							gCardInfo += "\t\t.banVegas = 2,\n"
			if card in wct06_ranks:
						gCardInfo += "\t\t.priceWCT06 = " + str((wct06_ranks[card]) * 50) + ",\n"
			gCardInfo += ("\t\t.priceCustom = 0,\n"
					+ "\t\t.priceVendor1 = 0,\n"
					+ "\t\t.priceVendor2 = 0,\n"
					+ "\t\t.priceVendor3 = 0,\n"
					+ '\t},\n')
			YGO_C += '    [ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = ' + str(card_counter) + ',\n'
			card_counter += 1

gCardInfo_Output = open('src/data/ygo/card_info.h', 'w')
gCardInfo_Output.write(gCardInfo)
gCardInfo_Output.close()
print('src/data/ygo/card_info.h written')
YGO_C_Output = open('src/ygo.c', 'w')
YGO_C_Output.write(YGO_C)
YGO_C_Output.close()
print('src/ygo.c written')