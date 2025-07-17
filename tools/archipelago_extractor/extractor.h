#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <string>
#include <vector>

#include <json.hpp>

#define NUM_LAND_ENCOUNTER_SLOTS 12
#define NUM_WATER_ENCOUNTER_SLOTS 5
#define NUM_FISHING_ENCOUNTER_SLOTS 10

class LocationInfo {
    public:
        std::string name;
        uint16_t flag;
        uint32_t address;
        uint16_t default_item;

        nlohmann::json to_json ();
};

class WarpInfo {
    public:
        bool is_one_way = true;
        std::string source_map;
        std::vector<int> source_indices;
        std::vector<std::tuple<int, int>> source_coordinates;
        std::string dest_map;
        std::vector<int> dest_indices;
        std::vector<std::tuple<int, int>> dest_coordinates;

        bool connects_to (const WarpInfo &other);
        std::string encode ();
        static WarpInfo decode (std::string s);
};

class LearnsetInfo {
    public:
        uint32_t address;
        std::vector<std::tuple<uint8_t, uint16_t>> moves;

        nlohmann::json to_json ();
};

enum EvolutionMethod {
    LEVEL,
    LEVEL_ATK_LT_DEF,
    LEVEL_ATK_EQ_DEF,
    LEVEL_ATK_GT_DEF,
    LEVEL_SILCOON,
    LEVEL_CASCOON,
    LEVEL_NINJASK,
    LEVEL_SHEDINJA,
    ITEM,
    FRIENDSHIP,
    FRIENDSHIP_DAY,
    FRIENDSHIP_NIGHT
};

class EvolutionInfo {
    public:
        EvolutionMethod method;
        uint16_t param;
        uint16_t species;
};

class SpeciesInfo {
    public:
        uint32_t address;
        uint32_t evolutions_address;
        uint16_t id;
        uint8_t base_stats[6];
        uint8_t catch_rate;
        uint8_t friendship;
        uint8_t abilities[2];
        uint8_t types[2];
        uint64_t tmhm_learnset;

        LearnsetInfo learnset_info;
        std::vector<EvolutionInfo> evolutions;

        nlohmann::json to_json ();
};

enum TrainerPokemonInfoType {
    NO_ITEM_DEFAULT_MOVES,
    NO_ITEM_CUSTOM_MOVES,
    ITEM_DEFAULT_MOVES,
    ITEM_CUSTOM_MOVES
};

class TrainerPokemonInfo {
    public:
        uint16_t species;
        uint8_t level;
        uint8_t moves[4];
};

class TrainerInfo {
    public:
        std::vector<TrainerPokemonInfo> party;
        TrainerPokemonInfoType pokemon_data_type;
        uint32_t address;
        uint32_t party_address;
        uint32_t battle_script_address;
        uint8_t battle_type;

        nlohmann::json to_json ();
};

struct EncounterSlotInfo {
    uint16_t default_species;
    uint8_t min_level;
    uint8_t max_level;
};

class EncounterTableInfo {
    public:
        uint32_t ram_address;
        uint32_t address;
        bool exists;
        std::vector<std::shared_ptr<EncounterSlotInfo>> encounter_slots;

        nlohmann::json to_json ();
};

class LegendaryEncounterInfo {
    public:
        std::string name;
        uint32_t address;
        uint16_t species;
        uint8_t level;
        uint16_t defeat_flag;
        uint16_t catch_flag;

        nlohmann::json to_json ();
};

class MiscPokemonInfo {
    public:
        std::string name;
        uint32_t address;
        uint16_t species;

        nlohmann::json to_json ();
};

class MapInfo {
    public:
        std::string name;
        uint32_t warp_table_address;
        uint32_t header_address;
        EncounterTableInfo land_encounters;
        EncounterTableInfo water_encounters;
        EncounterTableInfo fishing_encounters;
        EncounterTableInfo rock_smash_encounters;
        // std::vector<std::string> warps;

        nlohmann::json to_json ();
};

#endif
