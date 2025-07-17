#include "extractor.h"

#include <algorithm>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <set>
#include <string>
#include <regex>
#include <sstream>

#include <json.hpp>
using json = nlohmann::json;

#define ROM_START 0x8000000

int main (int argc, char *argv[])
{
    std::filesystem::path root_dir;

    if (argc == 1)
    {
        root_dir = std::filesystem::path(".");
    }
    else if (argc == 2)
    {
        root_dir = std::filesystem::path(argv[1]);
    }
    else
    {
        fprintf(stderr, "Too many arguments\nUSAGE: extractor [root directory]\n");
        exit(1);
    }

    // ------------------------------------------------------------------------
    // Getting constants
    // ------------------------------------------------------------------------
    std::cout << "Loading constants..." << std::endl;
    std::ifstream macro_file(root_dir / "constants.json");
    if (macro_file.fail())
    {
        fprintf(stderr, "Could not find constants.json\n");
        exit(1);
    }
    json constants_json = json::parse(macro_file);

    // ------------------------------------------------------------------------
    // Reading symbols
    // ------------------------------------------------------------------------
    std::cout << "Reading symbols..." << std::endl;
    std::ifstream symbol_map_file(root_dir / "pokeemerald_ap.sym");
    if (symbol_map_file.fail())
    {
        fprintf(stderr, "Could not find pokeemerald_ap.sym\n");
        exit(1);
    }
    std::regex symbol_map_regex("^([0-9a-fA-F]+) [lg] [0-9a-fA-F]+ ([a-zA-Z0-9_]+)$");
    std::map<std::string, uint32_t> symbol_map;

    std::string line;
    while (std::getline(symbol_map_file, line))
    {
        std::smatch m;
        if (std::regex_match(line, m, symbol_map_regex))
        {
            symbol_map[m[2]] = std::stoi(m[1], nullptr, 16);
        }
    }

    std::map<std::string, uint32_t> misc_ram_addresses = {
        { "CB2_Overworld", symbol_map["CB2_Overworld"] },
        { "gArchipelagoReceivedItem", symbol_map["gArchipelagoReceivedItem"] },
        { "gMain", symbol_map["gMain"] },
        { "gSaveBlock1Ptr", symbol_map["gSaveBlock1Ptr"] },
        { "gSaveBlock2Ptr", symbol_map["gSaveBlock2Ptr"] },
        { "gPlayerParty", symbol_map["gPlayerParty"] },
        { "gArchipelagoDeathLinkQueued", symbol_map["gArchipelagoDeathLinkQueued"] },
    };

    std::map<std::string, uint32_t> misc_rom_addresses = {
        { "gArchipelagoOptions", symbol_map["gArchipelagoOptions"] - ROM_START },
        { "gArchipelagoPlayerNames", symbol_map["gArchipelagoPlayerNames"] - ROM_START },
        { "gArchipelagoItemNames", symbol_map["gArchipelagoItemNames"] - ROM_START },
        { "gArchipelagoNameTable", symbol_map["gArchipelagoNameTable"] - ROM_START },
        { "gArchipelagoInfo", symbol_map["gArchipelagoInfo"] - ROM_START },
        { "gBattleMoves", symbol_map["gBattleMoves"] - ROM_START },
        { "gLevelUpLearnsets", symbol_map["gLevelUpLearnsets"] - ROM_START },
        { "sNewGamePCItems", symbol_map["sNewGamePCItems"] - ROM_START },
        { "gSpeciesInfo", symbol_map["gSpeciesInfo"] - ROM_START },
        { "sStarterMon", symbol_map["sStarterMon"] - ROM_START },
        { "gTMHMLearnsets", symbol_map["gTMHMLearnsets"] - ROM_START },
        { "gTrainers", symbol_map["gTrainers"] - ROM_START },
        { "sTMHMMoves", symbol_map["sTMHMMoves"] - ROM_START },
        { "gEvolutionTable", symbol_map["gEvolutionTable"] - ROM_START },
        { "gRandomizedSoundTable", symbol_map["gRandomizedSoundTable"] - ROM_START },
        { "gRandomizedBerryTreeItems", symbol_map["gRandomizedBerryTreeItems"] - ROM_START },
        { "gTutorMoves", symbol_map["gTutorMoves"] - ROM_START },
        { "sTutorLearnsets", symbol_map["sTutorLearnsets"] - ROM_START },
        { "LoadObjectEventPalette", symbol_map["LoadObjectEventPalette"] - ROM_START },
        { "PatchObjectPalette", symbol_map["PatchObjectPalette"] - ROM_START },
        { "FindObjectEventPaletteIndexByTag", symbol_map["FindObjectEventPaletteIndexByTag"] - ROM_START },
        { "gMonFrontPicTable", symbol_map["gMonFrontPicTable"] - ROM_START },
        { "gMonBackPicTable", symbol_map["gMonBackPicTable"] - ROM_START },
        { "gMonIconTable", symbol_map["gMonIconTable"] - ROM_START },
        { "gMonFootprintTable", symbol_map["gMonFootprintTable"] - ROM_START },
        { "gMonPaletteTable", symbol_map["gMonPaletteTable"] - ROM_START },
        { "gMonShinyPaletteTable", symbol_map["gMonShinyPaletteTable"] - ROM_START },
        { "gMonIconPaletteIndices", symbol_map["gMonIconPaletteIndices"] - ROM_START },
        { "sEggPalette", symbol_map["sEggPalette"] - ROM_START },
        { "sEggHatchTiles", symbol_map["sEggHatchTiles"] - ROM_START },
        { "gObjectEventGraphicsInfoPointers", symbol_map["gObjectEventGraphicsInfoPointers"] - ROM_START },
        { "sObjectEventSpritePalettes", symbol_map["sObjectEventSpritePalettes"] - ROM_START },
        { "gTrainerFrontPicTable", symbol_map["gTrainerFrontPicTable"] - ROM_START },
        { "gTrainerFrontPicPaletteTable", symbol_map["gTrainerFrontPicPaletteTable"] - ROM_START },
        { "gTrainerBackPicTable", symbol_map["gTrainerBackPicTable"] - ROM_START },
        { "gTrainerBackPicPaletteTable", symbol_map["gTrainerBackPicPaletteTable"] - ROM_START },
        { "sTrainerBackSpriteTemplates", symbol_map["sTrainerBackSpriteTemplates"] - ROM_START },
        { "gTrainerBackAnimsPtrTable", symbol_map["gTrainerBackAnimsPtrTable"] - ROM_START },
        { "sBackAnims_Brendan", symbol_map["sBackAnims_Brendan"] - ROM_START },
        { "sBackAnims_Red", symbol_map["sBackAnims_Red"] - ROM_START },
        { "sOamTables_16x16", symbol_map["sOamTables_16x16"] - ROM_START },
        { "sOamTables_16x32", symbol_map["sOamTables_16x32"] - ROM_START },
        { "sOamTables_32x32", symbol_map["sOamTables_32x32"] - ROM_START },
        { "gObjectEventBaseOam_16x16", symbol_map["gObjectEventBaseOam_16x16"] - ROM_START },
        { "gObjectEventBaseOam_16x32", symbol_map["gObjectEventBaseOam_16x32"] - ROM_START },
        { "gObjectEventBaseOam_32x32", symbol_map["gObjectEventBaseOam_32x32"] - ROM_START },
        { "sEmpty6", symbol_map["sEmpty6"] - ROM_START },
    };

    // ------------------------------------------------------------------------
    // Reading ROM
    // ------------------------------------------------------------------------
    std::cout << "Reading ROM..." << std::endl;
    std::ifstream rom(root_dir / "pokeemerald_ap.gba", std::ios::binary);
    if (rom.fail())
    {
        fprintf(stderr, "Could not open rom file\n");
        exit(1);
    }

    // NPC Gifts
    std::vector<std::shared_ptr<LocationInfo>> npc_gifts;
    for (auto const& [symbol, address] : symbol_map)
    {
        if (symbol.substr(0, 28) == "Archipelago_Target_NPC_Gift_")
        {
            std::shared_ptr<LocationInfo> item(new LocationInfo());
            item->name = "NPC_GIFT_" + symbol.substr(33);
            item->flag = constants_json[symbol.substr(28)];
            item->address = address + 3 - ROM_START;
            npc_gifts.push_back(item);
        }
    }

    // Berry Trees
    std::regex berry_regex("(ORAN|PECHA|CHERI|LEPPA|PINAP|CHESTO|KELPSY|BLUK|NANAB|WEPEAR|RAWST|RAZZ|PERSIM|SITRUS|HONDEW|POMEG|ASPEAR|GREPA|QUALOT|LIECHI)");
    std::vector<std::shared_ptr<LocationInfo>> berry_trees;
    for (json::iterator it = constants_json.begin(); it != constants_json.end(); ++it)
    {
        if (it.key().substr(0, 11) == "BERRY_TREE_")
        {
            uint8_t id = (uint8_t)(it.value());
            std::shared_ptr<LocationInfo> item(new LocationInfo());
            item->name = "BERRY_TREE_" + std::string(id < 10 ? "0" : "") + std::to_string(id);
            item->flag = uint16_t(constants_json["FLAG_BERRY_TREES_START"]) + (id - 1);
            item->address = symbol_map["gRandomizedBerryTreeItems"] + (id * 2) - ROM_START;

            std::smatch m;
            if (std::regex_search(it.key(), m, berry_regex))
            {
                item->default_item = constants_json["ITEM_" + m[1].str() + "_BERRY"];
            }
            else
            {
                item->default_item = constants_json["ITEM_SITRUS_BERRY"];
            }

            berry_trees.push_back(item);
        }
    }

    // Pokedex Entries
    std::vector<std::shared_ptr<LocationInfo>> dex_rewards;
    for (size_t i = 0; i < 386; ++i)
    {
        std::string padded_dex_number = std::to_string(i + 1);
        if (padded_dex_number.size() < 3)
        {
            padded_dex_number = std::string(3 - padded_dex_number.size(), '0') + padded_dex_number;
        }

        std::shared_ptr<LocationInfo> item(new LocationInfo());
        item->name = "POKEDEX_REWARD_" + padded_dex_number;
        item->flag = 0;
        item->address = symbol_map["sPokedexRewards"] + (i * 2) - ROM_START;
        item->default_item = constants_json["ITEM_GREAT_BALL"];
        dex_rewards.push_back(item);
    }

    // Badges
    std::vector<std::shared_ptr<LocationInfo>> badges;
    for (auto const& [symbol, address] : symbol_map)
    {
        if (symbol.substr(0, 25) == "Archipelago_Target_Badge_")
        {
            std::shared_ptr<LocationInfo> item(new LocationInfo());
            item->name = "BADGE_" + symbol.substr(25);
            item->flag = constants_json["FLAG_RECEIVED_BADGE_" + symbol.substr(25)];
            item->address = address + 3 - ROM_START;
            badges.push_back(item);
        }
    }

    // Trainer battle scripts
    std::map<uint16_t, uint32_t> trainer_battle_scripts;
    for (auto const& [symbol, address] : symbol_map)
    {
        if (symbol.substr(0, 26) == "Archipelago_Target_TRAINER")
        {
            trainer_battle_scripts[constants_json[symbol.substr(19)]] = address;
        }
    }

    // Reading trainers
    std::vector<std::shared_ptr<TrainerInfo>> trainers;
    for (size_t i = 0; i < constants_json["TRAINERS_COUNT"]; ++i)
    {
        std::shared_ptr<TrainerInfo> trainer(new TrainerInfo());

        trainer->address = misc_rom_addresses["gTrainers"] + (i * 0x28);

        uint8_t party_flags;
        rom.seekg(trainer->address + 0x0, rom.beg);
        rom.read((char*)&(party_flags), 1);

        uint8_t party_size;
        rom.seekg(trainer->address + 0x20, rom.beg);
        rom.read((char*)&(party_size), 1);

        rom.seekg(trainer->address + 0x24, rom.beg);
        rom.read((char*)&(trainer->party_address), 4);
        trainer->party_address -= ROM_START;

        auto battle_script_address = trainer_battle_scripts.find(i);
        if (battle_script_address != trainer_battle_scripts.end())
        {
            trainer->battle_script_address = battle_script_address->second - ROM_START;
            rom.seekg(trainer->battle_script_address + 1, rom.beg);
            rom.read((char*)&(trainer->battle_type), 1);
        }

        switch (party_flags)
        {
            case 0b00:
                trainer->pokemon_data_type = NO_ITEM_DEFAULT_MOVES;
                break;
            case 0b01:
                trainer->pokemon_data_type = NO_ITEM_CUSTOM_MOVES;
                break;
            case 0b10:
                trainer->pokemon_data_type = ITEM_DEFAULT_MOVES;
                break;
            case 0b11:
                trainer->pokemon_data_type = ITEM_CUSTOM_MOVES;
                break;
            default:
                throw new std::exception();
        }

        size_t pokemon_data_size;
        switch (trainer->pokemon_data_type)
        {
            case NO_ITEM_DEFAULT_MOVES:
                pokemon_data_size = 8;
                break;
            case NO_ITEM_CUSTOM_MOVES:
                pokemon_data_size = 16;
                break;
            case ITEM_DEFAULT_MOVES:
                pokemon_data_size = 8;
                break;
            case ITEM_CUSTOM_MOVES:
                pokemon_data_size = 16;
                break;
        }

        size_t moves_offset;
        switch (trainer->pokemon_data_type)
        {
            case NO_ITEM_CUSTOM_MOVES:
                moves_offset = 6;
                break;
            case ITEM_CUSTOM_MOVES:
                moves_offset = 8;
                break;
            default:
                moves_offset = 0;
                break;
        }

        for (size_t j = 0; j < party_size; ++j)
        {
            TrainerPokemonInfo pokemon;

            uint32_t address = trainer->party_address + (j * pokemon_data_size);

            rom.seekg(address + 2, rom.beg);
            rom.read((char*)&(pokemon.level), 1);

            rom.seekg(address + 4, rom.beg);
            rom.read((char*)&(pokemon.species), 2);

            if (trainer->pokemon_data_type == NO_ITEM_CUSTOM_MOVES || trainer->pokemon_data_type == ITEM_CUSTOM_MOVES)
            {
                for (size_t k = 0; k < 4; ++k)
                {
                    uint16_t move;
                    rom.seekg(address + moves_offset + (k * 2), rom.beg);
                    rom.read((char*)&(move), 2);

                    pokemon.moves[k] = move;
                }
            }
            else
            {
                pokemon.moves[0] = 0;
                pokemon.moves[1] = 0;
                pokemon.moves[2] = 0;
                pokemon.moves[3] = 0;
            }

            trainer->party.push_back(pokemon);
        }

        trainers.push_back(trainer);
    }

    // Trainer Rewards
    std::vector<std::shared_ptr<LocationInfo>> trainer_rewards;
    std::vector<std::string> trainer_names{
        "TRAINER_AARON",
        "TRAINER_ABIGAIL_1",
        "TRAINER_AIDAN",    
        "TRAINER_AISHA",
        "TRAINER_ALBERTO",
        "TRAINER_ALBERT",
        "TRAINER_ALEXA",
        "TRAINER_ALEXIA",
        "TRAINER_ALEX",
        "TRAINER_ALICE",
        "TRAINER_ALIX",
        "TRAINER_ALLEN",
        "TRAINER_ALLISON",
        "TRAINER_ALYSSA",
        "TRAINER_AMY_AND_LIV_1",
        "TRAINER_ANDREA",
        "TRAINER_ANDRES_1",
        "TRAINER_ANDREW",
        "TRAINER_ANGELICA",
        "TRAINER_ANGELINA",
        "TRAINER_ANGELO",
        "TRAINER_ANNA_AND_MEG_1",
        "TRAINER_ANNIKA",
        "TRAINER_ANTHONY",
        "TRAINER_ARCHIE",
        "TRAINER_ASHLEY",
        "TRAINER_ATHENA",
        "TRAINER_ATSUSHI",
        "TRAINER_AURON",
        "TRAINER_AUSTINA",
        "TRAINER_AUTUMN",
        "TRAINER_AXLE",
        "TRAINER_BARNY",
        "TRAINER_BARRY",
        "TRAINER_BEAU",
        "TRAINER_BECKY",
        "TRAINER_BECK",
        "TRAINER_BENJAMIN_1",
        "TRAINER_BEN",
        "TRAINER_BERKE",
        "TRAINER_BERNIE_1",
        "TRAINER_BETHANY",
        "TRAINER_BETH",
        "TRAINER_BEVERLY",
        "TRAINER_BIANCA",
        "TRAINER_BILLY",
        "TRAINER_BLAKE",
        "TRAINER_BRANDEN",
        "TRAINER_BRANDI",
        "TRAINER_BRAWLY_1",
        "TRAINER_BRAXTON",
        "TRAINER_BRENDAN_LILYCOVE_MUDKIP",
        "TRAINER_BRENDAN_LILYCOVE_TORCHIC",
        "TRAINER_BRENDAN_LILYCOVE_TREECKO",
        "TRAINER_BRENDAN_ROUTE_103_MUDKIP",
        "TRAINER_BRENDAN_ROUTE_103_TORCHIC",
        "TRAINER_BRENDAN_ROUTE_103_TREECKO",
        "TRAINER_BRENDAN_ROUTE_110_MUDKIP",
        "TRAINER_BRENDAN_ROUTE_110_TORCHIC",
        "TRAINER_BRENDAN_ROUTE_110_TREECKO",
        "TRAINER_BRENDAN_ROUTE_119_MUDKIP",
        "TRAINER_BRENDAN_ROUTE_119_TORCHIC",
        "TRAINER_BRENDAN_ROUTE_119_TREECKO",
        "TRAINER_BRENDAN_RUSTBORO_MUDKIP",
        "TRAINER_BRENDAN_RUSTBORO_TORCHIC",
        "TRAINER_BRENDAN_RUSTBORO_TREECKO",
        "TRAINER_BRENDA",
        "TRAINER_BRENDEN",
        "TRAINER_BRENT",
        "TRAINER_BRIANNA",
        "TRAINER_BRICE",
        "TRAINER_BRIDGET",
        "TRAINER_BROOKE_1",
        "TRAINER_BRYANT",
        "TRAINER_BRYAN",
        "TRAINER_CALE",
        "TRAINER_CALLIE",
        "TRAINER_CALVIN_1",
        "TRAINER_CAMDEN",
        "TRAINER_CAMERON_1",
        "TRAINER_CAMRON",
        "TRAINER_CARLEE",
        "TRAINER_CAROLINA",
        "TRAINER_CAROLINE",
        "TRAINER_CAROL",
        "TRAINER_CARTER",
        "TRAINER_CATHERINE_1",
        "TRAINER_CEDRIC",
        "TRAINER_CELIA",
        "TRAINER_CELINA",
        "TRAINER_CHAD",
        "TRAINER_CHANDLER",
        "TRAINER_CHARLIE",
        "TRAINER_CHARLOTTE",
        "TRAINER_CHASE",
        "TRAINER_CHESTER",
        "TRAINER_CHIP",
        "TRAINER_CHRIS",
        "TRAINER_CINDY_1",
        "TRAINER_CLARENCE",
        "TRAINER_CLARISSA",
        "TRAINER_CLARK",
        "TRAINER_CLAUDE",
        "TRAINER_CLIFFORD",
        "TRAINER_COBY",
        "TRAINER_COLE",
        "TRAINER_COLIN",
        "TRAINER_COLTON",
        "TRAINER_CONNIE",
        "TRAINER_CONOR",
        "TRAINER_CORY_1",
        "TRAINER_CRISSY",
        "TRAINER_CRISTIAN",
        "TRAINER_CRISTIN_1",
        "TRAINER_CYNDY_1",
        "TRAINER_DAISUKE",
        "TRAINER_DAISY",
        "TRAINER_DALE",
        "TRAINER_DALTON_1",
        "TRAINER_DANA",
        "TRAINER_DANIELLE",
        "TRAINER_DAPHNE",
        "TRAINER_DARCY",
        "TRAINER_DARIAN",
        "TRAINER_DARIUS",
        "TRAINER_DARRIN",
        "TRAINER_DAVID",
        "TRAINER_DAVIS",
        "TRAINER_DAWSON",
        "TRAINER_DAYTON",
        "TRAINER_DEANDRE",
        "TRAINER_DEAN",
        "TRAINER_DEBRA",
        "TRAINER_DECLAN",
        "TRAINER_DEMETRIUS",
        "TRAINER_DENISE",
        "TRAINER_DEREK",
        "TRAINER_DEVAN",
        "TRAINER_DEZ_AND_LUKE",
        "TRAINER_DIANA_1",
        "TRAINER_DIANNE",
        "TRAINER_DILLON",
        "TRAINER_DOMINIK",
        "TRAINER_DONALD",
        "TRAINER_DONNY",
        "TRAINER_DOUGLAS",
        "TRAINER_DOUG",
        "TRAINER_DRAKE",
        "TRAINER_DREW",
        "TRAINER_DUNCAN",
        "TRAINER_DUSTY_1",
        "TRAINER_DWAYNE",
        "TRAINER_DYLAN_1",
        "TRAINER_EDGAR",
        "TRAINER_EDMOND",
        "TRAINER_EDWARDO",
        "TRAINER_EDWARD",
        "TRAINER_EDWIN_1",
        "TRAINER_ED",
        "TRAINER_ELIJAH",
        "TRAINER_ELI",
        "TRAINER_ELLIOT_1",
        "TRAINER_ERIC",
        "TRAINER_ERNEST_1",
        "TRAINER_ETHAN_1",
        "TRAINER_FABIAN",
        "TRAINER_FELIX",
        "TRAINER_FERNANDO_1",
        "TRAINER_FLANNERY_1",
        "TRAINER_FLINT",
        "TRAINER_FOSTER",
        "TRAINER_FRANKLIN",
        "TRAINER_FREDRICK",
        "TRAINER_GABRIELLE_1",
        "TRAINER_GARRET",
        "TRAINER_GARRISON",
        "TRAINER_GEORGE",
        "TRAINER_GERALD",
        "TRAINER_GILBERT",
        "TRAINER_GINA_AND_MIA_1",
        "TRAINER_GLACIA",
        "TRAINER_GRACE",
        "TRAINER_GREG",
        "TRAINER_GRUNT_AQUA_HIDEOUT_1",
        "TRAINER_GRUNT_AQUA_HIDEOUT_2",
        "TRAINER_GRUNT_AQUA_HIDEOUT_3",
        "TRAINER_GRUNT_AQUA_HIDEOUT_4",
        "TRAINER_GRUNT_AQUA_HIDEOUT_5",
        "TRAINER_GRUNT_AQUA_HIDEOUT_6",
        "TRAINER_GRUNT_AQUA_HIDEOUT_7",
        "TRAINER_GRUNT_AQUA_HIDEOUT_8",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_10",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_11",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_12",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_13",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_14",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_15",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_16",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_1",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_2",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_3",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_4",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_5",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_6",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_7",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_8",
        "TRAINER_GRUNT_MAGMA_HIDEOUT_9",
        "TRAINER_GRUNT_MT_CHIMNEY_1",
        "TRAINER_GRUNT_MT_CHIMNEY_2",
        "TRAINER_GRUNT_MT_PYRE_1",
        "TRAINER_GRUNT_MT_PYRE_2",
        "TRAINER_GRUNT_MT_PYRE_3",
        "TRAINER_GRUNT_MT_PYRE_4",
        "TRAINER_GRUNT_MUSEUM_1",
        "TRAINER_GRUNT_MUSEUM_2",
        "TRAINER_GRUNT_PETALBURG_WOODS",
        "TRAINER_GRUNT_RUSTURF_TUNNEL",
        "TRAINER_GRUNT_SEAFLOOR_CAVERN_1",
        "TRAINER_GRUNT_SEAFLOOR_CAVERN_2",
        "TRAINER_GRUNT_SEAFLOOR_CAVERN_3",
        "TRAINER_GRUNT_SEAFLOOR_CAVERN_4",
        "TRAINER_GRUNT_SEAFLOOR_CAVERN_5",
        "TRAINER_GRUNT_SPACE_CENTER_1",
        "TRAINER_GRUNT_SPACE_CENTER_2",
        "TRAINER_GRUNT_SPACE_CENTER_3",
        "TRAINER_GRUNT_SPACE_CENTER_4",
        "TRAINER_GRUNT_SPACE_CENTER_5",
        "TRAINER_GRUNT_SPACE_CENTER_6",
        "TRAINER_GRUNT_SPACE_CENTER_7",
        "TRAINER_GRUNT_WEATHER_INST_1",
        "TRAINER_GRUNT_WEATHER_INST_2",
        "TRAINER_GRUNT_WEATHER_INST_3",
        "TRAINER_GRUNT_WEATHER_INST_4",
        "TRAINER_GRUNT_WEATHER_INST_5",
        "TRAINER_GWEN",
        "TRAINER_HAILEY",
        "TRAINER_HALEY_1",
        "TRAINER_HALLE",
        "TRAINER_HANNAH",
        "TRAINER_HARRISON",
        "TRAINER_HAYDEN",
        "TRAINER_HECTOR",
        "TRAINER_HEIDI",
        "TRAINER_HELENE",
        "TRAINER_HENRY",
        "TRAINER_HERMAN",
        "TRAINER_HIDEO",
        "TRAINER_HITOSHI",
        "TRAINER_HOPE",
        "TRAINER_HUDSON",
        "TRAINER_HUEY",
        "TRAINER_HUGH",
        "TRAINER_HUMBERTO",
        "TRAINER_IMANI",
        "TRAINER_IRENE",
        "TRAINER_ISAAC_1",
        "TRAINER_ISABELLA",
        "TRAINER_ISABELLE",
        "TRAINER_ISABEL_1",
        "TRAINER_ISAIAH_1",
        "TRAINER_ISOBEL",
        "TRAINER_IVAN",
        "TRAINER_JACE",
        "TRAINER_JACKI_1",
        "TRAINER_JACKSON_1",
        "TRAINER_JACK",
        "TRAINER_JACLYN",
        "TRAINER_JACOB",
        "TRAINER_JAIDEN",
        "TRAINER_JAMES_1",
        "TRAINER_JANICE",
        "TRAINER_JANI",
        "TRAINER_JARED",
        "TRAINER_JASMINE",
        "TRAINER_JAYLEN",
        "TRAINER_JAZMYN",
        "TRAINER_JEFFREY_1",
        "TRAINER_JEFF",
        "TRAINER_JENNA",
        "TRAINER_JENNIFER",
        "TRAINER_JENNY_1",
        "TRAINER_JEROME",
        "TRAINER_JERRY_1",
        "TRAINER_JESSICA_1",
        "TRAINER_JOCELYN",
        "TRAINER_JODY",
        "TRAINER_JOEY",
        "TRAINER_JOHANNA",
        "TRAINER_JOHN_AND_JAY_1",
        "TRAINER_JOHNSON",
        "TRAINER_JONAH",
        "TRAINER_JONAS",
        "TRAINER_JONATHAN",
        "TRAINER_JOSEPH",
        "TRAINER_JOSE",
        "TRAINER_JOSH",
        "TRAINER_JOSUE",
        "TRAINER_JUAN_1",
        "TRAINER_JULIE",
        "TRAINER_JULIO",
        "TRAINER_KAI",
        "TRAINER_KALEB",
        "TRAINER_KARA",
        "TRAINER_KAREN_1",
        "TRAINER_KATE_AND_JOY",
        "TRAINER_KATELYNN",
        "TRAINER_KATELYN_1",
        "TRAINER_KATHLEEN",
        "TRAINER_KATIE",
        "TRAINER_KAYLA",
        "TRAINER_KAYLEY",
        "TRAINER_KEEGAN",
        "TRAINER_KEIGO",
        "TRAINER_KELVIN",
        "TRAINER_KENT",
        "TRAINER_KEVIN",
        "TRAINER_KIM_AND_IRIS",
        "TRAINER_KINDRA",
        "TRAINER_KIRA_AND_DAN_1",
        "TRAINER_KIRK",
        "TRAINER_KIYO",
        "TRAINER_KOICHI",
        "TRAINER_KOJI_1",
        "TRAINER_KYLA",
        "TRAINER_KYRA",
        "TRAINER_LAO_1",
        "TRAINER_LARRY",
        "TRAINER_LAURA",
        "TRAINER_LAUREL",
        "TRAINER_LAWRENCE",
        "TRAINER_LEA_AND_JED",
        "TRAINER_LEAH",
        "TRAINER_LENNY",
        "TRAINER_LEONARDO",
        "TRAINER_LEONARD",
        "TRAINER_LEONEL",
        "TRAINER_LILA_AND_ROY_1",
        "TRAINER_LILITH",
        "TRAINER_LINDA",
        "TRAINER_LISA_AND_RAY",
        "TRAINER_LOLA_1",
        "TRAINER_LORENZO",
        "TRAINER_LUCAS_1",
        "TRAINER_LUIS",
        "TRAINER_LUNG",
        "TRAINER_LYDIA_1",
        "TRAINER_LYLE",
        "TRAINER_MACEY",
        "TRAINER_MADELINE_1",
        "TRAINER_MAKAYLA",
        "TRAINER_MARCEL",
        "TRAINER_MARCOS",
        "TRAINER_MARC",
        "TRAINER_MARIA_1",
        "TRAINER_MARK",
        "TRAINER_MARLENE",
        "TRAINER_MARLEY",
        "TRAINER_MARY",
        "TRAINER_MATTHEW",
        "TRAINER_MATT",
        "TRAINER_MAURA",
        "TRAINER_MAXIE_MAGMA_HIDEOUT",
        "TRAINER_MAXIE_MT_CHIMNEY",
        "TRAINER_MAY_LILYCOVE_MUDKIP",
        "TRAINER_MAY_LILYCOVE_TORCHIC",
        "TRAINER_MAY_LILYCOVE_TREECKO",
        "TRAINER_MAY_ROUTE_103_MUDKIP",
        "TRAINER_MAY_ROUTE_103_TORCHIC",
        "TRAINER_MAY_ROUTE_103_TREECKO",
        "TRAINER_MAY_ROUTE_110_MUDKIP",
        "TRAINER_MAY_ROUTE_110_TORCHIC",
        "TRAINER_MAY_ROUTE_110_TREECKO",
        "TRAINER_MAY_ROUTE_119_MUDKIP",
        "TRAINER_MAY_ROUTE_119_TORCHIC",
        "TRAINER_MAY_ROUTE_119_TREECKO",
        "TRAINER_MAY_RUSTBORO_MUDKIP",
        "TRAINER_MAY_RUSTBORO_TORCHIC",
        "TRAINER_MAY_RUSTBORO_TREECKO",
        "TRAINER_MEL_AND_PAUL",
        "TRAINER_MELINA",
        "TRAINER_MELISSA",
        "TRAINER_MICAH",
        "TRAINER_MICHELLE",
        "TRAINER_MIGUEL_1",
        "TRAINER_MIKE_2",
        "TRAINER_MISSY",
        "TRAINER_MITCHELL",
        "TRAINER_MIU_AND_YUKI",
        "TRAINER_MOLLIE",
        "TRAINER_MYLES",
        "TRAINER_NANCY",
        "TRAINER_NAOMI",
        "TRAINER_NATE",
        "TRAINER_NED",
        "TRAINER_NICHOLAS",
        "TRAINER_NICOLAS_1",
        "TRAINER_NIKKI",
        "TRAINER_NOB_1",
        "TRAINER_NOLAN",
        "TRAINER_NOLEN",
        "TRAINER_NORMAN_1",
        "TRAINER_OLIVIA",
        "TRAINER_OWEN",
        "TRAINER_PABLO_1",
        "TRAINER_PARKER",
        "TRAINER_PAT",
        "TRAINER_PAXTON",
        "TRAINER_PERRY",
        "TRAINER_PETE",
        "TRAINER_PHILLIP",
        "TRAINER_PHIL",
        "TRAINER_PHOEBE",
        "TRAINER_PRESLEY",
        "TRAINER_PRESTON",
        "TRAINER_QUINCY",
        "TRAINER_RACHEL",
        "TRAINER_RANDALL",
        "TRAINER_REED",
        "TRAINER_RELI_AND_IAN",
        "TRAINER_REYNA",
        "TRAINER_RHETT",
        "TRAINER_RICHARD",
        "TRAINER_RICKY_1",
        "TRAINER_RICK",
        "TRAINER_RILEY",
        "TRAINER_ROBERT_1",
        "TRAINER_RODNEY",
        "TRAINER_ROGER",
        "TRAINER_ROLAND",
        "TRAINER_RONALD",
        "TRAINER_ROSE_1",
        "TRAINER_ROXANNE_1",
        "TRAINER_RUBEN",
        "TRAINER_SAMANTHA",
        "TRAINER_SAMUEL",
        "TRAINER_SANTIAGO",
        "TRAINER_SARAH",
        "TRAINER_SAWYER_1",
        "TRAINER_SHANE",
        "TRAINER_SHANNON",
        "TRAINER_SHARON",
        "TRAINER_SHAWN",
        "TRAINER_SHAYLA",
        "TRAINER_SHEILA",
        "TRAINER_SHELBY_1",
        "TRAINER_SHELLY_SEAFLOOR_CAVERN",
        "TRAINER_SHELLY_WEATHER_INSTITUTE",
        "TRAINER_SHIRLEY",
        "TRAINER_SIDNEY",
        "TRAINER_SIENNA",
        "TRAINER_SIMON",
        "TRAINER_SOPHIE",
        "TRAINER_SPENCER",
        "TRAINER_STAN",
        "TRAINER_STEVEN",
        "TRAINER_STEVE_1",
        "TRAINER_SUSIE",
        "TRAINER_SYLVIA",
        "TRAINER_TABITHA_MAGMA_HIDEOUT",
        "TRAINER_TABITHA_MT_CHIMNEY",
        "TRAINER_TAKAO",
        "TRAINER_TAKASHI",
        "TRAINER_TALIA",
        "TRAINER_TAMMY",
        "TRAINER_TANYA",
        "TRAINER_TARA",
        "TRAINER_TASHA",
        "TRAINER_TATE_AND_LIZA_1",
        "TRAINER_TAYLOR",
        "TRAINER_THALIA_1",
        "TRAINER_THOMAS",
        "TRAINER_TIANA",
        "TRAINER_TIFFANY",
        "TRAINER_TIMMY",
        "TRAINER_TIMOTHY_1",
        "TRAINER_TISHA",
        "TRAINER_TOMMY",
        "TRAINER_TONY_1",
        "TRAINER_TORI_AND_TIA",
        "TRAINER_TRAVIS",
        "TRAINER_TRENT_1",
        "TRAINER_TYRA_AND_IVY",
        "TRAINER_TYRON",
        "TRAINER_VALERIE_1",
        "TRAINER_VANESSA",
        "TRAINER_VICKY",
        "TRAINER_VICTORIA",
        "TRAINER_VICTOR",
        "TRAINER_VIOLET",
        "TRAINER_VIRGIL",
        "TRAINER_VITO",
        "TRAINER_VIVIAN",
        "TRAINER_VIVI",
        "TRAINER_WADE",
        "TRAINER_WALLACE",
        "TRAINER_WALTER_1",
        "TRAINER_WALLY_MAUVILLE",
        "TRAINER_WALLY_VR_1",
        "TRAINER_WATTSON_1",
        "TRAINER_WARREN",
        "TRAINER_WAYNE",
        "TRAINER_WENDY",
        "TRAINER_WILLIAM",
        "TRAINER_WILTON_1",
        "TRAINER_WINONA_1",
        "TRAINER_WINSTON_1",
        "TRAINER_WYATT",
        "TRAINER_YASU",
        "TRAINER_ZANDER",
    };
    for (auto const& trainer_name : trainer_names)
    {
        uint16_t trainer_id = constants_json[trainer_name];

        uint8_t trainer_class;
        rom.seekg(misc_rom_addresses["gTrainers"] + (trainer_id * 0x28) + 1, rom.beg);
        rom.read((char*)&(trainer_class), 1);

        uint16_t reward_value = trainers[trainer_id]->party.back().level * 4;

        std::shared_ptr<LocationInfo> item(new LocationInfo());
        item->name = trainer_name + "_REWARD";
        item->flag = trainer_id + (uint16_t)constants_json["TRAINER_FLAGS_START"];
        item->address = symbol_map["sTrainerRewards"] + (trainer_id * 2) - ROM_START;

        switch (trainer_class)
        {
            case 0x12:  // TRAINER_CLASS_TUBER_F
            case 0x13:  // TRAINER_CLASS_TUBER_M
                reward_value *= 1;
                break;
            case 0x08:  // TRAINER_CLASS_SWIMMER_M
            case 0x2D:  // TRAINER_CLASS_SWIMMER_F
                reward_value *= 2;
                break;
            case 0x2A:  // TRAINER_CLASS_NINJA_BOY
            case 0x2E:  // TRAINER_CLASS_TWINS
            case 0x39:  // TRAINER_CLASS_SIS_AND_BRO
                reward_value *= 3;
                break;
            case 0x1A:  // TRAINER_CLASS_CAMPER
            case 0x1B:  // TRAINER_CLASS_PICNICKER
            case 0x22:  // TRAINER_CLASS_SR_AND_JR
            case 0x25:  // TRAINER_CLASS_YOUNGSTER
            case 0x33:  // TRAINER_CLASS_BUG_CATCHER
            case 0x36:  // TRAINER_CLASS_LASS
                reward_value *= 4;
                break;
            case 0x0E:  // TRAINER_CLASS_HEX_MANIAC
            case 0x1D:  // TRAINER_CLASS_PSYCHIC
            case 0x2B:  // TRAINER_CLASS_BATTLE_GIRL
                reward_value *= 6;
                break;
            case 0x06:  // TRAINER_CLASS_BIRD_KEEPER
            case 0x0C:  // TRAINER_CLASS_BLACK_BELT
            case 0x18:  // TRAINER_CLASS_GUITARIST
            case 0x19:  // TRAINER_CLASS_KINDLER
            case 0x2F:  // TRAINER_CLASS_SAILOR
            case 0x37:  // TRAINER_CLASS_YOUNG_COUPLE
                reward_value *= 8;
                break;
            case 0x02:  // TRAINER_CLASS_HIKER
            case 0x04:  // TRAINER_CLASS_PKMN_BREEDER
            case 0x0A:  // TRAINER_CLASS_EXPERT
            case 0x0B:  // TRAINER_CLASS_AQUA_ADMIN
            case 0x0F:  // TRAINER_CLASS_AROMA_LADY
            case 0x23:  // TRAINER_CLASS_WINSTRATE
            case 0x27:  // TRAINER_CLASS_FISHERMAN
            case 0x28:  // TRAINER_CLASS_TRIATHLETE
            case 0x2C:  // TRAINER_CLASS_PARASOL_LADY
            case 0x31:  // TRAINER_CLASS_MAGMA_ADMIN
            case 0x38:  // TRAINER_CLASS_OLD_COUPLE
                reward_value *= 10;
                break;
            case 0x05:  // TRAINER_CLASS_COOLTRAINER
            case 0x11:  // TRAINER_CLASS_INTERVIEWER
            case 0x29:  // TRAINER_CLASS_DRAGON_TAMER
            case 0x34:  // TRAINER_CLASS_PKMN_RANGER
                reward_value *= 12;
                break;
            case 0x07:  // TRAINER_CLASS_COLLECTOR
            case 0x10:  // TRAINER_CLASS_RUIN_MANIAC
            case 0x17:  // TRAINER_CLASS_POKEMANIAC
            case 0x1C:  // TRAINER_CLASS_BUG_MANIAC
            case 0x32:  // TRAINER_CLASS_RIVAL
                reward_value *= 15;
                break;
            case 0x0D:  // TRAINER_CLASS_AQUA_LEADER
            case 0x15:  // TRAINER_CLASS_BEAUTY
            case 0x1E:  // TRAINER_CLASS_GENTLEMAN
            case 0x24:  // TRAINER_CLASS_POKEFAN
            case 0x35:  // TRAINER_CLASS_MAGMA_LEADER
                reward_value *= 20;
                break;
            case 0x1F:  // TRAINER_CLASS_ELITE_FOUR
            case 0x20:  // TRAINER_CLASS_LEADER
                reward_value *= 25;
                break;
            case 0x14:  // TRAINER_CLASS_LADY
            case 0x16:  // TRAINER_CLASS_RICH_BOY
            case 0x26:  // TRAINER_CLASS_CHAMPION
                reward_value *= 50;
                break;
            default:
                reward_value *= 5;
                break;
        }

        if (reward_value < 250)
            item->default_item = constants_json["ITEM_TINY_MUSHROOM"];
        else if (reward_value < 700)
            item->default_item = constants_json["ITEM_PEARL"];
        else if (reward_value < 1000)
            item->default_item = constants_json["ITEM_STARDUST"];
        else if (reward_value < 2500)
            item->default_item = constants_json["ITEM_BIG_MUSHROOM"];
        else if (reward_value < 3750)
            item->default_item = constants_json["ITEM_BIG_PEARL"];
        else if (reward_value < 4900)
            item->default_item = constants_json["ITEM_STAR_PIECE"];
        else
            item->default_item = constants_json["ITEM_NUGGET"];

        trainer_rewards.push_back(item);
    }

    // ------------------------------------------------------------------------
    // Reading map.json files
    // ------------------------------------------------------------------------
    std::cout << "Reading maps..." << std::endl;
    std::vector<std::shared_ptr<LocationInfo>> ball_items;
    std::vector<std::shared_ptr<LocationInfo>> hidden_items;
    std::map<std::string, std::shared_ptr<MapInfo>> maps;
    std::vector<std::shared_ptr<WarpInfo>> warps;

    for(const auto& entry: std::filesystem::directory_iterator(root_dir / "data/maps/"))
    {
        if (entry.is_directory())
        {
            std::ifstream map_file(entry.path() / "map.json");
            json map_data_json = json::parse(map_file);

            std::shared_ptr<MapInfo> map(new MapInfo());
            map->name = map_data_json["id"];
            maps[map->name] = map;
            map->header_address = symbol_map[(std::string)map_data_json["name"]] - ROM_START;

            // ----------------------------------------------------------------
            // Warps
            // ----------------------------------------------------------------

            // Many warps are actually two or three events acting as one logical warp.
            // Doorways, for example, are often 2 tiles wide indoors but
            // only 1 tile wide outdoors. Both indoor warps point to the
            // outdoor warp, and the outdoor warp points to only one of the
            // indoor warps. There are also warps that are 2 tiles wide and lead to
            // a corresponding pair of warps. We want to describe warps logically in a way that
            // retains information about individual warp events.
            //
            // This is how warps are encoded:
            //
            // {source_map}:{source_warp_ids}/{dest_map}:{dest_warp_id}[!]
            //    source_map:       The map the warp events are located in
            //    source_warp_ids:  The ids of all adjacent warp events in source_map
            //                      (these must be in ascending order)
            //    dest_map:         The map of the warp event to which this one is connected
            //    dest_warp_ids:     The ids of the warp events in dest_map
            //    [!]:              If the warp expects to lead to a destination which does
            //                      not lead back to it, add a ! to the end
            //
            // Example:   MAP_LAVARIDGE_TOWN_HOUSE:0,1/MAP_LAVARIDGE_TOWN:4
            // Example 2: MAP_AQUA_HIDEOUT_B1F:14/MAP_AQUA_HIDEOUT_B1F:12!
            //
            // Note: A warp must have its destination set as another warp event.
            // However, that does not guarantee that the destination warp event
            // will warp back to the source. There are (few) one-way warps.
            //
            // Note2: Some warp destinations go to the map "MAP_DYNAMIC" and
            // have a warp id which is not a number. These edge cases are:
            //   - The Moving Truck
            //   - Terra Cave
            //   - Marine Cave
            //   - The Department Store Elevator
            //   - Secret Bases
            //   - The Trade Center
            //   - The Union Room
            //   - The Record Corner
            //   - 2P/4P Battle Colosseum

            map->warp_table_address = symbol_map[(std::string)map_data_json["name"] + "_MapWarps"] - ROM_START;

            json warp_events_json = map_data_json["warp_events"];
            // (id, x, y, destination_map, destination_id)
            std::vector<std::shared_ptr<WarpInfo>> map_warps;
            uint i = 0;
            for (const auto& warp_json: warp_events_json)
            {
                std::shared_ptr<WarpInfo> warp(new WarpInfo());
                warp->source_map = map->name;
                warp->source_indices.push_back(i);
                warp->source_coordinates.push_back(std::tuple<int, int>(warp_json["x"], warp_json["y"]));
                warp->dest_map = warp_json["dest_map"];
                if (warp_json["dest_warp_id"] == "WARP_ID_DYNAMIC")
                {
                    warp->dest_indices.push_back(-1);
                }
                else if (warp_json["dest_warp_id"] == "WARP_ID_SECRET_BASE")
                {
                    warp->dest_indices.push_back(-2);
                }
                else
                {
                    warp->dest_indices.push_back(std::stoi(static_cast<std::string>(warp_json["dest_warp_id"])));
                }

                map_warps.push_back(warp);
                ++i;
            }

            // Sort so that adjacency checker only needs to check against the
            // previously found matching warp. Otherwise would have to do a
            // recursive flood of some sort.
            std::sort(
                map_warps.begin(), map_warps.end(),
                [](std::shared_ptr<WarpInfo> a, std::shared_ptr<WarpInfo> b)
                {
                    return std::get<0>(a->source_coordinates[0]) == std::get<0>(b->source_coordinates[0])
                        ? std::get<1>(a->source_coordinates[0]) < std::get<1>(b->source_coordinates[0])
                        : std::get<0>(a->source_coordinates[0]) < std::get<0>(b->source_coordinates[0]);
                }
            );

            // Group warps by whether they're logically the same
            std::vector<std::shared_ptr<WarpInfo>> grouped_warps;
            std::vector<bool> is_collected(map_warps.size());
            for (uint i = 0; i < map_warps.size(); ++i)
            {
                if (is_collected[i]) continue;

                const auto warp = map_warps[i];
                is_collected[i] = true;

                for (uint j = i + 1; j < map_warps.size(); ++j)
                {
                    const auto other_warp = map_warps[j];

                    // Check destination map to exit early, but we're assuming that adjacent
                    // warps are always part of the same logical warp
                    if (warp->dest_map != other_warp->dest_map) continue;
                    // Check adjacency
                    if (
                        abs(std::get<0>(warp->source_coordinates.back()) - std::get<0>(other_warp->source_coordinates[0])) +
                        abs(std::get<1>(warp->source_coordinates.back()) - std::get<1>(other_warp->source_coordinates[0])) > 1
                    ) continue;

                    if (
                        map->name == "MAP_ROUTE110_TRICK_HOUSE_PUZZLE7" &&
                        (warp->source_indices[0] == 9 || warp->source_indices[0] == 11)
                    ) continue; // These are the only two warps in the game which are adjacent but go to completely different places

                    warp->source_indices.push_back(other_warp->source_indices[0]);
                    warp->dest_indices.push_back(other_warp->dest_indices[0]);
                    warp->source_coordinates.push_back(other_warp->source_coordinates[0]);
                    is_collected[j] = true;
                }
                grouped_warps.push_back(warp);
            }

            for (const auto warp: grouped_warps)
            {
                warps.push_back(warp);
            }

            // ----------------------------------------------------------------
            // Items
            // ----------------------------------------------------------------
            json object_events_json = map_data_json["object_events"];
            for (const auto& event_json: object_events_json)
            {
                std::string flag_name = event_json["flag"].get<std::string>();
                if (flag_name.substr(0, 9) == "FLAG_ITEM")
                {
                    std::shared_ptr<LocationInfo> item(new LocationInfo());
                    item->flag = constants_json[flag_name];
                    item->name = flag_name.substr(5);
                    item->address = symbol_map[event_json["script"]] + 3 - ROM_START;
                    ball_items.push_back(item);
                }
            }

            json bg_events_json = map_data_json["bg_events"];
            for (const auto& event_json: bg_events_json)
            {
                if (event_json["type"] == "hidden_item")
                {
                    std::string flag_name = event_json["flag"].get<std::string>();
                    std::shared_ptr<LocationInfo> item(new LocationInfo());
                    item->flag = constants_json[flag_name];
                    item->name = flag_name.substr(5);
                    item->address = symbol_map["Archipelago_Target_Hidden_Item_" + flag_name] + 8 - ROM_START;
                    item->default_item = constants_json[event_json["item"].get<std::string>()];
                    hidden_items.push_back(item);
                }
            }
        }
    }

    // Now that all warps are created we can check 1-way
    for (const auto &warp: warps)
    {
        for (const auto &other_warp: warps)
        {
            if (warp == other_warp) continue;
            if (warp->connects_to(*other_warp))
            {
                // Found our destination
                if (other_warp->connects_to(*warp))
                {
                    warp->is_one_way = false;
                }

                break;
            }
        }
    }

    // ------------------------------------------------------------------------
    // Reading encounter tables
    // ------------------------------------------------------------------------
    std::cout << "Reading encounter tables..." << std::endl;
    std::ifstream wild_encounters_file(root_dir / "src/data/wild_encounters.json");
    json wild_encounters_json = json::parse(wild_encounters_file);

    for (const auto& map_json: wild_encounters_json["wild_encounter_groups"][0]["encounters"]) {
        std::shared_ptr<MapInfo> map = maps[map_json["map"]];

        // Altering Cave is the only map with multiple encounter tables.
        // It is supposed to switch between them based on a value set by an unreleased event.
        // The only vanilla table is the first one, with all Zubats.
        if (map->name == "MAP_ALTERING_CAVE" && map_json["base_label"] != "gAlteringCave1") continue;

        std::string base_symbol = map_json["base_label"];

        map->land_encounters.ram_address = symbol_map[base_symbol + "_LandMons"];
        map->land_encounters.address = map->land_encounters.ram_address - ROM_START;
        map->water_encounters.ram_address = symbol_map[base_symbol + "_WaterMons"];
        map->water_encounters.address = map->water_encounters.ram_address - ROM_START;
        map->fishing_encounters.ram_address = symbol_map[base_symbol + "_FishingMons"];
        map->fishing_encounters.address = map->fishing_encounters.ram_address - ROM_START;
        map->rock_smash_encounters.ram_address = symbol_map[base_symbol + "_RockSmashMons"];
        map->rock_smash_encounters.address = map->rock_smash_encounters.ram_address - ROM_START;

        try
        {
            for (const auto& encounter_slot_json: map_json.at("land_mons")["mons"]) {
                auto slot = std::shared_ptr<EncounterSlotInfo>(new EncounterSlotInfo());
                map->land_encounters.encounter_slots.push_back(slot);
                slot->default_species = constants_json[encounter_slot_json["species"].get<std::string>()];
                slot->min_level = encounter_slot_json["min_level"];
                slot->max_level = encounter_slot_json["max_level"];
            }
            map->land_encounters.exists = true;
        }
        catch (const json::exception &e)
        {
            if (e.id != 403) {
                throw e;
            }
        }

        try
        {
            for (const auto& encounter_slot_json: map_json.at("water_mons")["mons"]) {
                auto slot = std::shared_ptr<EncounterSlotInfo>(new EncounterSlotInfo());
                map->water_encounters.encounter_slots.push_back(slot);
                slot->default_species = constants_json[encounter_slot_json["species"].get<std::string>()];
                slot->min_level = encounter_slot_json["min_level"];
                slot->max_level = encounter_slot_json["max_level"];
            }
            map->water_encounters.exists = true;
        }
        catch (const json::exception &e)
        {
            if (e.id != 403) {
                throw e;
            }
        }

        try
        {
            for (const auto& encounter_slot_json: map_json.at("fishing_mons")["mons"]) {
                auto slot = std::shared_ptr<EncounterSlotInfo>(new EncounterSlotInfo());
                map->fishing_encounters.encounter_slots.push_back(slot);
                slot->default_species = constants_json[encounter_slot_json["species"].get<std::string>()];
                slot->min_level = encounter_slot_json["min_level"];
                slot->max_level = encounter_slot_json["max_level"];
            }
            map->fishing_encounters.exists = true;
        }
        catch (const json::exception &e)
        {
            if (e.id != 403) {
                throw e;
            }
        }

        try
        {
            for (const auto& encounter_slot_json: map_json.at("rock_smash_mons")["mons"]) {
                auto slot = std::shared_ptr<EncounterSlotInfo>(new EncounterSlotInfo());
                map->rock_smash_encounters.encounter_slots.push_back(slot);
                slot->default_species = constants_json[encounter_slot_json["species"].get<std::string>()];
                slot->min_level = encounter_slot_json["min_level"];
                slot->max_level = encounter_slot_json["max_level"];
            }
            map->rock_smash_encounters.exists = true;
        }
        catch (const json::exception &e)
        {
            if (e.id != 403) {
                throw e;
            }
        }
    }

    // Reading static encounters
    std::vector<std::shared_ptr<MiscPokemonInfo>> misc_pokemon;
    for (auto const& [symbol, address] : symbol_map)
    {
        if (symbol.substr(0, 36) == "Archipelago_Target_Static_Encounter_")
        {
            std::shared_ptr<MiscPokemonInfo> static_encounter(new MiscPokemonInfo());

            static_encounter->name = symbol.substr(36);
            static_encounter->address = address + 1 - ROM_START;
            rom.seekg(static_encounter->address, rom.beg);
            rom.read((char*)&(static_encounter->species), 2);
            misc_pokemon.push_back(static_encounter);
        }
        else if (symbol == "Archipelago_Target_Special_Gift_Castform")
        {
            std::shared_ptr<MiscPokemonInfo> castform_gift(new MiscPokemonInfo());

            castform_gift->name = "Castform Gift";
            castform_gift->address = address + 3 - ROM_START;
            rom.seekg(castform_gift->address, rom.beg);
            rom.read((char*)&(castform_gift->species), 2);
            misc_pokemon.push_back(castform_gift);
        }
        else if (symbol == "Archipelago_Target_Special_Gift_Wynaut_Egg")
        {
            std::shared_ptr<MiscPokemonInfo> wynaut_egg_gift(new MiscPokemonInfo());

            wynaut_egg_gift->name = "Wynaut Egg Gift";
            wynaut_egg_gift->address = address + 1 - ROM_START;
            rom.seekg(wynaut_egg_gift->address, rom.beg);
            rom.read((char*)&(wynaut_egg_gift->species), 2);
            misc_pokemon.push_back(wynaut_egg_gift);
        }
    }

    // Reading legendary encounters
    std::vector<std::shared_ptr<LegendaryEncounterInfo>> legendary_encounters;
    for (auto const& [symbol, address] : symbol_map)
    {
        if (symbol.substr(0, 39) == "Archipelago_Target_Legendary_Encounter_")
        {
            std::shared_ptr<LegendaryEncounterInfo> legendary_encounter(new LegendaryEncounterInfo());

            legendary_encounter->name = symbol.substr(39);
            legendary_encounter->address = address + 1 - ROM_START;
            rom.seekg(legendary_encounter->address, rom.beg);
            rom.read((char*)&(legendary_encounter->species), 2);
            rom.read((char*)&(legendary_encounter->level), 1);
            legendary_encounter->defeat_flag = constants_json["FLAG_DEFEATED_" + legendary_encounter->name];
            if (constants_json.contains("FLAG_CAUGHT_" + legendary_encounter->name))
            {
                legendary_encounter->catch_flag = constants_json["FLAG_CAUGHT_" + legendary_encounter->name];
            }
            legendary_encounters.push_back(legendary_encounter);
        }
    }

    // Reading species info
    std::vector<std::shared_ptr<SpeciesInfo>> all_species;
    for (size_t i = 0; i < constants_json["NUM_SPECIES"]; ++i)
    {
        std::shared_ptr<SpeciesInfo> species(new SpeciesInfo());

        species->id = i;
        species->address = misc_rom_addresses["gSpeciesInfo"] + (i * 28);

        // Base Stats
        rom.seekg(species->address + 0, rom.beg);
        rom.read((char*)&(species->base_stats[0]), 1);
        rom.seekg(species->address + 1, rom.beg);
        rom.read((char*)&(species->base_stats[1]), 1);
        rom.seekg(species->address + 2, rom.beg);
        rom.read((char*)&(species->base_stats[2]), 1);
        rom.seekg(species->address + 3, rom.beg);
        rom.read((char*)&(species->base_stats[3]), 1);
        rom.seekg(species->address + 4, rom.beg);
        rom.read((char*)&(species->base_stats[4]), 1);
        rom.seekg(species->address + 5, rom.beg);
        rom.read((char*)&(species->base_stats[5]), 1);

        // Types
        rom.seekg(species->address + 6, rom.beg);
        rom.read((char*)&(species->types[0]), 1);
        rom.seekg(species->address + 7, rom.beg);
        rom.read((char*)&(species->types[1]), 1);

        // Catch Rate
        rom.seekg(species->address + 8, rom.beg);
        rom.read((char*)&(species->catch_rate), 1);

        // Friendship
        rom.seekg(species->address + 18, rom.beg);
        rom.read((char*)&(species->friendship), 1);

        // Abilities
        rom.seekg(species->address + 22, rom.beg);
        rom.read((char*)&(species->abilities[0]), 1);
        rom.seekg(species->address + 23, rom.beg);
        rom.read((char*)&(species->abilities[1]), 1);

        all_species.push_back(species);
    }

    // Reading learnsets
    for (size_t i = 0; i < constants_json["NUM_SPECIES"]; ++i)
    {
        const auto &species = all_species[i];

        uint32_t learnset_pointer;
        rom.seekg(misc_rom_addresses["gLevelUpLearnsets"] + (i * 4), rom.beg);
        rom.read((char*)&(learnset_pointer), 4);
        learnset_pointer -= ROM_START;
        species->learnset_info.address = learnset_pointer;

        uint16_t move;
        size_t move_i = 0;
        do
        {
            rom.seekg(learnset_pointer + (move_i * 2), rom.beg);
            rom.read((char*)&(move), 2);

            if (move != 0xFFFF)
            {
                uint8_t level = move >> 9;
                uint16_t move_id = move & 0x1FF;

                species->learnset_info.moves.push_back(std::tuple<uint8_t, uint16_t>(level, move_id));
            }

            ++move_i;
        }
        while (move != 0xFFFF);
    }

    // Reading TM/HM learnsets
    for (size_t i = 0; i < constants_json["NUM_SPECIES"]; ++i)
    {
        const auto &species = all_species[i];

        rom.seekg(misc_rom_addresses["gTMHMLearnsets"] + (i * 8), rom.beg);
        rom.read((char*)&(species->tmhm_learnset), 8);
    }

    // Reading evolutions
    for (size_t i = 0; i < constants_json["NUM_SPECIES"]; ++i)
    {
        const size_t NUM_EVOS_PER_MON = 5;
        const auto &species = all_species[i];

        species->evolutions_address = misc_rom_addresses["gEvolutionTable"] + (i * (8 * 5));

        for (size_t j = 0; j < NUM_EVOS_PER_MON; ++j)
        {
            uint16_t method = 0;
            rom.seekg(species->evolutions_address + (j * 8) + 0, rom.beg);
            rom.read((char*)&(method), 2);

            if (method == 0) continue;

            EvolutionInfo evolution;

            switch (method)
            {
                case 1:
                    evolution.method = FRIENDSHIP;
                    break;
                case 2:
                    evolution.method = FRIENDSHIP_DAY;
                    break;
                case 3:
                    evolution.method = FRIENDSHIP_NIGHT;
                    break;
                case 4:
                    evolution.method = LEVEL;
                    break;
                case 7:
                    evolution.method = ITEM;
                    break;
                case 8:
                    evolution.method = LEVEL_ATK_GT_DEF;
                    break;
                case 9:
                    evolution.method = LEVEL_ATK_EQ_DEF;
                    break;
                case 10:
                    evolution.method = LEVEL_ATK_LT_DEF;
                    break;
                case 11:
                    evolution.method = LEVEL_SILCOON;
                    break;
                case 12:
                    evolution.method = LEVEL_CASCOON;
                    break;
                case 13:
                    evolution.method = LEVEL_NINJASK;
                    break;
                case 14:
                    evolution.method = LEVEL_SHEDINJA;
                    break;
                default:
                    std::cerr << "Unknown evolution method: " << method << std::endl;
                    throw new std::exception();
            }
            
            rom.seekg(species->evolutions_address + (j * 8) + 2, rom.beg);
            rom.read((char*)&(evolution.param), 2);
            
            rom.seekg(species->evolutions_address + (j * 8) + 4, rom.beg);
            rom.read((char*)&(evolution.species), 2);

            species->evolutions.push_back(evolution);
        }
    }

    // Reading TM moves
    uint16_t tmhm_moves[58];
    for (size_t i = 0; i < 58; ++i)
    {
        rom.seekg(misc_rom_addresses["sTMHMMoves"] + (i * 2), rom.beg);
        rom.read((char*)&(tmhm_moves[i]), 2);
    }

    // Reading default items
    for (const auto& item: ball_items)
    {
        rom.seekg(item->address, rom.beg);
        rom.read((char*)&(item->default_item), 2);
    }

    for (const auto& item: npc_gifts)
    {
        rom.seekg(item->address, std::ios::beg);
        rom.read((char*)&(item->default_item), 2);
    }

    for (const auto& item: badges)
    {
        rom.seekg(item->address, std::ios::beg);
        rom.read((char*)&(item->default_item), 2);
    }

    // ------------------------------------------------------------------------
    // Creating output
    // ------------------------------------------------------------------------
    std::cout << "Creating JSON..." << std::endl;
    json maps_json;
    for (const auto& map_tuple: maps)
    {
        maps_json[map_tuple.first] = map_tuple.second->to_json();
    }

    json misc_pokemon_json = json::array();
    for (const auto& mon: misc_pokemon)
    {
        misc_pokemon_json.push_back(mon->to_json());
    }

    json legendary_encounters_json = json::array();
    for (const auto& legendary_encounter: legendary_encounters)
    {
        legendary_encounters_json.push_back(legendary_encounter->to_json());
    }

    json species_json = json::array();
    for (const auto& species: all_species)
    {
        species_json.push_back(species->to_json());
    }

    json trainers_json = json::array();
    for (const auto& trainer: trainers)
    {
        trainers_json.push_back(trainer->to_json());
    }

    json locations_json;
    for (const auto& location: npc_gifts)
    {
        locations_json[location->name] = location->to_json();
    }
    for (const auto& location: dex_rewards)
    {
        locations_json[location->name] = location->to_json();
    }
    for (const auto& location: trainer_rewards)
    {
        locations_json[location->name] = location->to_json();
    }
    for (const auto& location: berry_trees)
    {
        locations_json[location->name] = location->to_json();
    }
    for (const auto& location: ball_items)
    {
        locations_json[location->name] = location->to_json();
    }
    for (const auto& location: hidden_items)
    {
        locations_json[location->name] = location->to_json();
    }
    for (const auto& location: badges)
    {
        locations_json[location->name] = location->to_json();
    }

    std::map<std::string, std::string> warp_destinations;
    for (const auto& warp: warps)
    {
        std::string destination = "";
        for (const auto& other_warp: warps)
        {
            if (other_warp == warp)
            {
                continue;
            }

            if (warp->connects_to(*other_warp))
            {
                destination = other_warp->encode();
                break;
            }
        }

        warp_destinations[warp->encode()] = destination;
    }

    char rom_name[32];
    rom.seekg(symbol_map["sGFRomHeader"] - ROM_START + 8, rom.beg);
    rom.read((char*)&(rom_name), 32);

    json output_json = {
        { "_comment", "DO NOT MODIFY. This file was auto-generated. Your changes will likely be overwritten." },
        { "_rom_name", rom_name },
        { "maps", maps_json },
        { "legendary_encounters", legendary_encounters_json },
        { "misc_pokemon", misc_pokemon_json },
        { "misc_ram_addresses", misc_ram_addresses },
        { "misc_rom_addresses", misc_rom_addresses },
        { "locations", locations_json },
        { "warps", warp_destinations },
        { "species", species_json },
        { "trainers", trainers_json },
        { "tmhm_moves", tmhm_moves },
        { "constants", constants_json },
    };
    

    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_1"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_2"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_3"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_4"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_5"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_6"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_7"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_8"] + 3 - ROM_START
    };
    output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL"]["address"] = {
        output_json["locations"]["ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL"]["address"],
        symbol_map["Archipelago_Target_Missed_Item_Trick_House_9"] + 3 - ROM_START
    };

    std::cout << "Writing file..." << std::endl;
    std::ofstream outfile(root_dir / "extracted_data.json");
    outfile << output_json.dump() << std::endl;
}

