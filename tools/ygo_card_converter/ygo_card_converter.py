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
# packs = set()
with open('bastion.json', 'r') as f:
	data = json.load(f)
	for card in data:
		cards_by_pack[card['name']['en']] = card
		# try:
		# 	for set_tcg in card['sets']['en']:
		# 		packs.add('TCG_' + set_tcg['set_name'])
		# except:
		# 	pass
		# try:
		# 	for set_ocg in card['sets']['ja']:
		# 		packs.add('OCG_' + set_ocg['set_name'])
		# except:
		# 	pass

# packs = sorted(list(packs))

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

FL_ = dict()
banlists = set()
with open('FL.json', 'r') as f:
	data = json.load(f)
	with open('FL_cards.json', 'w', encoding='utf8') as FL:
		for card in data:
			if card['Index (TCG)'] != -1:
				card_ = card['Card']
				if card_ not in FL_:
					FL_[card_] = {}
				banlists.add(card['Month'])
				FL_[card_][card['Month']] = {}
				FL_[card_][card['Month']]['Usage'] = card['Usage (% - Weighted)']
				FL_[card_][card['Month']]['Banlist'] = card['Banlist']
			if card['Format'] in formats:
				cards_by_format[card['Format']][card['Card']] = card['Usage']
				if card['Usage (Weighted)'] > highest_usage[card['Format']]:
					highest_usage[card['Format']] = card['Usage (Weighted)']
		json.dump(dict(sorted(FL_.items())), FL, indent=4)
		FL.close()

for month in tqdm(sorted(banlists)):
	print(month)
	banlist = requests.get("https://formatlibrary.com/api/banlists/" + month.replace(' ', '%20') + "?category=TCG").json()
	with open('FL_cards.json', 'r') as f:
		dt = json.load(f)
		with open('FL_cards.json', 'w', encoding='utf8') as FL:
			for card in sorted(list(dt)):
				print(card)
				for card_index in range(len(banlist['forbidden'])):
					if card == banlist['forbidden'][card_index]['cardName']:
						FL_[card][month] = {}
						FL_[card][month]['Banlist'] = 'Forbidden'
						FL_[card][month]['Usage'] = 0
			json.dump(dict(sorted(FL_.items())), FL, indent=4)
			FL.close()

wct06_ranks = {}
with open('wct06.json', 'r') as f:
    data = json.load(f)
    for card in data:
        wct06_ranks[card['Card']] = 1
        if card['Rank']:
           wct06_ranks[card['Card']] = card['Rank']

