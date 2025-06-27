CASTFORMGFXDIR := graphics/pokemon/castform
TILESETGFXDIR := data/tilesets
FONTGFXDIR := graphics/fonts
INTERFACEGFXDIR := graphics/interface
BTLANMSPRGFXDIR := graphics/battle_anims/sprites
UNUSEDGFXDIR := graphics/unused
UNKNOWNGFXDIR := graphics/unknown
BATINTGFXDIR := graphics/battle_interface
MASKSGFXDIR := graphics/battle_anims/masks
BATTRANSGFXDIR := graphics/battle_transitions
TYPESGFXDIR := graphics/types
RAYQUAZAGFXDIR := graphics/rayquaza_scene
ROULETTEGFXDIR := graphics/roulette
SLOTMACHINEGFXDIR := graphics/slot_machine
PKNAVGFXDIR := graphics/pokenav
PKNAVOPTIONSGFXDIR := graphics/pokenav/options
WALLPAPERGFXDIR := graphics/pokemon_storage/wallpapers
OBJEVENTGFXDIR := graphics/object_events
MISCGFXDIR := graphics/misc
JPCONTESTGFXDIR := graphics/contest/japanese
POKEDEXGFXDIR := graphics/pokedex
STARTERGFXDIR := graphics/starter_choose
NAMINGGFXDIR := graphics/naming_screen
SPINDAGFXDIR := graphics/pokemon/spinda/spots
TITLESCREENGFXDIR := graphics/title_screen

types := normal fight flying poison ground rock bug ghost steel mystery fire water grass electric psychic ice dragon dark
contest_types := cool beauty cute smart tough



### Castform ###

$(CASTFORMGFXDIR)/front.4bpp: $(CASTFORMGFXDIR)/normal/front.4bpp \
                              $(CASTFORMGFXDIR)/sunny/front.4bpp \
                              $(CASTFORMGFXDIR)/rainy/front.4bpp \
                              $(CASTFORMGFXDIR)/snowy/front.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/back.4bpp: $(CASTFORMGFXDIR)/normal/back.4bpp \
                             $(CASTFORMGFXDIR)/sunny/back.4bpp \
                             $(CASTFORMGFXDIR)/rainy/back.4bpp \
                             $(CASTFORMGFXDIR)/snowy/back.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/anim_front.4bpp: $(CASTFORMGFXDIR)/normal/anim_front.4bpp \
                                   $(CASTFORMGFXDIR)/sunny/anim_front.4bpp \
                                   $(CASTFORMGFXDIR)/rainy/anim_front.4bpp \
                                   $(CASTFORMGFXDIR)/snowy/anim_front.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/normal.gbapal: $(CASTFORMGFXDIR)/normal/normal.gbapal \
                                 $(CASTFORMGFXDIR)/sunny/normal.gbapal \
                                 $(CASTFORMGFXDIR)/rainy/normal.gbapal \
                                 $(CASTFORMGFXDIR)/snowy/normal.gbapal
	@cat $^ >$@

$(CASTFORMGFXDIR)/shiny.gbapal: $(CASTFORMGFXDIR)/normal/shiny.gbapal \
                                $(CASTFORMGFXDIR)/sunny/shiny.gbapal \
                                $(CASTFORMGFXDIR)/rainy/shiny.gbapal \
                                $(CASTFORMGFXDIR)/snowy/shiny.gbapal
	@cat $^ >$@



### Tilesets ###

$(TILESETGFXDIR)/secondary/petalburg/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 159 -Wnum_tiles

$(TILESETGFXDIR)/secondary/rustboro/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 498 -Wnum_tiles

$(TILESETGFXDIR)/secondary/dewford/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 503 -Wnum_tiles

$(TILESETGFXDIR)/secondary/slateport/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 504 -Wnum_tiles

$(TILESETGFXDIR)/secondary/mauville/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 503 -Wnum_tiles

$(TILESETGFXDIR)/secondary/lavaridge/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 450 -Wnum_tiles

$(TILESETGFXDIR)/secondary/fortree/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 493 -Wnum_tiles

$(TILESETGFXDIR)/secondary/pacifidlog/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 504 -Wnum_tiles

$(TILESETGFXDIR)/secondary/sootopolis/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 328 -Wnum_tiles

$(TILESETGFXDIR)/secondary/battle_frontier_outside_west/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 508 -Wnum_tiles

$(TILESETGFXDIR)/secondary/battle_frontier_outside_east/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 508 -Wnum_tiles

$(TILESETGFXDIR)/primary/building/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 502 -Wnum_tiles

$(TILESETGFXDIR)/secondary/shop/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 502 -Wnum_tiles

$(TILESETGFXDIR)/secondary/pokemon_center/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 478 -Wnum_tiles

$(TILESETGFXDIR)/secondary/cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 425 -Wnum_tiles

$(TILESETGFXDIR)/secondary/pokemon_school/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 278 -Wnum_tiles

$(TILESETGFXDIR)/secondary/pokemon_fan_club/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 319 -Wnum_tiles

$(TILESETGFXDIR)/secondary/unused_1/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 17 -Wnum_tiles

$(TILESETGFXDIR)/secondary/meteor_falls/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 460 -Wnum_tiles

$(TILESETGFXDIR)/secondary/oceanic_museum/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 319 -Wnum_tiles

$(TILESETGFXDIR)/secondary/cable_club/unknown_tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 120 -Wnum_tiles

$(TILESETGFXDIR)/secondary/seashore_house/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 312 -Wnum_tiles

$(TILESETGFXDIR)/secondary/pretty_petal_flower_shop/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 345 -Wnum_tiles

$(TILESETGFXDIR)/secondary/pokemon_day_care/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 355 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/brown_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/brown_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/tree/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/tree/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/shrub/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/shrub/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/blue_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/blue_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/yellow_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/yellow_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/red_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/red_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/brown_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/tree/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/shrub/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/blue_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/yellow_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESETGFXDIR)/secondary/secret_base/red_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESETGFXDIR)/secondary/inside_of_truck/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 62 -Wnum_tiles