json LocationInfo::to_json ()
{
    return {
        { "flag", this->flag },
        { "address", this->address },
        { "default_item", this->default_item },
    };
}

bool WarpInfo::connects_to (const WarpInfo &other)
{
    if (this->dest_map != other.source_map) return false;

    bool contains_all_indices = true;
    for (uint dest_i: this->dest_indices)
    {
        bool found_index = false;
        for (uint other_source_i: other.source_indices)
        {
            if (dest_i == other_source_i)
            {
                found_index = true;
                break;
            }
        }

        if (!found_index) {
            contains_all_indices = false;
            break;
        }
    }

    return contains_all_indices;
}

std::string WarpInfo::encode ()
{
    std::string result = "";

    result += this->source_map + ":";
    std::set<int> sorted_source_indices(this->source_indices.begin(), this->source_indices.end());
    for (int i: sorted_source_indices)
    {
        result += std::to_string(i) + ",";
    }
    result.pop_back();

    result += "/";

    result += this->dest_map + ":";
    std::set<int> sorted_dest_indices(this->dest_indices.begin(), this->dest_indices.end());
    for (int i: sorted_dest_indices)
    {
        result += std::to_string(i) + ",";
    }
    result.pop_back();

    if (this->is_one_way)
    {
        result += '!';
    }

    return result;
}