card_names = [
	'''4-Starred Ladybug of Doom''',
	'''7 Colored Fish''',
	'''A Legendary Ocean''',
	'''ABC-Dragon Buster''',
	'''Abyss Dweller''',
	'''Abyss Soldier''',
	'''Abyss-sphere''',
	'''Advanced Ritual Art''',
	'''Agido the Ancient Sentinel''',
	'''Airknight Parshath''',
	'''Alba-Lenatus the Abyss Dragon''',
	'''Albaz the Ashen''',
	'''Albion the Sanctifire Dragon''',
	'''Albion the Shrouded Dragon''',
	'''Alexandrite Dragon''',
	'''Allure of Darkness''',
	'''Ally of Justice Catastor''',
	'''Ally of Justice Cycle Reader''',
	'''Aluber the Jester of Despia''',
	'''Amazoness Archer''',
	'''Amazoness Spiritualist''',
	'''Amphibious Bugroth MK-3''',
	'''Amulet Dragon''',
	'''Ancient Fairy Dragon''',
	'''Ancient Gear Dragon''',
	'''Ancient Gear Golem - Ultimate Pound''',
	'''Angmarl the Fiendish Monarch''',
	'''Anti-Spell Fragrance''',
	'''Apollousa, Bow of the Goddess''',
	'''Apprentice Illusion Magician''',
	'''Aqua Madoor''',
	'''Aqua Spirit''',
	'''Arcanite Magician''',
	'''Archfiend Black Skull Dragon''',
	'''Archfiend Cavalry''',
	'''Archfiend Commander''',
	'''Archfiend Eccentrick''',
	'''Archfiend Empress''',
	'''Archfiend Giant''',
	'''Archfiend Heiress''',
	'''Archfiend Interceptor''',
	'''Archfiend of Gilfer''',
	'''Archfiend Soldier''',
	'''Archfiend's Advent''',
	'''Archfiend's Manifestation''',
	'''Archnemeses Protos''',
	'''Ariel, Priestess of the Nekroz''',
	'''Arisen Gaia the Fierce Knight''',
	'''Armageddon Knight''',
	'''Armed Ninja''',
	'''Armored Cybern''',
	'''Armory Arm''',
	'''Arsenal Bug''',
	'''Arsenal Summoner''',
	'''Artifact Lancea''',
	'''Artifact Moralltach''',
	'''Artifact Sanctum''',
	'''Ash Blossom & Joyous Spring''',
	'''Asura Priest''',
	'''Atlantean Dragoons''',
	'''Atlantean Heavy Infantry''',
	'''Atlantean Marksman''',
	'''Aurkus, Lightsworn Druid''',
	'''Avance, Swordsman of the Nekroz''',
	'''Axe Dragonute''',
	'''Axe of Despair''',
	'''Baku the Beast Ninja''',
	'''Banisher of the Light''',
	'''Banisher of the Radiance''',
	'''Baobaboon''',
	'''Barrel Behind the Door''',
	'''Battle Footballer''',
	'''Battle Ox''',
	'''Baxia, Brightness of the Yang Zing''',
	'''Bazoo the Soul-Eater''',
	'''Beast of Talwar''',
	'''Beast of Talwar - The Sword Summit''',
	'''Beatrice, Lady of the Eternal''',
	'''Beckoning Light''',
	'''Beginning Knight''',
	'''Beiige, Vanguard of Dark World''',
	'''Berlineth the Firestorm Vassal''',
	'''Berserk Dragon''',
	'''Berserk Gorilla''',
	'''Bickuribox''',
	'''Big Bang Shot''',
	'''Big Shield Gardna''',
	'''Big-Tusked Mammoth''',
	'''Black Dragon's Chick''',
	'''Black Horn of Heaven''',
	'''Black Illusion Ritual''',
	'''Black Luster Soldier - Envoy of the Beginning''',
	'''Black Luster Soldier - Envoy of the Evening Twilight''',
	'''Black Metal Dragon''',
	'''Black Pendant''',
	'''Black Rose Dragon''',
	'''Black Skull Dragon''',
	'''Black Whirlwind''',
	'''Blackwing - Blizzard the Far North''',
	'''Blackwing - Bora the Spear''',
	'''Blackwing - Gale the Whirlwind''',
	'''Blackwing - Kalut the Moon Shadow''',
	'''Blackwing - Shura the Blue Flame''',
	'''Blackwing - Silverwind the Ascendant''',
	'''Blackwing - Sirocco the Dawn''',
	'''Blackwing - Vayu the Emblem of Honor''',
	'''Blackwing Armed Wing''',
	'''Blackwing Armor Master''',
	'''Blade Knight''',
	'''Blast with Chain''',
	'''Blaster, Dragon Ruler of Infernos''',
	'''Blazing Cartesia, the Virtuous''',
	'''Blazing Inpachi''',
	'''Blindly Loyal Goblin''',
	'''Block Attack''',
	'''Blowback Dragon''',
	'''Blue Flame Swordsman''',
	'''Blue-Eyes Alternative Ultimate Dragon''',
	'''Blue-Eyes Alternative White Dragon''',
	'''Blue-Eyes Jet Dragon''',
	'''Blue-Eyes Toon Dragon''',
	'''Blue-Eyes Twin Burst Dragon''',
	'''Blue-Eyes Tyrant Dragon''',
	'''Blue-Eyes Ultimate Dragon''',
	'''Blue-Eyes White Dragon''',
	'''BM-4 Blast Spider''',
	'''Bone Archfiend''',
	'''Bonfire''',
	'''Book of Eclipse''',
	'''Book of Life''',
	'''Book of Moon''',
	'''Book of Taiyou''',
	'''Borreload Dragon''',
	'''Bottomless Trap Hole''',
	'''Bowganian''',
	'''Brain Control''',
	'''Branded in High Spirits''',
	'''Breaker the Magical Warrior''',
	'''Breakthrough Skill''',
	'''Brigrand the Glory Dragon''',
	'''Brilliant Rose''',
	'''Brionac, Dragon of the Ice Barrier''',
	'''Brotherhood of the Fire Fist - Bear''',
	'''Broww, Huntsman of Dark World''',
	'''Brron, Mad King of Dark World''',
	'''Burial from a Different Dimension''',
	'''Burner, Dragon Ruler of Sparks''',
	'''Buster Blader''',
	'''Buster Blader, the Destruction Swordmaster''',
	'''Buster Blader, the Dragon Destroyer Swordsman''',
	'''Byser Shock''',
	'''Bystial Baldrake''',
	'''Bystial Druiswurm''',
	'''Bystial Magnamhut''',
	'''Bystial Saronir''',
	'''Caius the Mega Monarch''',
	'''Caius the Shadow Monarch''',
	'''Call of the Haunted''',
	'''Called by the Grave''',
	'''Cannon Soldier''',
	'''Card Destruction''',
	'''Card of Demise''',
	'''Card of Safe Return''',
	'''Card Trooper''',
	'''Cards from the Sky''',
	'''Cards of Consonance''',
	'''Castel, the Skyblaster Musketeer''',
	'''Castle of Dark Illusions''',
	'''Castle Walls''',
	'''Catapult Turtle''',
	'''Ceasefire''',
	'''Celestia, Lightsworn Angel''',
	'''Chain Disappearance''',
	'''Chain Energy''',
	'''Chainsaw Insect''',
	'''Change of Heart''',
	'''Chaos Emperor Dragon - Envoy of the End''',
	'''Chaos Hunter''',
	'''Chaos Nephthys''',
	'''Chaos Sorcerer''',
	'''Charcoal Inpachi''',
	'''Charge of the Light Brigade''',
	'''Charging Gaia the Fierce Knight''',
	'''Chicken Game''',
	'''Chimeratech Fortress Dragon''',
	'''Chimeratech Overdragon''',
	'''Chiron the Mage''',
	'''Chronicle Magician''',
	'''Chronicle Sorceress''',
	'''Cipher Soldier''',
	'''Cir, Malebranche of the Burning Abyss''',
	'''Clorless, Chaos King of Dark World''',
	'''Cold Wave''',
	'''Colossal Fighter''',
	'''Command Knight''',
	'''Compulsory Evacuation Device''',
	'''Confiscation''',
	'''Consecrated Light''',
	'''Cosmic Cyclone''',
	'''Crass Clown''',
	'''Creature Swap''',
	'''Crevice Into the Different Dimension''',
	'''Crimson Blader''',
	'''Crimson Ninja''',
	'''Crossout Designator''',
	'''Crush Card Virus''',
	'''Crystal Rose''',
	'''Cursed Seal of the Forbidden Spell''',
	'''Cyber Dragon''',
	'''Cyber Dragon Drei''',
	'''Cyber Dragon Infinity''',
	'''Cyber Dragon Nova''',
	'''Cyber Dragon Vier''',
	'''Cyber Dragon Zwei''',
	'''Cyber Eltanin''',
	'''Cyber End Dragon''',
	'''Cyber Harpie Lady''',
	'''Cyber Jar''',
	'''Cyber Larva''',
	'''Cyber Phoenix''',
	'''Cyber Twin Dragon''',
	'''Cyber Valley''',
	'''Cyber-Stein''',
	'''Cyberdark Wurm''',
	'''Cynet Mining''',
	'''D.D. Assailant''',
	'''D.D. Crazy Beast''',
	'''D.D. Crow''',
	'''D.D. Survivor''',
	'''D.D. Trainer''',
	'''D.D. Warrior Lady''',
	'''Daigusto Emeral''',
	'''Dance Princess of the Nekroz''',
	'''Dandylion''',
	'''Danger! Nessie!''',
	'''Dante, Traveler of the Burning Abyss''',
	'''Dark Armed Dragon''',
	'''Dark Balter the Terrible''',
	'''Dark Blade''',
	'''Dark Blade the Dragon Knight''',
	'''Dark Cavalry''',
	'''Dark Deal''',
	'''Dark Elf''',
	'''Dark End Dragon''',
	'''Dark Eradicator Warlock''',
	'''Dark Flare Knight''',
	'''Dark Grepher''',
	'''Dark Hole''',
	'''Dark Magic Curtain''',
	'''Dark Magician''',
	'''Dark Magician Girl''',
	'''Dark Magician Girl the Dragon Knight''',
	'''Dark Magician Girl the Magician's Apprentice''',
	'''Dark Magician of Chaos''',
	'''Dark Magician the Dragon Knight''',
	'''Dark Magician the Knight of Dragon Magic''',
	'''Dark Mimic LV1''',
	'''Dark Mimic LV3''',
	'''Dark Nephthys''',
	'''Dark Paladin''',
	'''Dark Ruler Ha Des''',
	'''Dark Ruler No More''',
	'''Dark Scorpion - Chick the Yellow''',
	'''Dark Scorpion - Cliff the Trap Remover''',
	'''Dark Strike Fighter''',
	'''Dark World Lightning''',
	'''Darkfire Dragon''',
	'''Darklord Zerato''',
	'''De-Fusion''',
	'''De-Spell''',
	'''Debris Dragon''',
	'''Debunk''',
	'''Deck Devastation Virus''',
	'''Deep Sea Diva''',
	'''Deep-Eyes White Dragon''',
	'''Defender of Nephthys''',
	'''Dekoichi the Battlechanted Locomotive''',
	'''Delg the Dark Monarch''',
	'''Delinquent Duo''',
	'''Demise, King of Armageddon''',
	'''Denko Sekka''',
	'''Des Dendle''',
	'''Des Koala''',
	'''Des Lacooda''',
	'''Des Wombat''',
	'''Desert Sunlight''',
	'''Destiny Draw''',
	'''Destiny HERO - Celestial''',
	'''Destiny HERO - Dasher''',
	'''Destiny HERO - Destroyer Phoenix Enforcer''',
	'''Destiny HERO - Diamond Dude''',
	'''Destiny HERO - Disk Commander''',
	'''Destiny HERO - Fear Monger''',
	'''Destiny HERO - Malicious''',
	'''Dharc the Dark Charmer, Gloomy''',
	'''Diabellstar the Black Witch''',
	'''Diamond Dire Wolf''',
	'''Dian Keto the Cure Master''',
	'''Dictator of D.''',
	'''Dimension Conjurer''',
	'''Dimension Fusion''',
	'''Dimension Shifter''',
	'''Dimension Wall''',
	'''Dimensional Barrier''',
	'''Dimensional Fissure''',
	'''Dimensional Prison''',
	'''Dingirsu, the Orcust of the Evening Star''',
	'''Dinomight Knight, the True Dracofighter''',
	'''Dinoster Power, the Mighty Dracoslayer''',
	'''Dinowrestler Capaptera''',
	'''Dinowrestler Pankratops''',
	'''Dinowrestler Valeonyx''',
	'''Disciple of Nephthys''',
	'''Divine Arsenal AA-ZEUS - Sky Thunder''',
	'''Divine Dragon Knight Felgrand''',
	'''Divine Temple of the Snake-Eye''',
	'''Divine Wrath''',
	'''DNA Surgery''',
	'''Dominus Impulse''',
	'''Don Zaloog''',
	'''Doom Dozer''',
	'''Doomcaliber Knight''',
	'''Doomkaiser Dragon''',
	'''Downerd Magician''',
	'''Draco Face-Off''',
	'''Dracoback, the Rideable Dragon''',
	'''Dragged Down into the Grave''',
	'''Dragon Ravine''',
	'''Dragon Shrine''',
	'''Dragon's Mirror''',
	'''Dragon's Rage''',
	'''Dragoness the Wicked Knight''',
	'''Dragonic Diagram''',
	'''Dragunity Corsesca''',
	'''Dream Clown''',
	'''Drillroid''',
	'''Droll & Lock Bird''',
	'''Drop Off''',
	'''Dunames Dark Witch''',
	'''Dupe Frog''',
	'''Dust Tornado''',
	'''Earth Effigy''',
	'''Earthbound Spirit''',
	'''Effect Veiler''',
	'''Ehther the Heavenly Monarch''',
	'''Eidos the Underworld Monarch''',
	'''Eidos the Underworld Squire''',
	'''El Shaddoll Anoyatyllis''',
	'''El Shaddoll Apkallone''',
	'''El Shaddoll Construct''',
	'''El Shaddoll Fusion''',
	'''El Shaddoll Grysta''',
	'''El Shaddoll Shekhinaga''',
	'''El Shaddoll Wendigo''',
	'''El Shaddoll Winda''',
	'''Elder Entity Norden''',
	'''Electric Snake''',
	'''Electric Virus''',
	'''Elemental HERO Blazeman''',
	'''Elemental HERO Clayman''',
	'''Elemental HERO Flame Wingman''',
	'''Elemental HERO Prisma''',
	'''Elemental HERO Stratos''',
	'''Elemental HERO Wildheart''',
	'''Elemental HERO Woodsman''',
	'''Emergency Provisions''',
	'''Emergency Teleport''',
	'''Emilia, Dance Priestess of the Nekroz''',
	'''Emissary of the Afterlife''',
	'''Empress Judge''',
	'''Enemy Controller''',
	'''Envoy of Chaos''',
	'''Eradicator Epidemic Virus''',
	'''Erebus the Underworld Monarch''',
	'''Escape from the Dark Dimension''',
	'''Evening Twilight Knight''',
	'''Evenly Matched''',
	'''Evilswarm Exciton Knight''',
	'''Evilswarm Heliotrope''',
	'''Evilswarm Ketos''',
	'''Evolzar Laggia''',
	'''Exa, Enforcer of the Nekroz''',
	'''Exarion Universe''',
	'''Exchange''',
	'''Exchange of the Spirit''',
	'''Exiled Force''',
	'''Exodia the Forbidden One''',
	'''Ext Ryzeal''',
	'''Fabled Lurrie''',
	'''Fairy Tail - Snow''',
	'''Fairy Wind''',
	'''Fake Trap''',
	'''Fallen of Albaz''',
	'''Familiar-Possessed - Aussa''',
	'''Familiar-Possessed - Eria''',
	'''Familiar-Possessed - Hiita''',
	'''Familiar-Possessed - Wynn''',
	'''Fantastical Dragon Phantazmay''',
	'''Farfa, Malebranche of the Burning Abyss''',
	'''Fateful Adventure''',
	'''Fiber Jar''',
	'''Fiend Griefing''',
	'''Fiend Skull Dragon''',
	'''Fiendish Chain''',
	'''Fiendsmith Engraver''',
	'''Fiendsmith's Lacrima''',
	'''Fiendsmith's Requiem''',
	'''Fiendsmith's Sequence''',
	'''Fiendsmith's Tract''',
	'''Fighting Flame Swordsman''',
	'''Final Flame''',
	'''Fire Formation - Tenki''',
	'''Fire Hand''',
	'''Fire King High Avatar Kirin''',
	'''Fire Lake of the Burning Abyss''',
	'''Firewall Dragon''',
	'''Fissure''',
	'''Flame Bufferlo''',
	'''Flame Ghost''',
	'''Flame Swordsman''',
	'''Flamvell Guard''',
	'''Flip Flop Frog''',
	'''Floodgate Trap Hole''',
	'''Flying "C"''',
	'''Flying Kamakiri #1''',
	'''Foolish Burial''',
	'''Forbidden Apocrypha''',
	'''Forbidden Chalice''',
	'''Forbidden Droplet''',
	'''Forbidden Lance''',
	'''Formula Synchron''',
	'''Fossil Dyna Pachycephalo''',
	'''Frontier Wiseman''',
	'''Full House''',
	'''Fusilier Dragon, the Dual-Mode Beast''',
	'''Fusion Destiny''',
	'''Fusion Devourer''',
	'''Fusion Substitute''',
	'''Gagaga Cowboy''',
	'''Gagagigo''',
	'''Gaia Knight, the Force of Earth''',
	'''Gaia Power''',
	'''Gaia the Dragon Champion''',
	'''Gaia The Fierce Knight''',
	'''Galatea, the Orcust Automaton''',
	'''Galaxy Cyclone''',
	'''Gameciel, the Sea Turtle Kaiju''',
	'''Garoth, Lightsworn Warrior''',
	'''Garura, Wings of Resonant Life''',
	'''Gatling Dragon''',
	'''Gear Golem the Moving Fortress''',
	'''Gearfried the Iron Knight''',
	'''Gearfried the Red-Eyes Iron Knight''',
	'''Gem-Armadillo''',
	'''Gem-Elephant''',
	'''Gem-Knight Alexandrite''',
	'''Gem-Knight Emerald''',
	'''Gem-Knight Garnet''',
	'''Gem-Knight Hollowcore''',
	'''Gem-Knight Lady Rose Diamond''',
	'''Gem-Knight Nepyrim''',
	'''Gem-Knight Prismaura''',
	'''Gem-Knight Quartz''',
	'''Gem-Knight Ruby''',
	'''Gem-Knight Sapphire''',
	'''Gem-Knight Tourmaline''',
	'''Gem-Knight Zirconia''',
	'''Gem-Turtle''',
	'''Gemini Elf''',
	'''Gemini Imps''',
	'''Gene-Warped Warwolf''',
	'''Genta, Gateman of Dark World''',
	'''Ghost Belle & Haunted Mansion''',
	'''Ghost Mourner & Moonlit Chill''',
	'''Ghost Ogre & Snow Rabbit''',
	'''Ghost Reaper & Winter Cherries''',
	'''Ghost Sister & Spooky Dogwood''',
	'''Giant Germ''',
	'''Giant Orc''',
	'''Giant Rat''',
	'''Giant Red Seasnake''',
	'''Giant Soldier of Stone''',
	'''Giant Trunade''',
	'''Giga-Tech Wolf''',
	'''Gigantes''',
	'''Gigantic Spright''',
	'''Gil Garth''',
	'''Gilasaurus''',
	'''Giltia the D. Knight - Soul Spear''',
	'''Gishki Abyss''',
	'''Gishki Ariel''',
	'''Gishki Avance''',
	'''Gishki Beast''',
	'''Gishki Chain''',
	'''Gishki Emilia''',
	'''Gishki Grimness''',
	'''Gishki Marker''',
	'''Gishki Natalia''',
	'''Gishki Noellia''',
	'''Gishki Shadow''',
	'''Gishki Vanity''',
	'''Gishki Vision''',
	'''Gladiator Beast Bestiari''',
	'''Gladiator Beast Darius''',
	'''Gladiator Beast Gaiodiaz''',
	'''Gladiator Beast Gyzarus''',
	'''Gladiator Beast Heraklinos''',
	'''Gladiator Beast Laquari''',
	'''Gladiator Beast Murmillo''',
	'''Goblin Attack Force''',
	'''Goblin Elite Attack Force''',
	'''Goblin Pothole Squad''',
	'''Goblin Zombie''',
	'''Gokipon''',
	'''Gold Sarcophagus''',
	'''Goldd, Wu-Lord of Dark World''',
	'''Golem Sentry''',
	'''Gora Turtle''',
	'''Gorz the Emissary of Darkness''',
	'''Gottoms' Emergency Call''',
	'''Goyo Guardian''',
	'''Graceful Charity''',
	'''Graff, Malebranche of the Burning Abyss''',
	'''Granguignol the Dusk Dragon''',
	'''Granmarg the Mega Monarch''',
	'''Granmarg the Rock Monarch''',
	'''Grapha, Dragon Lord of Dark World''',
	'''Grapha, Dragon Overlord of Dark World''',
	'''Gravekeeper's Assailant''',
	'''Gravekeeper's Guard''',
	'''Gravekeeper's Spear Soldier''',
	'''Gravekeeper's Spy''',
	'''Gravekeeper's Watcher''',
	'''Gravity Bind''',
	'''Great White''',
	'''Green Ninja''',
	'''Gren, Tactician of Dark World''',
	'''Guardian Sphinx''',
	'''Guardragon Garmides''',
	'''Guiding Ariadne''',
	'''Gunkan Suship Shari''',
	'''Gyaku-Gire Panda''',
	'''Gyakutenno Megami''',
	'''Hallowed Life Barrier''',
	'''Hammer Shot''',
	'''Hand of Nephthys''',
	'''Hane-Hane''',
	'''Hanewata''',
	'''Harpie's Feather Duster''',
	'''Heart of the Blue-Eyes''',
	'''Heavy Storm''',
	'''Heavy Storm Duster''',
	'''Herald of Orange Light''',
	'''Herald of the Arc Light''',
	'''Hieracosphinx''',
	'''Hiita the Fire Charmer, Ablaze''',
	'''Honest''',
	'''Horn of Heaven''',
	'''Horn of the Phantom Beast''',
	'''Howling Insect''',
	'''Humanoid Slime''',
	'''Hydrogeddon''',
	'''Hyper Hammerhead''',
	'''I:P Masquerena''',
	'''Icarus Attack''',
	'''Ice Hand''',
	'''Ice Knight''',
	'''Ice Ryzeal''',
	'''Ignister Prominence, the Blasting Dracoslayer''',
	'''Illusion of Chaos''',
	'''Illusory Snatcher''',
	'''Imperial Iron Wall''',
	'''Imperial Order''',
	'''Inaba White Rabbit''',
	'''Incredible Ecclesia, the Virtuous''',
	'''Indomitable Fighter Lei Lei''',
	'''Infernalqueen Salmon''',
	'''Infernity Archfiend''',
	'''Infernity Barrier''',
	'''Infernity Beetle''',
	'''Infernity Inferno''',
	'''Infernity Launcher''',
	'''Infernity Necromancer''',
	'''Infernoid Decatron''',
	'''Infernoid Harmadik''',
	'''Infernoid Patrulea''',
	'''Infinite Impermanence''',
	'''Injection Fairy Lily''',
	'''Inpachi''',
	'''Insect Knight''',
	'''Instant Fusion''',
	'''Interrupted Kaiju Slumber''',
	'''Island Turtle''',
	'''Isolde, Two Tales of the Noble Knights''',
	'''Jar of Greed''',
	'''Jinzo''',
	'''Jioh the Gravity Ninja''',
	'''Jirai Gumo''',
	'''Jongleur-Ghoul Illusionist''',
	'''Jowgen the Spiritualist''',
	'''Judge Man''',
	'''Judgment Dragon''',
	'''Jurrac Guaiba''',
	'''Just Desserts''',
	'''Kabazauls''',
	'''Kagemusha of the Six Samurai''',
	'''Kagero the Cannon Ninja''',
	'''Kaibaman''',
	'''Kaiser Sea Horse''',
	'''Karma Cut''',
	'''Kashtira Birth''',
	'''Kashtira Fenrir''',
	'''Kashtira Riseheart''',
	'''Kashtira Unicorn''',
	'''Kashtiratheosis''',
	'''Keeper of Dragon Magic''',
	'''Keeper of the Shrine''',
	'''Kelbek the Ancient Vanguard''',
	'''Keldo the Sacred Protector''',
	'''King Dragun''',
	'''King of the Feral Imps''',
	'''King of the Swamp''',
	'''King Tiger Wanghu''',
	'''Knightmare Cerberus''',
	'''Knightmare Goblin''',
	'''Knightmare Phoenix''',
	'''Knightmare Unicorn''',
	'''Kozmo Dark Destroyer''',
	'''Kozmo Farmgirl''',
	'''Kozmo Sliprider''',
	'''Kozmo Tincan''',
	'''Kozmojo''',
	'''Kozmoll Wickedwitch''',
	'''Kozmotown''',
	'''Krebons''',
	'''Kumongous, the Sticky String Kaiju''',
	'''Kuriboh''',
	'''Kurikara Divincarnate''',
	'''Kycoo the Ghost Destroyer''',
	'''La Jinn the Mystical Genie of the Lamp''',
	'''Labrynth Archfiend''',
	'''Labyrinth Tank''',
	'''Lacrima the Crimson Tears''',
	'''Lady Ninja Yae''',
	'''Lancer Archfiend''',
	'''Last Will''',
	'''Leeching the Light''',
	'''Left Arm of the Forbidden One''',
	'''Left Leg of the Forbidden One''',
	'''Legacy of Yata-Garasu''',
	'''Legendary Jujitsu Master''',
	'''Legendary Six Samurai - Kizan''',
	'''Leotron''',
	'''Lesser Fiend''',
	'''Level Limit - Area B''',
	'''Levia-Dragon - Daedalus''',
	'''Leviair the Sea Dragon''',
	'''Libic, Malebranche of the Burning Abyss''',
	'''Light and Darkness Dragon''',
	'''Light of Intervention''',
	'''Light-Imprisoning Mirror''',
	'''Lightning Storm''',
	'''Lightning Vortex''',
	'''Lightning, Dragon Ruler of Drafts''',
	'''Lightpulsar Dragon''',
	'''Limiter Removal''',
	'''Link Spider''',
	'''Linkuriboh''',
	'''Lonefire Blossom''',
	'''Lord of D.''',
	'''Lubellion the Searing Dragon''',
	'''Lucent, Netherlord of Dark World''',
	'''Lucius the Shadow Vassal''',
	'''Lullaby of Obedience''',
	'''Lumina, Lightsworn Summoner''',
	'''Lunalight Black Sheep''',
	'''Luster Dragon''',
	'''Luster Pendulum, the Dracoslayer''',
	'''Lyla, Lightsworn Sorceress''',
	'''M-X-Saber Invoker''',
	'''Machine Duplication''',
	'''Macro Cosmos''',
	'''Mad Archfiend''',
	'''Mad Dog of Darkness''',
	'''Maestroke the Symphony Djinn''',
	'''Mage Power''',
	'''Magic Cylinder''',
	'''Magic Deflector''',
	'''Magic Jammer''',
	'''Magical Abductor''',
	'''Magical Android''',
	'''Magical Dimension''',
	'''Magical Merchant''',
	'''Magical Scientist''',
	'''Magician of Dark Illusion''',
	'''Magician of Faith''',
	'''Magician's Circle''',
	'''Magician's Robe''',
	'''Magician's Rod''',
	'''Magician's Valkyria''',
	'''Magicians' Souls''',
	'''Magikuriboh''',
	'''Maiden of the Aqua''',
	'''Maiden of White''',
	'''Maiden with Eyes of Blue''',
	'''Majespecter Raccoon - Bunbuku''',
	'''Majespecter Unicorn - Kirin''',
	'''Majester Paladin, the Ascending Dracoslayer''',
	'''Majesty's Fiend''',
	'''Makyura the Destructor''',
	'''Malefic Blue-Eyes White Dragon''',
	'''Malefic Cyber End Dragon''',
	'''Malefic Red-Eyes Black Dragon''',
	'''Malevolent Catastrophe''',
	'''Maliss in Underground''',
	'''Maliss P Dormouse''',
	'''Maliss P White Rabbit''',
	'''Man-Eater Bug''',
	'''Manju of the Ten Thousand Hands''',
	'''Manticore of Darkness''',
	'''Marauding Captain''',
	'''Mask of Darkness''',
	'''Mask of Restrict''',
	'''Masked Dragon''',
	'''Masked Ninja Ebisu''',
	'''Masked Sorcerer''',
	'''Master Hyperion''',
	'''Master of Chaos''',
	'''Master of Oz''',
	'''Master Peace, the True Dracoslaying King''',
	'''Master Pendulum, the Dracoslayer''',
	'''Master with Eyes of Blue''',
	'''Mataza the Zapper''',
	'''Mathematician''',
	'''Matriarch of Nephthys''',
	'''Maxx "C"''',
	'''Mecha Phantom Beast Dracossack''',
	'''Mechanicalchaser''',
	'''Megalosmasher X''',
	'''Megamorph''',
	'''Meizen the Battle Ninja''',
	'''Mekk-Knight Avram''',
	'''Mereologic Aggregator''',
	'''Mermaid Knight''',
	'''Mermail Abyssgaios''',
	'''Mermail Abyssgunde''',
	'''Mermail Abysslinde''',
	'''Mermail Abyssmegalo''',
	'''Mermail Abysspike''',
	'''Mermail Abyssteus''',
	'''Mermail Abysstrite''',
	'''Mermail Abyssturge''',
	'''Messenger of Peace''',
	'''Metal Reflect Slime''',
	'''Metalflame Swordsman''',
	'''Metalfoes Goldriver''',
	'''Metalfoes Silverd''',
	'''Metalfoes Steelen''',
	'''Metalfoes Volflame''',
	'''Metaltronus''',
	'''Metamorphosis''',
	'''Meteor Black Comet Dragon''',
	'''Meteor Dragon''',
	'''Mezuki''',
	'''Milus Radiant''',
	'''Minar''',
	'''Mind Control''',
	'''Mind Crush''',
	'''Mind Protector''',
	'''Mine Golem''',
	'''Miracle Restoring''',
	'''Mirage Dragon''',
	'''Mirage Knight''',
	'''Mirage of Nightmare''',
	'''Mirage Swordsman''',
	'''Mirror Force''',
	'''Mirror of Oaths''',
	'''Missus Radiant''',
	'''Mist Wurm''',
	'''Mistake''',
	'''Mitsu the Insect Ninja''',
	'''Moai Interceptor Cannons''',
	'''Mobius the Frost Monarch''',
	'''Mobius the Mega Monarch''',
	'''Monk of the Tenyi''',
	'''Monster Gate''',
	'''Monster Reborn''',
	'''Monster Reincarnation''',
	'''Moon of the Closed Heaven''',
	'''Morphing Jar''',
	'''Morphing Jar #2''',
	'''Mother Grizzly''',
	'''Mudora the Sword Oracle''',
	'''Mudragon of the Swamp''',
	'''Muka Muka''',
	'''Mulcharmy Fuwalos''',
	'''Mulcharmy Meowls''',
	'''Mulcharmy Purulia''',
	'''My Body as a Shield''',
	'''Mystery Shell Dragon''',
	'''Mystic Mine''',
	'''Mystic Swordsman LV2''',
	'''Mystic Swordsman LV4''',
	'''Mystic Tomato''',
	'''Mystical Elf''',
	'''Mystical Elf - White Lightning''',
	'''Mystical Space Typhoon''',
	'''Mystik Wok''',
	'''Naelshaddoll Ariel''',
	'''Necro Gardna''',
	'''Necrovalley''',
	'''Needle Ceiling''',
	'''Neko Mane King''',
	'''Nekroz Cycle''',
	'''Nekroz Kaleidoscope''',
	'''Nekroz Mirror''',
	'''Nekroz of Brionac''',
	'''Nekroz of Clausolas''',
	'''Nekroz of Unicore''',
	'''Nekroz of Valkyrus''',
	'''Neo Bug''',
	'''Neo Kaiser Sea Horse''',
	'''Neo the Magic Swordsman''',
	'''Neo-Spacian Dark Panther''',
	'''Newdoria''',
	'''Nibiru, the Primal Being''',
	'''Night Assailant''',
	'''Night Beam''',
	'''Nightmare Magician''',
	'''Nightmare Wheel''',
	'''Nightmare's Steelcage''',
	'''Nimble Angler''',
	'''Nimble Beaver''',
	'''Nimble Momonga''',
	'''Nin-Ken Dog''',
	'''Ninja Grandmaster Hanzo''',
	'''Ninja Grandmaster Sasuke''',
	'''Nobleman of Crossout''',
	'''Nobleman of Extermination''',
	'''Number 101: Silent Honor ARK''',
	'''Number 11: Big Eye''',
	'''Number 17: Leviathan Dragon''',
	'''Number 30: Acid Golem of Destruction''',
	'''Number 39: Utopia''',
	'''Number 41: Bagooska the Terribly Tired Tapir''',
	'''Number 66: Master Key Beetle''',
	'''Offerings to the Doomed''',
	'''Ojama King''',
	'''Ojama Trio''',
	'''Ookazi''',
	'''Oppressed People''',
	'''Opticlops''',
	'''Orcust Cymbal Skeleton''',
	'''Orcust Harp Horror''',
	'''Orcust Knightmare''',
	'''Orcustrated Return''',
	'''Original Sinful Spoils - Snake-Eye''',
	'''Overload Fusion''',
	'''Painful Choice''',
	'''Painful Decision''',
	'''Paladin of White Dragon''',
	'''Paleozoic Anomalocaris''',
	'''Paleozoic Canadia''',
	'''Paleozoic Dinomischus''',
	'''Paleozoic Marrella''',
	'''Paleozoic Olenoides''',
	'''Paleozoic Opabinia''',
	'''Palladium Oracle Mahad''',
	'''Pantheism of the Monarchs''',
	'''Parl, Hermit of Dark World''',
	'''Penguin Knight''',
	'''Penguin Ninja''',
	'''Performage Damage Juggler''',
	'''Performage Hat Tricker''',
	'''Performage Mirror Conductor''',
	'''Performage Plushfire''',
	'''Performage Trapeze Magician''',
	'''Performage Trick Clown''',
	'''Performapal Guitartle''',
	'''Performapal Lizardraw''',
	'''Performapal Monkeyboard''',
	'''Performapal Pendulum Sorcerer''',
	'''Performapal Silver Claw''',
	'''Performapal Skullcrobat Joker''',
	'''Phantom Gryphon''',
	'''Phantom Knights' Fog Blade''',
	'''Phoenix Wing Wind Blast''',
	'''Pikeru's Circle of Enchantment''',
	'''Pinch Hopper''',
	'''Pitch-Black Power Stone''',
	'''Plaguespreader Zombie''',
	'''Poison of the Old Man''',
	'''Polymerization''',
	'''Pot of Avarice''',
	'''Pot of Desires''',
	'''Pot of Duality''',
	'''Pot of Generosity''',
	'''Pot of Greed''',
	'''Pot of Prosperity''',
	'''Prank-Kids Dodo-Doodle-Doo''',
	'''Prank-Kids Dropsies''',
	'''Prank-Kids Fansies''',
	'''Prank-Kids Lampsies''',
	'''Prank-Kids Place''',
	'''Prank-Kids Rocksies''',
	'''Predaplant Dragostapelia''',
	'''Predaplant Verte Anaconda''',
	'''Premature Burial''',
	'''Pressured Planet Wraitsoth''',
	'''Prevent Rat''',
	'''Prickle Fairy''',
	'''Priestess with Eyes of Blue''',
	'''Primal Dragon, the Primordial''',
	'''Primeval Planet Perlereino''',
	'''Princess of Tsurugi''',
	'''Prohibition''',
	'''Promethean Princess, Bestower of Flames''',
	'''Protector of the Sanctuary''',
	'''Protector with Eyes of Blue''',
	'''Psi-Blocker''',
	'''PSY-Frame Driver''',
	'''PSY-Framegear Gamma''',
	'''Pulling the Rug''',
	'''Punished Eagle''',
	'''Puppet Plant''',
	'''Pyramid Turtle''',
	'''Qadshaddoll Keios''',
	'''Qliphort Carrier''',
	'''Qliphort Disk''',
	'''Qliphort Helix''',
	'''Qliphort Scout''',
	'''Raigeki''',
	'''Raigeki Break''',
	'''Raiza the Mega Monarch''',
	'''Raiza the Storm Monarch''',
	'''Reactan, Dragon Ruler of Pebbles''',
	'''Reaper on the Nightmare''',
	'''Reasoning''',
	'''Reborn Tengu''',
	'''Reckless Greed''',
	'''Red Dragon Archfiend''',
	'''Red Dragon Ninja''',
	'''Red Reboot''',
	'''Red-Eyes Alternative Black Dragon''',
	'''Red-Eyes Baby Dragon''',
	'''Red-Eyes Black Dragon''',
	'''Red-Eyes Black Dragon Sword''',
	'''Red-Eyes Black Fullmetal Dragon''',
	'''Red-Eyes Black Metal Dragon''',
	'''Red-Eyes Black Meteor Dragon''',
	'''Red-Eyes Darkness Metal Dragon''',
	'''Red-Eyes Retro Dragon''',
	'''Red-Eyes Slash Dragon''',
	'''Red-Eyes Soul''',
	'''Red-Eyes Toon Dragon''',
	'''Red-Eyes Wyvern''',
	'''Red-Eyes Zombie Dragon''',
	'''Redox, Dragon Ruler of Boulders''',
	'''Reeshaddoll Wendi''',
	'''Reflect Bounder''',
	'''Reign-Beaux, Overking of Dark World''',
	'''Reign-Beaux, Overlord of Dark World''',
	'''Reinforcement of the Army''',
	'''Reinforcements''',
	'''Relinkuriboh''',
	'''Relinquished''',
	'''Relinquished Anima''',
	'''Reload''',
	'''Remove Trap''',
	'''Renge, Gatekeeper of Dark World''',
	'''Rescue Cat''',
	'''Rescue Rabbit''',
	'''Retaliating "C"''',
	'''Return from the Different Dimension''',
	'''Rider of the Storm Winds''',
	'''Right Arm of the Forbidden One''',
	'''Right Leg of the Forbidden One''',
	'''Ring of Destruction''',
	'''Rising Air Current''',
	'''Rite of Aramesir''',
	'''Rivalry of Warlords''',
	'''Roaring Ocean Snake''',
	'''Robbin' Goblin''',
	'''Ronintoadin''',
	'''Roulette Barrel''',
	'''Royal Decree''',
	'''Royal Magical Library''',
	'''Royal Oppression''',
	'''Rubic, Malebranche of the Burning Abyss''',
	'''Runick Destruction''',
	'''Runick Flashing Fire''',
	'''Runick Freezing Curses''',
	'''Runick Tip''',
	'''Rush Recklessly''',
	'''Ryko, Lightsworn Hunter''',
	'''Ryu Kokki''',
	'''Ryu Senshi''',
	'''Ryzeal Cross''',
	'''Ryzeal Detonator''',
	'''Ryzeal Duo Drive''',
	'''S:P Little Knight''',
	'''Saber Beetle''',
	'''Sabersaurus''',
	'''Sacred Crane''',
	'''Sacred Phoenix of Nephthys''',
	'''Sacred Sword of Seven Stars''',
	'''Sage with Eyes of Blue''',
	'''Sakuretsu Armor''',
	'''Salamandra, the Flying Flame Dragon''',
	'''Salamangreat Balelynx''',
	'''Salamangreat Foxy''',
	'''Salamangreat Raging Phoenix''',
	'''Salamangreat Spinny''',
	'''Salamangreat Sunlight Wolf''',
	'''Salvage''',
	'''Sand Moth''',
	'''Sangan''',
	'''Sangen Kaimen''',
	'''Sangen Summoning''',
	'''Saqlifice''',
	'''Sasuke Samurai''',
	'''Sasuke Samurai #4''',
	'''Scapegoat''',
	'''Scarm, Malebranche of the Burning Abyss''',
	'''Scarr, Scout of Dark World''',
	'''Scrap Dragon''',
	'''Sea Serpent Warrior of Darkness''',
	'''Second Coin Toss''',
	'''Secret Barrel''',
	'''Self-Destruct Button''',
	'''Senior Silver Ninja''',
	'''Senju of the Thousand Hands''',
	'''Serial Spell''',
	'''Serpentine Princess''',
	'''Seven Tools of the Bandit''',
	'''Shaddoll Beast''',
	'''Shaddoll Dragon''',
	'''Shaddoll Falco''',
	'''Shaddoll Fusion''',
	'''Shaddoll Hedgehog''',
	'''Shaddoll Hound''',
	'''Shaddoll Squamata''',
	'''Shadow-Imprisoning Mirror''',
	'''Shared Ride''',
	'''Shien's Smoke Signal''',
	'''Shining Angel''',
	'''Shiny Black "C"''',
	'''Shiny Black "C" Squadder''',
	'''Shrink''',
	'''Shuffle Reborn''',
	'''Shurit, Strategist of the Nekroz''',
	'''Sillva, Warlord of Dark World''',
	'''Silpheed''',
	'''Sinister Serpent''',
	'''Sinister Shadow Games''',
	'''Six Samurai United''',
	'''Skill Drain''',
	'''Skilled Dark Magician''',
	'''Skilled Red Magician''',
	'''Skilled White Magician''',
	'''Skull Dog Marron''',
	'''Skull Lair''',
	'''Sky Iris''',
	'''Sky Scout''',
	'''Sky Striker Ace - Kagari''',
	'''Sky Striker Ace - Raye''',
	'''Sky Striker Ace - Roze''',
	'''Sky Striker Ace - Shizuku''',
	'''Sky Striker Maneuver - Afterburners!''',
	'''Sky Striker Mecha - Hornet Drones''',
	'''Sky Striker Mecha - Shark Cannon''',
	'''Sky Striker Mecha - Widow Anchor''',
	'''Sky Striker Mobilize - Engage!''',
	'''Slate Warrior''',
	'''Smashing Ground''',
	'''Snake-Eye Ash''',
	'''Snake-Eye Birch''',
	'''Snake-Eye Oak''',
	'''Snake-Eyes Diabellstar''',
	'''Snake-Eyes Flamberge Dragon''',
	'''Snake-Eyes Poplar''',
	'''Snatch Steal''',
	'''Snipe Hunter''',
	'''Snowman Eater''',
	'''Snoww, Unlight of Dark World''',
	'''Solar Recharge''',
	'''Solemn Judgment''',
	'''Solemn Strike''',
	'''Solemn Warning''',
	'''Solemn Wishes''',
	'''Sonic Bird''',
	'''Soul Charge''',
	'''Soul Exchange''',
	'''Soul Taker''',
	'''Soul Tiger''',
	'''Spear Cretin''',
	'''Spear Dragon''',
	'''Speedroid Taketomborg''',
	'''Speedroid Terrortop''',
	'''Spell Canceller''',
	'''Spell Reproduction''',
	'''Spell Shattering Arrow''',
	'''Spellbook Magician of Prophecy''',
	'''Spellbook of Judgment''',
	'''Spellbook of Secrets''',
	'''Sphere Kuriboh''',
	'''Spirit of the Harp''',
	'''Spirit Reaper''',
	'''Spiritual Earth Art - Kurogane''',
	'''Spiritual Water Art - Aoi''',
	'''Spiritual Wind Art - Miyabi''',
	'''Spiritualism''',
	'''Spright Blue''',
	'''Spright Carrot''',
	'''Spright Elf''',
	'''Spright Jet''',
	'''Spright Red''',
	'''Spright Smashers''',
	'''Spright Sprind''',
	'''Spright Starter''',
	'''Stardust Dragon''',
	'''Starlight Road''',
	'''Stealth Bird''',
	'''Steelswarm Roach''',
	'''Stone Statue of the Aztecs''',
	'''Stop Defense''',
	'''Stream, Dragon Ruler of Droplets''',
	'''Strike Ninja''',
	'''Substitoad''',
	'''Summon Limit''',
	'''Summoned Skull''',
	'''Summoner Monk''',
	'''Summoner's Art''',
	'''Super Polymerization''',
	'''Super Rejuvenation''',
	'''Super Soldier Soul''',
	'''Super Starslayer TY-PHON - Sky Crisis''',
	'''Swap Frog''',
	'''Swarm of Locusts''',
	'''Swarm of Scarabs''',
	'''Swift Scarecrow''',
	'''Sword Ryzeal''',
	'''Swords of Revealing Light''',
	'''Swordsoul Blackout''',
	'''Swordsoul Emergence''',
	'''Swordsoul Grandmaster - Chixiao''',
	'''Swordsoul of Mo Ye''',
	'''Swordsoul of Taia''',
	'''Swordsoul Strategist Longyuan''',
	'''System Down''',
	'''T.A.D.P.O.L.E.''',
	'''T.G. Rush Rhino''',
	'''T.G. Striker''',
	'''T.G. Warwolf''',
	'''Tearlaments Cryme''',
	'''Tearlaments Havnis''',
	'''Tearlaments Heartbeat''',
	'''Tearlaments Kaleido-Heart''',
	'''Tearlaments Kashtira''',
	'''Tearlaments Kitkallos''',
	'''Tearlaments Merrli''',
	'''Tearlaments Reinoheart''',
	'''Tearlaments Rulkallos''',
	'''Tearlaments Scheiren''',
	'''Tearlaments Scream''',
	'''Tearlaments Sulliek''',
	'''Tellarknight Ptolemaeus''',
	'''Tempest Magician''',
	'''Tempest, Dragon Ruler of Storms''',
	'''Temtempo the Percussion Djinn''',
	'''Tenacity of the Monarchs''',
	'''Tenmataitei''',
	'''Tenpai Dragon Chundra''',
	'''Tenpai Dragon Fadra''',
	'''Tenyi Spirit - Adhara''',
	'''Tenyi Spirit - Ashuna''',
	'''Tenyi Spirit - Vishuda''',
	'''Terraforming''',
	'''Terrorking Salmon''',
	'''Tessera the Prime Squire''',
	'''Test Tiger''',
	'''TG1-EM1''',
	'''That Grass Looks Greener''',
	'''The Agent of Miracles - Jupiter''',
	'''The Agent of Mystery - Earth''',
	'''The Big March of Animals''',
	'''The Black Stone of Legend''',
	'''The Bystial Aluber''',
	'''The Bystial Lubellion''',
	'''The Dark - Hex-Sealed Fusion''',
	'''The Dark Magicians''',
	'''The Dragon Dwelling in the Cave''',
	'''The Earth - Hex-Sealed Fusion''',
	'''The Fiend Megacyber''',
	'''The Forceful Sentry''',
	'''The Forgiving Maiden''',
	'''The Golden Swordsoul''',
	'''The Last Warrior from Another Planet''',
	'''The Light - Hex-Sealed Fusion''',
	'''The Little Swordsman of Aile''',
	'''The Monarchs Stormforth''',
	'''The Phantom Knights of Ancient Cloak''',
	'''The Phantom Knights of Break Sword''',
	'''The Phantom Knights of Silent Boots''',
	'''The Prime Monarch''',
	'''The Tricky''',
	'''The White Stone of Ancients''',
	'''The White Stone of Legend''',
	'''The Wicked Worm Beast''',
	'''The Winged Dragon of Ra - Sphere Mode''',
	'''There Can Be Only One''',
	'''Thestalos the Firestorm Monarch''',
	'''Thestalos the Mega Monarch''',
	'''Thestalos the Shadowfire Monarch''',
	'''Thought Ruler Archfiend''',
	'''Thousand-Eyes Restrict''',
	'''Threatening Roar''',
	'''Throwstone Unit''',
	'''Thunder Dragon''',
	'''Thunder Dragon Colossus''',
	'''Thunder Dragon Titan''',
	'''Thunder Dragondark''',
	'''Thunder Dragonduo''',
	'''Thunder Dragonhawk''',
	'''Thunder Dragonlord''',
	'''Thunder Dragonmatrix''',
	'''Thunder Dragonroar''',
	'''Thunder King Rai-Oh''',
	'''Thunder Nyan Nyan''',
	'''Thunder Sea Horse''',
	'''Tidal, Dragon Ruler of Waterfalls''',
	'''Timaeus the United Dragon''',
	'''Time Seal''',
	'''Time-Space Trap Hole''',
	'''Titaniklad the Ash Dragon''',
	'''Tlakalel, His Malevolent Majesty''',
	'''Toadally Awesome''',
	'''Tobari the Sky Ninja''',
	'''Token Collector''',
	'''Toon Cannon Soldier''',
	'''Toon Cyber Dragon''',
	'''Toon Dark Magician Girl''',
	'''Toon Gemini Elf''',
	'''Toon Goblin Attack Force''',
	'''Toon Masked Sorcerer''',
	'''Toon Summoned Skull''',
	'''Toon Table of Contents''',
	'''Tornado Dragon''',
	'''Torrential Tribute''',
	'''Totem Bird''',
	'''Tour Guide From the Underworld''',
	'''Tradetoad''',
	'''Tragoedia''',
	'''Trap Dustshoot''',
	'''Trap Eater''',
	'''Trap Hole''',
	'''Trap Master''',
	'''Trap Stun''',
	'''Traptrix Arachnocampa''',
	'''Traptrix Atrax''',
	'''Traptrix Dionaea''',
	'''Traptrix Genlisea''',
	'''Traptrix Mantis''',
	'''Traptrix Myrmeleo''',
	'''Traptrix Nepenthes''',
	'''Traptrix Pudica''',
	'''Traptrix Rafflesia''',
	'''Traptrix Trap Hole Nightmare''',
	'''Traptrix Vesiculo''',
	'''Treeborn Frog''',
	'''Tremendous Fire''',
	'''Tri-Brigade Fraktall''',
	'''Tri-Brigade Kitt''',
	'''Tri-Brigade Nervall''',
	'''Tri-Brigade Revolt''',
	'''Tribe-Infecting Virus''',
	'''Tribute to the Doomed''',
	'''Trickstar Candina''',
	'''Trickstar Light Stage''',
	'''Trickstar Lycoris''',
	'''Trickstar Reincarnation''',
	'''Triple Tactics Talent''',
	'''Triple Tactics Thrust''',
	'''Trishula, Dragon of the Ice Barrier''',
	'''True Draco Heritage''',
	'''True King's Return''',
	'''Tsukuyomi''',
	'''Twilight Ninja Getsuga, the Shogun''',
	'''Twilight Ninja Nichirin, the Chunin''',
	'''Twilight Ninja Shingetsu''',
	'''Twin Twisters''',
	'''Twin-Headed Behemoth''',
	'''Twin-Headed Thunder Dragon''',
	'''Twister''',
	'''Typhoon''',
	'''UFO Turtle''',
	'''Ultimate Flame Swordsman''',
	'''Ultimate Insect LV3''',
	'''Ultimate Insect LV5''',
	'''Ultimate Insect LV7''',
	'''Ultimate Offering''',
	'''Ultimate Slayer''',
	'''United We Stand''',
	'''Upstart Goblin''',
	'''Upstart Golden Ninja''',
	'''Vampire Lord''',
	'''Vanity's Emptiness''',
	'''Vanity's Fiend''',
	'''Vector Pendulum, the Dracoverlord''',
	'''Vessel for the Dragon Cycle''',
	'''Virgil, Rock Star of the Burning Abyss''',
	'''Vision HERO Vyon''',
	'''Void Feast''',
	'''Void Vanishment''',
	'''Volcanic Scattershot''',
	'''Vorse Raider''',
	'''Waboku''',
	'''Wall of Illusion''',
	'''Wall of Revealing Light''',
	'''Wandering Gryphon Rider''',
	'''WANTED: Seeker of Sinful Spoils''',
	'''Water Enchantress of the Temple''',
	'''Wave-Motion Cannon''',
	'''Wavering Eyes''',
	'''White Dragon Ninja''',
	'''White Dragon Ritual''',
	'''White Dragon Wyverburster''',
	'''White Magical Hat''',
	'''White Night Dragon''',
	'''White Ninja''',
	'''Widespread Ruin''',
	'''Wind-Up Factory''',
	'''Wind-Up Magician''',
	'''Wind-Up Rabbit''',
	'''Wind-Up Rat''',
	'''Wind-Up Shark''',
	'''Wind-Up Zenmaines''',
	'''Witch of the Black Forest''',
	'''Wroughtweiler''',
	'''Wulf, Lightsworn Beast''',
	'''X-Head Cannon''',
	'''X-Saber Airbellum''',
	'''X-Saber Urbellum''',
	'''Xing Zhen Hu''',
	'''XX-Saber Boggart Knight''',
	'''XX-Saber Darksoul''',
	'''XX-Saber Emmersblade''',
	'''XX-Saber Faultroll''',
	'''XX-Saber Fulhelmknight''',
	'''XX-Saber Gottoms''',
	'''XX-Saber Hyunlei''',
	'''Xyz Encore''',
	'''Yata-Garasu''',
	'''Yellow Dragon Ninja''',
	'''Yellow Ninja''',
	'''Yomi Ship''',
	'''Zaborg the Thunder Monarch''',
	'''Zombie Master''',
	'''Zombie World''',
	'''Zombino''',
	'''Zombyra the Dark''',
	'''Zoodiac Barrage''',
	'''Zoodiac Boarbow''',
	'''Zoodiac Broadbull''',
	'''Zoodiac Chakanine''',
	'''Zoodiac Combo''',
	'''Zoodiac Drident''',
	'''Zoodiac Hammerkong''',
	'''Zoodiac Ramram''',
	'''Zoodiac Ratpier''',
	'''Zoodiac Thoroughblade''',
	'''Zoodiac Tigermortar''',
	'''Zoodiac Whiptail''',
	'''Zure, Knight of Dark World''',
]

