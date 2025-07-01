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

formats = ['Yugi-Kaiba', 'Critter', 'Treasure', 'Imperial', 'Android', 'Joey-Pegasus', 'Fiber', 'Yata', 'Scientist', 'Vampire', 'Chaos', 'Warrior', 'Goat', 'Cyber', 'Reaper', 'Chaos Return', 'Demise', 'Trooper', 'Zombie', 'Perfect Circle', 'DAD Return', 'Gladiator', 'TeleDAD', 'Cat', 'Edison', 'Frog', 'Starstrike', 'Tengu', 'Dino Rabbit', 'Wind-Up', 'Miami', 'Meadowlands', 'Baby Ruler', 'Ravine Ruler', 'Fire-Water', 'HAT', 'Vegas']

highest_usage = {}
cards_by_format = {}
for format in formats:
   highest_usage[format] = 0
   cards_by_format[format] = {}

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
	"4-Starred Ladybug of Doom",
	"7 Colored Fish",
	"A Legendary Ocean",
	"Abyss Soldier",
	"Airknight Parshath",
	"Amazoness Archer",
	"Amphibious Bugroth MK-3",
	"Anti-Spell Fragrance",
	"Aqua Madoor",
	"Aqua Spirit",
	"Archfiend Soldier",
	"Arsenal Bug",
	"Arsenal Summoner",
	"Asura Priest",
	"Axe of Despair",
	"Banisher of the Light",
	"Barrel Behind the Door",
	"Battle Footballer",
	"Battle Ox",
	"Bazoo the Soul-Eater",
	"Berserk Gorilla",
	"Bickuribox",
	"Big Bang Shot",
	"Big Shield Gardna",
	"Big-Tusked Mammoth",
	"Black Illusion Ritual",
	"Black Luster Soldier - Envoy of the Beginning",
	"Black Pendant",
	"Black Skull Dragon",
	"Blade Knight",
	"Blast with Chain",
	"Blazing Inpachi",
	"Blindly Loyal Goblin",
	"Block Attack",
	"Blowback Dragon",
	"Blue-Eyes Ultimate Dragon",
	"Blue-Eyes White Dragon",
	"Book of Life",
	"Book of Moon",
	"Book of Taiyou",
	"Bottomless Trap Hole",
	"Bowganian",
	"Brain Control",
	"Breaker the Magical Warrior",
	"Broww, Huntsman of Dark World",
	"Brron, Mad King of Dark World",
	"Buster Blader",
	"Byser Shock",
	"Call of the Haunted",
	"Cannon Soldier",
	"Card Destruction",
	"Castle of Dark Illusions",
	"Castle Walls",
	"Catapult Turtle",
	"Ceasefire",
	"Chain Disappearance",
	"Chain Energy",
	"Chainsaw Insect",
	"Change of Heart",
	"Chaos Emperor Dragon - Envoy of the End",
	"Chaos Sorcerer",
	"Charcoal Inpachi",
	"Chiron the Mage",
	"Cipher Soldier",
	"Cold Wave",
	"Command Knight",
	"Compulsory Evacuation Device",
	"Confiscation",
	"Crass Clown",
	"Creature Swap",
	"Crush Card Virus",
	"Cursed Seal of the Forbidden Spell",
	"Cyber Dragon",
	"Cyber End Dragon",
	"Cyber Harpie Lady",
	"Cyber Jar",
	"Cyber Twin Dragon",
	"Cyber-Stein",
	"D.D. Assailant",
	"D.D. Crazy Beast",
	"D.D. Survivor",
	"D.D. Trainer",
	"D.D. Warrior Lady",
	"Dark Blade",
	"Dark Blade the Dragon Knight",
	"Dark Deal",
	"Dark Elf",
	"Dark Hole",
	"Dark Magic Curtain",
	"Dark Magician",
	"Dark Magician of Chaos",
	"Dark Mimic LV1",
	"Dark Mimic LV3",
	"Dark Paladin",
	"Dark Ruler Ha Des",
	"Dark Scorpion - Chick the Yellow",
	"Dark Scorpion - Cliff the Trap Remover",
	"Dark World Lightning",
	"De-Spell",
	"Deck Devastation Virus",
	"Dekoichi the Battlechanted Locomotive",
	"Delinquent Duo",
	"Des Dendle",
	"Des Koala",
	"Des Lacooda",
	"Des Wombat",
	"Desert Sunlight",
	"Dian Keto the Cure Master",
	"Dimension Fusion",
	"Don Zaloog",
	"Doom Dozer",
	"Doomcaliber Knight",
	"Dragged Down into the Grave",
	"Dragon's Mirror",
	"Dragon's Rage",
	"Dream Clown",
	"Drillroid",
	"Drop Off",
	"Dunames Dark Witch",
	"Dust Tornado",
	"Earthbound Spirit",
	"Electric Snake",
	"Elemental HERO Clayman",
	"Elemental HERO Flame Wingman",
	"Elemental HERO Wildheart",
	"Emergency Provisions",
	"Emissary of the Afterlife",
	"Enemy Controller",
	"Exarion Universe",
	"Exchange",
	"Exchange of the Spirit",
	"Exiled Force",
	"Exodia the Forbidden One",
	"Fake Trap",
	"Familiar-Possessed - Aussa",
	"Familiar-Possessed - Eria",
	"Familiar-Possessed - Hiita",
	"Familiar-Possessed - Wynn",
	"Fiber Jar",
	"Final Flame",
	"Fissure",
	"Flame Swordsman",
	"Flying Kamakiri #1",
	"Fusilier Dragon, the Dual-Mode Beast",
	"Gagagigo",
	"Gaia Power",
	"Gaia the Dragon Champion",
	"Gatling Dragon",
	"Gear Golem the Moving Fortress",
	"Gearfried the Iron Knight",
	"Gemini Elf",
	"Giant Germ",
	"Giant Orc",
	"Giant Rat",
	"Giant Red Seasnake",
	"Giant Soldier of Stone",
	"Giant Trunade",
	"Giga-Tech Wolf",
	"Gigantes",
	"Gil Garth",
	"Gilasaurus",
	"Goblin Attack Force",
	"Goblin Elite Attack Force",
	"Gokipon",
	"Golem Sentry",
	"Gora Turtle",
	"Graceful Charity",
	"Gravekeeper's Assailant",
	"Gravekeeper's Guard",
	"Gravekeeper's Spear Soldier",
	"Gravekeeper's Spy",
	"Gravekeeper's Watcher",
	"Gravity Bind",
	"Great White",
	"Guardian Sphinx",
	"Gyaku-Gire Panda",
	"Gyakutenno Megami",
	"Hallowed Life Barrier",
	"Hane-Hane",
	"Harpie's Feather Duster",
	"Heavy Storm",
	"Hieracosphinx",
	"Horn of Heaven",
	"Howling Insect",
	"Humanoid Slime",
	"Hydrogeddon",
	"Hyper Hammerhead",
	"Imperial Order",
	"Inaba White Rabbit",
	"Indomitable Fighter Lei Lei",
	"Injection Fairy Lily",
	"Inpachi",
	"Insect Knight",
	"Island Turtle",
	"Jar of Greed",
	"Jinzo",
	"Jirai Gumo",
	"Jowgen the Spiritualist",
	"Judge Man",
	"Just Desserts",
	"Kaiser Sea Horse",
	"Karma Cut",
	"King Dragun",
	"King of the Swamp",
	"King Tiger Wanghu",
	"Kuriboh",
	"Kycoo the Ghost Destroyer",
	"La Jinn the Mystical Genie of the Lamp",
	"Labyrinth Tank",
	"Lady Ninja Yae",
	"Last Will",
	"Left Arm of the Forbidden One",
	"Left Leg of the Forbidden One",
	"Legendary Jujitsu Master",
	"Level Limit - Area B",
	"Levia-Dragon - Daedalus",
	"Light of Intervention",
	"Lightning Vortex",
	"Limiter Removal",
	"Luster Dragon",
	"Mad Dog of Darkness",
	"Mage Power",
	"Magic Cylinder",
	"Magic Jammer",
	"Magical Dimension",
	"Magical Merchant",
	"Magical Scientist",
	"Magician of Faith",
	"Magician's Circle",
	"Magician's Valkyria",
	"Maiden of the Aqua",
	"Makyura the Destructor",
	"Man-Eater Bug",
	"Manju of the Ten Thousand Hands",
	"Manticore of Darkness",
	"Marauding Captain",
	"Mask of Darkness",
	"Mask of Restrict",
	"Masked Dragon",
	"Masked Sorcerer",
	"Mataza the Zapper",
	"Mechanicalchaser",
	"Megamorph",
	"Mermaid Knight",
	"Messenger of Peace",
	"Metal Reflect Slime",
	"Metamorphosis",
	"Milus Radiant",
	"Minar",
	"Mind Control",
	"Mine Golem",
	"Miracle Restoring",
	"Mirage Dragon",
	"Mirage of Nightmare",
	"Mirror Force",
	"Moai Interceptor Cannons",
	"Mobius the Frost Monarch",
	"Monster Gate",
	"Monster Reborn",
	"Monster Reincarnation",
	"Morphing Jar",
	"Mother Grizzly",
	"Muka Muka",
	"Mystic Swordsman LV2",
	"Mystic Swordsman LV4",
	"Mystic Tomato",
	"Mystical Elf",
	"Mystical Space Typhoon",
	"Mystik Wok",
	"Necrovalley",
	"Needle Ceiling",
	"Neko Mane King",
	"Neo Bug",
	"Neo the Magic Swordsman",
	"Newdoria",
	"Night Assailant",
	"Nightmare Wheel",
	"Nightmare's Steelcage",
	"Nimble Momonga",
	"Nin-Ken Dog",
	"Ninja Grandmaster Sasuke",
	"Nobleman of Crossout",
	"Nobleman of Extermination",
	"Offerings to the Doomed",
	"Ojama King",
	"Ojama Trio",
	"Ookazi",
	"Oppressed People",
	"Opticlops",
	"Painful Choice",
	"Paladin of White Dragon",
	"Penguin Knight",
	"Phoenix Wing Wind Blast",
	"Pikeru's Circle of Enchantment",
	"Pinch Hopper",
	"Pitch-Black Power Stone",
	"Poison of the Old Man",
	"Polymerization",
	"Pot of Avarice",
	"Pot of Generosity",
	"Pot of Greed",
	"Premature Burial",
	"Prevent Rat",
	"Prickle Fairy",
	"Princess of Tsurugi",
	"Protector of the Sanctuary",
	"Pyramid Turtle",
	"Raigeki",
	"Raigeki Break",
	"Reaper on the Nightmare",
	"Reasoning",
	"Reckless Greed",
	"Reflect Bounder",
	"Reinforcement of the Army",
	"Reinforcements",
	"Relinquished",
	"Reload",
	"Remove Trap",
	"Rescue Cat",
	"Return from the Different Dimension",
	"Right Arm of the Forbidden One",
	"Right Leg of the Forbidden One",
	"Ring of Destruction",
	"Rising Air Current",
	"Robbin' Goblin",
	"Roulette Barrel",
	"Royal Decree",
	"Royal Magical Library",
	"Royal Oppression",
	"Rush Recklessly",
	"Ryu Kokki",
	"Saber Beetle",
	"Sacred Crane",
	"Sacred Phoenix of Nephthys",
	"Sakuretsu Armor",
	"Salvage",
	"Sand Moth",
	"Sangan",
	"Sasuke Samurai",
	"Sasuke Samurai #4",
	"Scapegoat",
	"Sea Serpent Warrior of Darkness",
	"Second Coin Toss",
	"Secret Barrel",
	"Self-Destruct Button",
	"Serial Spell",
	"Serpentine Princess",
	"Seven Tools of the Bandit",
	"Shining Angel",
	"Shrink",
	"Sillva, Warlord of Dark World",
	"Silpheed",
	"Sinister Serpent",
	"Skill Drain",
	"Skilled Dark Magician",
	"Skilled White Magician",
	"Skull Dog Marron",
	"Skull Lair",
	"Sky Scout",
	"Slate Warrior",
	"Smashing Ground",
	"Snatch Steal",
	"Solemn Judgment",
	"Solemn Wishes",
	"Soul Exchange",
	"Soul Tiger",
	"Spear Cretin",
	"Spear Dragon",
	"Spell Canceller",
	"Spell Reproduction",
	"Spirit of the Harp",
	"Spirit Reaper",
	"Spiritual Earth Art - Kurogane",
	"Spiritual Water Art - Aoi",
	"Spiritual Wind Art - Miyabi",
	"Spiritualism",
	"Stealth Bird",
	"Stone Statue of the Aztecs",
	"Stop Defense",
	"Summoned Skull",
	"Swarm of Locusts",
	"Swarm of Scarabs",
	"Swords of Revealing Light",
	"Terraforming",
	"The Big March of Animals",
	"The Dragon Dwelling in the Cave",
	"The Fiend Megacyber",
	"The Forceful Sentry",
	"The Forgiving Maiden",
	"The Last Warrior from Another Planet",
	"The Little Swordsman of Aile",
	"The Wicked Worm Beast",
	"Thestalos the Firestorm Monarch",
	"Thousand-Eyes Restrict",
	"Threatening Roar",
	"Throwstone Unit",
	"Thunder Dragon",
	"Thunder Nyan Nyan",
	"Time Seal",
	"Toon Cannon Soldier",
	"Toon Dark Magician Girl",
	"Toon Gemini Elf",
	"Toon Goblin Attack Force",
	"Toon Masked Sorcerer",
	"Toon Table of Contents",
	"Torrential Tribute",
	"Trap Dustshoot",
	"Trap Hole",
	"Trap Master",
	"Treeborn Frog",
	"Tremendous Fire",
	"Tribe-Infecting Virus",
	"Tribute to the Doomed",
	"Tsukuyomi",
	"Twin-Headed Behemoth",
	"Twin-Headed Thunder Dragon",
	"Ultimate Insect LV3",
	"Ultimate Insect LV5",
	"Ultimate Insect LV7",
	"Ultimate Offering",
	"United We Stand",
	"Upstart Goblin",
	"Vampire Lord",
	"Vorse Raider",
	"Waboku",
	"Wall of Illusion",
	"Wall of Revealing Light",
	"Wave-Motion Cannon",
	"White Dragon Ritual",
	"White Magical Hat",
	"Widespread Ruin",
	"Witch of the Black Forest",
	"X-Head Cannon",
	"Xing Zhen Hu",
	"Yata-Garasu",
	"Yomi Ship",
	"Zaborg the Thunder Monarch",
	"Zombyra the Dark",
	"Zure, Knight of Dark World",
	# Archetypal/series-related cards (new cards)
	"Amazoness Spiritualist",
	"Ancient Gear Dragon",
	"Angmarl the Fiendish Monarch",
	"Apprentice Illusion Magician",
	"Archfiend Cavalry",
	"Archfiend Commander",
	"Archfiend Giant",
	"Archfiend Heiress",
	"Archfiend Interceptor",
	"Archfiend of Gilfer",
	"Archfiend's Advent",
	"Baku the Beast Ninja",
	"Beginning Knight",
	"Beiige, Vanguard of Dark World",
	"Berlineth the Firestorm Vassal",
	"Black Dragon's Chick",
	"Black Metal Dragon",
	"Blue Flame Swordsman",
	"Bone Archfiend",
	"Caius the Shadow Monarch",
	"Chronicle Sorceress",
	"Cyber Dragon Drei",
	"Cyber Dragon Vier",
	"Cyber Dragon Zwei",
	"Cyber Larva",
	"Cyberdark Wurm",
	"Dark Magician Girl",
	"Dark Magician Girl the Magician's Apprentice",
	"Defender of Nephthys",
	"Delg the Dark Monarch",
	"Dictator of D.",
	"Dimension Conjurer",
	"Disciple of Nephthys",
	"Dupe Frog",
	"Eidos the Underworld Monarch",
	"Eidos the Underworld Squire",
	"Elemental HERO Blazeman",
	"Elemental HERO Woodsman",
	"Envoy of Chaos",
	"Evening Twilight Knight",
	"Fighting Flame Swordsman",
	"Flip Flop Frog",
	"Fusion Devourer",
	"Gearfried the Red-Eyes Iron Knight",
	"Gem-Knight Quartz",
	"Genta, Gateman of Dark World",
	"Giltia the D. Knight - Soul Spear",
	"Goblin Pothole Squad",
	"Granmarg the Rock Monarch",
	"Green Ninja",
	"Gren, Tactician of Dark World",
	"Hand of Nephthys",
	"Ice Knight",
	"Infernalqueen Salmon",
	"Kagero the Cannon Ninja",
	"Kaibaman",
	"Keeper of Dragon Magic",
	"Keeper of the Shrine",
	"Lancer Archfiend",
	"Lesser Fiend",
	"Lord of D.",
	"Lucent, Netherlord of Dark World",
	"Lucius the Shadow Vassal",
	"Mad Archfiend",
	"Magician's Robe",
	"Magician's Rod",
	"Magicians' Souls",
	"Magikuriboh",
	"Masked Ninja Ebisu",
	"Matriarch of Nephthys",
	"Metalflame Swordsman",
	"Mitsu the Insect Ninja",
	"Mystical Elf - White Lightning",
	"Ninja Grandmaster Hanzo",
	"Parl, Hermit of Dark World",
	"Red Dragon Ninja",
	"Red-Eyes Baby Dragon",
	"Red-Eyes Black Meteor Dragon",
	"Red-Eyes Retro Dragon",
	"Red-Eyes Wyvern",
	"Relinkuriboh",
	"Ronintoadin",
	"Salamandra, the Flying Flame Dragon",
	"Scarr, Scout of Dark World",
	"Senior Silver Ninja",
	"Senju of the Thousand Hands",
	"Skilled Red Magician",
	"Snoww, Unlight of Dark World",
	"Sonic Bird",
	"Sphere Kuriboh",
	"Substitoad",
	"Super Soldier Soul",
	"Swap Frog",
	"T.A.D.P.O.L.E.",
	"Tenmataitei",
	"Tessera the Prime Squire",
	"The Black Stone of Legend",
	"The Dark - Hex-Sealed Fusion",
	"The Earth - Hex-Sealed Fusion",
	"The Light - Hex-Sealed Fusion",
	"Thunder Dragondark",
	"Thunder Dragonhawk",
	"Thunder Dragonmatrix",
	"Thunder Dragonroar",
	"Thunder Sea Horse",
	"Tlakalel, His Malevolent Majesty",
	"Tobari the Sky Ninja",
	"Tradetoad",
	"Traptrix Arachnocampa",
	"Traptrix Atrax",
	"Traptrix Dionaea",
	"Traptrix Genlisea",
	"Traptrix Mantis",
	"Traptrix Myrmeleo",
	"Traptrix Nepenthes",
	"Traptrix Pudica",
	"Traptrix Vesiculo",
	"Twilight Ninja Nichirin, the Chunin",
	"Twilight Ninja Shingetsu",
	"Upstart Golden Ninja",
	"Vision HERO Vyon",
	"Wroughtweiler",
	"Yellow Ninja",
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
SRCDataItems = ''
card_counter = 1
pack_counter = 1928
description_lines = dict()