WarpInfo WarpInfo::decode (std::string s)
{
    bool is_one_way = false;
    if (s.back() == '!')
    {
        is_one_way = true;
        s.pop_back();
    }

    size_t slash_i = s.find('/');
    std::string source = s.substr(0, slash_i);
    std::string dest = s.substr(slash_i + 1);

    size_t source_colon_i = source.find(':');
    std::string source_map = source.substr(0, source_colon_i);
    std::string source_indices_string = source.substr(source_colon_i + 1);
    size_t dest_colon_i = dest.find(':');
    std::string dest_map = dest.substr(0, dest_colon_i);
    std::string dest_indices_string = dest.substr(dest_colon_i + 1);

    size_t i = 0;
    size_t prev_i = 0;
    std::vector<int> source_indices;
    while ((i = source_indices_string.find(',', i)) < source_indices_string.size())
    {
        source_indices.push_back(std::stoi(source_indices_string.substr(prev_i, i - prev_i)));
        prev_i = i + 1;
    }

    i = 0;
    prev_i = 0;
    std::vector<int> dest_indices;
    while ((i = dest_indices_string.find(',', i)) < dest_indices_string.size())
    {
        dest_indices.push_back(std::stoi(dest_indices_string.substr(prev_i, i - prev_i)));
        prev_i = i + 1;
    }

    WarpInfo warp_info;
    warp_info.is_one_way = is_one_way;
    warp_info.source_map = source_map;
    warp_info.source_indices = source_indices;
    warp_info.dest_map = dest_map;
    warp_info.dest_indices = dest_indices;

    return warp_info;
}