pack_names = [
	'''TCG_2-Player Starter Set''',
	'''TCG_Absolute Powerforce''',
	'''TCG_Abyss Rising''',
	'''TCG_Age of Overlord''',
	'''TCG_Alliance Insight''',
	'''TCG_Ancient Prophecy''',
	'''TCG_Ancient Sanctuary''',
	'''TCG_Battle of Chaos''',
	'''TCG_Blazing Vortex''',
	'''TCG_Breakers of Shadow''',
	'''TCG_Burst of Destiny''',
	'''TCG_Chaos Impact''',
	'''TCG_Circuit Break''',
	'''TCG_Clash of Rebellions''',
	'''TCG_Code of the Duelist''',
	'''TCG_Cosmo Blazer''',
	'''TCG_Crimson Crisis''',
	'''TCG_Crossed Souls''',
	'''TCG_Crossroads of Chaos''',
	'''TCG_Cyber Dragon Revolution Structure Deck''',
	'''TCG_Cyberdark Impact''',
	'''TCG_Cybernetic Horizon''',
	'''TCG_Cybernetic Revolution''',
	'''TCG_Cyberstorm Access''',
	'''TCG_Dark Crisis''',
	'''TCG_Dark Legion Starter Deck''',
	'''TCG_Dark Neostorm''',
	'''TCG_Darkwing Blast''',
	'''TCG_Dawn of Majesty''',
	'''TCG_Dimension Force''',
	'''TCG_Dimension of Chaos''',
	'''TCG_Dinosmasher's Fury Structure Deck''',
	# '''TCG_Doom of Dimensions''',
	'''TCG_Dragons Collide Structure Deck''',
	'''TCG_Dragunity Legion Structure Deck''',
	'''TCG_Duelist Alliance''',
	'''TCG_Duelist Nexus''',
	'''TCG_Duelist Revolution''',
	'''TCG_Duelist's Advance''',
	'''TCG_Egyptian God Deck: Obelisk the Tormentor''',
	'''TCG_Egyptian God Deck: Slifer the Sky Dragon''',
	'''TCG_Elemental Energy''',
	'''TCG_Emperor of Darkness Structure Deck''',
	'''TCG_Enemy of Justice''',
	'''TCG_Eternity Code''',
	'''TCG_Extreme Force''',
	'''TCG_Extreme Victory''',
	'''TCG_Flames of Destruction''',
	'''TCG_Flaming Eternity''',
	'''TCG_Force of the Breaker''',
	'''TCG_Galactic Overlord''',
	'''TCG_Gates of the Underworld Structure Deck''',
	'''TCG_Geargia Rampage Structure Deck''',
	'''TCG_Generation Force''',
	'''TCG_Gladiator's Assault''',
	'''TCG_HERO Strike Structure Deck''',
	'''TCG_Ignition Assault''',
	'''TCG_Invasion of Chaos''',
	'''TCG_Invasion: Vengeance''',
	'''TCG_Judgment of the Light''',
	'''TCG_Labyrinth of Nightmare''',
	'''TCG_Legacy of Darkness''',
	'''TCG_Legacy of Destruction''',
	'''TCG_Legacy of the Valiant''',
	'''TCG_Legend of Blue Eyes White Dragon''',
	'''TCG_Light of Destruction''',
	'''TCG_Lightning Overdrive''',
	'''TCG_Lord of the Tachyon Galaxy''',
	'''TCG_Lost Sanctuary Structure Deck''',
	'''TCG_Machina Mayhem Structure Deck''',
	'''TCG_Machine Reactor Structure Deck''',
	'''TCG_Magician's Force''',
	'''TCG_Master of Pendulum Structure Deck''',
	'''TCG_Maximum Crisis''',
	'''TCG_Metal Raiders''',
	'''TCG_Onslaught of the Fire Kings Structure Deck''',
	'''TCG_Order of Chaos''',
	'''TCG_Pendulum Domination Structure Deck''',
	'''TCG_Phantom Darkness''',
	'''TCG_Phantom Nightmare''',
	'''TCG_Phantom Rage''',
	'''TCG_Pharaoh's Servant''',
	'''TCG_Pharaonic Guardian''',
	'''TCG_Photon Hypernova''',
	'''TCG_Photon Shockwave''',
	'''TCG_Power of the Duelist''',
	'''TCG_Power of the Elements''',
	'''TCG_Primal Origin''',
	'''TCG_Rage of the Abyss''',
	'''TCG_Raging Battle''',
	'''TCG_Raging Tempest''',
	'''TCG_Realm of Light Structure Deck''',
	'''TCG_Realm of the Sea Emperor Structure Deck''',
	'''TCG_Return of the Duelist''',
	'''TCG_Rise of Destiny''',
	'''TCG_Rise of the Dragon Lords Structure Deck''',
	'''TCG_Rise of the Duelist''',
	'''TCG_Rise of the True Dragons Structure Deck''',
	'''TCG_Rising Rampage''',
	'''TCG_Saber Force Starter Deck''',
	'''TCG_Saga of Blue-Eyes White Dragon Structure Deck''',
	'''TCG_Samurai Warlords Structure Deck''',
	'''TCG_Savage Strike''',
	'''TCG_Secrets of Eternity''',
	'''TCG_Shadow Specters''',
	'''TCG_Shadow of Infinity''',
	'''TCG_Shining Victories''',
	'''TCG_Soul Fusion''',
	'''TCG_Soul of the Duelist''',
	'''TCG_Spell Ruler''',
	'''TCG_Spellcaster's Command Structure Deck''',
	'''TCG_Stardust Overdrive''',
	'''TCG_Starstrike Blast''',
	'''TCG_Starter Deck 2006''',
	'''TCG_Starter Deck: Codebreaker''',
	'''TCG_Starter Deck: Dawn of the Xyz''',
	'''TCG_Starter Deck: Duelist Toolbox''',
	'''TCG_Starter Deck: Jaden Yuki''',
	'''TCG_Starter Deck: Joey''',
	'''TCG_Starter Deck: Kaiba''',
	'''TCG_Starter Deck: Kaiba Evolution''',
	'''TCG_Starter Deck: Kaiba Reloaded''',
	'''TCG_Starter Deck: Link Strike''',
	'''TCG_Starter Deck: Pegasus''',
	'''TCG_Starter Deck: Syrus Truesdale''',
	'''TCG_Starter Deck: Xyz Symphony''',
	'''TCG_Starter Deck: Yu-Gi-Oh! 5D's''',
	'''TCG_Starter Deck: Yu-Gi-Oh! 5D's 2009''',
	'''TCG_Starter Deck: Yugi''',
	'''TCG_Starter Deck: Yugi Evolution''',
	'''TCG_Starter Deck: Yugi Reloaded''',
	'''TCG_Starter Deck: Yuya''',
	'''TCG_Storm of Ragnarok''',
	'''TCG_Strike of Neos''',
	'''TCG_Structure Deck: Albaz Strike''',
	'''TCG_Structure Deck: Beware of Traptrix''',
	'''TCG_Structure Deck: Blaze of Destruction''',
	'''TCG_Structure Deck: Blue-Eyes White Destiny''',
	'''TCG_Structure Deck: Cyber Strike''',
	'''TCG_Structure Deck: Cyberse Link''',
	'''TCG_Structure Deck: Dark World''',
	'''TCG_Structure Deck: Dinosaur's Rage''',
	'''TCG_Structure Deck: Dragon's Roar''',
	'''TCG_Structure Deck: Fire Kings''',
	'''TCG_Structure Deck: Freezing Chains''',
	'''TCG_Structure Deck: Fury from the Deep''',
	'''TCG_Structure Deck: Invincible Fortress''',
	'''TCG_Structure Deck: Lair of Darkness''',
	'''TCG_Structure Deck: Legend of the Crystal Beasts''',
	'''TCG_Structure Deck: Lord of the Storm''',
	'''TCG_Structure Deck: Machine Re-Volt''',
	# '''TCG_Structure Deck: Marik''',
	'''TCG_Structure Deck: Mechanized Madness''',
	'''TCG_Structure Deck: Order of the Spellcasters''',
	'''TCG_Structure Deck: Powercode Link''',
	'''TCG_Structure Deck: Rokket Revolt''',
	'''TCG_Structure Deck: Sacred Beasts''',
	'''TCG_Structure Deck: Seto Kaiba''',
	'''TCG_Structure Deck: Shaddoll Showdown''',
	'''TCG_Structure Deck: Soulburner''',
	'''TCG_Structure Deck: Spellcaster's Judgment''',
	'''TCG_Structure Deck: Spirit Charmers''',
	'''TCG_Structure Deck: The Crimson King''',
	'''TCG_Structure Deck: Warrior's Triumph''',
	'''TCG_Structure Deck: Wave of Light''',
	'''TCG_Structure Deck: Yugi Muto''',
	'''TCG_Structure Deck: Zombie Horde''',
	'''TCG_Structure Deck: Zombie Madness''',
	'''TCG_Super Starter: Space-Time Showdown''',
	'''TCG_Super Starter: V for Victory''',
	'''TCG_Supreme Darkness''',
	'''TCG_Synchron Extreme Structure Deck''',
	'''TCG_Tactical Evolution''',
	'''TCG_The Dark Emperor Structure Deck''',
	'''TCG_The Dark Illusion''',
	'''TCG_The Duelist Genesis''',
	'''TCG_The Infinite Forbidden''',
	'''TCG_The Lost Millennium''',
	'''TCG_The New Challengers''',
	'''TCG_The Shining Darkness''',
	'''TCG_Warriors' Strike Structure Deck''',
	'''TCG_Zombie World Structure Deck''',
]