$(TILESETGFXDIR)/secondary/contest/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 430 -Wnum_tiles

$(TILESETGFXDIR)/secondary/lilycove_museum/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 431 -Wnum_tiles

$(TILESETGFXDIR)/secondary/lab/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 500 -Wnum_tiles

$(TILESETGFXDIR)/secondary/underwater/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 500 -Wnum_tiles

$(TILESETGFXDIR)/secondary/generic_building/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 509 -Wnum_tiles

$(TILESETGFXDIR)/secondary/mauville_game_corner/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 469 -Wnum_tiles

$(TILESETGFXDIR)/secondary/unused_2/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 150 -Wnum_tiles

$(TILESETGFXDIR)/secondary/rustboro_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 60 -Wnum_tiles

$(TILESETGFXDIR)/secondary/dewford_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 61 -Wnum_tiles

$(TILESETGFXDIR)/secondary/lavaridge_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 54 -Wnum_tiles

$(TILESETGFXDIR)/secondary/petalburg_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 148 -Wnum_tiles

$(TILESETGFXDIR)/secondary/fortree_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 61 -Wnum_tiles

$(TILESETGFXDIR)/secondary/mossdeep_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESETGFXDIR)/secondary/sootopolis_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 484 -Wnum_tiles

$(TILESETGFXDIR)/secondary/trick_house_puzzle/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 294 -Wnum_tiles

$(TILESETGFXDIR)/secondary/inside_ship/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 342 -Wnum_tiles

$(TILESETGFXDIR)/secondary/elite_four/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 505 -Wnum_tiles

$(TILESETGFXDIR)/secondary/battle_frontier/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 310 -Wnum_tiles

$(TILESETGFXDIR)/secondary/battle_factory/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 424 -Wnum_tiles

$(TILESETGFXDIR)/secondary/battle_pike/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 382 -Wnum_tiles

$(TILESETGFXDIR)/secondary/mirage_tower/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 420 -Wnum_tiles

$(TILESETGFXDIR)/secondary/mossdeep_game_corner/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 95 -Wnum_tiles

$(TILESETGFXDIR)/secondary/island_harbor/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 503 -Wnum_tiles

$(TILESETGFXDIR)/secondary/trainer_hill/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 374 -Wnum_tiles

$(TILESETGFXDIR)/secondary/navel_rock/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 420 -Wnum_tiles

$(TILESETGFXDIR)/secondary/battle_frontier_ranking_hall/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 136 -Wnum_tiles

$(TILESETGFXDIR)/secondary/mystery_events_house/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 509 -Wnum_tiles



### Fonts ###

$(FONTGFXDIR)/small.latfont: $(FONTGFXDIR)/latin_small.png
	$(GFX) $< $@

$(FONTGFXDIR)/normal.latfont: $(FONTGFXDIR)/latin_normal.png
	$(GFX) $< $@

$(FONTGFXDIR)/short.latfont: $(FONTGFXDIR)/latin_short.png
	$(GFX) $< $@

$(FONTGFXDIR)/narrow.latfont: $(FONTGFXDIR)/latin_narrow.png
	$(GFX) $< $@

$(FONTGFXDIR)/small_narrow.latfont: $(FONTGFXDIR)/latin_small_narrow.png
	$(GFX) $< $@

$(FONTGFXDIR)/small.hwjpnfont: $(FONTGFXDIR)/japanese_small.png
	$(GFX) $< $@

$(FONTGFXDIR)/normal.hwjpnfont: $(FONTGFXDIR)/japanese_normal.png
	$(GFX) $< $@

$(FONTGFXDIR)/bold.hwjpnfont: $(FONTGFXDIR)/japanese_bold.png
	$(GFX) $< $@

$(FONTGFXDIR)/short.fwjpnfont: $(FONTGFXDIR)/japanese_short.png
	$(GFX) $< $@

$(FONTGFXDIR)/braille.fwjpnfont: $(FONTGFXDIR)/braille.png
	$(GFX) $< $@

$(FONTGFXDIR)/frlg_male.fwjpnfont: $(FONTGFXDIR)/japanese_frlg_male.png
	$(GFX) $< $@

$(FONTGFXDIR)/frlg_female.fwjpnfont: $(FONTGFXDIR)/japanese_frlg_female.png
	$(GFX) $< $@


### Miscellaneous ###

$(TITLESCREENGFXDIR)/pokemon_logo.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 224

$(TITLESCREENGFXDIR)/emerald_version.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -mwidth 8 -mheight 4