for format_ in formats:
    SRCDataItems += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', format_) + 'Desc[] = _("' + textwrap.fill(format_, width=20).replace('\n', '\\n') + '.");\n\n'

pack_counter = 990
for format_ in formats:
    Items += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + '] = ' + str(pack_counter) + ',\n'
    pack_counter += 1
Items += '\n'

for format_ in formats:
    YGO_C += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + '''] =
    {
        .name = _("''' + format_[:13] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''
YGO_C += '\n'

ItemUse = ''
Item = ''
for format_ in formats:
    Item += '''    else if (VarGet(VAR_YGO_SHOP) == BANLIST_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + ''')
    {
        if (gCardInfo[card].ban''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''')
            return gCardInfo[card].ban''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''';
        else
            return 3;
    }\n'''
    ItemUse += '''    else if (pack == PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + ''')
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
# TCG_Set_Writer = open('tcg_sets.json', 'w', encoding='utf-8')
for data in card_info_data['data']:
	try:
		for set_ in data['card_sets']:
			tcg_sets.add(set_['set_name'])
	except:
		pass

tcg_sets_write = {}
for set_ in sorted(list(tcg_sets)):
    tcg_sets_write[set_] = {}
    for data in card_info_data['data']:
        try:
            for set__ in data['card_sets']:
                if set_ == set__['set_name']:
                    tcg_sets_write[set_][data['name']] = set__['set_rarity']
        except:
             pass

# json.dump(dict(sorted(tcg_sets_write.items())), TCG_Set_Writer, indent=4)
# TCG_Set_Writer.close()

sets_print = ''
with open('tcg_sets.json', 'r') as f:
    data = json.load(f)
    for set_ in data:
        sets_print += 'const struct PackContents g' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '[] =\n{'
        for card in data[set_]:
            if card in card_names:
                sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', data[set_][card]).replace('__', '_').replace('__', '_').upper() + '},\n'
        sets_print += '};\n\n'

for set_ in sorted(list(tcg_sets)):
    Scripts += '\tadditem ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + ' 10\n' 
Scripts += '\n'

YGO_C += '\nconst u16 PackIdMapping[] = \n{\n'
with open('tcg_sets.json', 'r') as f:
    data = json.load(f)
    for set_ in data:
        YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + '] = ' + str(sorted(list(tcg_sets)).index(set_)) + ',\n'
YGO_C += '};\n\n'

sets_print += '\nconst struct Pack gPacks[] =\n{\n'
card_count = 0
with open('tcg_sets.json', 'r') as f:
    data = json.load(f)
    for set_ in data:
        sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + '] =\n\t{\n        .pack = g' + re.sub(r'[^a-zA-Z0-9]', '', set_) + ',\n        .length = '
        for card in data[set_]:
            if card in card_names:
                 card_count += 1
        sets_print += str(card_count)
        sets_print += ',\n\t},\n'
        card_count = 0

sets_print += '};\n'
PacksWrite = open('src/data/ygo/packs.h', 'w', encoding='utf-8')
PacksWrite.write(sets_print)
PacksWrite.close()
print('src/data/ygo/packs.h written')

card_count = 0
with open('tcg_sets.json', 'r') as f:
    data = json.load(f)
    for set_ in data:
        SRCDataItems += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', set_) + 'Desc[] = _(\n    "' + textwrap.fill(set_, width=20).replace('\n', '\\n"\n    "') + '.");\n\n'

SRCDataItemsWrite = open('src/data/items.h', 'w', encoding='utf-8')
SRCDataItemsWrite.write(SRCDataItems)
SRCDataItemsWrite.close()
print('src/data/items.h written')

for card_name in card_names:
	for data in card_info_data['data']:
		description_lines[card_name] = 1
		if card_name == data['name']:
			gCardInfo += ('const u8 gCardName_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + card_name.replace('#', '') + '");\n'
					+ 'const u8 gCardNameShort_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
			+ card_name[:19].replace('#', '') + '");\n'
					+ 'const u8 gCardNameShortBag_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
			+ card_name[:26].replace('#', '') + '");\n')
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
			ItemIconTable += '\t[ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + '] = {gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ', gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '},\n'
			Scripts += '\tadditem ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + '\n'
			YGO_Graphics_C += ('const u32 gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.8bpp.lz");\n'
						+ 'const u16 gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U16("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.gbapal");\n'
						+ 'const u32 gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_small.4bpp.lz");\n'
						+ 'const u32 gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_small.gbapal.lz");\n'
						+ 'const u32 gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.4bpp.lz");\n'
						+ 'const u32 gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.gbapal.lz");\n'
						+ 'const u32 gCardIconTiny_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_tiny.4bpp.lz");\n'
						+ 'const u32 gCardIconTinyPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_tiny.gbapal.lz");\n')
			YGO_Constants += '#define CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + ' ' + str(card_counter) + '\n'
			Item_Constants += '#define ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + ' ' + str(card_counter + 376) + '\n'
			card_counter += 1
			Items += '''\t[ITEM_CARD_''' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + '''] =
	{
		.name = _("''' + re.sub(r'[^a-zA-Z0-9]', '', data['name'])[:13] + '''"),
		.itemId = ITEM_CARD_''' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + ''',
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
sets_count = 938
for set_ in sorted(list(tcg_sets)):
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + ' ' + str(sets_count) + '\n'
    sets_count += 1
Item_Constants += '\n'

for format_ in formats:
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + ' ' + str(pack_counter) + '\n'
    pack_counter += 1

for set_ in sorted(list(tcg_sets)):
    Items += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + '''] =
    {
        .name = _("''' + set_[:13] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''
Items += '\n'

for format in formats:
    Items += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format).replace('__', '_').replace('__', '_').upper() + '''] =
    {
        .name = _("''' + set_[:13] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format).replace('__', '_').replace('__', '_').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', format) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''

ItemIconTable += '\n'
for set_ in sorted(list(tcg_sets)):
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'
    sets_count += 1

ItemIconTable += '\n'
for format_ in formats:
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'

YGO_Constants += '\n'
for set_ in sorted(list(tcg_sets)):
    YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + ' ' + str(sorted(list(tcg_sets)).index(set_)) + '\n'

YGO_Constants += '\n'
pack_counter = 990
for format_ in formats:
    YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').upper() + ' ' + str(pack_counter) + '\n'
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
	setvar VAR_YGO_SHOP, FORMAT_''' + re.sub(r'\W+', '_', format).replace('__', '_').replace('__', '_').upper() + '''
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
					Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').upper() + '\n'
	Scripts += '\tpokemartlistend\n\n'

for format in cards_by_format:
	Scripts += 'InsideOfTruck_Text_' + re.sub(r'\W+', '', format) + ', '

Scripts += '\n\n'
for format in cards_by_format:
	Scripts += 'InsideOfTruck_Text_' + re.sub(r'\W+', '', format) + 'Banlist, '

Scripts += '\n\n'
for format in cards_by_format:
	Scripts += '''InsideOfTruck_Text_''' + re.sub(r'\W+', '', format) + ''':
	.string "''' + format + '''$"\n\n'''

Scripts += '\n\n'
for format in cards_by_format:
	Scripts += '''InsideOfTruck_Text_''' + re.sub(r'\W+', '', format) + '''Banlist:
	.string "''' + format + ''' banlist$"\n\n'''

counter = 0
for format in cards_by_format:
	Scripts += '\tcase ' + str(counter) + ', InsideOfTruck_EventScript_Clerk_' + re.sub(r'\W+', '', format) + '\n'
	counter += 1

Scripts += '\n\n'
counter = 0
for format in cards_by_format:
	Scripts += '\tcase ' + str(counter) + ', InsideOfTruck_EventScript_Clerk_' + re.sub(r'\W+', '', format) + 'Banlist\n'
	counter += 1

Scripts += '\n\n'
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
	setvar VAR_YGO_SHOP, BANLIST_''' + re.sub(r'\W+', '_', format).replace('__', '_').replace('__', '_').upper() + '''
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
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').upper() + '\n'
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] == 'Semi-Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').upper() + '\n'
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] != 'Limited' and card__['Banlist'] != 'Semi-Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').upper() + '\n'
		Scripts += '\tpokemartlistend\n\n'