with open('ocg_sets.json', 'r') as f:
	data = json.load(f)
	for series in tqdm(data):
		for set_ in tqdm(pack_names):
			print(set_)
			try:
				set_url = data[series][set_[4:]]['image_url']
				res = requests.get(set_url)
				image = 'Sets/' + set_ + '.jpg'
				if not os.path.exists(image):
					with open(image, 'wb') as file:
						file.write(res.content)
						print(set_ + ' image written')
				outfile = 'Sets/Icons/' + re.sub(r'\W+', '_', set_).lower() + '_icon.jpg'
				if not os.path.exists(outfile):
					master = Image.new(
						mode='RGBA',
						size=(32, 32),
						color=(57,255,20,0))
					size = 32, 32
					im = Image.open(image)
					im.thumbnail(size, Image.Resampling.LANCZOS)
					pillow_width, pillow_height = im.size
					# Calculate the top-left coordinates for pasting
					paste_x = (32 - pillow_width) // 2
					paste_y = (32 - pillow_height) // 2
					master.paste(im, box=(paste_x,paste_y))
					master.save(outfile, "PNG")
					master = Image.open(outfile)
					master = master.convert(
						"P", palette=Image.ADAPTIVE, colors=15
					)
					master = move_palette_color(master, 15, 0)
					master.save(outfile, "PNG")
					subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
					print(set_ + ' icon written')
			except:
				pass

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
pack_counter = 1

