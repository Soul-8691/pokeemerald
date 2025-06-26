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

formats = ['Yugi-Kaiba', 'Critter', 'Treasure', 'Imperial', 'Android', 'Joey-Pegasus', 'Fiber', 'Yata', 'Scientist', 'Vampire', 'Chaos', 'Warrior', 'Goat', 'Cyber', 'Reaper', 'Chaos Return', 'Demise', 'Trooper', 'Zombie', 'Perfect Circle', 'DAD Return', 'Gladiator', 'TeleDAD', 'Cat', 'Edison', 'Frog', 'Starstrike', 'Tengu', 'Dino Rabbit', 'Wind-Up', 'Miami', 'Meadowlands', 'Baby Ruler', 'Ravine Ruler', 'Fire-Water', 'HAT', 'Vegas']

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
	"4-Starred Ladybug of Doom",
	"7 Colored Fish",
	"A Wingbeat of Giant Dragon",
	"Abyss Dweller",
	"Abyss Soldier",
	"Abyss-sphere",
	"Abyss-squall",
	"Accumulated Fortune",
	"Acid Trap Hole",
	"Adreus, Keeper of Armageddon",
	"Advanced Ritual Art",
	"Airknight Parshath",
	"Allure of Darkness",
	"Ally of Justice Catastor",
	"Ally of Justice Decisive Armor",
	"Amazoness Archer",
	"Ancient Fairy Dragon",
	"Ancient Gear Gadjiltron Dragon",
	"Ancient Sacred Wyvern",
	"Angel of Zera",
	"Anti-Spell Fragrance",
	"Apprentice Magician",
	"Aqua Madoor",
	"Aqua Spirit",
	"Arcanite Magician",
	"Archfiend Soldier",
	"Archlord Kristya",
	"Armades, Keeper of Boundaries",
	"Armageddon Knight",
	"Armored Kappa",
	"Armory Arm",
	"Artifact Beagalltach",
	"Artifact Durendal",
	"Artifact Ignition",
	"Artifact Moralltach",
	"Artifact Sanctum",
	"Artifact Scythe",
	"Asceticism of the Six Samurai",
	"Asura Priest",
	"Atlantean Dragoons",
	"Atlantean Heavy Infantry",
	"Atlantean Marksman",
	"Aurkus, Lightsworn Druid",
	"Autonomous Action Unit",
	"Avenging Knight Parshath",
	"Azure-Eyes Silver Dragon",
	"Bahamut Shark",
	"Banisher of the Light",
	"Banisher of the Radiance",
	"Barrel Behind the Door",
	"Battle Fader",
	"Battle Ox",
	"Bazoo the Soul-Eater",
	"Beast King Barbaros",
	"Beckoning Light",
	"Beelze Frog",
	"Berserk Gorilla",
	"Bickuribox",
	"Big Shield Gardna",
	"Black Horn of Heaven",
	"Black Luster Soldier - Envoy of the Beginning",
	"Black Rose Dragon",
	"Black Salvo",
	"Black Skull Dragon",
	"Black Whirlwind",
	"Blackwing - Blizzard the Far North",
	"Blackwing - Bora the Spear",
	"Blackwing - Gale the Whirlwind",
	"Blackwing - Kalut the Moon Shadow",
	"Blackwing - Shura the Blue Flame",
	"Blackwing - Silverwind the Ascendant",
	"Blackwing - Sirocco the Dawn",
	"Blackwing - Vayu the Emblem of Honor",
	"Blackwing Armed Wing",
	"Blackwing Armor Master",
	"Blade Armor Ninja",
	"Blade Knight",
	"Blast with Chain",
	"Blaster, Dragon Ruler of Infernos",
	"Blue Thunder T-45",
	"Blue-Eyes Ultimate Dragon",
	"Blue-Eyes White Dragon",
	"Book of Eclipse",
	"Book of Life",
	"Book of Moon",
	"Book of Taiyou",
	"Bottomless Trap Hole",
	"Brain Control",
	"Breaker the Magical Warrior",
	"Breakthrough Skill",
	"Brionac, Dragon of the Ice Barrier",
	"Brotherhood of the Fire Fist - Bear",
	"Brotherhood of the Fire Fist - Boar",
	"Brotherhood of the Fire Fist - Cardinal",
	"Brotherhood of the Fire Fist - Dragon",
	"Brotherhood of the Fire Fist - Gorilla",
	"Brotherhood of the Fire Fist - Tiger King",
	"Broww, Huntsman of Dark World",
	"Bujin Hirume",
	"Bujin Mikazuchi",
	"Bujin Yamato",
	"Bujincarnation",
	"Bujingi Crane",
	"Bujingi Hare",
	"Bujingi Quilin",
	"Bujingi Sinyou",
	"Bujingi Turtle",
	"Bujintei Kagutsuchi",
	"Bujintei Susanowo",
	"Burial from a Different Dimension",
	"Burner, Dragon Ruler of Sparks",
	"Caius the Shadow Monarch",
	"Call of the Haunted",
	"Cannon Soldier",
	"Card Destruction",
	"Card of Safe Return",
	"Card Trooper",
	"Cardcar D",
	"Cards for Black Feathers",
	"Cards from the Sky",
	"Cards of Consonance",
	"Castle of Dragon Souls",
	"Castle Walls",
	"Catapult Turtle",
	"Ceasefire",
	"Celestia, Lightsworn Angel",
	"Chain Disappearance",
	"Chain Energy",
	"Chain Strike",
	"Change of Heart",
	"Chaos Emperor Dragon - Envoy of the End",
	"Chaos Sorcerer",
	"Charge of the Light Brigade",
	"Charubin the Fire Knight",
	"Chimeratech Fortress Dragon",
	"Chimeratech Overdragon",
	"Chiron the Mage",
	"Chivalry",
	"Cipher Soldier",
	"Circle of the Fire Kings",
	"Closed Forest",
	"Coach Soldier Wolfbark",
	"Cold Wave",
	"Colossal Fighter",
	"Common Charity",
	"Compulsory Escape Device",
	"Compulsory Evacuation Device",
	"Confiscation",
	"Consecrated Light",
	"Constellar Algiedi",
	"Constellar Kaus",
	"Constellar Omega",
	"Constellar Pleiades",
	"Constellar Pollux",
	"Constellar Ptolemy M7",
	"Constellar Sombre",
	"Contract with the Abyss",
	"Corridor of Agony",
	"Crass Clown",
	"Creature Swap",
	"Crevice Into the Different Dimension",
	"Crimson Blader",
	"Crusader of Endymion",
	"Crush Card Virus",
	"Crystal Seer",
	"Cunning of the Six Samurai",
	"Cursed Seal of the Forbidden Spell",
	"Cyber Blader",
	"Cyber Dragon",
	"Cyber End Dragon",
	"Cyber Jar",
	"Cyber Ogre 2",
	"Cyber Phoenix",
	"Cyber Saurus",
	"Cyber Twin Dragon",
	"Cyber Valley",
	"Cyber-Stein",
	"D.D. Assailant",
	"D.D. Crow",
	"D.D. Designator",
	"D.D. Survivor",
	"D.D. Warrior",
	"D.D. Warrior Lady",
	"D.D.M. - Different Dimension Master",
	"D.D.R. - Different Dimension Reincarnation",
	"Daigusto Emeral",
	"Daigusto Phoenix",
	"Dandylion",
	"Dark Armed Dragon",
	"Dark Balter the Terrible",
	"Dark Blade the Dragon Knight",
	"Dark Bribe",
	"Dark Dust Spirit",
	"Dark Elf",
	"Dark End Dragon",
	"Dark Eruption",
	"Dark Flare Knight",
	"Dark Grepher",
	"Dark Hole",
	"Dark Magician of Chaos",
	"Dark Mimic LV3",
	"Dark Nephthys",
	"Dark Paladin",
	"Dark Ruler Ha Des",
	"Dark Smog",
	"Dark Strike Fighter",
	"Dark World Dealings",
	"Dark World Lightning",
	"Darkfire Dragon",
	"Darkflare Dragon",
	"Darklord Zerato",
	"De-Spell",
	"Debris Dragon",
	"Debunk",
	"Deck Devastation Virus",
	"Deck Lockdown",
	"Deep Dark Trap Hole",
	"Deep Sea Diva",
	"Deepsea Shark",
	"Dekoichi the Battlechanted Locomotive",
	"Delinquent Duo",
	"Delta Crow - Anti Reverse",
	"Demise, King of Armageddon",
	"Des Frog",
	"Des Koala",
	"Des Wombat",
	"Desert Sunlight",
	"Destiny Draw",
	"Destiny HERO - Dasher",
	"Destiny HERO - Defender",
	"Destiny HERO - Diamond Dude",
	"Destiny HERO - Disk Commander",
	"Destiny HERO - Dogma",
	"Destiny HERO - Doom Lord",
	"Destiny HERO - Fear Monger",
	"Destiny HERO - Malicious",
	"Destiny HERO - Plasma",
	"Dewloren, Tiger King of the Ice Barrier",
	"Diamond Dire Wolf",
	"Different Dimension Capsule",
	"Dimension Fusion",
	"Dimension Wall",
	"Dimensional Alchemist",
	"Dimensional Fissure",
	"Dimensional Prison",
	"Divine Dragon Knight Felgrand",
	"Divine Sword - Phoenix Blade",
	"Divine Wrath",
	"DNA Surgery",
	"Don Zaloog",
	"Doom Dozer",
	"Doomcaliber Knight",
	"Doomkaiser Dragon",
	"Double Cyclone",
	"Double-Edged Sword Technique",
	"Downerd Magician",
	"Dragged Down into the Grave",
	"Dragon Ravine",
	"Dragon Shrine",
	"Dragoness the Wicked Knight",
	"Dragonic Knight",
	"Dragunity Arma Mystletainn",
	"Dragunity Corsesca",
	"Dragunity Dux",
	"Dragunity Knight - Gae Dearg",
	"Dragunity Knight - Vajrayana",
	"Dragunity Phalanx",
	"Drill Warrior",
	"Drillroid",
	"Droll & Lock Bird",
	"Drop Off",
	"Dupe Frog",
	"Dust Tornado",
	"E - Emergency Call",
	"Eclipse Wyvern",
	"Effect Veiler",
	"Ehren, Lightsworn Monk",
	"Elder of the Six Samurai",
	"Electric Snake",
	"Electric Virus",
	"Elemental HERO Absolute Zero",
	"Elemental HERO Air Neos",
	"Elemental HERO Bubbleman",
	"Elemental HERO Chaos Neos",
	"Elemental HERO Dark Neos",
	"Elemental HERO Electrum",
	"Elemental HERO Flame Wingman",
	"Elemental HERO Gaia",
	"Elemental HERO Grand Neos",
	"Elemental HERO Mariner",
	"Elemental HERO Neos Alius",
	"Elemental HERO Ocean",
	"Elemental HERO Phoenix Enforcer",
	"Elemental HERO Prisma",
	"Elemental HERO Shining Flare Wingman",
	"Elemental HERO Stratos",
	"Elemental HERO Tempest",
	"Elemental HERO The Shining",
	"Elemental HERO Wildheart",
	"Emergency Provisions",
	"Emergency Teleport",
	"Empress Judge",
	"Enemy Controller",
	"Eradicator Epidemic Virus",
	"Escape from the Dark Dimension",
	"Evigishki Merrowgeist",
	"Evil HERO Dark Gaia",
	"Evilswarm Bahamut",
	"Evilswarm Castor",
	"Evilswarm Exciton Knight",
	"Evilswarm Heliotrope",
	"Evilswarm Kerykeion",
	"Evilswarm Mandragora",
	"Evilswarm Ophion",
	"Evilswarm Ouroboros",
	"Evilswarm Thunderbird",
	"Evolzar Dolkka",
	"Evolzar Laggia",
	"Exarion Universe",
	"Exchange",
	"Exiled Force",
	"Exodia the Forbidden One",
	"Exploder Dragon",
	"Fairy King Albverdich",
	"Fake Trap",
	"Fencing Fire Ferret",
	"Fiber Jar",
	"Fiend Skull Dragon",
	"Fiendish Chain",
	"Final Flame",
	"Fire Formation - Gyokkou",
	"Fire Formation - Tenken",
	"Fire Formation - Tenki",
	"Fire Formation - Tensen",
	"Fire Formation - Tensu",
	"Fire Hand",
	"Fire King Avatar Barong",
	"Fire King Avatar Yaksha",
	"Fire King High Avatar Garunix",
	"Fires of Doomsday",
	"Fishborg Blaster",
	"Fissure",
	"Five-Headed Dragon",
	"Flame Ghost",
	"Flame Swordsman",
	"Flamvell Firedog",
	"Flamvell Guard",
	"Flamvell Uruquizas",
	"Flip Flop Frog",
	"Flower Wolf",
	'Flying "C"',
	"Fog King",
	"Foolish Burial",
	"Forbidden Chalice",
	"Forbidden Dress",
	"Forbidden Lance",
	"Formula Synchron",
	"Fossil Dyna Pachycephalo",
	"Full House",
	"Fusilier Dragon, the Dual-Mode Beast",
	"Fusionist",
	"Future Fusion",
	"G.B. Hunter",
	"Gachi Gachi Gantetsu",
	"Gagaga Cowboy",
	"Gaia Dragon, the Thunder Charger",
	"Gaia Knight, the Force of Earth",
	"Gaia the Dragon Champion",
	"Garoth, Lightsworn Warrior",
	"Gateway of the Six",
	"Gatling Dragon",
	"Gauntlet Launcher",
	"Gear Gigant X",
	"Gearfried the Iron Knight",
	"Geargiaccelerator",
	"Geargiagear",
	"Geargiano",
	"Geargiano Mk-II",
	"Geargiarmor",
	"Geargiarsenal",
	"Geartown",
	"Gem-Knight Pearl",
	"Gemini Elf",
	"Gemini Imps",
	"Gemini Spark",
	"Generation Shift",
	"Genex Ally Birdman",
	"Genex Controller",
	"Genex Undine",
	"Ghostrick Alucard",
	"Giant Germ",
	"Giant Orc",
	"Giant Rat",
	"Giant Soldier of Stone",
	"Giant Trunade",
	"Giga-Tech Wolf",
	"Gigantes",
	"Gigaplant",
	"Gilasaurus",
	"Giltia the D. Knight",
	"Gladiator Beast Bestiari",
	"Gladiator Beast Darius",
	"Gladiator Beast Equeste",
	"Gladiator Beast Gaiodiaz",
	"Gladiator Beast Gyzarus",
	"Gladiator Beast Heraklinos",
	"Gladiator Beast Hoplomus",
	"Gladiator Beast Laquari",
	"Gladiator Beast Murmillo",
	"Gladiator Beast Retiari",
	"Gladiator Beast Samnite",
	"Gladiator Beast Secutor",
	"Gladiator Beast War Chariot",
	"Gladiator Beast's Respite",
	"Gladiator Proving Ground",
	"Glow-Up Bulb",
	"Goblin Attack Force",
	"Goblin Zombie",
	"Gold Sarcophagus",
	"Goldd, Wu-Lord of Dark World",
	"Good Goblin Housekeeping",
	"Gorz the Emissary of Darkness",
	"Gottoms' Emergency Call",
	"Goyo Guardian",
	"Gozen Match",
	"Graceful Charity",
	"Grandmaster of the Six Samurai",
	"Grandsoil the Elemental Lord",
	"Grapha, Dragon Lord of Dark World",
	"Gravekeeper's Assailant",
	"Gravekeeper's Commandant",
	"Gravekeeper's Descendant",
	"Gravekeeper's Guard",
	"Gravekeeper's Recruiter",
	"Gravekeeper's Spear Soldier",
	"Gravekeeper's Spy",
	"Gravekeeper's Stele",
	"Gravekeeper's Watcher",
	"Gravity Bind",
	"Great Shogun Shien",
	"Great White",
	"Green Baboon, Defender of the Forest",
	"Green Gadget",
	"Gungnir, Dragon of the Ice Barrier",
	"Gyaku-Gire Panda",
	"Gyakutenno Megami",
	"Hallowed Life Barrier",
	"Hammer Shot",
	"Hand Destruction",
	"Hane-Hane",
	"Hanewata",
	"Harpie's Feather Duster",
	"Heavy Storm",
	"Herald of Green Light",
	"Herald of Orange Light",
	"Herald of Pure Light",
	"Hero's Rule 2",
	"Heroic Champion - Excalibur",
	"Hidden Armory",
	"Hieratic Dragon King of Atum",
	"Hieratic Dragon of Eset",
	"Hieratic Dragon of Su",
	"Hieratic Dragon of Tefnuit",
	"Hieratic Seal From the Ashes",
	"Hieratic Seal of Convocation",
	"Hieratic Sun Dragon Overlord of Heliopolis",
	"Hierophant of Prophecy",
	"High Priestess of Prophecy",
	"Honest",
	"Horn of Heaven",
	"Horn of the Phantom Beast",
	"Horus the Black Flame Dragon LV6",
	"Horus the Black Flame Dragon LV8",
	"HTS Psyhemuth",
	"Hundred Eyes Dragon",
	"Hydrogeddon",
	"Icarus Attack",
	"Ice Hand",
	"Il Blud",
	"Imperial Iron Wall",
	"Imperial Order",
	"Infernity Archfiend",
	"Infernity Avenger",
	"Infernity Barrier",
	"Infernity Beetle",
	"Infernity Break",
	"Infernity Doom Dragon",
	"Infernity Inferno",
	"Infernity Launcher",
	"Infernity Mirage",
	"Infernity Necromancer",
	"Infestation Infection",
	"Infestation Pandemic",
	"Infestation Terminus",
	"Injection Fairy Lily",
	"Insect Knight",
	"Instant Fusion",
	"Inzektor Centipede",
	"Inzektor Dragonfly",
	"Inzektor Exa-Beetle",
	"Inzektor Hornet",
	"Inzektor Sword - Zektkaliber",
	"Iron Chain Dragon",
	"Jain, Lightsworn Paladin",
	"Jar of Greed",
	"Jinzo",
	"Jirai Gumo",
	"Jowgen the Spiritualist",
	"Judge Man",
	"Judgment Dragon",
	"Judgment of Anubis",
	"Junk Destroyer",
	"Jurrac Guaiba",
	"Just Desserts",
	"Justice of Prophecy",
	"Kabazauls",
	"Kagemusha of the Six Samurai",
	"Kagetokage",
	'Karakuri Komachi mdl 224 "Ninishi"',
	'Karakuri Merchant mdl 177 "Inashichi"',
	'Karakuri Muso mdl 818 "Haipa"',
	'Karakuri Ninja mdl 919 "Kuick"',
	'Karakuri Shogun mdl 00 "Burei"',
	'Karakuri Soldier mdl 236 "Nisamu"',
	'Karakuri Steel Shogun mdl 00X "Bureido"',
	'Karakuri Strategist mdl 248 "Nishipachi"',
	'Karakuri Watchdog mdl 313 "Saizan"',
	"Karbonala Warrior",
	"King Dragun",
	"King of the Feral Imps",
	"King Tiger Wanghu",
	"Koa'ki Meiru Drago",
	"Krebons",
	"Kuriboh",
	"Kwagar Hercules",
	"Kycoo the Ghost Destroyer",
	"La Jinn the Mystical Genie of the Lamp",
	"Labradorite Dragon",
	"Labyrinth Tank",
	"Last Day of Witch",
	"Last Will",
	"Lava Golem",
	"Lavalval Chain",
	"Leeching the Light",
	"Left Arm of the Forbidden One",
	"Left Leg of the Forbidden One",
	"Legacy of Yata-Garasu",
	"Legendary Jujitsu Master",
	"Legendary Six Samurai - Kageki",
	"Legendary Six Samurai - Kizan",
	"Legendary Six Samurai - Shi En",
	"Leo, the Keeper of the Sacred Tree",
	"Level Limit - Area B",
	"Leviair the Sea Dragon",
	"Light and Darkness Dragon",
	"Light-Imprisoning Mirror",
	"Lightning Vortex",
	"Lightning, Dragon Ruler of Drafts",
	"Lightpulsar Dragon",
	"Limit Reverse",
	"Limiter Removal",
	"Lonefire Blossom",
	"Lumina, Lightsworn Summoner",
	"Lyla, Lightsworn Sorceress",
	"Machina Cannon",
	"Machina Force",
	"Machina Fortress",
	"Machina Gearframe",
	"Machine Duplication",
	"Macro Cosmos",
	"Madolche Magileine",
	"Maestroke the Symphony Djinn",
	"Mage Power",
	"Magic Cylinder",
	"Magic Jammer",
	"Magical Android",
	"Magical Explosion",
	"Magical Mallet",
	"Magical Merchant",
	"Magical Scientist",
	"Magical Stone Excavation",
	"Magician of Faith",
	"Malefic Cyber End Dragon",
	"Malefic Stardust Dragon",
	"Malevolent Catastrophe",
	"Man-Eater Bug",
	"Manju of the Ten Thousand Hands",
	"Mark of the Rose",
	"Marshmallon",
	"Mask of Darkness",
	"Mask of Restrict",
	"Masked Sorcerer",
	"Mass Driver",
	"Master Hyperion",
	"Master of Oz",
	'Maxx "C"',
	"Mecha Phantom Beast Dracossack",
	"Mecha-Dog Marron",
	"Mechanicalchaser",
	"Mechquipped Angineer",
	"Megamorph",
	"Mei-Kou, Master of Barriers",
	"Mermail Abyssgaios",
	"Mermail Abyssgunde",
	"Mermail Abyssleed",
	"Mermail Abysslinde",
	"Mermail Abyssmegalo",
	"Mermail Abysspike",
	"Mermail Abyssteus",
	"Mermail Abysstrite",
	"Mermail Abyssturge",
	"Messenger of Peace",
	"Metaion, the Timelord",
	"Metal Armored Bug",
	"Metal Dragon",
	"Metamorphosis",
	"Mezuki",
	"Minar",
	"Mind Control",
	"Mind Crush",
	"Mind Drain",
	"Miracle Fertilizer",
	"Miracle Fusion",
	"Mirage of Nightmare",
	"Mirror Force",
	"Mirror of Oaths",
	"Mist Wurm",
	"Mobius the Frost Monarch",
	"Monster Gate",
	"Monster Reborn",
	"Monster Reincarnation",
	"Moray of Greed",
	"Morphing Jar",
	"Mother Grizzly",
	"Moulinglacia the Elemental Lord",
	"Muka Muka",
	"Musician King",
	"My Body as a Shield",
	"Mystic Swordsman LV2",
	"Mystic Tomato",
	"Mystical Elf",
	"Mystical Refpanel",
	"Mystical Shine Ball",
	"Mystical Space Typhoon",
	"Mystik Wok",
	"Mythic Tree Dragon",
	"Mythic Water Dragon",
	"Naturia Barkion",
	"Naturia Beast",
	"Necro Gardna",
	"Necrovalley",
	"Needle Ceiling",
	"Neko Mane King",
	"Neo Bug",
	"Neo the Magic Swordsman",
	"Neo-Spacian Dark Panther",
	"Neo-Spacian Grand Mole",
	"Newdoria",
	"Night Assailant",
	"Night Beam",
	"Nightmare Wheel",
	"Nimble Momonga",
	"Ninja Grandmaster Hanzo",
	"Ninja Grandmaster Sasuke",
	"Ninjitsu Art of Super-Transformation",
	"Nitro Warrior",
	"Nobleman of Crossout",
	"Nobleman of Extermination",
	"Non Aggression Area",
	"Number 101: Silent Honor ARK",
	"Number 103: Ragnazero",
	"Number 106: Giant Hand",
	"Number 11: Big Eye",
	"Number 16: Shock Master",
	"Number 17: Leviathan Dragon",
	"Number 20: Giga-Brilliant",
	"Number 30: Acid Golem of Destruction",
	"Number 39: Utopia",
	"Number 47: Nightmare Shark",
	"Number 50: Blackship of Corn",
	"Number 61: Volcasaurus",
	"Number 66: Master Key Beetle",
	"Number 80: Rhapsody in Berserk",
	"Number 82: Heartlandraco",
	"Number 85: Crazy Box",
	"Number 96: Dark Mist",
	"Number C39: Utopia Ray",
	"Ojama King",
	"Ojama Knight",
	"Ojama Trio",
	"Old Vindictive Magician",
	"One Day of Peace",
	"One for One",
	"Onslaught of the Fire Kings",
	"Ookazi",
	"Orient Dragon",
	"Overload Fusion",
	"Overworked",
	"Painful Choice",
	"Penguin Knight",
	"Phantom Dragon",
	"Phantom of Chaos",
	"Phoenix Wing Wind Blast",
	"Photon Papilloperative",
	"Photon Strike Bounzer",
	"Photon Thrasher",
	"Pikeru's Circle of Enchantment",
	"Plaguespreader Zombie",
	"Poison Draw Frog",
	"Poison of the Old Man",
	"Pole Position",
	"Polymerization",
	"Pot of Avarice",
	"Pot of Duality",
	"Pot of Greed",
	"Power Tool Dragon",
	"Premature Burial",
	"Prime Material Dragon",
	"Princess of Tsurugi",
	"Prohibition",
	"Prometheus, King of the Shadows",
	"Protector of the Sanctuary",
	"Psi-Blocker",
	"Psychic Commander",
	"Psychic Lifetrancer",
	"Pulling the Rug",
	"Punished Eagle",
	"Puppet Plant",
	"Pyramid Turtle",
	"Queen Dragun Djinn",
	"Quickdraw Synchron",
	"Raigeki",
	"Raigeki Break",
	"Rainbow Life",
	"Raiza the Storm Monarch",
	"Reactan, Dragon Ruler of Pebbles",
	"Reaper on the Nightmare",
	"Reasoning",
	"Reborn Tengu",
	"Reckless Greed",
	"Red Dragon Archfiend",
	"Red Gadget",
	"Red-Eyes Darkness Metal Dragon",
	"Redox, Dragon Ruler of Boulders",
	"Reflect Bounder",
	"Reinforce Truth",
	"Reinforcement of the Army",
	"Reinforcements",
	"Rekindling",
	"Relinquished",
	"Reload",
	"Remove Trap",
	"Rescue Cat",
	"Rescue Rabbit",
	"Retort",
	"Return from the Different Dimension",
	"Revived King Ha Des",
	"Right Arm of the Forbidden One",
	"Right Leg of the Forbidden One",
	"Ring of Defense",
	"Ring of Destruction",
	"Rivalry of Warlords",
	"Roaring Ocean Snake",
	"Robbin' Goblin",
	"Ronintoadin",
	"Rose, Warrior of Revenge",
	"Royal Decree",
	"Royal Oppression",
	"Royal Tribute",
	"Rush Recklessly",
	"Ryko, Lightsworn Hunter",
	"Ryu Kokki",
	"Ryu Senshi",
	"Saber Hole",
	"Saber Slash",
	"Sabersaurus",
	"Sacred Crane",
	"Sacred Sword of Seven Stars",
	"Safe Zone",
	"Sakuretsu Armor",
	"Salvage",
	"Sangan",
	"Sanwitch",
	"Sasuke Samurai",
	"Scapegoat",
	"Scrap Archfiend",
	"Scrap Beast",
	"Scrap Chimera",
	"Scrap Dragon",
	"Scrap Goblin",
	"Scrap Golem",
	"Scrapstorm",
	"Sea Dragon Lord Gishilnodon",
	"Secret Barrel",
	"Self-Destruct Button",
	"Senju of the Thousand Hands",
	"Serial Spell",
	"Seven Tools of the Bandit",
	"Shadow-Imprisoning Mirror",
	"Shien's Smoke Signal",
	"Shining Angel",
	"Shining Elf",
	'Shiny Black "C"',
	"Shooting Star Dragon",
	"Shrink",
	"Sillva, Warlord of Dark World",
	"Sinister Serpent",
	"Six Samurai United",
	"Sixth Sense",
	"Skill Drain",
	"Skilled Dark Magician",
	"Skull Knight",
	"Skull Lair",
	"Skull Meister",
	"Smashing Ground",
	"Snatch Steal",
	"Snipe Hunter",
	"Snowman Eater",
	"Snoww, Unlight of Dark World",
	"Solar Recharge",
	"Solemn Judgment",
	"Solemn Warning",
	"Solemn Wishes",
	"Sonic Bird",
	"Soul Charge",
	"Soul Drain",
	"Soul Exchange",
	"Soul of Silvermountain",
	"Soul Release",
	"Soul Taker",
	"Spear Cretin",
	"Spear Dragon",
	"Spell Canceller",
	"Spell Economics",
	"Spell Reproduction",
	"Spell Shield Type-8",
	"Spell Striker",
	"Spellbook Library of the Crescent",
	"Spellbook Magician of Prophecy",
	"Spellbook of Eternity",
	"Spellbook of Fate",
	"Spellbook of Judgment",
	"Spellbook of Life",
	"Spellbook of Power",
	"Spellbook of Secrets",
	"Spellbook of the Master",
	"Spellbook of Wisdom",
	"Spellbook Star Hall",
	"Spirit of the Harp",
	"Spirit of the Six Samurai",
	"Spirit Reaper",
	"Spiritual Water Art - Aoi",
	"Spiritualism",
	"Splendid Rose",
	"Spore",
	"St. Joan",
	"Star Eater",
	"Stardust Dragon",
	"Stardust Spark Dragon",
	"Starliege Paladynamo",
	"Starlight Road",
	"Stealth Bird",
	"Steam Gyroid",
	"Steelswarm Roach",
	"Stop Defense",
	"Stream, Dragon Ruler of Droplets",
	"Strike Ninja",
	"Stygian Sergeants",
	"Stygian Street Patrol",
	"Substitoad",
	"Summon Limit",
	"Summoned Skull",
	"Summoner Monk",
	"Super Polymerization",
	"Super Rejuvenation",
	"Super Robolady",
	"Super Roboyarou",
	"Super Solar Nutrient",
	"Super Vehicroid Jumbo Drill",
	"Super-Nimble Mega Hamster",
	"Supervise",
	"Swallow Flip",
	"Swap Frog",
	"Swift Scarecrow",
	"Swords of Revealing Light",
	"System Down",
	"T.G. Hyper Librarian",
	"T.G. Power Gladiator",
	"T.G. Rush Rhino",
	"T.G. Striker",
	"T.G. Warwolf",
	"T.G. Wonder Magician",
	"Temperance of Prophecy",
	"Tempest Magician",
	"Tempest, Dragon Ruler of Storms",
	"Temtempo the Percussion Djinn",
	"Terraforming",
	"Test Tiger",
	"TG1-EM1",
	"The Agent of Creation - Venus",
	"The Agent of Miracles - Jupiter",
	"The Agent of Mystery - Earth",
	"The Fabled Catsith",
	"The Fiend Megacyber",
	"The Forceful Sentry",
	"The Gates of Dark World",
	"The Grand Spellbook Tower",
	"The Last Warrior from Another Planet",
	"The Light - Hex-Sealed Fusion",
	"The Little Swordsman of Aile",
	"The Six Samurai - Irou",
	"The Six Samurai - Kamon",
	"The Six Samurai - Yaichi",
	"The Six Samurai - Zanji",
	"The Transmigration Prophecy",
	"The White Stone of Legend",
	"The Wicked Worm Beast",
	"Thestalos the Firestorm Monarch",
	"Thought Ruler Archfiend",
	"Thousand Dragon",
	"Thousand-Eyes Restrict",
	"Threatening Roar",
	"Thunder Dragon",
	"Thunder King Rai-Oh",
	"Thunder Nyan Nyan",
	"Tidal, Dragon Ruler of Waterfalls",
	"Time Seal",
	"Tin Goldfish",
	"Tiras, Keeper of Genesis",
	"Toon Table of Contents",
	"Torrential Tribute",
	"Tour Guide From the Underworld",
	"Trade-In",
	"Tragoedia",
	"Trance Archfiend",
	"Trap Dustshoot",
	"Trap Eater",
	"Trap Hole",
	"Trap Master",
	"Trap Stun",
	"Traptrix Dionaea",
	"Traptrix Myrmeleo",
	"Traptrix Trap Hole Nightmare",
	"Treacherous Trap Hole",
	"Treeborn Frog",
	"Tremendous Fire",
	"Tribe-Infecting Virus",
	"Tribute to the Doomed",
	"Trident Dragion",
	"Trigon",
	"Trishula, Dragon of the Ice Barrier",
	"Tsukuyomi",
	"Turbo Warrior",
	"Twin-Headed Behemoth",
	"Twin-Headed Thunder Dragon",
	"Twister",
	"Tytannial, Princess of Camellias",
	"UFO Turtle",
	"Ultimate Offering",
	"Unifrog",
	"United We Stand",
	"Upstart Goblin",
	"Van'Dalgyon the Dark Dragon Lord",
	"Vanity's Emptiness",
	"Vanity's Fiend",
	"Volcanic Queen",
	"Volcanic Rocket",
	"Volcanic Shell",
	"Vorse Raider",
	"Vortex Trooper",
	"Waboku",
	"Wall of Illusion",
	"Wall of Revealing Light",
	"Warrior Elimination",
	"Warrior of Tradition",
	"Wave-Motion Cannon",
	"White Magical Hat",
	"Widespread Dud",
	"Widespread Ruin",
	"Wind-Up Arsenal Zenmaioh",
	"Wind-Up Carrier Zenmaity",
	"Wind-Up Factory",
	"Wind-Up Hunter",
	"Wind-Up Magician",
	"Wind-Up Rabbit",
	"Wind-Up Rat",
	"Wind-Up Shark",
	"Wind-Up Zenmaines",
	"Wind-Up Zenmaister",
	"Winged Kuriboh",
	"Winged Rhynos",
	"Wiretap",
	"Witch of the Black Forest",
	"Wulf, Lightsworn Beast",
	"X-Saber Airbellum",
	"X-Saber Pashuul",
	"X-Saber Urbellum",
	"X-Saber Wayne",
	"Xing Zhen Hu",
	"XX-Saber Boggart Knight",
	"XX-Saber Darksoul",
	"XX-Saber Emmersblade",
	"XX-Saber Faultroll",
	"XX-Saber Fulhelmknight",
	"XX-Saber Gottoms",
	"XX-Saber Hyunlei",
	"XX-Saber Ragigura",
	"Xyz Encore",
	"Yata-Garasu",
	"Yellow Gadget",
	"Zaborg the Thunder Monarch",
	"Zombie Master",
	"Zombyra the Dark",
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
         + card_name[:19] + '");\n'
                  + 'const u8 gCardNameShortBag_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + '[] = _("'
         + card_name[:26] + '");\n')
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
        .pocket = POCKET_TRUNK,
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
                  + '\t\t.nameShortBag = gCardNameShortBag_' + re.sub(r'[^a-zA-Z0-9]', '', data['name']) + ',\n'
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
                      + "\t\t.archetypesSeries = {ARCHETYPE_SERIES_NONE, ARCHETYPE_SERIES_NONE, ARCHETYPE_SERIES_NONE},\n")
        with open('FL.json', 'r') as f:
            data_ = json.load(f)
            for card_ in data_:
                if card_['Card'] == card and card_['Format'] == 'Yugi-Kaiba':
                      gCardInfo += "\t\t.priceYK = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Critter':
                      gCardInfo += "\t\t.priceCritter = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Treasure':
                      gCardInfo += "\t\t.priceTreasure = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Imperial':
                      gCardInfo += "\t\t.priceImperial = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Android':
                      gCardInfo += "\t\t.priceAndroid = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Joey-Pegasus':
                      gCardInfo += "\t\t.priceJoeyPegasus = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Fiber':
                      gCardInfo += "\t\t.priceFiber = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Yata':
                      gCardInfo += "\t\t.priceYata = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Scientist':
                      gCardInfo += "\t\t.priceScientist = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Vampire':
                      gCardInfo += "\t\t.priceVampire = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Chaos':
                      gCardInfo += "\t\t.priceChaos = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Warrior':
                      gCardInfo += "\t\t.priceWarrior = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Goat':
                      gCardInfo += "\t\t.priceGoat = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Cyber':
                      gCardInfo += "\t\t.priceCyber = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Reaper':
                      gCardInfo += "\t\t.priceReaper = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Chaos Return':
                      gCardInfo += "\t\t.priceChaosReturn = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Demise':
                      gCardInfo += "\t\t.priceDemise = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Trooper':
                      gCardInfo += "\t\t.priceTrooper = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Zombie':
                      gCardInfo += "\t\t.priceZombie = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Perfect Circle':
                      gCardInfo += "\t\t.pricePerfectCircle = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'DAD Return':
                      gCardInfo += "\t\t.priceDADReturn = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Gladiator':
                      gCardInfo += "\t\t.priceGladiator = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'TeleDAD':
                      gCardInfo += "\t\t.priceTeleDAD = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Cat':
                      gCardInfo += "\t\t.priceCat = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Edison':
                      gCardInfo += "\t\t.priceEdison = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Frog':
                      gCardInfo += "\t\t.priceFrog = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Starstrike':
                      gCardInfo += "\t\t.priceStarstrike = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Tengu':
                      gCardInfo += "\t\t.priceTengu = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Dino Rabbit':
                      gCardInfo += "\t\t.priceDinoRabbit = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Wind-Up':
                      gCardInfo += "\t\t.priceWindUp = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Miami':
                      gCardInfo += "\t\t.priceMiami = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Meadowlands':
                      gCardInfo += "\t\t.priceMeadowlands = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Baby Ruler':
                      gCardInfo += "\t\t.priceBabyRuler = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Ravine Ruler':
                      gCardInfo += "\t\t.priceRavineRuler = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Fire-Water':
                      gCardInfo += "\t\t.priceFireWater = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'HAT':
                      gCardInfo += "\t\t.priceHAT = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
                if card_['Card'] == card and card_['Format'] == 'Vegas':
                      gCardInfo += "\t\t.priceVegas = " + str(round((card_['Usage (Weighted)']/highest_usage[card_['Format']]) * 1000)) + ",\n"
        gCardInfo += ("\t\t.priceCustom = 0,\n"
                  + "\t\t.priceVendor1 = 0,\n"
                  + "\t\t.priceVendor2 = 0,\n"
                  + "\t\t.priceVendor3 = 0,\n"
                  + "\t\t.priceVendor4 = 0,\n"
                  + "\t\t.priceVendor5 = 0,\n"
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