json MapInfo::to_json ()
{
    json map_json = {
        { "warp_table_address", this->warp_table_address },
        { "header_address", this->header_address },
    };

    if (this->land_encounters.exists)
    {
        map_json["land_encounters"] = this->land_encounters.to_json();
    }
    if (this->water_encounters.exists)
    {
        map_json["water_encounters"] = this->water_encounters.to_json();
    }
    if (this->fishing_encounters.exists)
    {
        map_json["fishing_encounters"] = this->fishing_encounters.to_json();
    }
    if (this->rock_smash_encounters.exists)
    {
        map_json["rock_smash_encounters"] = this->rock_smash_encounters.to_json();
    }

    return map_json;
}

json EncounterTableInfo::to_json ()
{
    if (!this->exists) return nullptr;
    json slots_json = json::array();
    for (const auto &encounter_slot: this->encounter_slots)
    {
        slots_json.push_back(encounter_slot->default_species);
    }

    return {
        { "slots", slots_json },
        { "address", this->address },
    };
}

json LegendaryEncounterInfo::to_json ()
{
    return {
        { "species", this->species },
        { "level", this->level },
        { "address", this->address },
        { "defeat_flag", this->defeat_flag },
        { "catch_flag", this->catch_flag }
    };
}

json MiscPokemonInfo::to_json ()
{
    return {
        { "species", this->species },
        { "address", this->address },
    };
}