for card_name in tqdm(card_names):
	for data in card_info_data['data']:
		if card_name == data['name']:
			YGO_C += 'const u8 gCardDescription_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + textwrap.fill(data['desc'].replace('"', '').replace('\r\n', '').replace('\n', '').replace("''", '').replace('[ ', '').replace(' ]', ':'), width=30).replace('\n', '\\n').replace('●', '-').replace('#', '') + '");\n'

for card_name in tqdm(card_names):
	for data in card_info_data['data']:
		if card_name == data['name']:
			YGO_C += '    [ITEM_CARD_' + re.sub(r'\W+', '_', data['name']).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = ' + str(card_counter) + ',\n'

YGO_C += '\t[ITEM_LIST_END] = 0,};\n\n'

pack_counter = 1
YGO_C += '\nconst u16 PackIdMapping[] = \n{\n'
for set_ in pack_names:
	YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = ' + str(pack_counter) + ',\n'
	pack_counter += 1

for format_ in formats:
    YGO_C += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = ' + str(pack_counter) + ',\n'
    pack_counter += 1

YGO_C += '};\n'

YGO_C_Output = open('src/ygo.c', 'w')
YGO_C_Output.write(YGO_C)
YGO_C_Output.close()
print('src/ygo.c written')

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

Set_Writer = open('sets.json', 'w', encoding='utf-8')
sets_write = {}
for set_ in tqdm(pack_names):
    print(set_)
    sets_write[set_] = {}
    for card in cards_by_pack:
        try:
            for set__ in cards_by_pack[card]['sets']['ja']:
                if set_[4:] == set__['set_name']:
                    sets_write[set_][card] = list()
                    for rarity in set__['rarities']:
                        sets_write[set_][card].append(rarity)
        except:
            pass
        try:
            for set__ in cards_by_pack[card]['sets']['en']:
                if set_[4:] == set__['set_name']:
                    sets_write[set_][card] = list()
                    for rarity in set__['rarities']:
                        sets_write[set_][card].append(rarity)
        except:
            pass

