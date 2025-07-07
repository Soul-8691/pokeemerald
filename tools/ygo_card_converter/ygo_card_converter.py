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
# 				outfile = 'Sets/Icons/' + set_.lower() + '_icon.jpg'
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
	'4-Starred Ladybug of Doom',
	'7 Colored Fish',
	'A Legendary Ocean',
	'A Wingbeat of Giant Dragon',
	'A-Assault Core',
	'A.I. Meet You',
	'Abominable Chamber of the Unchained',
	'Absolute King Back Jack',
	'Abyss Actor - Curtain Raiser',
	'Abyss Soldier',
	'Abyss-sphere',
	'Accumulated Fortune',
	'Achichi @Ignister',
	'Acid Trap Hole',
	'Advanced Ritual Art',
	'Agave Dragon',
	'Agido the Ancient Sentinel',
	'Airknight Parshath',
	'Alba-Lenatus the Abyss Dragon',
	'Albaz the Ashen',
	'Albion the Sanctifire Dragon',
	'Albion the Shrouded Dragon',
	'Aleister the Invoker',
	'ALERT!',
	'Alexandrite Dragon',
	'Alich, Malebranche of the Burning Abyss',
	'Allure of Darkness',
	'Ally of Justice Cycle Reader',
	'Aloof Lupine',
	'Altergeist Marionetter',
	'Altergeist Meluseek',
	'Altergeist Multifaker',
	'Altergeist Protocol',
	'Aluber the Jester of Despia',
	'Amazoness Archer',
	'Amazoness Spiritualist',
	'Amphibious Bugroth MK-3',
	'Amulet Dragon',
	'Ancient Gear Dragon',
	'Ancient Gear Golem - Ultimate Pound',
	'Angel of Blue Tears',
	'Angel Statue - Azurune',
	'Angmarl the Fiendish Monarch',
	'Anti-Magic Arrows',
	'Anti-Spell Fragrance',
	'Appointer of the Red Lotus',
	'Apprentice Illusion Magician',
	'Apprentice Magician',
	'Aqua Madoor',
	'Aqua Spirit',
	'Archfiend Black Skull Dragon',
	'Archfiend Cavalry',
	'Archfiend Commander',
	'Archfiend Eccentrick',
	'Archfiend Empress',
	'Archfiend Giant',
	'Archfiend Heiress',
	'Archfiend Interceptor',
	'Archfiend of Gilfer',
	'Archfiend Soldier',
	'Archlord Kristya',
	'Archnemeses Protos',
	'Arianna the Labrynth Servant',
	'Arias the Labrynth Butler',
	'Ariel, Priestess of the Nekroz',
	'Arisen Gaia the Fierce Knight',
	'Armageddon Knight',
	'Armed Ninja',
	'Armored Cybern',
	'Arsenal Bug',
	'Arsenal Summoner',
	'Artifact Beagalltach',
	'Artifact Ignition',
	'Artifact Lancea',
	'Artifact Moralltach',
	'Artifact Sanctum',
	'Artifact Scythe',
	'Asceticism of the Six Samurai',
	'Ash Blossom & Joyous Spring',
	'Asura Priest',
	'Atlantean Dragoons',
	'Atlantean Heavy Infantry',
	'Atlantean Marksman',
	'Aurkus, Lightsworn Druid',
	'Autonomous Action Unit',
	'Avance, Swordsman of the Nekroz',
	'Axe Dragonute',
	'Axe of Despair',
	'B-Buster Drake',
	'Babycerasaurus',
	'Backup Soldier',
	'Baku the Beast Ninja',
	'Balance of Judgment',
	'Banisher of the Light',
	'Banisher of the Radiance',
	'Banishment of the Darklords',
	'Baobaboon',
	'Barbar, Malebranche of the Burning Abyss',
	'Barrel Behind the Door',
	'Barrier of the Voiceless Voice',
	'Barrier Statue of the Stormwinds',
	'Batteryman Solar',
	'Battle Fader',
	'Battle Footballer',
	'Battle Ox',
	'Bazoo the Soul-Eater',
	'Beast of Talwar',
	'Beast of Talwar - The Sword Summit',
	'Beautiful Headhuntress',
	'Beckoning Light',
	'Beginning Knight',
	'Beiige, Vanguard of Dark World',
	'Berlineth the Firestorm Vassal',
	'Berserk Dragon',
	'Berserk Gorilla',
	'Bickuribox',
	'Big Bang Shot',
	'Big Shield Gardna',
	'Big Welcome Labrynth',
	'Big-Tusked Mammoth',
	'Black Dragon Collapserpent',
	'Black Horn of Heaven',
	'Black Illusion Ritual',
	'Black Luster Soldier - Envoy of the Beginning',
	'Black Luster Soldier - Envoy of the Evening Twilight',
	'Black Metal Dragon',
	'Black Pendant',
	'Black Salvo',
	'Black Skull Dragon',
	'Black Whirlwind',
	'Blackwing - Blizzard the Far North',
	'Blackwing - Bora the Spear',
	'Blackwing - Gale the Whirlwind',
	'Blackwing - Gofu the Vague Shadow',
	'Blackwing - Kalut the Moon Shadow',
	'Blackwing - Shura the Blue Flame',
	'Blackwing - Sirocco the Dawn',
	'Blackwing - Vayu the Emblem of Honor',
	'Blackwing - Zephyros the Elite',
	'Blade Knight',
	'Blast with Chain',
	'Blaster, Dragon Ruler of Infernos',
	'Blazing Cartesia, the Virtuous',
	'Blazing Inpachi',
	'Blazing Mirror Force',
	'Blind Obliteration',
	'Blindly Loyal Goblin',
	'Block Attack',
	'Blowback Dragon',
	'Blue Flame Swordsman',
	'Blue-Eyes Alternative Ultimate Dragon',
	'Blue-Eyes Alternative White Dragon',
	'Blue-Eyes Jet Dragon',
	'Blue-Eyes Toon Dragon',
	'Blue-Eyes Twin Burst Dragon',
	'Blue-Eyes Tyrant Dragon',
	'Blue-Eyes Ultimate Dragon',
	'Blue-Eyes White Dragon',
	'BM-4 Blast Spider',
	'Bone Archfiend',
	'Bonfire',
	'Book of Eclipse',
	'Book of Life',
	'Book of Lunar Eclipse',
	'Book of Moon',
	'Book of Taiyou',
	'Bottomless Trap Hole',
	'Bowganian',
	'Brain Control',
	'Branded Beast',
	'Branded Fusion',
	'Branded in High Spirits',
	'Branded in Red',
	'Branded Opening',
	'Branded Regained',
	'Breaker the Magical Warrior',
	'Breakthrough Skill',
	'Brigrand the Glory Dragon',
	'Brilliant Fusion',
	'Brilliant Rose',
	'Brotherhood of the Fire Fist - Bear',
	'Brotherhood of the Fire Fist - Dragon',
	'Brotherhood of the Fire Fist - Gorilla',
	'Broww, Huntsman of Dark World',
	'Brron, Mad King of Dark World',
	'Bujin Mikazuchi',
	'Bujin Yamato',
	'Bujincarnation',
	'Bujingi Crane',
	'Bujingi Hare',
	'Bujingi Turtle',
	'Burial from a Different Dimension',
	'Burner, Dragon Ruler of Sparks',
	'Burst Rebirth',
	'Buster Blader',
	'Buster Blader, the Destruction Swordmaster',
	'Buster Blader, the Dragon Destroyer Swordsman',
	'Byser Shock',
	'Bystial Baldrake',
	'Bystial Druiswurm',
	'Bystial Magnamhut',
	'Bystial Saronir',
	'C-Crush Wyvern',
	'Cagna, Malebranche of the Burning Abyss',
	'Caius the Mega Monarch',
	'Caius the Shadow Monarch',
	'Calcab, Malebranche of the Burning Abyss',
	'Call of the Haunted',
	'Called by the Grave',
	'Cannon Soldier',
	'Card',
	'Card Destruction',
	'Card of Demise',
	'Card of Safe Return',
	'Card Trooper',
	'Cardcar D',
	'Cards for Black Feathers',
	'Cards from the Sky',
	'Cards of Consonance',
	'Castle of Dark Illusions',
	'Castle Walls',
	'Catapult Turtle',
	'Ceasefire',
	'Celestia, Lightsworn Angel',
	'Chain Disappearance',
	'Chain Energy',
	'Chain Strike',
	'Chainsaw Insect',
	'Change of Heart',
	'Chaos Emperor Dragon - Envoy of the End',
	'Chaos Hunter',
	'Chaos Nephthys',
	'Chaos Sorcerer',
	'Chaos Space',
	'Chaos Trap Hole',
	'Charcoal Inpachi',
	'Charge of the Light Brigade',
	'Charging Gaia the Fierce Knight',
	'Chicken Game',
	'Chimeratech Fortress Dragon',
	'Chiron the Mage',
	'Chronicle Magician',
	'Chronicle Sorceress',
	'Chronograph Sorcerer',
	'Chronomaly Crystal Skull',
	'Chronomaly Golden Jet',
	'Chronomaly Nebra Disk',
	'Cipher Soldier',
	'Cir, Malebranche of the Burning Abyss',
	'Clorless, Chaos King of Dark World',
	'Closed Forest',
	'Coach Soldier Wolfbark',
	'Cold Wave',
	'Command Knight',
	'Compulsory Escape Device',
	'Compulsory Evacuation Device',
	'Confiscation',
	'Conquistador of the Golden Land',
	'Consecrated Light',
	'Contact "C"',
	'CONTAIN!',
	'Cosmic Cyclone',
	'Couplet the Melodious Songstress',
	'Crackdown',
	'Crass Clown',
	'Creature Swap',
	'Crevice Into the Different Dimension',
	'Crimson Ninja',
	'Crossout Designator',
	'Crush Card Virus',
	'Crystal Rose',
	'Cursed Eldland',
	'Cursed Seal of the Forbidden Spell',
	'Cyber Angel Benten',
	'Cyber Angel Idaten',
	'Cyber Angel Natasha',
	'Cyber Dragon',
	'Cyber Dragon Core',
	'Cyber Dragon Drei',
	'Cyber Dragon Vier',
	'Cyber Dragon Zwei',
	'Cyber Eltanin',
	'Cyber Emergency',
	'Cyber End Dragon',
	'Cyber Harpie Lady',
	'Cyber Jar',
	'Cyber Larva',
	'Cyber Network',
	'Cyber Phoenix',
	'Cyber Repair Plant',
	'Cyber Twin Dragon',
	'Cyber Valley',
	'Cyber-Stein',
	'Cyberdark Wurm',
	'Cyberse Gadget',
	'Cynet Mining',
	'D.D. Assailant',
	'D.D. Crazy Beast',
	'D.D. Crow',
	'D.D. Designator',
	'D.D. Survivor',
	'D.D. Trainer',
	'D.D. Warrior',
	'D.D. Warrior Lady',
	'D.D.R. - Different Dimension Reincarnation',
	'D/D Savant Kepler',
	'Dance Princess of the Nekroz',
	'Dandylion',
	'Danger! Bigfoot!',
	'Danger! Mothman!',
	'Danger! Nessie!',
	'Danger!? Jackalope?',
	'Danger!? Tsuchinoko?',
	'Dark Armed Dragon',
	'Dark Beckoning Beast',
	'Dark Blade',
	'Dark Blade the Dragon Knight',
	'Dark Bribe',
	'Dark Cavalry',
	'Dark Contract with the Gate',
	'Dark Deal',
	'Dark Elf',
	'Dark Eradicator Warlock',
	'Dark Flare Knight',
	'Dark Grepher',
	'Dark Hole',
	'Dark Magic Curtain',
	'Dark Magician',
	'Dark Magician Girl',
	'Dark Magician Girl the Dragon Knight',
	'Dark Magician of Chaos',
	'Dark Magician the Dragon Knight',
	'Dark Magician the Knight of Dragon Magic',
	'Dark Mimic LV1',
	'Dark Mimic LV3',
	'Dark Nephthys',
	'Dark Paladin',
	'Dark Ruler Ha Des',
	'Dark Ruler No More',
	'Dark Scorpion - Chick the Yellow',
	'Dark Scorpion - Cliff the Trap Remover',
	'Dark Smog',
	'Dark World Dealings',
	'Dark World Lightning',
	'Darkest Diabolos, Lord of the Lair',
	'Darkflare Dragon',
	'Darklord Contact',
	'Darklord Ixchel',
	'Darklord Nasten',
	'Darklord Rebellion',
	'Darklord Superbia',
	'Darklord Zerato',
	'De-Fusion',
	'De-Spell',
	'De-Synchro',
	'Debris Dragon',
	'Debunk',
	'Deception of the Sinful Spoils',
	'Deck Devastation Virus',
	'Deck Lockdown',
	'Deep Dark Trap Hole',
	'Deep Sea Diva',
	'Deep-Eyes White Dragon',
	'Defender of Nephthys',
	'Dekoichi the Battlechanted Locomotive',
	'Delg the Dark Monarch',
	'Delinquent Duo',
	'Delta Crow - Anti Reverse',
	'Demise, King of Armageddon',
	'Denko Sekka',
	'Des Dendle',
	'Des Frog',
	'Des Koala',
	'Des Lacooda',
	'Des Wombat',
	'Desert Sunlight',
	'Deskbot 001',
	'Despian Tragedy',
	'Desrook Archfiend',
	'Destiny Draw',
	'Destiny HERO - Celestial',
	'Destiny HERO - Dasher',
	'Destiny HERO - Diamond Dude',
	'Destiny HERO - Disk Commander',
	'Destiny HERO - Doom Lord',
	'Destiny HERO - Fear Monger',
	'Destiny HERO - Malicious',
	'Destiny HERO - Plasma',
	'Destructive Daruma Karma Cannon',
	'Dharc the Dark Charmer, Gloomy',
	'Diabellstar the Black Witch',
	'Diamond Dust',
	'Dian Keto the Cure Master',
	'Dictator of D.',
	'Different Dimension Ground',
	'Dimension Conjurer',
	'Dimension Fusion',
	'Dimension Shifter',
	'Dimension Wall',
	'Dimensional Alchemist',
	'Dimensional Barrier',
	'Dimensional Fissure',
	'Dimensional Prison',
	'Dinomight Knight, the True Dracofighter',
	'Dinowrestler Capaptera',
	'Dinowrestler Pankratops',
	'Dinowrestler Valeonyx',
	'Disciple of Nephthys',
	'Disciples of the True Dracophoenix',
	'Divine Sword - Phoenix Blade',
	'Divine Temple of the Snake-Eye',
	'Divine Wrath',
	'Diviner of the Herald',
	'Djinn Releaser of Rituals',
	'DNA Surgery',
	'Dogmatika Ecclesia, the Virtuous',
	'Dogmatika Maximus',
	'Dogmatika Punishment',
	'Dogoran, the Mad Flame Kaiju',
	'Domain of the True Monarchs',
	'Dominus Impulse',
	'Dominus Purge',
	'Don Zaloog',
	'Doom Dozer',
	'Doomcaliber Knight',
	'Doppelwarrior',
	'Dora Dora',
	'Dotscaper',
	'Double Cyclone',
	'Double-Edged Sword Technique',
	'Draco Face-Off',
	'Dracoback, the Rideable Dragon',
	'Dragged Down into the Grave',
	'Dragon Ravine',
	'Dragon Shrine',
	'Dragonic Diagram',
	'Dragonpit Magician',
	'Dragoons of Draconia',
	'Dragunity Arma Mystletainn',
	'Dragunity Corsesca',
	'Dragunity Dux',
	'Dragunity Phalanx',
	'Dream Clown',
	'Drillroid',
	'Droll & Lock Bird',
	'Drop Off',
	'Drowning Mirror Force',
	'Drytron Alpha Thuban',
	'Drytron Delta Altais',
	'Drytron Fafnir',
	'Drytron Gamma Eltanin',
	'Drytron Nova',
	'Drytron Zeta Aldhibah',
	'Duelist Alliance',
	'Dunames Dark Witch',
	'Dupe Frog',
	'Dust Tornado',
	'Dynatherium',
	'E - Emergency Call',
	'Earth Effigy',
	'Earthbound Spirit',
	'Eclipse Wyvern',
	'Edea the Heavenly Squire',
	'Edge Imp Chain',
	'Effect Veiler',
	'Ehren, Lightsworn Monk',
	'Ehther the Heavenly Monarch',
	'Eidos the Underworld Monarch',
	'Eidos the Underworld Squire',
	'El Shaddoll Anoyatyllis',
	'El Shaddoll Apkallone',
	'El Shaddoll Construct',
	'El Shaddoll Fusion',
	'El Shaddoll Grysta',
	'El Shaddoll Shekhinaga',
	'El Shaddoll Wendigo',
	"Elder Entity N'tss",
	'Elder of the Six Samurai',
	'Eldlich the Golden Lord',
	'Eldlixir of Scarlet Sanguine',
	'Electric Snake',
	'Electric Virus',
	'Elemental HERO Blazeman',
	'Elemental HERO Bubbleman',
	'Elemental HERO Clayman',
	'Elemental HERO Flame Wingman',
	'Elemental HERO Neos Alius',
	'Elemental HERO Prisma',
	'Elemental HERO Stratos',
	'Elemental HERO Wildheart',
	'Elemental HERO Woodsman',
	'Emergency Provisions',
	'Emergency Teleport',
	'EMERGENCY!',
	'Emilia, Dance Priestess of the Nekroz',
	'Emissary of the Afterlife',
	'Enemy Controller',
	'Envoy of Chaos',
	'Eradicator Epidemic Virus',
	'Erebus the Underworld Monarch',
	'Escape from the Dark Dimension',
	'Escape of the Unchained',
	'Eva',
	'Evening Twilight Knight',
	'Evenly Matched',
	'Evigishki Mind Augus',
	'Evilswarm Castor',
	'Evilswarm Heliotrope',
	'Evilswarm Kerykeion',
	'Evilswarm Ketos',
	'Evilswarm Mandragora',
	'Evilswarm Thunderbird',
	'Evil★Twins Ki-sikil & Lil-la',
	'Exa, Enforcer of the Nekroz',
	'Exarion Universe',
	'Exchange',
	'Exchange of the Spirit',
	'Exiled Force',
	'Exodia the Forbidden One',
	'Exosister Elis',
	'Exosister Martha',
	'Exosister Pax',
	'Exosister Returnia',
	'Exosister Sophia',
	'Exosister Stella',
	'Exosister Vadis',
	'Exploder Dragon',
	'Ext Ryzeal',
	'EXTINGUISH!',
	'Fabled Grimro',
	'Fabled Lurrie',
	'Fairy Tail - Snow',
	'Fairy Wind',
	'Fake Trap',
	'Fallen of Albaz',
	'Familiar-Possessed - Aussa',
	'Familiar-Possessed - Eria',
	'Familiar-Possessed - Hiita',
	'Familiar-Possessed - Wynn',
	'Fantastical Dragon Phantazmay',
	'Farfa, Malebranche of the Burning Abyss',
	'Fateful Adventure',
	'Felis, Lightsworn Archer',
	'Fencing Fire Ferret',
	'Fiber Jar',
	'Fiend Griefing',
	'Fiendish Chain',
	'Fiendsmith Engraver',
	'Fiendsmith in Paradise',
	'Fighting Flame Swordsman',
	'Final Flame',
	'Fire Cracker',
	'Fire Formation - Gyokkou',
	'Fire Formation - Tenken',
	'Fire Formation - Tenki',
	'Fire Formation - Tensen',
	'Fire Formation - Tensu',
	'Fire Hand',
	'Fire King Avatar Arvata',
	'Fire King Avatar Barong',
	'Fire King Avatar Yaksha',
	'Fire King Courtier Ulcanix',
	'Fire King High Avatar Garunix',
	'Fire King High Avatar Kirin',
	'Fire King Island',
	'Fire King Sanctuary',
	'Fire Lake of the Burning Abyss',
	'Fishborg Blaster',
	'Fissure',
	'Flame Bufferlo',
	'Flame Swordsman',
	'Flamvell Firedog',
	'Flamvell Guard',
	'Flip Flop Frog',
	'Floodgate Trap Hole',
	'Floowandereeze & Eglen',
	'Floowandereeze & Empen',
	'Floowandereeze & Robina',
	'Floowandereeze & Stri',
	'Floowandereeze & Toccan',
	'Floowandereeze and the Advent of Adventure',
	'Floowandereeze and the Dreaming Town',
	'Floowandereeze and the Magnificent Map',
	'Floowandereeze and the Unexplored Winds',
	'Flying "C"',
	'Flying Kamakiri #1',
	'Fog King',
	'Foolish Burial',
	'Foolish Burial Goods',
	'Forbidden Apocrypha',
	'Forbidden Chalice',
	'Forbidden Droplet',
	'Forbidden Lance',
	'Fossil Dig',
	'Fossil Dyna Pachycephalo',
	'Frightfur Patchwork',
	'Frontier Wiseman',
	'Full House',
	'Fullmetalfoes Fusion',
	'Fusilier Dragon, the Dual-Mode Beast',
	'Fusion Deployment',
	'Fusion Destiny',
	'Fusion Devourer',
	'Fusion Substitute',
	'Future Fusion',
	'Gadarla, the Mystery Dust Kaiju',
	'Gagagigo',
	'Gaia Power',
	'Gaia the Dragon Champion',
	'Gaia The Fierce Knight',
	'Galaxy Cyclone',
	'Galaxy Soldier',
	'Gale Dogra',
	'Gameciel, the Sea Turtle Kaiju',
	'Garoth, Lightsworn Warrior',
	'Gateway of the Six',
	'Gatling Dragon',
	'Gear Golem the Moving Fortress',
	'Gearfried the Iron Knight',
	'Gearfried the Red-Eyes Iron Knight',
	'Geargiaccelerator',
	'Geargiagear',
	'Geargiano',
	'Geargiano Mk-II',
	'Geargiarmor',
	'Geargiarsenal',
	'Geargiauger',
	'Gem-Armadillo',
	'Gem-Elephant',
	'Gem-Knight Alexandrite',
	'Gem-Knight Emerald',
	'Gem-Knight Garnet',
	'Gem-Knight Hollowcore',
	'Gem-Knight Lady Rose Diamond',
	'Gem-Knight Nepyrim',
	'Gem-Knight Prismaura',
	'Gem-Knight Quartz',
	'Gem-Knight Ruby',
	'Gem-Knight Sapphire',
	'Gem-Knight Tourmaline',
	'Gem-Knight Zirconia',
	'Gem-Turtle',
	'Gemini Elf',
	'Gemini Imps',
	'Gemini Spark',
	'Gene-Warped Warwolf',
	'Genex Ally Birdman',
	'Genex Controller',
	'Genex Undine',
	'Genta, Gateman of Dark World',
	'Ghost Belle & Haunted Mansion',
	'Ghost Mourner & Moonlit Chill',
	'Ghost Ogre & Snow Rabbit',
	'Ghost Reaper & Winter Cherries',
	'Ghost Sister & Spooky Dogwood',
	'Giant Germ',
	'Giant Orc',
	'Giant Rat',
	'Giant Red Seasnake',
	'Giant Soldier of Stone',
	'Giant Trunade',
	'Giga-Tech Wolf',
	'Gigantes',
	'Gil Garth',
	'Gilasaurus',
	'Giltia the D. Knight - Soul Spear',
	'Gishki Abyss',
	'Gishki Ariel',
	'Gishki Avance',
	'Gishki Beast',
	'Gishki Chain',
	'Gishki Emilia',
	'Gishki Grimness',
	'Gishki Marker',
	'Gishki Natalia',
	'Gishki Noellia',
	'Gishki Shadow',
	'Gishki Vanity',
	'Gishki Vision',
	'Gizmek Orochi, the Serpentron Sky Slasher',
	'Gladiator Beast Bestiari',
	'Gladiator Beast Darius',
	'Gladiator Beast Equeste',
	'Gladiator Beast Hoplomus',
	'Gladiator Beast Laquari',
	'Gladiator Beast Murmillo',
	'Gladiator Beast Samnite',
	'Gladiator Beast Secutor',
	'Gladiator Beast War Chariot',
	'Gladiator Proving Ground',
	'Glow-Up Bulb',
	'Gnomaterial',
	'Goblin Attack Force',
	'Goblin Biker Grand Breakout',
	'Goblin Elite Attack Force',
	'Goblin Pothole Squad',
	'Goblin Zombie',
	'Goblindbergh',
	'Gokipon',
	'Gold Gadget',
	'Gold Sarcophagus',
	'Goldd, Wu-Lord of Dark World',
	'Golem Sentry',
	'Good Goblin Housekeeping',
	'Gora Turtle',
	'Gorz the Emissary of Darkness',
	"Gottoms' Emergency Call",
	'Gouki Bearhug',
	'Gouki Headbatt',
	'Gouki Octostretch',
	'Gouki Re-Match',
	'Gouki Riscorpio',
	'Gouki Suprex',
	'Gouki Twistcobra',
	'Gozen Match',
	'Graceful Charity',
	'Graff, Malebranche of the Burning Abyss',
	'Grand Horn of Heaven',
	'Grandmaster of the Six Samurai',
	'Grandsoil the Elemental Lord',
	'Granguignol the Dusk Dragon',
	'Granmarg the Mega Monarch',
	'Granmarg the Rock Monarch',
	'Grapha, Dragon Lord of Dark World',
	'Grapha, Dragon Overlord of Dark World',
	'Grave of the Super Ancient Organism',
	'Graverobber',
	'Gravity Bind',
	'Great Shogun Shien',
	'Great Sorcerer of the Nekroz',
	'Great White',
	'Green Baboon, Defender of the Forest',
	'Green Gadget',
	'Green Ninja',
	'Gren, Tactician of Dark World',
	'Grisaille Prison',
	'Gruesome Grave Squirmer',
	'Guardian Sphinx',
	'Guardragon Garmides',
	'Guiding Ariadne',
	'Gunkan Suship Shari',
	'Gyaku-Gire Panda',
	'Gyakutenno Megami',
	'Hallowed Life Barrier',
	'Hammer Shot',
	'Hand Destruction',
	'Hand of Nephthys',
	'Hane-Hane',
	'Hanewata',
	'Harmonizing Magician',
	'Heart of the Blue-Eyes',
	'Heat Wave',
	'Heavenly Dragon Circle',
	'Heavy Storm',
	'Heavy Storm Duster',
	'Herald of Green Light',
	'Herald of Orange Light',
	'Hero Blast',
	'Hidden Armory',
	'Hieracosphinx',
	'Hieratic Dragon of Eset',
	'Hieratic Dragon of Su',
	'Hieratic Dragon of Tefnuit',
	'Hieratic Seal From the Ashes',
	'Hieratic Seal of Convocation',
	'High Priestess of Prophecy',
	'Holding Legs',
	'Honest',
	'Horn of Heaven',
	'Horn of the Phantom Beast',
	'Howling Insect',
	'Huaquero of the Golden Land',
	'Humanoid Slime',
	'Hunter Owl',
	'Hydrogeddon',
	'Hyper Hammerhead',
	'Icarus Attack',
	'Ice Hand',
	'Ice Knight',
	'Ice Ryzeal',
	'Ignis Heat, the True Dracowarrior',
	'Ignister A.I.Land',
	'Il Blud',
	'Illusion of Chaos',
	'Illusory Snatcher',
	'Imperial Iron Wall',
	'Imperial Order',
	'Imsety, Glory of Horus',
	'Inaba White Rabbit',
	'Incredible Ecclesia, the Virtuous',
	'Indomitable Fighter Lei Lei',
	'Infernalqueen Salmon',
	'Infernity Archfiend',
	'Infernity Avenger',
	'Infernity Barrier',
	'Infernity Beetle',
	'Infernity Break',
	'Infernity Inferno',
	'Infernity Launcher',
	'Infernity Mirage',
	'Infernity Necromancer',
	'Infernoid Attondel',
	'Infernoid Decatron',
	'Infernoid Devyaty',
	'Infernoid Harmadik',
	'Infernoid Onuncu',
	'Infernoid Patrulea',
	'Infernoid Seitsemas',
	'Infernoid Sjette',
	'Infestation Pandemic',
	'Infinite Impermanence',
	'Injection Fairy Lily',
	'Inpachi',
	'Insect Knight',
	'Inspector Boarder',
	'Instant Fusion',
	'Interrupted Kaiju Slumber',
	'Into the Void',
	'Invocation',
	'Inzektor Centipede',
	'Inzektor Dragonfly',
	'Inzektor Hornet',
	'Inzektor Ladybug',
	'Inzektor Sword - Zektkaliber',
	'Ipiria',
	'Island Turtle',
	'Jain, Lightsworn Paladin',
	'Jar of Greed',
	'Jet Synchron',
	'Jigabyte',
	'Jinzo',
	'Jioh the Gravity Ninja',
	'Jirai Gumo',
	'Jizukiru, the Star Destroying Kaiju',
	'Jongleur-Ghoul Illusionist',
	'Jowgen the Spiritualist',
	'Judge Man',
	'Judgment Dragon',
	'Junk Forward',
	'Junk Synchron',
	'Jurrac Guaiba',
	'Just Desserts',
	'Justice of Prophecy',
	'Kabazauls',
	'Kagemusha of the Six Samurai',
	'Kagero the Cannon Ninja',
	'Kagetokage',
	'Kaibaman',
	'Kaiser Colosseum',
	'Kaiser Sea Horse',
	'Karakuri Komachi mdl 224 "Ninishi"',
	'Karakuri Merchant mdl 177 "Inashichi"',
	'Karakuri Ninja mdl 919 "Kuick"',
	'Karakuri Soldier mdl 236 "Nisamu"',
	'Karma Cut',
	'Kashtira Big Bang',
	'Kashtira Birth',
	'Kashtira Fenrir',
	'Kashtira Riseheart',
	'Kashtira Unicorn',
	'Kashtiratheosis',
	'Keeper of Dragon Magic',
	'Keeper of the Shrine',
	'Kelbek the Ancient Vanguard',
	'Keldo the Sacred Protector',
	'King Dragun',
	'King of the Swamp',
	'King Tiger Wanghu',
	'Knightmare Corruptor Iblee',
	"Koa'ki Meiru Drago",
	'Kozmo Dark Destroyer',
	'Kozmo DOG Fighter',
	'Kozmo Farmgirl',
	'Kozmo Forerunner',
	'Kozmo Goodwitch',
	'Kozmo Sliprider',
	'Kozmo Strawman',
	'Kozmo Tincan',
	'Kozmojo',
	'Kozmoll Dark Lady',
	'Kozmoll Wickedwitch',
	'Kozmotown',
	'Krebons',
	'Kumongous, the Sticky String Kaiju',
	'Kunai with Chain',
	'Kuraz the Light Monarch',
	'Kuribandit',
	'Kuriboh',
	'Kurikara Divincarnate',
	'Kycoo the Ghost Destroyer',
	'La Jinn the Mystical Genie of the Lamp',
	'Labradorite Dragon',
	'Labrynth Archfiend',
	'Labrynth Chandraglier',
	'Labrynth Cooclock',
	'Labrynth Stovie Torbie',
	'Labyrinth Tank',
	'Lacrima the Crimson Tears',
	'Lady Debug',
	'Lady Labrynth of the Silver Castle',
	'Lady Ninja Yae',
	'Lancer Archfiend',
	'Last Day of Witch',
	'Last Will',
	'Lava Golem',
	'Lazion, the Timelord',
	'Leeching the Light',
	'Left Arm of the Forbidden One',
	'Left Arm Offering',
	'Left Leg of the Forbidden One',
	'Legacy of Yata-Garasu',
	'Legendary Fire King Ponix',
	'Legendary Jujitsu Master',
	'Legendary Six Samurai - Enishi',
	'Legendary Six Samurai - Kageki',
	'Legendary Six Samurai - Kizan',
	'Leotron',
	'Lesser Fiend',
	'Level Eater',
	'Level Limit - Area B',
	'Levia-Dragon - Daedalus',
	'Libic, Malebranche of the Burning Abyss',
	'Light and Darkness Dragon',
	'Light of Intervention',
	'Light-Imprisoning Mirror',
	'Lightning Storm',
	'Lightning Vortex',
	'Lightning, Dragon Ruler of Drafts',
	'Lightpulsar Dragon',
	'Limit Reverse',
	'Limiter Removal',
	'Live☆Twin Ki-sikil',
	'Live☆Twin Lil-la',
	'Lo, the Prayers of the Voiceless Voice',
	'Lonefire Blossom',
	'Lord of D.',
	'Lose 1 Turn',
	'Lost Wind',
	'Lubellion the Searing Dragon',
	'Lucent, Netherlord of Dark World',
	'Lucius the Shadow Vassal',
	'Lullaby of Obedience',
	'Lumina, Lightsworn Summoner',
	'Luna Light Perfume',
	'Lunalight Black Sheep',
	'Lunalight Kaleido Chick',
	'Lunalight Tiger',
	'Lunalight Yellow Marten',
	'Luster Dragon',
	'Luster Pendulum, the Dracoslayer',
	'Lyla, Lightsworn Sorceress',
	'Machina Cannon',
	'Machina Fortress',
	'Machina Gearframe',
	'Machine Duplication',
	'Macro Cosmos',
	'Mad Archfiend',
	'Mad Dog of Darkness',
	'Madolche Anjelly',
	'Madolche Chateau',
	'Madolche Hootcake',
	'Madolche Magileine',
	'Madolche Messengelato',
	'Madolche Mewfeuille',
	'Mage Power',
	'Magic Cylinder',
	'Magic Deflector',
	'Magic Jammer',
	'Magical Abductor',
	'Magical Dimension',
	'Magical Meltdown',
	'Magical Merchant',
	'Magical Scientist',
	'Magical Spring',
	'Magical Stone Excavation',
	'Magician of Dark Illusion',
	'Magician of Faith',
	"Magicians' Souls",
	'Magikuriboh',
	'Maiden of the Aqua',
	'Maiden of White',
	'Maiden with Eyes of Blue',
	'Majespecter Raccoon - Bunbuku',
	'Majespecter Unicorn - Kirin',
	'Makyura the Destructor',
	'Malefic Blue-Eyes White Dragon',
	'Malefic Cyber End Dragon',
	'Malefic Red-Eyes Black Dragon',
	'Malefic Stardust Dragon',
	'Malevolent Catastrophe',
	'Maliss C GWC-06',
	'Maliss C MTP-07',
	'Maliss C TB-11',
	'Maliss in Underground',
	'Maliss P Chessy Cat',
	'Maliss P Dormouse',
	'Maliss P White Rabbit',
	'Man-Eater Bug',
	'Manju of the Ten Thousand Hands',
	'Mannadium Meek',
	'Mannadium Riumheart',
	'Manticore of Darkness',
	'Marauding Captain',
	'Marshmallon',
	'Mask Change II',
	'Mask of Darkness',
	'Mask of Restrict',
	'Masked Dragon',
	'Masked Ninja Ebisu',
	'Masked Sorcerer',
	'Mass Driver',
	'Master Hyperion',
	'Master of Chaos',
	'Master Peace, the True Dracoslaying King',
	'Master Pendulum, the Dracoslayer',
	'Master with Eyes of Blue',
	'Mataza the Zapper',
	'Mathematician',
	'Matriarch of Nephthys',
	'Maxx "C"',
	'Mecha-Dog Marron',
	'Mechanicalchaser',
	'Megalosmasher X',
	'Megamorph',
	'Mei-Kou, Master of Barriers',
	'Meizen the Battle Ninja',
	'Mekk-Knight Avram',
	'Mementotlan Angwitch',
	'Mementotlan Bone Party',
	'Mementotlan Dark Blade',
	'Mementotlan Fusion',
	'Mementotlan Tatsunootoshigo',
	'Mermaid Knight',
	'Mermail Abyssgunde',
	'Mermail Abyssleed',
	'Mermail Abysslinde',
	'Mermail Abyssmegalo',
	'Mermail Abysspike',
	'Mermail Abyssteus',
	'Mermail Abyssturge',
	'Mermail Shadow Squad',
	'Messenger of Peace',
	'Metal Reflect Slime',
	'Metalflame Swordsman',
	'Metalfoes Combination',
	'Metalfoes Counter',
	'Metalfoes Fusion',
	'Metalfoes Goldriver',
	'Metalfoes Silverd',
	'Metalfoes Steelen',
	'Metalfoes Volflame',
	'Metaltronus',
	'Metamorphosis',
	'Metaverse',
	'Meteonis Drytron',
	'Meteor Black Comet Dragon',
	'Meteor Dragon',
	'Mezuki',
	'Milus Radiant',
	'Minar',
	'Mind Control',
	'Mind Crush',
	'Mind Drain',
	'Mind Protector',
	'Mine Golem',
	'Miracle Dig',
	'Miracle Fusion',
	'Miracle Restoring',
	'Mirage Dragon',
	'Mirage Knight',
	'Mirage of Nightmare',
	'Mirage Swordsman',
	'Mirror Force',
	'Mirror of Oaths',
	'Miscellaneousaurus',
	'Mist Valley Apex Avian',
	'Mistake',
	'Mistaken Arrest',
	'Mitsu the Insect Ninja',
	'Mitsurugi no Mikoto, Saji',
	'Mitsurugi Prayers',
	'Mitsurugi Ritual',
	'Moai Interceptor Cannons',
	'Mobius the Frost Monarch',
	'Mobius the Mega Monarch',
	'Monster Gate',
	'Monster Reborn',
	'Monster Reincarnation',
	'Moray of Greed',
	'Morphing Jar',
	'Morphing Jar #2',
	'Mother Grizzly',
	'Moulinglacia the Elemental Lord',
	'Mudan the Rikka Fairy',
	'Mudora the Sword Oracle',
	'Muka Muka',
	'Muko',
	'Mulcharmy Fuwalos',
	'Mulcharmy Meowls',
	'Mulcharmy Purulia',
	'My Body as a Shield',
	'My Friend Purrely',
	'Mystery Shell Dragon',
	'Mystic Mine',
	'Mystic Swordsman LV2',
	'Mystic Swordsman LV4',
	'Mystic Tomato',
	'Mystical Elf',
	'Mystical Elf - White Lightning',
	'Mystical Refpanel',
	'Mystical Shine Ball',
	'Mystical Space Typhoon',
	'Mystik Wok',
	'Mythic Tree Dragon',
	'Mythic Water Dragon',
	'Mythical Beast Master Cerberus',
	'Nadir Servant',
	'Naelshaddoll Ariel',
	'Necro Gardna',
	'Necrovalley',
	'Necroworld Banshee',
	'Needle Ceiling',
	'Neko Mane King',
	'Nekroz Cycle',
	'Nekroz Kaleidoscope',
	'Nekroz Mirror',
	'Nekroz of Brionac',
	'Nekroz of Clausolas',
	'Nekroz of Decisive Armor',
	'Nekroz of Gungnir',
	'Nekroz of Trishula',
	'Nekroz of Unicore',
	'Nekroz of Valkyrus',
	'Neo Bug',
	'Neo Kaiser Sea Horse',
	'Neo the Magic Swordsman',
	'Neo-Spacian Dark Panther',
	'Neo-Spacian Grand Mole',
	'Neptabyss, the Atlantean Prince',
	'Newdoria',
	'Nibiru, the Primal Being',
	'Night Assailant',
	'Night Beam',
	'Night Sword Serpent',
	'Nightmare Magician',
	'Nightmare Pain',
	'Nightmare Throne',
	'Nightmare Wheel',
	'Nimble Angler',
	'Nimble Beaver',
	'Nimble Momonga',
	'Nin-Ken Dog',
	'Ninja Grandmaster Hanzo',
	'Ninja Grandmaster Sasuke',
	'Ninjitsu Art of Super-Transformation',
	'Nobleman of Crossout',
	'Nobleman of Extermination',
	'Noctovision Dragon',
	'Node Ryzeal',
	'Non Aggression Area',
	'Non-Fusion Area',
	'Number 85: Crazy Box',
	'Oafdragon Magician',
	'Oasis of Dragon Souls',
	'Odd-Eyes Fusion',
	'Odd-Eyes Pendulum Dragon',
	'Offerings to the Doomed',
	'Ojama King',
	'Ojama Trio',
	'Old Vindictive Magician',
	'One Day of Peace',
	'One for One',
	'Onslaught of the Fire Kings',
	'Ookazi',
	'Opening of the Spirit Gates',
	'Oppressed People',
	'Opticlops',
	'Orcust Crescendo',
	'Orcust Cymbal Skeleton',
	'Orcust Harp Horror',
	'Orcust Knightmare',
	'Orcustrated Babel',
	'Orcustrated Return',
	'Original Sinful Spoils - Snake-Eye',
	'Ostinato',
	'Overload Fusion',
	'Overworked',
	'Painful Choice',
	'Painful Decision',
	'Paladin of White Dragon',
	'Paleozoic Canadia',
	'Paleozoic Dinomischus',
	'Paleozoic Leanchoilia',
	'Paleozoic Marrella',
	'Paleozoic Olenoides',
	'Paleozoic Pikaia',
	'Palladium Oracle Mahad',
	'Pantheism of the Monarchs',
	'Parallel eXceed',
	'Parl, Hermit of Dark World',
	'Pendulum Call',
	'Penguin Knight',
	'Penguin Ninja',
	'Performage Damage Juggler',
	'Performage Hat Tricker',
	'Performage Mirror Conductor',
	'Performage Plushfire',
	'Performage Trick Clown',
	'Performapal Guitartle',
	'Performapal Lizardraw',
	'Performapal Monkeyboard',
	'Performapal Odd-Eyes Light Phoenix',
	'Performapal Odd-Eyes Unicorn',
	'Performapal Partnaga',
	'Performapal Pendulum Sorcerer',
	'Performapal Silver Claw',
	'Performapal Skullcrobat Joker',
	'Performapal Trampolynx',
	'Peropero Cerperus',
	'Personal Spoofing',
	'Petiteranodon',
	'Phantom Dragon',
	'Phantom Gryphon',
	"Phantom Knights' Fog Blade",
	'Phantom of Chaos',
	'Phoenix Wing Wind Blast',
	'Photon Thrasher',
	'Pianissimo',
	'Pikari @Ignister',
	'Pinch Hopper',
	'Pitch-Black Power Stone',
	'Plaguespreader Zombie',
	'Poison Draw Frog',
	'Poison of the Old Man',
	'Polymerization',
	'Pot of Avarice',
	'Pot of Desires',
	'Pot of Duality',
	'Pot of Extravagance',
	'Pot of Generosity',
	'Pot of Greed',
	'Pot of Prosperity',
	'Prank-Kids Dropsies',
	'Prank-Kids Fansies',
	'Prank-Kids Lampsies',
	'Prank-Kids Pandemonium',
	'Prank-Kids Place',
	'Prank-Kids Pranks',
	'Prank-Kids Rocksies',
	'Prayers of the Voiceless Voice',
	'Pre-Preparation of Rites',
	'Premature Burial',
	'Preparation of Rites',
	'Pressured Planet Wraitsoth',
	'Prevent Rat',
	'Prickle Fairy',
	'Priestess with Eyes of Blue',
	'Primal Dragon, the Primordial',
	'Prime Material Dragon',
	'Primeval Planet Perlereino',
	'Princess of Tsurugi',
	'Prohibition',
	'Prometheus, King of the Shadows',
	'Protector of the Sanctuary',
	'Protector with Eyes of Blue',
	'Psi-Blocker',
	'PSY-Frame Driver',
	'PSY-Framegear Delta',
	'PSY-Framegear Gamma',
	'Psychic Commander',
	'Pulling the Rug',
	'Puppet Plant',
	'Purrely',
	'Purrely Delicious Memory',
	'Purrely Happy Memory',
	'Purrely Pretty Memory',
	'Purrely Sleepy Memory',
	'Purrelyly',
	'Pyramid Turtle',
	'Qadshaddoll Keios',
	'Qlimate Change',
	'Qliphort Carrier',
	'Qliphort Cephalopod',
	'Qliphort Disk',
	'Qliphort Helix',
	'Qliphort Monolith',
	'Qliphort Scout',
	'Qliphort Shell',
	'Qliphort Stealth',
	'Quaking Mirror Force',
	'Quick Launch',
	'Quickdraw Synchron',
	'Radian, the Multidimensional Kaiju',
	'Raiden, Hand of the Lightsworn',
	'Raigeki',
	'Raigeki Break',
	'Rainbow Kuriboh',
	'Rainbow Life',
	'Raiza the Mega Monarch',
	'Raiza the Storm Monarch',
	'Raremetalfoes Bismugear',
	'Re-Cover',
	'Re-qliate',
	'Reactan, Dragon Ruler of Pebbles',
	'Reaper on the Nightmare',
	'Reasoning',
	'Reborn Tengu',
	'Reckless Greed',
	'Red Dragon Ninja',
	'Red Gadget',
	'Red Reboot',
	'Red Resonator',
	'Red Rose Dragon',
	'Red-Eyes Alternative Black Dragon',
	'Red-Eyes Baby Dragon',
	'Red-Eyes Black Dragon',
	'Red-Eyes Black Dragon Sword',
	'Red-Eyes Black Fullmetal Dragon',
	'Red-Eyes Black Metal Dragon',
	'Red-Eyes Black Meteor Dragon',
	'Red-Eyes Darkness Metal Dragon',
	'Red-Eyes Fusion',
	'Red-Eyes Retro Dragon',
	'Red-Eyes Slash Dragon',
	'Red-Eyes Soul',
	'Red-Eyes Toon Dragon',
	'Red-Eyes Wyvern',
	'Red-Eyes Zombie Dragon',
	'Redox, Dragon Ruler of Boulders',
	'Reeshaddoll Wendi',
	'Reflect Bounder',
	'Refrain the Melodious Songstress',
	'Reign-Beaux, Overking of Dark World',
	'Reign-Beaux, Overlord of Dark World',
	'Reinforcement of the Army',
	'Reinforcements',
	'Rekindling',
	'Relinkuriboh',
	'Relinquished',
	'Reload',
	'Remove Trap',
	'Renge, Gatekeeper of Dark World',
	'Rescue Cat',
	'Rescue Rabbit',
	'RESCUE!',
	'Rescue-ACE Air Lifter',
	'Rescue-ACE HQ',
	'Rescue-ACE Hydrant',
	'Rescue-ACE Impulse',
	'Rescue-ACE Preventer',
	'Rescue-ACE Turbulence',
	'Retaliating "C"',
	'Return from the Different Dimension',
	'Return of the Monarchs',
	'Rex, Freight Fur Hire',
	'Rider of the Storm Winds',
	'Right Arm of the Forbidden One',
	'Right Leg of the Forbidden One',
	'Rikka Glamour',
	'Rikka Konkon',
	'Rikka Petal',
	'Rikka Princess',
	'Ring of Defense',
	'Ring of Destruction',
	'Rising Air Current',
	'Rite of Aramesir',
	'Ritual Beast Ambush',
	'Ritual Beast Inheritance',
	'Ritual Beast Steeds',
	'Ritual Beast Tamer Elder',
	'Rivalry of Warlords',
	"Robbin' Goblin",
	'Rogue Doll',
	'Rokket Tracer',
	'Ronintoadin',
	'Roulette Barrel',
	'Royal Decree',
	'Royal Magical Library',
	'Royal Oppression',
	'Royal Tribute',
	'Rubic, Malebranche of the Burning Abyss',
	'Runick Destruction',
	'Runick Flashing Fire',
	'Runick Fountain',
	'Runick Freezing Curses',
	'Runick Slumber',
	'Runick Tip',
	'Rush Recklessly',
	'Ryko, Lightsworn Hunter',
	'Ryu Kokki',
	'Ryzeal Cross',
	'Ryzeal Plugin',
	'Saber Beetle',
	'Saber Slash',
	'Sabersaurus',
	'Sacred Crane',
	'Sacred Fire King Garunix',
	'Sacred Phoenix of Nephthys',
	'Sacred Sword of Seven Stars',
	'Saffira, Dragon Queen of the Voiceless Voice',
	'Sage with Eyes of Blue',
	'Sakuretsu Armor',
	'Salamandra, the Flying Flame Dragon',
	'Salamangreat Circle',
	'Salamangreat Falco',
	'Salamangreat Foxy',
	'Salamangreat Gazelle',
	'Salamangreat Jack Jaguar',
	'Salamangreat Rage',
	'Salamangreat Roar',
	'Salamangreat Sanctuary',
	'Salamangreat Spinny',
	'Salvage',
	'Samsara D Lotus',
	'Sand Moth',
	'Sangan',
	'Sangen Kaimen',
	'Sangen Summoning',
	'Santa Claws',
	'Saqlifice',
	'Sasuke Samurai',
	'Sasuke Samurai #4',
	'Satellarknight Altair',
	'Satellarknight Deneb',
	'Satellarknight Unukalhai',
	'Satellarknight Vega',
	'Sauravis, the Ancient and Ascended',
	'Scapegoat',
	'Scareclaw Kashtira',
	'Scarm, Malebranche of the Burning Abyss',
	'Scarr, Scout of Dark World',
	'Sea Archiver',
	'Sea Serpent Warrior of Darkness',
	'Second Coin Toss',
	'Secret Barrel',
	'Secret Blast',
	'Secret Village of the Spellcasters',
	'Self-Destruct Button',
	'Senior Silver Ninja',
	'Senju of the Thousand Hands',
	'Serial Spell',
	'Serpentine Princess',
	'Set Rotation',
	'Seven Tools of the Bandit',
	'Shaddoll Beast',
	'Shaddoll Core',
	'Shaddoll Dragon',
	'Shaddoll Falco',
	'Shaddoll Fusion',
	'Shaddoll Hedgehog',
	'Shaddoll Hound',
	'Shaddoll Squamata',
	'Shadow-Imprisoning Mirror',
	'Shared Ride',
	'Shield Crush',
	'Shine Palace',
	'Shining Angel',
	'Shiny Black "C"',
	'Shiny Black "C" Squadder',
	'Shiranui Solitaire',
	'Shrink',
	'Shuffle Reborn',
	'Shurit, Strategist of the Nekroz',
	'Sillva, Warlord of Dark World',
	'Silpheed',
	'Silver Gadget',
	'Sinister Serpent',
	'Sinister Shadow Games',
	'Six Samurai United',
	'Sixth Sense',
	'Skelengel',
	'Skill Drain',
	'Skilled Dark Magician',
	'Skilled Red Magician',
	'Skilled White Magician',
	'Skull Dog Marron',
	'Skull Guardian, Protector of the Voiceless Voice',
	'Skull Lair',
	'Skull Meister',
	'Skull-Mark Ladybug',
	'Sky Iris',
	'Sky Scout',
	'Sky Striker Ace - Raye',
	'Sky Striker Ace - Roze',
	'Sky Striker Airspace - Area Zero',
	'Sky Striker Maneuver - Afterburners!',
	'Sky Striker Maneuver - Jamming Waves!',
	'Sky Striker Mecha - Eagle Booster',
	'Sky Striker Mecha - Hornet Drones',
	'Sky Striker Mecha - Shark Cannon',
	'Sky Striker Mecha - Widow Anchor',
	'Sky Striker Mecha Modules - Multirole',
	'Sky Striker Mobilize - Engage!',
	'Slate Warrior',
	'Small World',
	'Smashing Ground',
	'Snake-Eye Ash',
	'Snake-Eye Birch',
	'Snake-Eye Oak',
	'Snake-Eyes Diabellstar',
	'Snake-Eyes Flamberge Dragon',
	'Snake-Eyes Poplar',
	'Snatch Steal',
	'Snipe Hunter',
	'Snowman Eater',
	'Snoww, Unlight of Dark World',
	'Solar Recharge',
	'Solemn Judgment',
	'Solemn Scolding',
	'Solemn Strike',
	'Solemn Warning',
	'Solemn Wishes',
	'Sonic Bird',
	'Soul Charge',
	'Soul Drain',
	'Soul Exchange',
	'Soul of the Pure',
	'Soul Release',
	'Soul Taker',
	'Soul Tiger',
	'Soul Transition',
	'Souleating Oviraptor',
	'Spear Cretin',
	'Spear Dragon',
	'Speedroid Menko',
	'Speedroid Passinglider',
	'Speedroid Taketomborg',
	'Speedroid Terrortop',
	'Spell Canceller',
	'Spell Reproduction',
	'Spell Shattering Arrow',
	'Spellbook Library of the Crescent',
	'Spellbook Magician of Prophecy',
	'Spellbook of Eternity',
	'Spellbook of Fate',
	'Spellbook of Judgment',
	'Spellbook of Life',
	'Spellbook of Power',
	'Spellbook of Secrets',
	'Spellbook of the Master',
	'Spellbook of Wisdom',
	'Spellbook Star Hall',
	'Sphere Kuriboh',
	'Spirit of the Harp',
	'Spirit of Yubel',
	'Spirit Reaper',
	'Spiritual Beast Apelio',
	'Spiritual Beast Cannahawk',
	'Spiritual Beast Rampengu',
	'Spiritual Beast Tamer Lara',
	'Spiritual Earth Art - Kurogane',
	'Spiritual Water Art - Aoi',
	'Spiritual Wind Art - Miyabi',
	'Spiritualism',
	'Spore',
	'Spright Blue',
	'Spright Carrot',
	'Spright Double Cross',
	'Spright Jet',
	'Spright Pixies',
	'Spright Red',
	'Spright Smashers',
	'Spright Starter',
	'SPYRAL GEAR - Drone',
	'SPYRAL MISSION - Rescue',
	'SPYRAL Quik-Fix',
	'SPYRAL Resort',
	'SPYRAL Super Agent',
	'SPYRAL Tough',
	'Starliege Seyfert',
	'Starlight Road',
	'Stealth Bird',
	'Stellarnova Alpha',
	'Stone Statue of the Aztecs',
	'Stop Defense',
	'Storm',
	'Storming Mirror Force',
	'Stray Purrely Street',
	'Stream, Dragon Ruler of Droplets',
	'Strike Ninja',
	'Stygian Dirge',
	'Stygian Street Patrol',
	'Substitoad',
	'Summon Limit',
	'Summoned Skull',
	'Summoner Monk',
	'Sunseed Genius Loci',
	'Sunvine Sowing',
	'Super Polymerization',
	'Super Quantum Red Layer',
	'Super Rejuvenation',
	'Super Soldier Soul',
	'Super-Nimble Mega Hamster',
	'Supply Squad',
	'Supreme King Dragon Darkwurm',
	'Swallow Flip',
	'Swap Frog',
	'Swarm of Locusts',
	'Swarm of Scarabs',
	'Swift Scarecrow',
	'Sword Ryzeal',
	'Swords of Concealing Light',
	'Swords of Revealing Light',
	'Swordsoul Blackout',
	'Swordsoul Emergence',
	'Swordsoul of Mo Ye',
	'Swordsoul of Taia',
	'Swordsoul Sacred Summit',
	'Swordsoul Strategist Longyuan',
	'System Down',
	'T.A.D.P.O.L.E.',
	'T.G. Rush Rhino',
	'T.G. Striker',
	'T.G. Warwolf',
	'Tearlaments Cryme',
	'Tearlaments Grief',
	'Tearlaments Havnis',
	'Tearlaments Heartbeat',
	'Tearlaments Kashtira',
	'Tearlaments Merrli',
	'Tearlaments Reinoheart',
	'Tearlaments Scheiren',
	'Tearlaments Scream',
	'Tearlaments Sulliek',
	'Temperance of Prophecy',
	'Tempest, Dragon Ruler of Storms',
	'Tenacity of the Monarchs',
	'Tenmataitei',
	'Tenpai Dragon Chundra',
	'Tenpai Dragon Fadra',
	'Tenpai Dragon Genroku',
	'Tenpai Dragon Paidra',
	'Tenyi Spirit - Adhara',
	'Tenyi Spirit - Ashuna',
	'Tenyi Spirit - Shthana',
	'Tenyi Spirit - Vishuda',
	'Terraforming',
	'Terrorking Archfiend',
	'Terrorking Salmon',
	'Tessera the Prime Squire',
	'Test Tiger',
	'TG1-EM1',
	'That Grass Looks Greener',
	'The Agent of Creation - Venus',
	'The Agent of Miracles - Jupiter',
	'The Agent of Mystery - Earth',
	'The Beginning of the End',
	'The Big March of Animals',
	'The Black Goat Laughs',
	'The Black Stone of Legend',
	'The Bystial Aluber',
	'The Bystial Lubellion',
	'The Dark - Hex-Sealed Fusion',
	'The Dark Magicians',
	'The Dragon Dwelling in the Cave',
	'The Earth - Hex-Sealed Fusion',
	'The Fabled Catsith',
	'The Fabled Cerburrel',
	'The Fabled Chawa',
	'The Fabled Ganashia',
	'The Fabled Nozoochee',
	'The Fiend Megacyber',
	'The Forceful Sentry',
	'The Forgiving Maiden',
	'The Gates of Dark World',
	'The Golden Swordsoul',
	'The Grand Spellbook Tower',
	'The Hallowed Azamina',
	'The Last Warrior from Another Planet',
	'The Light - Hex-Sealed Fusion',
	'The Little Swordsman of Aile',
	'The Monarchs Erupt',
	'The Monarchs Stormforth',
	'The Phantom Knights of Ancient Cloak',
	'The Phantom Knights of Ragged Gloves',
	'The Phantom Knights of Silent Boots',
	'The Prime Monarch',
	'The Six Samurai - Irou',
	'The Six Samurai - Yaichi',
	'The Six Samurai - Zanji',
	'The Transmigration Prophecy',
	'The Traveler and the Burning Abyss',
	'The Tricky',
	'The White Stone of Ancients',
	'The White Stone of Legend',
	'The Wicked Worm Beast',
	'The Winged Dragon of Ra - Sphere Mode',
	'There Can Be Only One',
	'Therion "King" Regulus',
	'Therion "Lily" Borea',
	'Thestalos the Firestorm Monarch',
	'Thestalos the Mega Monarch',
	'Thestalos the Shadowfire Monarch',
	'Thousand-Eyes Restrict',
	'Threatening Roar',
	'Throwstone Unit',
	'Thunder Dragon',
	'Thunder Dragon Colossus',
	'Thunder Dragon Fusion',
	'Thunder Dragon Titan',
	'Thunder Dragondark',
	'Thunder Dragonduo',
	'Thunder Dragonhawk',
	'Thunder Dragonlord',
	'Thunder Dragonmatrix',
	'Thunder Dragonroar',
	'Thunder King Rai-Oh',
	'Thunder Nyan Nyan',
	'Thunder Sea Horse',
	'Tidal, Dragon Ruler of Waterfalls',
	'Timaeus the United Dragon',
	'Time Seal',
	'Time-Space Trap Hole',
	'Tin Goldfish',
	'Titaniklad the Ash Dragon',
	'Tlakalel, His Malevolent Majesty',
	'Tobari the Sky Ninja',
	'Token Collector',
	'Toon Cannon Soldier',
	'Toon Cyber Dragon',
	'Toon Dark Magician Girl',
	'Toon Gemini Elf',
	'Toon Goblin Attack Force',
	'Toon Masked Sorcerer',
	'Toon Summoned Skull',
	'Toon Table of Contents',
	'Torrential Tribute',
	'Tour Guide From the Underworld',
	'Trade-In',
	'Tradetoad',
	'Tragoedia',
	'Trance Archfiend',
	'Transaction Rollback',
	'Trap Dustshoot',
	'Trap Eater',
	'Trap Hole',
	'Trap Master',
	'Trap Stun',
	'Trap Trick',
	'Traptrix Arachnocampa',
	'Traptrix Atrax',
	'Traptrix Dionaea',
	'Traptrix Genlisea',
	'Traptrix Mantis',
	'Traptrix Myrmeleo',
	'Traptrix Nepenthes',
	'Traptrix Pudica',
	'Traptrix Trap Hole Nightmare',
	'Traptrix Vesiculo',
	'Treacherous Trap Hole',
	'Treeborn Frog',
	'Tremendous Fire',
	'Tri-Brigade Fraktall',
	'Tri-Brigade Kerass',
	'Tri-Brigade Kitt',
	'Tri-Brigade Nervall',
	'Tri-Brigade Revolt',
	'Tribe-Infecting Virus',
	'Tribute to the Doomed',
	'Trickstar Candina',
	'Trickstar Light Stage',
	'Trickstar Lilybell',
	'Trickstar Lycoris',
	'Trickstar Reincarnation',
	'Trigon',
	'Triple Tactics Talent',
	'Triple Tactics Thrust',
	'Trivikarma',
	'True Draco Apocalypse',
	'True Draco Heritage',
	'True King Lithosagym, the Disaster',
	'Tsukuyomi',
	'Tuning',
	'Twilight Ninja Getsuga, the Shogun',
	'Twilight Ninja Nichirin, the Chunin',
	'Twilight Ninja Shingetsu',
	'Twin Twisters',
	'Twin-Headed Behemoth',
	'Twin-Headed Thunder Dragon',
	'Twister',
	'Typhoon',
	'Tytannial, Princess of Camellias',
	'U.A. Midfielder',
	'U.A. Mighty Slugger',
	'U.A. Penalty Box',
	'U.A. Perfect Ace',
	'U.A. Powered Jersey',
	'U.A. Rival Rebounder',
	'U.A. Signing Deal',
	'U.A. Stadium',
	'UFO Turtle',
	'Ultimate Flame Swordsman',
	'Ultimate Insect LV3',
	'Ultimate Insect LV5',
	'Ultimate Insect LV7',
	'Ultimate Offering',
	'Ultimate Slayer',
	'Unchained Soul of Sharvara',
	'Unchained Twins - Aruha',
	'Unending Nightmare',
	'Unexpected Dai',
	'Unifrog',
	'Union Hangar',
	'United We Stand',
	'Upstart Goblin',
	'Upstart Golden Ninja',
	'Vampire Lord',
	'Vector Pendulum, the Dracoverlord',
	'Vessel for the Dragon Cycle',
	'Virtual World City - Kauwloon',
	'Virtual World Gate - Chuche',
	'Virtual World Gate - Qinglong',
	'Virtual World Gate - Xuanwu',
	'Virtual World Hime - Nyannyan',
	'Virtual World Kirin - Lili',
	'Virtual World Mai-Hime - Lulu',
	'Virtual World Roshi - Laolao',
	'Virtual World Xiezhi - Jiji',
	'Vision HERO Vyon',
	'Void Feast',
	'Void Imagination',
	'Void Vanishment',
	'Volcanic Scattershot',
	'Vorse Raider',
	'Waboku',
	'Wall of Illusion',
	'Wall of Revealing Light',
	'Wandering Gryphon Rider',
	'WANTED: Seeker of Sinful Spoils',
	'Water Enchantress of the Temple',
	'Wave-Motion Cannon',
	'Wavering Eyes',
	'Welcome Labrynth',
	'Where Arf Thou?',
	'White Dragon Ninja',
	'White Dragon Ritual',
	'White Dragon Wyverburster',
	'White Magical Hat',
	'White Night Dragon',
	'White Ninja',
	'Widespread Dud',
	'Widespread Ruin',
	'Will of the Salamangreat',
	'Wind-Up Factory',
	'Wind-Up Hunter',
	'Wind-Up Magician',
	'Wind-Up Rabbit',
	'Wind-Up Rat',
	'Wind-Up Shark',
	'Winged Rhynos',
	'Wiretap',
	'Wisdom-Eye Magician',
	'Witch of the Black Forest',
	'World Legacy - "World Wand"',
	'Wroughtweiler',
	'Wulf, Lightsworn Beast',
	'X-Head Cannon',
	'X-Saber Airbellum',
	'X-Saber Pashuul',
	'Xing Zhen Hu',
	'XX-Saber Boggart Knight',
	'XX-Saber Darksoul',
	'XX-Saber Emmersblade',
	'XX-Saber Faultroll',
	'XX-Saber Fulhelmknight',
	'Xyz Encore',
	'Xyz Universe',
	'Yata-Garasu',
	'Yellow Dragon Ninja',
	'Yellow Gadget',
	'Yellow Ninja',
	'Yomi Ship',
	'Yubel',
	'Yubel - Terror Incarnate',
	'Zaborg the Thunder Monarch',
	'Zaphion, the Timelord',
	'Zefrasaber, Swordmaster of the Nekroz',
	'Zombie Master',
	'Zombie World',
	'Zombino',
	'Zombyra the Dark',
	'Zoodiac Barrage',
	'Zoodiac Combo',
	'Zoodiac Ramram',
	'Zoodiac Ratpier',
	'Zoodiac Thoroughblade',
	'Zoodiac Whiptail',
	'Zure, Knight of Dark World',
	"Abomination's Prison",
	"Archfiend's Advent",
	"Archfiend's Manifestation",
	"Black Dragon's Chick",
	"Dark Magician Girl the Magician's Apprentice",
	"Destrudo the Lost Dragon's Frisson",
	"Dragon's Mirror",
	"Dragon's Rage",
	"Fiendsmith's Tract",
	"Gravekeeper's Assailant",
	"Gravekeeper's Commandant",
	"Gravekeeper's Descendant",
	"Gravekeeper's Guard",
	"Gravekeeper's Inscription",
	"Gravekeeper's Recruiter",
	"Gravekeeper's Spear Soldier",
	"Gravekeeper's Spy",
	"Gravekeeper's Stele",
	"Gravekeeper's Watcher",
	"Harpie's Feather Duster",
	"Harpie's Feather Storm",
	"Hero's Rule 2",
	"Ice Dragon's Prison",
	"King's Sarcophagus",
	"Magician's Circle",
	"Magician's Robe",
	"Magician's Rod",
	"Magician's Valkyria",
	"Majesty's Fiend",
	"Nightmare's Steelcage",
	"Pikeru's Circle of Enchantment",
	"Shien's Smoke Signal",
	"Summoner's Art",
	"True King's Return",
	"Vanity's Emptiness",
	"Vanity's Fiend",
	"Vanity's Ruler",
	'Abyss Dweller',
	'Ally of Justice Catastor',
	'Ancient Fairy Dragon',
	'Apollousa, Bow of the Goddess',
	'Arcanite Magician',
	'Baxia, Brightness of the Yang Zing',
	'Beatrice, Lady of the Eternal',
	'Black Rose Dragon',
	'Blackwing Armed Wing',
	'Blackwing Armor Master',
	'Borreload Dragon',
	'Brionac, Dragon of the Ice Barrier',
	'Castel, the Skyblaster Musketeer',
	'Chimeratech Overdragon',
	'Colossal Fighter',
	'Crimson Blader',
	'Crystron Halqifibrax',
	'Cyber Dragon Infinity',
	'Cyber Dragon Nova',
	'Daigusto Emeral',
	'Dante, Traveler of the Burning Abyss',
	'Dark Balter the Terrible',
	'Dark End Dragon',
	'Dark Strike Fighter',
	'Darkfire Dragon',
	'Destiny HERO - Destroyer Phoenix Enforcer',
	'Diamond Dire Wolf',
	'Dingirsu, the Orcust of the Evening Star',
	'Dinoster Power, the Mighty Dracoslayer',
	'Divine Arsenal AA-ZEUS - Sky Thunder',
	'Divine Dragon Knight Felgrand',
	'Downerd Magician',
	'El Shaddoll Winda',
	'Elder Entity Norden',
	'Evilswarm Exciton Knight',
	'Evolzar Laggia',
	'Fiend Skull Dragon',
	"Fiendsmith's Lacrima",
	"Fiendsmith's Requiem",
	"Fiendsmith's Sequence",
	'Firewall Dragon',
	'Formula Synchron',
	'Gagaga Cowboy',
	'Galatea, the Orcust Automaton',
	'Garura, Wings of Resonant Life',
	'Gigantic Spright',
	'Gladiator Beast Gaiodiaz',
	'Gladiator Beast Gyzarus',
	'Gladiator Beast Heraklinos',
	'Goyo Guardian',
	'Herald of the Arc Light',
	'Hiita the Fire Charmer, Ablaze',
	'I:P Masquerena',
	'Ignister Prominence, the Blasting Dracoslayer',
	'Isolde, Two Tales of the Noble Knights',
	'Kashtira Arise-Heart',
	'King of the Feral Imps',
	'Knightmare Cerberus',
	'Knightmare Goblin',
	'Knightmare Phoenix',
	'Knightmare Unicorn',
	'Leviair the Sea Dragon',
	'Link Spider',
	'Linkuriboh',
	'M-X-Saber Invoker',
	'Maestroke the Symphony Djinn',
	'Magical Android',
	'Majester Paladin, the Ascending Dracoslayer',
	'Master of Oz',
	'Mecha Phantom Beast Dracossack',
	'Mereologic Aggregator',
	'Mermail Abyssgaios',
	'Mermail Abysstrite',
	'Missus Radiant',
	'Mist Wurm',
	'Monk of the Tenyi',
	'Moon of the Closed Heaven',
	'Mudragon of the Swamp',
	'Number 101: Silent Honor ARK',
	'Number 11: Big Eye',
	'Number 17: Leviathan Dragon',
	'Number 30: Acid Golem of Destruction',
	'Number 39: Utopia',
	'Number 66: Master Key Beetle',
	'Paleozoic Opabinia',
	'Prank-Kids Dodo-Doodle-Doo',
	'Prank-Kids Meow-Meow-Mu',
	'Predaplant Dragostapelia',
	'Predaplant Verte Anaconda',
	'Promethean Princess, Bestower of Flames',
	'Red Dragon Archfiend',
	'Relinquished Anima',
	'Roaring Ocean Snake',
	'Ryu Senshi',
	'Ryzeal Detonator',
	'Ryzeal Duo Drive',
	'S:P Little Knight',
	'Salamangreat Balelynx',
	'Salamangreat Raging Phoenix',
	'Salamangreat Sunlight Wolf',
	'Scrap Dragon',
	'Sky Striker Ace - Kagari',
	'Sky Striker Ace - Shizuku',
	'Spright Elf',
	'Spright Sprind',
	'Stardust Dragon',
	'Steelswarm Roach',
	'Super Starslayer TY-PHON - Sky Crisis',
	'Swordsoul Grandmaster - Chixiao',
	'T.G. Hyper Librarian',
	'Tearlaments Kaleido-Heart',
	'Tearlaments Kitkallos',
	'Tearlaments Rulkallos',
	'Tellarknight Ptolemaeus',
	'Temtempo the Percussion Djinn',
	'The Phantom Knights of Break Sword',
	'Thought Ruler Archfiend',
	'Toadally Awesome',
	'Tornado Dragon',
	'Traptrix Rafflesia',
	'Trishula, Dragon of the Ice Barrier',
	'Virgil, Rock Star of the Burning Abyss',
	'Wind-Up Carrier Zenmaity',
	'Wind-Up Zenmaines',
	'XX-Saber Gottoms',
	'XX-Saber Hyunlei',
	'Zoodiac Boarbow',
	'Zoodiac Broadbull',
	'Zoodiac Chakanine',
	'Zoodiac Drident',
	'Zoodiac Hammerkong',
	'Zoodiac Tigermortar',
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
    Item += '''    else if (VarGet(VAR_YGO_SHOP) == BANLIST_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ''')
    {
        if (gCardInfo[card].ban''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''')
            return gCardInfo[card].ban''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + ''';
        else
            return 3;
    }\n'''
    ItemUse += '''    else if (pack == PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ''')
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
# 								sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', rarity).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '},\n'
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
# 								sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', rarity).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '},\n'
# 				except:
# 					pass
# 		sets_print += '};\n\n'

# with open('tcg_sets.json', 'r') as f:
#     data = json.load(f)
#     for set_ in data:
#         sets_print += 'const struct PackContents gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '[] =\n{\n'
#         for card in data[set_]:
#             if card in card_names:
#                 sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', data[set_][card]).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '},\n'
#         sets_print += '};\n\n'

# with open('ocg_sets.json', 'r') as f:
# 	data = json.load(f)
# 	for series in data:
# 		for set_ in data[series]:
# 			sets_print += 'const struct PackContents gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '[] =\n{\n'
# 			for card in data[series][set_]['cards']:
# 				if card in card_names:
# 					sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ', RARITY_COMMON},\n'
# 			sets_print += '};\n\n'

for set_ in packs:
    Scripts += '\tadditem ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' 10\n' 
Scripts += '\n'

YGO_C += '\nconst u16 PackIdMapping[] = \n{\n'
for set_ in packs:
	YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] = ' + str(packs.index(set_)) + ',\n'

for format_ in formats:
    YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] = ' + str(pack_counter) + ',\n'
    pack_counter += 1

YGO_C += '};\n\n'

# sets_print += '\nconst struct Pack gPacks[] =\n{\n'
# card_count = 0
# with open('sets.json', 'r') as f:
# 	data = json.load(f)
# 	for set_ in packs:
# 		if set_[0:3] == 'TCG':
# 			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_[4:]).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] =\n\t{\n        .pack = gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + ',\n        .length = '
# 		else:
# 			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_[4:]).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] =\n\t{\n        .pack = gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + ',\n        .length = '
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
# 			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] =\n\t{\n        .pack = gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_) + ',\n        .length = '
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
with open('tcg_sets.json', 'r') as f:
    data = json.load(f)
    for set_ in data:
        SRCDataItemDescs += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', set_) + 'Desc[] = _(\n    "' + textwrap.fill(set_, width=16).replace('\n', '\\n"\n    "') + '.");\n\n'

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
			ItemIconTable += '\t[ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] = {gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ', gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '},\n'
			Scripts += '\tadditem ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'
			YGO_Graphics_C += ('const u32 gCardPicLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '_Big[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.8bpp.lz");\n'
						+ 'const u16 gCardPalLarge_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U16("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_large_big.gbapal");\n'
						+ 'const u32 gCardIconSquare_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_small.4bpp.lz");\n'
						+ 'const u32 gCardIconSquarePalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/pic_small.gbapal.lz");\n'
						+ 'const u32 gCardIconSmall_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.4bpp.lz");\n'
						+ 'const u32 gCardIconSmallPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_small.gbapal.lz");\n'
						+ 'const u32 gCardIconTiny_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_tiny.4bpp.lz");\n'
						+ 'const u32 gCardIconTinyPalette_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = INCBIN_U32("graphics/cards/' + re.sub(r'\W+', '_', data['name']).lower() + '/icon_tiny.gbapal.lz");\n')
			YGO_Constants += '#define CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' ' + str(card_counter) + '\n'
			Item_Constants += '#define ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' ' + str(card_counter + 376) + '\n'
			card_counter += 1
			Items += '''\t[ITEM_CARD_''' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '''] =
	{
		.name = _("''' + re.sub(r'[^a-zA-Z0-9]', '', data['name'])[:13] + '''"),
		.itemId = ITEM_CARD_''' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ''',
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
sets_count = 1054
for set_ in sorted(list(tcg_sets)):
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' ' + str(sets_count) + '\n'
    sets_count += 1
Item_Constants += '\n'

pack_counter = 2044
for format_ in formats:
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' ' + str(pack_counter) + '\n'
    pack_counter += 1

for set_ in sorted(list(tcg_sets)):
    Items += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '''] =
    {
        .name = _("''' + set_[:13] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', set_) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''
Items += '\n'

for format_ in formats:
    Items += '''	[ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '''] =
    {
        .name = _("''' + format_[:13] + '''"),
        .itemId = ITEM_PACK_''' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ''',
        .price = 0,
        .description = s''' + re.sub(r'[^a-zA-Z0-9]', '', format_) + '''Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },\n\n'''

ItemIconTable += '\n'
for set_ in sorted(list(tcg_sets)):
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'
    sets_count += 1

ItemIconTable += '\n'
for format_ in formats:
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'

YGO_Constants += '\n'
for set_ in sorted(list(tcg_sets)):
    YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' ' + str(sorted(list(tcg_sets)).index(set_)) + '\n'

YGO_Constants += '\n'
pack_counter = 990
for format_ in formats:
    YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ' ' + str(pack_counter) + '\n'
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
	setvar VAR_YGO_SHOP, FORMAT_''' + re.sub(r'\W+', '_', format).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '''
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
					Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'
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
	setvar VAR_YGO_SHOP, BANLIST_''' + re.sub(r'\W+', '_', format).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '''
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
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] == 'Semi-Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'
		for data in card_info_data['data']:
			card_name = data['name']
			if card_name in card_names:
				for card_ in cards_by_format[format]:
					if card_ == card_name and cards_by_format[format][card_]:
						for card__ in data_:
							if card__['Card'] == card_name and card__['Format'] == format and card__['Banlist'] != 'Limited' and card__['Banlist'] != 'Semi-Limited':
								Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card_name).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'
		Scripts += '\tpokemartlistend\n\n'

for set_ in sorted(list(tcg_sets)):
	Scripts += '\t.2byte  ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'
Scripts += '\tpokemartlistend\n\n'

for card in card_names:
	Scripts += '\t.2byte  ITEM_CARD_' + re.sub(r'\W+', '_', card).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '\n'

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
				try:
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
				except:
					pass
			card = data['name']
			gCardInfo += ("\t[CARD_" + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + "] =\n"
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
					+ ("\t\t.type = TYPE_" + re.sub(r'\W+', '_', data['type']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ",\n"))
			try:
				gCardInfo += ("\t\t.attribute = ATTRIBUTE_" + data['attribute'] + ",\n"
						+ "\t\t.level = " + str(data['level']) + ",\n"
						+ "\t\t.atk = " + str(int(data['atk']/10)) + ",\n"
						+ "\t\t.def = " + str(int(data['def']/10)) + ",\n"
						+ "\t\t.race = RACE_" + re.sub(r'\W+', '_', data['race']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + ",\n")
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
			YGO_C += '    [ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('__', '_').upper() + '] = ' + str(card_counter) + ',\n'
			card_counter += 1

gCardInfo_Output = open('src/data/ygo/card_info.h', 'w')
gCardInfo_Output.write(gCardInfo)
gCardInfo_Output.close()
print('src/data/ygo/card_info.h written')
YGO_C_Output = open('src/ygo.c', 'w')
YGO_C_Output.write(YGO_C)
YGO_C_Output.close()
print('src/ygo.c written')