json SpeciesInfo::to_json ()
{
    const auto evolution_method_to_string = [](EvolutionMethod method) {
        switch (method)
        {
            case LEVEL:
                return "LEVEL";
            case LEVEL_ATK_LT_DEF:
                return "LEVEL_ATK_LT_DEF";
            case LEVEL_ATK_EQ_DEF:
                return "LEVEL_ATK_EQ_DEF";
            case LEVEL_ATK_GT_DEF:
                return "LEVEL_ATK_GT_DEF";
            case LEVEL_SILCOON:
                return "LEVEL_SILCOON";
            case LEVEL_CASCOON:
                return "LEVEL_CASCOON";
            case LEVEL_NINJASK:
                return "LEVEL_NINJASK";
            case LEVEL_SHEDINJA:
                return "LEVEL_SHEDINJA";
            case ITEM:
                return "ITEM";
            case FRIENDSHIP:
                return "FRIENDSHIP";
            case FRIENDSHIP_DAY:
                return "FRIENDSHIP_DAY";
            case FRIENDSHIP_NIGHT:
                return "FRIENDSHIP_NIGHT";
            default:
                throw new std::exception();
        }
    };


    json evolutions_json = json::array();
    for (const auto &evolution: this->evolutions)
    {
        evolutions_json.push_back({
            { "species", evolution.species },
            { "param", evolution.param },
            { "method", evolution_method_to_string(evolution.method) },
        });
    }

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(16) << std::hex << std::uppercase << this->tmhm_learnset;
    std::string tmhm_learnset_str = ss.str();

    return {
        { "address", this->address },
        { "id", this->id },
        { "base_stats", {
            this->base_stats[0],
            this->base_stats[1],
            this->base_stats[2],
            this->base_stats[3],
            this->base_stats[4],
            this->base_stats[5],
        } },
        { "types", {
            this->types[0],
            this->types[1],
        } },
        { "abilities", {
            this->abilities[0],
            this->abilities[1],
        } },
        { "catch_rate", this->catch_rate },
        { "friendship", this->friendship },
        { "learnset", this->learnset_info.to_json() },
        { "tmhm_learnset", tmhm_learnset_str },
        { "evolutions", evolutions_json },
    };
}