graphics/cards/4_starred_ladybug_of_doom/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/7_colored_fish/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/a_wingbeat_of_giant_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_dweller/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_soldier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_sphere/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_squall/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/accumulated_fortune/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/acid_trap_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/adreus_keeper_of_armageddon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/advanced_ritual_art/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/airknight_parshath/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/allure_of_darkness/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ally_of_justice_catastor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ally_of_justice_decisive_armor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/amazoness_archer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_fairy_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_gear_gadjiltron_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_sacred_wyvern/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/angel_of_zera/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/anti_spell_fragrance/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/apprentice_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/aqua_madoor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/aqua_spirit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/arcanite_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_soldier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/archlord_kristya/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/armades_keeper_of_boundaries/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/armageddon_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/armored_kappa/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/armory_arm/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_beagalltach/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_durendal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_ignition/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_moralltach/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_sanctum/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_scythe/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/asceticism_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/asura_priest/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/atlantean_dragoons/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/atlantean_heavy_infantry/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/atlantean_marksman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/aurkus_lightsworn_druid/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/autonomous_action_unit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/avenging_knight_parshath/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/azure_eyes_silver_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bahamut_shark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/banisher_of_the_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/banisher_of_the_radiance/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/barrel_behind_the_door/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/battle_fader/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/battle_ox/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bazoo_the_soul_eater/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/beast_king_barbaros/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/beckoning_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/beelze_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/berserk_gorilla/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bickuribox/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/big_shield_gardna/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/black_horn_of_heaven/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/black_luster_soldier_envoy_of_the_beginning/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/black_rose_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/black_salvo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/black_skull_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/black_whirlwind/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_blizzard_the_far_north/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_bora_the_spear/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_gale_the_whirlwind/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_kalut_the_moon_shadow/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_shura_the_blue_flame/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_silverwind_the_ascendant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_sirocco_the_dawn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_vayu_the_emblem_of_honor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_armed_wing/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blackwing_armor_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blade_armor_ninja/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blade_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blast_with_chain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blaster_dragon_ruler_of_infernos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blue_thunder_t_45/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_ultimate_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_eclipse/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_life/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_moon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_taiyou/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bottomless_trap_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brain_control/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/breaker_the_magical_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/breakthrough_skill/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brionac_dragon_of_the_ice_barrier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_bear/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_boar/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_cardinal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_gorilla/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_tiger_king/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/broww_huntsman_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujin_hirume/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujin_mikazuchi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujin_yamato/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujincarnation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujingi_crane/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujingi_hare/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujingi_quilin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujingi_sinyou/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujingi_turtle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujintei_kagutsuchi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/bujintei_susanowo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/burial_from_a_different_dimension/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/burner_dragon_ruler_of_sparks/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/caius_the_shadow_monarch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/call_of_the_haunted/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cannon_soldier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/card_destruction/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/card_of_safe_return/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/card_trooper/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cardcar_d/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cards_for_black_feathers/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cards_from_the_sky/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cards_of_consonance/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/castle_of_dragon_souls/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/castle_walls/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/catapult_turtle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ceasefire/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/celestia_lightsworn_angel/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chain_disappearance/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chain_energy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chain_strike/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/change_of_heart/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_emperor_dragon_envoy_of_the_end/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_sorcerer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/charge_of_the_light_brigade/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/charubin_the_fire_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chimeratech_fortress_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chimeratech_overdragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chiron_the_mage/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/chivalry/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cipher_soldier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/circle_of_the_fire_kings/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/closed_forest/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/coach_soldier_wolfbark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cold_wave/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/colossal_fighter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/common_charity/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/compulsory_escape_device/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/compulsory_evacuation_device/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/confiscation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/consecrated_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_algiedi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_kaus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_omega/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_pleiades/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_pollux/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_ptolemy_m7/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/constellar_sombre/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/contract_with_the_abyss/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/corridor_of_agony/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/crass_clown/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/creature_swap/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/crevice_into_the_different_dimension/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/crimson_blader/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/crusader_of_endymion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/crush_card_virus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/crystal_seer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cunning_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cursed_seal_of_the_forbidden_spell/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_blader/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_end_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_jar/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_ogre_2/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_phoenix/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_saurus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_twin_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_valley/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_stein/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_assailant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_crow/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_designator/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_survivor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_warrior_lady/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_m_different_dimension_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_r_different_dimension_reincarnation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/daigusto_emeral/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/daigusto_phoenix/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dandylion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_armed_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_balter_the_terrible/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_blade_the_dragon_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_bribe/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_dust_spirit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_elf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_end_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_eruption/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_flare_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_grepher/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_of_chaos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_mimic_lv3/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_nephthys/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_paladin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_ruler_ha_des/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_smog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_strike_fighter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_world_dealings/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_world_lightning/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/darkfire_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/darkflare_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/darklord_zerato/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/de_spell/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/debris_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/debunk/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/deck_devastation_virus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/deck_lockdown/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/deep_dark_trap_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/deep_sea_diva/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/deepsea_shark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dekoichi_the_battlechanted_locomotive/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/delinquent_duo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/delta_crow_anti_reverse/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/demise_king_of_armageddon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/des_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/des_koala/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/des_wombat/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/desert_sunlight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_draw/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_dasher/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_defender/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_diamond_dude/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_disk_commander/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_dogma/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_doom_lord/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_fear_monger/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_malicious/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_plasma/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dewloren_tiger_king_of_the_ice_barrier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/diamond_dire_wolf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/different_dimension_capsule/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_fusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_wall/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dimensional_alchemist/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dimensional_fissure/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dimensional_prison/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/divine_dragon_knight_felgrand/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/divine_sword_phoenix_blade/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/divine_wrath/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dna_surgery/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/don_zaloog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/doom_dozer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/doomcaliber_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/doomkaiser_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/double_cyclone/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/double_edged_sword_technique/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/downerd_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragged_down_into_the_grave/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_ravine/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_shrine/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragoness_the_wicked_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragonic_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_arma_mystletainn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_corsesca/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_dux/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_knight_gae_dearg/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_knight_vajrayana/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_phalanx/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/drill_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/drillroid/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/droll_lock_bird/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/drop_off/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dupe_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dust_tornado/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/e_emergency_call/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/eclipse_wyvern/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/effect_veiler/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ehren_lightsworn_monk/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elder_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/electric_snake/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/electric_virus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_absolute_zero/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_air_neos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_bubbleman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_chaos_neos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_dark_neos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_electrum/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_flame_wingman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_gaia/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_grand_neos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_mariner/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_neos_alius/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_ocean/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_phoenix_enforcer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_prisma/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_shining_flare_wingman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_stratos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_tempest/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_the_shining/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_wildheart/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/emergency_provisions/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/emergency_teleport/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/empress_judge/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/enemy_controller/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/eradicator_epidemic_virus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/escape_from_the_dark_dimension/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evigishki_merrowgeist/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evil_hero_dark_gaia/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_bahamut/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_castor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_exciton_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_heliotrope/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_kerykeion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_mandragora/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_ophion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_ouroboros/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_thunderbird/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evolzar_dolkka/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/evolzar_laggia/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/exarion_universe/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/exchange/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/exiled_force/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/exodia_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/exploder_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fairy_king_albverdich/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fake_trap/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fencing_fire_ferret/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fiber_jar/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fiend_skull_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fiendish_chain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/final_flame/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_formation_gyokkou/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_formation_tenken/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_formation_tenki/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_formation_tensen/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_formation_tensu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_hand/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_king_avatar_barong/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_king_avatar_yaksha/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fire_king_high_avatar_garunix/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fires_of_doomsday/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fishborg_blaster/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fissure/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/five_headed_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flame_ghost/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flamvell_firedog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flamvell_guard/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flamvell_uruquizas/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flip_flop_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flower_wolf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/flying_c_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fog_king/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/foolish_burial/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_chalice/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_dress/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_lance/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/formula_synchron/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fossil_dyna_pachycephalo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/full_house/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fusilier_dragon_the_dual_mode_beast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/fusionist/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/future_fusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/g_b_hunter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gachi_gachi_gantetsu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gagaga_cowboy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_dragon_the_thunder_charger/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_knight_the_force_of_earth/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_the_dragon_champion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/garoth_lightsworn_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gateway_of_the_six/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gatling_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gauntlet_launcher/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gear_gigant_x/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gearfried_the_iron_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geargiaccelerator/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geargiagear/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geargiano/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geargiano_mk_ii/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geargiarmor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geargiarsenal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/geartown/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_pearl/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gemini_elf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gemini_imps/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gemini_spark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/generation_shift/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/genex_ally_birdman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/genex_controller/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/genex_undine/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ghostrick_alucard/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giant_germ/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giant_orc/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giant_rat/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giant_soldier_of_stone/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giant_trunade/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giga_tech_wolf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gigantes/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gigaplant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gilasaurus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/giltia_the_d_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_bestiari/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_darius/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_equeste/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_gaiodiaz/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_gyzarus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_heraklinos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_hoplomus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_laquari/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_murmillo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_retiari/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_samnite/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_secutor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_war_chariot/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_s_respite/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_proving_ground/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/glow_up_bulb/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_attack_force/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_zombie/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gold_sarcophagus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/goldd_wu_lord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/good_goblin_housekeeping/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gorz_the_emissary_of_darkness/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gottoms_emergency_call/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/goyo_guardian/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gozen_match/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/graceful_charity/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/grandmaster_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/grandsoil_the_elemental_lord/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/grapha_dragon_lord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_assailant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_commandant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_descendant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_guard/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_recruiter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_spear_soldier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_spy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_stele/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_watcher/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gravity_bind/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/great_shogun_shien/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/great_white/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/green_baboon_defender_of_the_forest/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/green_gadget/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gungnir_dragon_of_the_ice_barrier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gyaku_gire_panda/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/gyakutenno_megami/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hallowed_life_barrier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hammer_shot/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hand_destruction/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hane_hane/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hanewata/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/harpie_s_feather_duster/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/heavy_storm/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/herald_of_green_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/herald_of_orange_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/herald_of_pure_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hero_s_rule_2/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/heroic_champion_excalibur/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hidden_armory/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_dragon_king_of_atum/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_dragon_of_eset/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_dragon_of_su/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_dragon_of_tefnuit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_seal_from_the_ashes/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_seal_of_convocation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hieratic_sun_dragon_overlord_of_heliopolis/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hierophant_of_prophecy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/high_priestess_of_prophecy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/honest/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/horn_of_heaven/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/horn_of_the_phantom_beast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/horus_the_black_flame_dragon_lv6/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/horus_the_black_flame_dragon_lv8/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hts_psyhemuth/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hundred_eyes_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/hydrogeddon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/icarus_attack/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ice_hand/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/il_blud/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/imperial_iron_wall/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/imperial_order/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_archfiend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_avenger/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_barrier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_beetle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_break/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_doom_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_inferno/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_launcher/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_mirage/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_necromancer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infestation_infection/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infestation_pandemic/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/infestation_terminus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/injection_fairy_lily/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/insect_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/instant_fusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/inzektor_centipede/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/inzektor_dragonfly/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/inzektor_exa_beetle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/inzektor_hornet/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/inzektor_sword_zektkaliber/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/iron_chain_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/jain_lightsworn_paladin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/jar_of_greed/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/jinzo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/jirai_gumo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/jowgen_the_spiritualist/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/judge_man/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/judgment_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/judgment_of_anubis/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/junk_destroyer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/jurrac_guaiba/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/just_desserts/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/justice_of_prophecy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/kabazauls/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/kagemusha_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/kagetokage/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_komachi_mdl_224_ninishi_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_merchant_mdl_177_inashichi_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_muso_mdl_818_haipa_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_ninja_mdl_919_kuick_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_shogun_mdl_00_burei_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_soldier_mdl_236_nisamu_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_steel_shogun_mdl_00x_bureido_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_strategist_mdl_248_nishipachi_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karakuri_watchdog_mdl_313_saizan_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/karbonala_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/king_dragun/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/king_of_the_feral_imps/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/king_tiger_wanghu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/koa_ki_meiru_drago/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/krebons/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/kuriboh/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/kwagar_hercules/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/kycoo_the_ghost_destroyer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/la_jinn_the_mystical_genie_of_the_lamp/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/labradorite_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/labyrinth_tank/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/last_day_of_witch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/last_will/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lava_golem/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lavalval_chain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/leeching_the_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/left_arm_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/left_leg_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/legacy_of_yata_garasu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/legendary_jujitsu_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/legendary_six_samurai_kageki/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/legendary_six_samurai_kizan/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/legendary_six_samurai_shi_en/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/leo_the_keeper_of_the_sacred_tree/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/level_limit_area_b/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/leviair_the_sea_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/light_and_darkness_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/light_imprisoning_mirror/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lightning_vortex/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lightning_dragon_ruler_of_drafts/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lightpulsar_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/limit_reverse/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/limiter_removal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lonefire_blossom/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lumina_lightsworn_summoner/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/lyla_lightsworn_sorceress/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/machina_cannon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/machina_force/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/machina_fortress/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/machina_gearframe/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/machine_duplication/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/macro_cosmos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/madolche_magileine/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/maestroke_the_symphony_djinn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mage_power/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magic_cylinder/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magic_jammer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magical_android/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magical_explosion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magical_mallet/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magical_merchant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magical_scientist/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magical_stone_excavation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/magician_of_faith/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_cyber_end_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_stardust_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/malevolent_catastrophe/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/man_eater_bug/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/manju_of_the_ten_thousand_hands/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mark_of_the_rose/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/marshmallon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mask_of_darkness/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mask_of_restrict/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/masked_sorcerer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mass_driver/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/master_hyperion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/master_of_oz/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/maxx_c_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mecha_phantom_beast_dracossack/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mecha_dog_marron/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mechanicalchaser/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mechquipped_angineer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/megamorph/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mei_kou_master_of_barriers/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssgaios/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssgunde/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssleed/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abysslinde/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssmegalo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abysspike/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssteus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abysstrite/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssturge/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/messenger_of_peace/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/metaion_the_timelord/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/metal_armored_bug/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/metal_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/metamorphosis/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mezuki/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/minar/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mind_control/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mind_crush/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mind_drain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/miracle_fertilizer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/miracle_fusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_of_nightmare/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mirror_force/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mirror_of_oaths/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mist_wurm/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mobius_the_frost_monarch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/monster_gate/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/monster_reborn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/monster_reincarnation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/moray_of_greed/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/morphing_jar/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mother_grizzly/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/moulinglacia_the_elemental_lord/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/muka_muka/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/musician_king/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/my_body_as_a_shield/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_swordsman_lv2/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_tomato/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_elf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_refpanel/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_shine_ball/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_space_typhoon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mystik_wok/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mythic_tree_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/mythic_water_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/naturia_barkion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/naturia_beast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/necro_gardna/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/necrovalley/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/needle_ceiling/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/neko_mane_king/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/neo_bug/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/neo_the_magic_swordsman/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/neo_spacian_dark_panther/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/neo_spacian_grand_mole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/newdoria/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/night_assailant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/night_beam/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/nightmare_wheel/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/nimble_momonga/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ninja_grandmaster_hanzo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ninja_grandmaster_sasuke/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ninjitsu_art_of_super_transformation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/nitro_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/nobleman_of_crossout/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/nobleman_of_extermination/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/non_aggression_area/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_101_silent_honor_ark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_103_ragnazero/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_106_giant_hand/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_11_big_eye/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_16_shock_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_17_leviathan_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_20_giga_brilliant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_30_acid_golem_of_destruction/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_39_utopia/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_47_nightmare_shark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_50_blackship_of_corn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_61_volcasaurus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_66_master_key_beetle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_80_rhapsody_in_berserk/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_82_heartlandraco/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_85_crazy_box/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_96_dark_mist/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/number_c39_utopia_ray/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ojama_king/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ojama_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ojama_trio/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/old_vindictive_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/one_day_of_peace/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/one_for_one/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/onslaught_of_the_fire_kings/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ookazi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/orient_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/overload_fusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/overworked/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/painful_choice/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/penguin_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/phantom_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/phantom_of_chaos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/phoenix_wing_wind_blast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/photon_papilloperative/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/photon_strike_bounzer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/photon_thrasher/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pikeru_s_circle_of_enchantment/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/plaguespreader_zombie/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/poison_draw_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/poison_of_the_old_man/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pole_position/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/polymerization/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_avarice/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_duality/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_greed/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/power_tool_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/premature_burial/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/prime_material_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/princess_of_tsurugi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/prohibition/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/prometheus_king_of_the_shadows/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/protector_of_the_sanctuary/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/psi_blocker/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/psychic_commander/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/psychic_lifetrancer/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pulling_the_rug/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/punished_eagle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/puppet_plant/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/pyramid_turtle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/queen_dragun_djinn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/quickdraw_synchron/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/raigeki/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/raigeki_break/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rainbow_life/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/raiza_the_storm_monarch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reactan_dragon_ruler_of_pebbles/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reaper_on_the_nightmare/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reasoning/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reborn_tengu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reckless_greed/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/red_dragon_archfiend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/red_gadget/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_darkness_metal_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/redox_dragon_ruler_of_boulders/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reflect_bounder/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reinforce_truth/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reinforcement_of_the_army/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reinforcements/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rekindling/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/relinquished/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/reload/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/remove_trap/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rescue_cat/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rescue_rabbit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/retort/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/return_from_the_different_dimension/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/revived_king_ha_des/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/right_arm_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/right_leg_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ring_of_defense/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ring_of_destruction/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rivalry_of_warlords/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/roaring_ocean_snake/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/robbin_goblin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ronintoadin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rose_warrior_of_revenge/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/royal_decree/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/royal_oppression/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/royal_tribute/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/rush_recklessly/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ryko_lightsworn_hunter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ryu_kokki/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ryu_senshi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/saber_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/saber_slash/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sabersaurus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_crane/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_sword_of_seven_stars/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/safe_zone/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sakuretsu_armor/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/salvage/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sangan/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sanwitch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sasuke_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scapegoat/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_archfiend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_beast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_chimera/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_goblin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_golem/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/scrapstorm/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sea_dragon_lord_gishilnodon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/secret_barrel/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/self_destruct_button/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/senju_of_the_thousand_hands/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/serial_spell/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/seven_tools_of_the_bandit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shadow_imprisoning_mirror/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shien_s_smoke_signal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shining_angel/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shining_elf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shiny_black_c_/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shooting_star_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/shrink/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sillva_warlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sinister_serpent/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/six_samurai_united/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sixth_sense/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/skill_drain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_dark_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/skull_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/skull_lair/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/skull_meister/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/smashing_ground/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/snatch_steal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/snipe_hunter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/snowman_eater/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/snoww_unlight_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/solar_recharge/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_judgment/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_warning/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_wishes/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/sonic_bird/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/soul_charge/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/soul_drain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/soul_exchange/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/soul_of_silvermountain/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/soul_release/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/soul_taker/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spear_cretin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spear_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spell_canceller/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spell_economics/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spell_reproduction/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spell_shield_type_8/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spell_striker/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_library_of_the_crescent/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_magician_of_prophecy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_eternity/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_fate/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_judgment/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_life/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_power/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_secrets/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_the_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_wisdom/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_star_hall/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spirit_of_the_harp/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spirit_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spirit_reaper/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spiritual_water_art_aoi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spiritualism/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/splendid_rose/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/spore/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/st_joan/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/star_eater/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stardust_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stardust_spark_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/starliege_paladynamo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/starlight_road/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stealth_bird/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/steam_gyroid/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/steelswarm_roach/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stop_defense/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stream_dragon_ruler_of_droplets/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/strike_ninja/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stygian_sergeants/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/stygian_street_patrol/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/substitoad/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/summon_limit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/summoned_skull/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/summoner_monk/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_polymerization/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_rejuvenation/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_robolady/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_roboyarou/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_solar_nutrient/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_vehicroid_jumbo_drill/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/super_nimble_mega_hamster/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/supervise/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/swallow_flip/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/swap_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/swift_scarecrow/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/swords_of_revealing_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/system_down/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_hyper_librarian/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_power_gladiator/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_rush_rhino/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_striker/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_warwolf/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_wonder_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/temperance_of_prophecy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tempest_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tempest_dragon_ruler_of_storms/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/temtempo_the_percussion_djinn/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/terraforming/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/test_tiger/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tg1_em1/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_agent_of_creation_venus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_agent_of_miracles_jupiter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_agent_of_mystery_earth/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_fabled_catsith/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_fiend_megacyber/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_forceful_sentry/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_gates_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_grand_spellbook_tower/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_last_warrior_from_another_planet/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_light_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_little_swordsman_of_aile/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_six_samurai_irou/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_six_samurai_kamon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_six_samurai_yaichi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_six_samurai_zanji/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_transmigration_prophecy/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_white_stone_of_legend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/the_wicked_worm_beast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_firestorm_monarch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thought_ruler_archfiend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thousand_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thousand_eyes_restrict/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/threatening_roar/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_king_rai_oh/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_nyan_nyan/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tidal_dragon_ruler_of_waterfalls/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/time_seal/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tin_goldfish/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tiras_keeper_of_genesis/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/toon_table_of_contents/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/torrential_tribute/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tour_guide_from_the_underworld/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trade_in/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tragoedia/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trance_archfiend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trap_dustshoot/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trap_eater/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trap_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trap_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trap_stun/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_dionaea/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_myrmeleo/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_trap_hole_nightmare/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/treacherous_trap_hole/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/treeborn_frog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tremendous_fire/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tribe_infecting_virus/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tribute_to_the_doomed/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trident_dragion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trigon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/trishula_dragon_of_the_ice_barrier/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tsukuyomi/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/turbo_warrior/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/twin_headed_behemoth/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/twin_headed_thunder_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/twister/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/tytannial_princess_of_camellias/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ufo_turtle/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_offering/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/unifrog/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/united_we_stand/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/upstart_goblin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/van_dalgyon_the_dark_dragon_lord/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/vanity_s_emptiness/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/vanity_s_fiend/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/volcanic_queen/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/volcanic_rocket/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/volcanic_shell/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/vorse_raider/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/vortex_trooper/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/waboku/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wall_of_illusion/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wall_of_revealing_light/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/warrior_elimination/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/warrior_of_tradition/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wave_motion_cannon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/white_magical_hat/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/widespread_dud/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/widespread_ruin/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_arsenal_zenmaioh/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_carrier_zenmaity/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_factory/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_hunter/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_rabbit/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_rat/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_shark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_zenmaines/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_zenmaister/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/winged_kuriboh/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/winged_rhynos/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wiretap/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/witch_of_the_black_forest/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/wulf_lightsworn_beast/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/x_saber_airbellum/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/x_saber_pashuul/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/x_saber_urbellum/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/x_saber_wayne/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xing_zhen_hu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_boggart_knight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_darksoul/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_emmersblade/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_faultroll/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_fulhelmknight/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_gottoms/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_hyunlei/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xx_saber_ragigura/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/xyz_encore/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/yata_garasu/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/yellow_gadget/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/zaborg_the_thunder_monarch/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/zombie_master/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/zombyra_the_dark/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/zure_knight_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/pokemon_jump/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 63 -Wnum_tiles