json.dump(dict(sorted(sets_write.items())), Set_Writer, indent=4)
Set_Writer.close()
print('sets.json written')

sets_print = ''
for set_ in tqdm(pack_names):
	print(set_)
	if set_[0:3] == 'TCG':
		sets_print += 'const struct PackContents gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + '[] =\n{\n'
		for card in cards_by_pack:
			if card in card_names:
				try:
					for set__ in cards_by_pack[card]['sets']['en']:
						if set__['set_name'] == set_[4:]:
							for rarity in set__['rarities']:
								sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', rarity).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '},\n'
				except:
					pass
		sets_print += '};\n\n'
	if set_[0:3] == 'OCG':
		sets_print += 'const struct PackContents gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + '[] =\n{\n'
		for card in cards_by_pack:
			if card in card_names:
				try:
					for set__ in cards_by_pack[card]['sets']['en']:
						if set__['set_name'] == set_[4:]:
							for rarity in set__['rarities']:
								sets_print += '\t{ITEM_CARD_' + re.sub(r'[^a-zA-Z0-9]', '_', card).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ', RARITY_' + re.sub(r'[^a-zA-Z0-9]', '_', rarity).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '},\n'
				except:
					pass
		sets_print += '};\n\n'

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

for set_ in pack_names:
    Scripts += '\t.2byte ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' 10\n' 
Scripts += '\n'

sets_print += '\nconst struct Pack gPacks[] =\n{\n'
card_count = 0
with open('sets.json', 'r') as f:
	data = json.load(f)
	for set_ in pack_names:
		if set_[0:3] == 'TCG':
			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] =\n\t{\n        .pack = gTCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + ',\n        .length = '
		else:
			sets_print += '\t[PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] =\n\t{\n        .pack = gOCG' + re.sub(r'[^a-zA-Z0-9]', '', set_[4:]) + ',\n        .length = '
		for card in data[set_]:
			if card in card_names:
				for rarity in data[set_][card]:
					card_count += 1
		sets_print += str(card_count)
		sets_print += ',\n\t},\n'
		card_count = 0

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

sets_print += '};\n'
PacksWrite = open('src/data/ygo/packs.h', 'w', encoding='utf-8')
PacksWrite.write(sets_print)
PacksWrite.close()
print('src/data/ygo/packs.h written')

card_count = 0
for set_ in pack_names:
	SRCDataItemDescs += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', set_) + 'Desc[] = _(\n    "' + textwrap.fill(set_[4:].replace('"', ''), width=16).replace('\n', '\\n"\n    "') + '.");\n\n'

for format_ in formats:
    SRCDataItemDescs += 'static const u8 s' + re.sub(r'[^a-zA-Z0-9]', '', format_) + 'Desc[] = _("' + textwrap.fill(format_, width=20).replace('\n', '\\n') + '.");\n\n'

SRCDataItemDescsWrite = open('src/data/text/item_descriptions.h', 'w', encoding='utf-8')
SRCDataItemDescsWrite.write(SRCDataItemDescs)
SRCDataItemDescsWrite.close()
print('src/data/text/item_descriptions.h written')

for card_name in card_names:
	for data in card_info_data['data']:
		if card_name == data['name']:
			gCardInfo += ('const u8 gCardName_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("' + card_name.replace('#', '').replace('"', '') + '");\n'
					+ 'const u8 gCardNameShort_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
			+ card_name[:19].replace('#', '').replace('"', '') + '");\n'
					+ 'const u8 gCardNameShortBag_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
			+ card_name[:26].replace('#', '').replace('"', '') + '");\n')
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
			card_counter += 1

Item_Constants += '\n'
for set_ in pack_names:
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(card_counter + 376) + '\n'
    card_counter += 1
Item_Constants += '\n'

for format_ in formats:
    Item_Constants += '#define ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(card_counter + 376) + '\n'
    card_counter += 1

for set_ in pack_names:
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
for set_ in pack_names:
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'

ItemIconTable += '\n'
for format_ in formats:
    ItemIconTable += '\t[ITEM_PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', format_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + '] = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},\n'

pack_counter = 1
YGO_Constants += '\n'
for set_ in pack_names:
	YGO_Constants += '#define PACK_' + re.sub(r'[^a-zA-Z0-9]', '_', set_).replace('__', '_').replace('__', '_').replace('★', ' ').replace('ū', 'u').replace('ō', 'o').replace('☆', ' ').replace('"', '').upper() + ' ' + str(pack_counter) + '\n'
	pack_counter += 1

YGO_Constants += '\n'
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
YGO_C += '\nconst u16 CardIdMapping[] = \n{\n\t    [ITEM_NONE] = 0,\n'
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

for set_ in pack_names:
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
			card_counter += 1

gCardInfo_Output = open('src/data/ygo/card_info.h', 'w')
gCardInfo_Output.write(gCardInfo)
gCardInfo_Output.close()
print('src/data/ygo/card_info.h written')