for set_ in sorted(list(tcg_sets)):
	Scripts += '\t.2byte  ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').upper() + '\n'
Scripts += '\tpokemartlistend\n\n'

for card in card_names:
	Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card).replace('__', '_').replace('__', '_').upper() + '\n'

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
					with open(image, 'wb') as file:
						file.write(res.content)
						print(card_name + ' image written')
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
					subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.8bpp')])
					subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.pal')])
					subprocess.run(['../gbagfx/gbagfx', outfile.replace('.png', '.8bpp'), outfile.replace('.png', '.8bpp')])
					subprocess.run(['../gbagfx/gbagfx', outfile.replace('.png', '.8bpp'), outfile.replace('.png', '.png'), '-palette', outfile.replace('.png', '.pal'), '-mwidth', '10'])
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
			gCardInfo += ("\t[CARD_" + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + "] =\n"
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
					+ ("\t\t.type = TYPE_" + re.sub(r'\W+', '_', data['type']).replace('__', '_').replace('__', '_').upper() + ",\n"))
			try:
				gCardInfo += ("\t\t.attribute = ATTRIBUTE_" + data['attribute'] + ",\n"
						+ "\t\t.level = " + str(data['level']) + ",\n"
						+ "\t\t.atk = " + str(int(data['atk']/10)) + ",\n"
						+ "\t\t.def = " + str(int(data['def']/10)) + ",\n"
						+ "\t\t.race = RACE_" + re.sub(r'\W+', '_', data['race']).replace('__', '_').replace('__', '_').upper() + ",\n")
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
			YGO_C += '    [ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').upper() + '] = ' + str(card_counter) + ',\n'
			card_counter += 1

gCardInfo_Output = open('src/data/ygo/card_info.h', 'w')
gCardInfo_Output.write(gCardInfo)
gCardInfo_Output.close()
print('src/data/ygo/card_info.h written')
YGO_C_Output = open('src/ygo.c', 'w')
YGO_C_Output.write(YGO_C)
YGO_C_Output.close()
print('src/ygo.c written')