graphics/pokenav/region_map/map.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 233 -Wnum_tiles

$(MISCGFXDIR)/japanese_hof.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 29 -Wnum_tiles

$(MISCGFXDIR)/mirage_tower.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 73 -Wnum_tiles

$(BATINTGFXDIR)/textbox.gbapal: $(BATINTGFXDIR)/textbox_0.gbapal \
                                $(BATINTGFXDIR)/textbox_1.gbapal
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/ice_cube.4bpp: $(BTLANMSPRGFXDIR)/ice_cube_0.4bpp \
                                  $(BTLANMSPRGFXDIR)/ice_cube_1.4bpp \
                                  $(BTLANMSPRGFXDIR)/ice_cube_2.4bpp \
                                  $(BTLANMSPRGFXDIR)/ice_cube_3.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi_palpak1.gbapal: $(UNUSEDGFXDIR)/old_pal1.gbapal \
                                    $(UNUSEDGFXDIR)/old_pal2.gbapal \
                                    $(UNUSEDGFXDIR)/old_pal3.gbapal
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi_palpak3.gbapal: $(UNUSEDGFXDIR)/old_pal5.gbapal \
                                    $(UNUSEDGFXDIR)/old_pal6.gbapal \
                                    $(UNUSEDGFXDIR)/old_pal7.gbapal
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi1.4bpp: $(UNUSEDGFXDIR)/old_bulbasaur.4bpp \
                           $(UNUSEDGFXDIR)/old_charizard.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi2.4bpp: $(UNUSEDGFXDIR)/old_bulbasaur2.4bpp \
                           $(UNUSEDGFXDIR)/old_battle_interface_1.4bpp \
                           $(UNUSEDGFXDIR)/old_battle_interface_2.4bpp \
                           $(UNUSEDGFXDIR)/old_battle_interface_3.4bpp
	@cat $^ >$@