json LearnsetInfo::to_json ()
{
    json moves_json = json::array();
    for (const auto& move: this->moves)
    {
        moves_json.push_back({
            { "level", std::get<0>(move) },
            { "move_id", std::get<1>(move) },
        });
    }

    return {
        { "address", this->address },
        { "moves", moves_json },
    };
}

json TrainerInfo::to_json ()
{
    json party_json = json::array();
    for (const auto& pokemon: this->party)
    {
        json mon = {
            { "species", pokemon.species },
            { "level", pokemon.level },
        };

        if (this->pokemon_data_type == NO_ITEM_CUSTOM_MOVES || this->pokemon_data_type == ITEM_CUSTOM_MOVES)
        {
            mon["moves"] = pokemon.moves;
        }

        party_json.push_back(mon);
    }

    std::string pokemon_data_type_string;
    switch (this->pokemon_data_type)
    {
        case NO_ITEM_DEFAULT_MOVES:
            pokemon_data_type_string = "NO_ITEM_DEFAULT_MOVES";
            break;
        case NO_ITEM_CUSTOM_MOVES:
            pokemon_data_type_string = "NO_ITEM_CUSTOM_MOVES";
            break;
        case ITEM_DEFAULT_MOVES:
            pokemon_data_type_string = "ITEM_DEFAULT_MOVES";
            break;
        case ITEM_CUSTOM_MOVES:
            pokemon_data_type_string = "ITEM_CUSTOM_MOVES";
            break;
    }

    return {
        { "address", this->address },
        { "party_address", this->party_address },
        { "script_address", this->battle_script_address },
        { "battle_type", this->battle_type },
        { "party", party_json },
        { "data_type", pokemon_data_type_string },
    };
}