$(BATINTGFXDIR)/battle_bar.4bpp: $(BATINTGFXDIR)/hpbar_anim_unused.4bpp \
                                 $(BATINTGFXDIR)/numbers1.4bpp \
                                 $(BATINTGFXDIR)/numbers2.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/redyellowgreen_frame.bin: $(UNUSEDGFXDIR)/red_frame.bin \
                                          $(UNUSEDGFXDIR)/yellow_frame.bin \
                                          $(UNUSEDGFXDIR)/green_frame.bin \
                                          $(UNUSEDGFXDIR)/blank_frame.bin
	@cat $^ >$@

$(UNUSEDGFXDIR)/color_frames.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 353 -Wnum_tiles

$(BATINTGFXDIR)/unused_window2bar.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(JPCONTESTGFXDIR)/composite_1.4bpp: $(JPCONTESTGFXDIR)/frame_1.4bpp \
                                     $(JPCONTESTGFXDIR)/floor.4bpp \
                                     $(JPCONTESTGFXDIR)/frame_2.4bpp \
                                     $(JPCONTESTGFXDIR)/symbols.4bpp \
                                     $(JPCONTESTGFXDIR)/meter.4bpp \
                                     $(JPCONTESTGFXDIR)/letters.4bpp \
                                     $(JPCONTESTGFXDIR)/numbers.4bpp
	@cat $^ >$@

$(JPCONTESTGFXDIR)/composite_2.4bpp: $(JPCONTESTGFXDIR)/interface.4bpp \
                                     $(JPCONTESTGFXDIR)/audience.4bpp
	@cat $^ >$@

$(JPCONTESTGFXDIR)/voltage.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 36 -Wnum_tiles

$(BTLANMSPRGFXDIR)/ice_crystals.4bpp: $(BTLANMSPRGFXDIR)/ice_crystals_0.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_1.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_2.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_3.4bpp \
                                      $(BTLANMSPRGFXDIR)/ice_crystals_4.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/mud_sand.4bpp: $(BTLANMSPRGFXDIR)/mud_sand_0.4bpp \
                                  $(BTLANMSPRGFXDIR)/mud_sand_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/flower.4bpp: $(BTLANMSPRGFXDIR)/flower_0.4bpp \
                                $(BTLANMSPRGFXDIR)/flower_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/spark.4bpp: $(BTLANMSPRGFXDIR)/spark_0.4bpp \
                               $(BTLANMSPRGFXDIR)/spark_1.4bpp
	@cat $^ >$@

$(MASKSGFXDIR)/unused_level_up.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 14 -Wnum_tiles

$(BATTRANSGFXDIR)/vs_frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 16 -Wnum_tiles

graphics/party_menu/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 62 -Wnum_tiles

$(TYPESGFXDIR)/move_types.4bpp: $(types:%=$(TYPESGFXDIR)/%.4bpp) $(contest_types:%=$(TYPESGFXDIR)/contest_%.4bpp)
	@cat $^ >$@

$(TYPESGFXDIR)/move_types.gbapal: $(TYPESGFXDIR)/move_types_1.gbapal \
                                  $(TYPESGFXDIR)/move_types_2.gbapal \
                                  $(TYPESGFXDIR)/move_types_3.gbapal
	@cat $^ >$@

graphics/bag/menu.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_2/rayquaza.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 227 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_2/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 313 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_3/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 124 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_3/rayquaza_tail_fix.4bpp: $(RAYQUAZAGFXDIR)/scene_3/rayquaza_tail.4bpp
	cp $< $@
	head -c 12 /dev/zero >> $@

$(RAYQUAZAGFXDIR)/scene_4/streaks.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 19 -Wnum_tiles

$(RAYQUAZAGFXDIR)/scene_4/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 155 -Wnum_tiles

graphics/picture_frame/lobby.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 86 -Wnum_tiles

$(ROULETTEGFXDIR)/roulette_tilt.4bpp: $(ROULETTEGFXDIR)/shroomish.4bpp \
                                      $(ROULETTEGFXDIR)/tailow.4bpp
	@cat $^ >$@

$(ROULETTEGFXDIR)/wheel_icons.4bpp: $(ROULETTEGFXDIR)/wynaut.4bpp \
                                    $(ROULETTEGFXDIR)/azurill.4bpp \
                                    $(ROULETTEGFXDIR)/skitty.4bpp \
                                    $(ROULETTEGFXDIR)/makuhita.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/regis.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(BATTRANSGFXDIR)/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 938 -Wnum_tiles

$(BATTRANSGFXDIR)/frontier_square_1.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
                                          $(BATTRANSGFXDIR)/frontier_squares_1.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/frontier_square_2.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
                                          $(BATTRANSGFXDIR)/frontier_squares_2.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/frontier_square_3.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
                                          $(BATTRANSGFXDIR)/frontier_squares_3.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/frontier_square_4.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
                                          $(BATTRANSGFXDIR)/frontier_squares_4.4bpp
	@cat $^ >$@

$(SLOTMACHINEGFXDIR)/reel_time_gfx.4bpp: $(SLOTMACHINEGFXDIR)/reel_time_pikachu.4bpp \
                                         $(SLOTMACHINEGFXDIR)/reel_time_machine.4bpp
	@cat $^ >$@

graphics/birch_speech/unused_beauty.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 822 -Wnum_tiles



### Pokémon Storage System ###

$(WALLPAPERGFXDIR)/forest/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 55 -Wnum_tiles

$(WALLPAPERGFXDIR)/forest/tiles.4bpp: $(WALLPAPERGFXDIR)/forest/frame.4bpp $(WALLPAPERGFXDIR)/forest/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/city/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 52 -Wnum_tiles

$(WALLPAPERGFXDIR)/city/tiles.4bpp: $(WALLPAPERGFXDIR)/city/frame.4bpp $(WALLPAPERGFXDIR)/city/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/desert/tiles.4bpp: $(WALLPAPERGFXDIR)/desert/frame.4bpp $(WALLPAPERGFXDIR)/desert/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/savanna/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 45 -Wnum_tiles

$(WALLPAPERGFXDIR)/savanna/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 23 -Wnum_tiles

$(WALLPAPERGFXDIR)/savanna/tiles.4bpp: $(WALLPAPERGFXDIR)/savanna/frame.4bpp $(WALLPAPERGFXDIR)/savanna/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/crag/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 49 -Wnum_tiles

$(WALLPAPERGFXDIR)/crag/tiles.4bpp: $(WALLPAPERGFXDIR)/crag/frame.4bpp $(WALLPAPERGFXDIR)/crag/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/volcano/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 56 -Wnum_tiles

$(WALLPAPERGFXDIR)/volcano/tiles.4bpp: $(WALLPAPERGFXDIR)/volcano/frame.4bpp $(WALLPAPERGFXDIR)/volcano/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/snow/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 57 -Wnum_tiles

$(WALLPAPERGFXDIR)/snow/tiles.4bpp: $(WALLPAPERGFXDIR)/snow/frame.4bpp $(WALLPAPERGFXDIR)/snow/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/cave/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 55 -Wnum_tiles

$(WALLPAPERGFXDIR)/cave/tiles.4bpp: $(WALLPAPERGFXDIR)/cave/frame.4bpp $(WALLPAPERGFXDIR)/cave/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/beach/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 46 -Wnum_tiles

$(WALLPAPERGFXDIR)/beach/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 23 -Wnum_tiles

$(WALLPAPERGFXDIR)/beach/tiles.4bpp: $(WALLPAPERGFXDIR)/beach/frame.4bpp $(WALLPAPERGFXDIR)/beach/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/seafloor/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 54 -Wnum_tiles

$(WALLPAPERGFXDIR)/seafloor/tiles.4bpp: $(WALLPAPERGFXDIR)/seafloor/frame.4bpp $(WALLPAPERGFXDIR)/seafloor/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/river/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 51 -Wnum_tiles

$(WALLPAPERGFXDIR)/river/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 11 -Wnum_tiles

$(WALLPAPERGFXDIR)/river/tiles.4bpp: $(WALLPAPERGFXDIR)/river/frame.4bpp $(WALLPAPERGFXDIR)/river/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/sky/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 45 -Wnum_tiles

$(WALLPAPERGFXDIR)/sky/tiles.4bpp: $(WALLPAPERGFXDIR)/sky/frame.4bpp $(WALLPAPERGFXDIR)/sky/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/polkadot/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 54 -Wnum_tiles

$(WALLPAPERGFXDIR)/polkadot/tiles.4bpp: $(WALLPAPERGFXDIR)/polkadot/frame.4bpp $(WALLPAPERGFXDIR)/polkadot/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/pokecenter/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 35 -Wnum_tiles

$(WALLPAPERGFXDIR)/pokecenter/tiles.4bpp: $(WALLPAPERGFXDIR)/pokecenter/frame.4bpp $(WALLPAPERGFXDIR)/pokecenter/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/machine/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 33 -Wnum_tiles

$(WALLPAPERGFXDIR)/machine/tiles.4bpp: $(WALLPAPERGFXDIR)/machine/frame.4bpp $(WALLPAPERGFXDIR)/machine/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/plain/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 18 -Wnum_tiles

$(WALLPAPERGFXDIR)/plain/tiles.4bpp: $(WALLPAPERGFXDIR)/plain/frame.4bpp $(WALLPAPERGFXDIR)/plain/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/friends_frame1.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 57 -Wnum_tiles

$(WALLPAPERGFXDIR)/friends_frame2.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 57 -Wnum_tiles

$(WALLPAPERGFXDIR)/zigzagoon/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/zigzagoon/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/screen/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/screen/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/horizontal/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/horizontal/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/diagonal/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/diagonal/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/block/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/block/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/ribbon/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/ribbon/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/pokecenter2/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/pokecenter2/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/frame/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/frame/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/blank/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/blank/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/circles/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/circles/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/azumarill/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/azumarill/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/pikachu/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/pikachu/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/legendary/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/legendary/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/dusclops/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/dusclops/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/ludicolo/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/ludicolo/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/whiscash/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/whiscash/bg.4bpp
	@cat $^ >$@

$(INTERFACEGFXDIR)/outline_cursor.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 8 -Wnum_tiles

$(BATTRANSGFXDIR)/frontier_logo_center.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 43 -Wnum_tiles



### Pokenav ###

$(PKNAVOPTIONSGFXDIR)/options.4bpp: $(PKNAVOPTIONSGFXDIR)/hoenn_map.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/condition.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/match_call.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/ribbons.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/switch_off.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/party.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/search.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/cool.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/beauty.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/cute.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/smart.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/tough.4bpp \
                                    $(PKNAVOPTIONSGFXDIR)/cancel.4bpp
	@cat $^ >$@

$(PKNAVGFXDIR)/header.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(PKNAVGFXDIR)/device_outline.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(PKNAVGFXDIR)/match_call/ui.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 13 -Wnum_tiles

$(POKEDEXGFXDIR)/region_map.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 232 -Wnum_tiles

$(POKEDEXGFXDIR)/region_map_affine.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 233 -Wnum_tiles

$(NAMINGGFXDIR)/cursor.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(NAMINGGFXDIR)/cursor_squished.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(NAMINGGFXDIR)/cursor_filled.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(SPINDAGFXDIR)/spot_0.1bpp: %.1bpp: %.png
	$(GFX) $< $@ -plain -data_width 2

$(SPINDAGFXDIR)/spot_1.1bpp: %.1bpp: %.png
	$(GFX) $< $@ -plain -data_width 2

$(SPINDAGFXDIR)/spot_2.1bpp: %.1bpp: %.png
	$(GFX) $< $@ -plain -data_width 2

$(SPINDAGFXDIR)/spot_3.1bpp: %.1bpp: %.png
	$(GFX) $< $@ -plain -data_width 2

$(FONTGFXDIR)/small_narrower.latfont: $(FONTGFXDIR)/latin_small_narrower.png
	$(GFX) $< $@
