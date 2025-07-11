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

graphics/cards/a_legendary_ocean/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/abc_dragon_buster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_dweller/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/abyss_sphere/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/advanced_ritual_art/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/agido_the_ancient_sentinel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/airknight_parshath/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/alba_lenatus_the_abyss_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/albaz_the_ashen/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/albion_the_sanctifire_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/albion_the_shrouded_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/alexandrite_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/allure_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ally_of_justice_catastor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ally_of_justice_cycle_reader/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/aluber_the_jester_of_despia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amazoness_archer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amazoness_spiritualist/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amphibious_bugroth_mk_3/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amulet_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_fairy_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_gear_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_gear_golem_ultimate_pound/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/angmarl_the_fiendish_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/anti_spell_fragrance/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/apollousa_bow_of_the_goddess/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/apprentice_illusion_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/aqua_madoor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/aqua_spirit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arcanite_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_black_skull_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_cavalry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_commander/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_eccentrick/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_empress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_giant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_heiress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_interceptor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_of_gilfer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_s_advent/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_s_manifestation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archnemeses_protos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ariel_priestess_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arisen_gaia_the_fierce_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/armageddon_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/armed_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/armored_cybern/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/armory_arm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arsenal_bug/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arsenal_summoner/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_lancea/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_moralltach/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/artifact_sanctum/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ash_blossom_joyous_spring/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/avance_swordsman_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/axe_dragonute/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/axe_of_despair/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/baku_the_beast_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/banisher_of_the_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/banisher_of_the_radiance/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/baobaboon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/barrel_behind_the_door/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/battle_footballer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/battle_ox/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/baxia_brightness_of_the_yang_zing/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bazoo_the_soul_eater/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beast_of_talwar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beast_of_talwar_the_sword_summit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beatrice_lady_of_the_eternal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beckoning_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beginning_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beiige_vanguard_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/berlineth_the_firestorm_vassal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/berserk_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/berserk_gorilla/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bickuribox/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/big_bang_shot/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/big_shield_gardna/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/big_tusked_mammoth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_dragon_s_chick/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_horn_of_heaven/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_illusion_ritual/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_luster_soldier_envoy_of_the_beginning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_luster_soldier_envoy_of_the_evening_twilight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_metal_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_pendant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_rose_dragon/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/blade_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blast_with_chain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blaster_dragon_ruler_of_infernos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blazing_cartesia_the_virtuous/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blazing_inpachi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blindly_loyal_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/block_attack/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blowback_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_alternative_ultimate_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_alternative_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_jet_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_toon_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_twin_burst_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_tyrant_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_ultimate_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bm_4_blast_spider/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bone_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bonfire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_eclipse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_life/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_moon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_taiyou/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/borreload_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bottomless_trap_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bowganian/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brain_control/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/branded_in_high_spirits/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/breaker_the_magical_warrior/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/breakthrough_skill/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brigrand_the_glory_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brilliant_rose/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brionac_dragon_of_the_ice_barrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brotherhood_of_the_fire_fist_bear/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/broww_huntsman_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brron_mad_king_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/burial_from_a_different_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/burner_dragon_ruler_of_sparks/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/buster_blader/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/buster_blader_the_destruction_swordmaster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/buster_blader_the_dragon_destroyer_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/byser_shock/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bystial_baldrake/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bystial_druiswurm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bystial_magnamhut/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bystial_saronir/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/caius_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/caius_the_shadow_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/call_of_the_haunted/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/called_by_the_grave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cannon_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/card_destruction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/card_of_demise/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/card_of_safe_return/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/card_trooper/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cards_from_the_sky/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cards_of_consonance/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/castel_the_skyblaster_musketeer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/castle_of_dark_illusions/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/chainsaw_insect/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/change_of_heart/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_emperor_dragon_envoy_of_the_end/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_hunter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/charcoal_inpachi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/charge_of_the_light_brigade/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/charging_gaia_the_fierce_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chicken_game/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chimeratech_fortress_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chimeratech_overdragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chiron_the_mage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chronicle_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chronicle_sorceress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cipher_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cir_malebranche_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/clorless_chaos_king_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cold_wave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/colossal_fighter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/command_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/compulsory_evacuation_device/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/confiscation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/consecrated_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cosmic_cyclone/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crass_clown/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/creature_swap/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crevice_into_the_different_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crimson_blader/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crimson_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crossout_designator/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crush_card_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crystal_rose/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cursed_seal_of_the_forbidden_spell/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_drei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_infinity/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_nova/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_vier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_zwei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_eltanin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_end_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_harpie_lady/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_jar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_larva/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_phoenix/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_twin_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_valley/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_stein/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyberdark_wurm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cynet_mining/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_assailant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_crazy_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_crow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_survivor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_trainer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_warrior_lady/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/daigusto_emeral/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dance_princess_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dandylion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/danger_nessie_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dante_traveler_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_armed_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_balter_the_terrible/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_blade/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_blade_the_dragon_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_cavalry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_deal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_end_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_eradicator_warlock/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_flare_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_grepher/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magic_curtain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_girl/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_girl_the_dragon_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_girl_the_magician_s_apprentice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_of_chaos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_the_dragon_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_the_knight_of_dragon_magic/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_mimic_lv1/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_mimic_lv3/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_paladin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_ruler_ha_des/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_ruler_no_more/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_scorpion_chick_the_yellow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_scorpion_cliff_the_trap_remover/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_strike_fighter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_world_lightning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/darkfire_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/darklord_zerato/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/de_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/de_spell/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/debris_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/debunk/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/deck_devastation_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/deep_sea_diva/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/deep_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/defender_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dekoichi_the_battlechanted_locomotive/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/delg_the_dark_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/delinquent_duo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/demise_king_of_armageddon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/denko_sekka/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/des_dendle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/des_koala/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/des_lacooda/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/des_wombat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/desert_sunlight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_draw/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_celestial/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_dasher/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_destroyer_phoenix_enforcer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_diamond_dude/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_disk_commander/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_fear_monger/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/destiny_hero_malicious/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dharc_the_dark_charmer_gloomy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/diabellstar_the_black_witch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/diamond_dire_wolf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dian_keto_the_cure_master/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dictator_of_d_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_conjurer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_shifter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_wall/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimensional_barrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimensional_fissure/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimensional_prison/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dingirsu_the_orcust_of_the_evening_star/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dinomight_knight_the_true_dracofighter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dinoster_power_the_mighty_dracoslayer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dinowrestler_capaptera/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dinowrestler_pankratops/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dinowrestler_valeonyx/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/disciple_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/divine_arsenal_aa_zeus_sky_thunder/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/divine_dragon_knight_felgrand/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/divine_temple_of_the_snake_eye/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/divine_wrath/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dna_surgery/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dominus_impulse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/don_zaloog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/doom_dozer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/doomcaliber_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/doomkaiser_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/downerd_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/draco_face_off/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dracoback_the_rideable_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragged_down_into_the_grave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_ravine/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_shrine/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_s_mirror/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_s_rage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragoness_the_wicked_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragonic_diagram/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragunity_corsesca/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dream_clown/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/drillroid/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/droll_lock_bird/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/drop_off/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dunames_dark_witch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dupe_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dust_tornado/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/earth_effigy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/earthbound_spirit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/effect_veiler/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ehther_the_heavenly_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/eidos_the_underworld_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/eidos_the_underworld_squire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_anoyatyllis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_apkallone/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_construct/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_grysta/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_shekhinaga/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_wendigo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/el_shaddoll_winda/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elder_entity_norden/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/electric_snake/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/electric_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_blazeman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_clayman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_flame_wingman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_prisma/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_stratos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_wildheart/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_woodsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emergency_provisions/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emergency_teleport/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emilia_dance_priestess_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emissary_of_the_afterlife/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/empress_judge/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/enemy_controller/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/envoy_of_chaos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/eradicator_epidemic_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/erebus_the_underworld_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/escape_from_the_dark_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evening_twilight_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evenly_matched/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_exciton_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_heliotrope/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_ketos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evolzar_laggia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exa_enforcer_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exarion_universe/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exchange/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exchange_of_the_spirit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exiled_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exodia_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ext_ryzeal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fabled_lurrie/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fairy_tail_snow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fairy_wind/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fake_trap/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fallen_of_albaz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_aussa/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_eria/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_hiita/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_wynn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fantastical_dragon_phantazmay/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/farfa_malebranche_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fateful_adventure/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiber_jar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiend_griefing/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiend_skull_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiendish_chain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiendsmith_engraver/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiendsmith_s_lacrima/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiendsmith_s_requiem/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiendsmith_s_sequence/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiendsmith_s_tract/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fighting_flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/final_flame/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fire_formation_tenki/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fire_hand/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fire_king_high_avatar_kirin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fire_lake_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/firewall_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fissure/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flame_bufferlo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flame_ghost/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flamvell_guard/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flip_flop_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/floodgate_trap_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flying_c_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flying_kamakiri_1/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/foolish_burial/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_apocrypha/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_chalice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_droplet/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/forbidden_lance/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/formula_synchron/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fossil_dyna_pachycephalo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/frontier_wiseman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/full_house/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fusilier_dragon_the_dual_mode_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fusion_destiny/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fusion_devourer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fusion_substitute/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gagaga_cowboy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gagagigo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_knight_the_force_of_earth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_power/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_the_dragon_champion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_the_fierce_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/galatea_the_orcust_automaton/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/galaxy_cyclone/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gameciel_the_sea_turtle_kaiju/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/garoth_lightsworn_warrior/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/garura_wings_of_resonant_life/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gatling_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gear_golem_the_moving_fortress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gearfried_the_iron_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gearfried_the_red_eyes_iron_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_armadillo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_elephant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_alexandrite/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_emerald/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_garnet/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_hollowcore/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_lady_rose_diamond/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_nepyrim/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_prismaura/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_quartz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_ruby/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_sapphire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_tourmaline/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_zirconia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gemini_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gemini_imps/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gene_warped_warwolf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/genta_gateman_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ghost_belle_haunted_mansion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ghost_mourner_moonlit_chill/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ghost_ogre_snow_rabbit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ghost_reaper_winter_cherries/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ghost_sister_spooky_dogwood/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giant_germ/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giant_orc/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giant_rat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giant_red_seasnake/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giant_soldier_of_stone/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giant_trunade/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giga_tech_wolf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gigantes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gigantic_spright/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gil_garth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gilasaurus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/giltia_the_d_knight_soul_spear/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_ariel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_avance/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_chain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_emilia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_grimness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_marker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_natalia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_noellia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_shadow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_vanity/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gishki_vision/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_bestiari/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_darius/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_gaiodiaz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_gyzarus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_heraklinos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_laquari/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gladiator_beast_murmillo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_attack_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_elite_attack_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_pothole_squad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_zombie/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gokipon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gold_sarcophagus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goldd_wu_lord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/golem_sentry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gora_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gorz_the_emissary_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gottoms_emergency_call/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goyo_guardian/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/graceful_charity/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/graff_malebranche_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/granguignol_the_dusk_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/granmarg_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/granmarg_the_rock_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/grapha_dragon_lord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/grapha_dragon_overlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_assailant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_guard/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_spear_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_spy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gravekeeper_s_watcher/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gravity_bind/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/great_white/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/green_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gren_tactician_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/guardian_sphinx/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/guardragon_garmides/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/guiding_ariadne/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gunkan_suship_shari/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gyaku_gire_panda/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gyakutenno_megami/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hallowed_life_barrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hammer_shot/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hand_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hane_hane/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hanewata/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/harpie_s_feather_duster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/heart_of_the_blue_eyes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/heavy_storm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/heavy_storm_duster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/herald_of_orange_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/herald_of_the_arc_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hieracosphinx/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hiita_the_fire_charmer_ablaze/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/honest/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/horn_of_heaven/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/horn_of_the_phantom_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/howling_insect/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/humanoid_slime/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hydrogeddon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hyper_hammerhead/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/i_p_masquerena/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/icarus_attack/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ice_hand/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ice_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ice_ryzeal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ignister_prominence_the_blasting_dracoslayer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/illusion_of_chaos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/illusory_snatcher/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/imperial_iron_wall/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/imperial_order/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/inaba_white_rabbit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/incredible_ecclesia_the_virtuous/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/indomitable_fighter_lei_lei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernalqueen_salmon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_barrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_beetle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_inferno/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_launcher/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernity_necromancer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernoid_decatron/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernoid_harmadik/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernoid_patrulea/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infinite_impermanence/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/injection_fairy_lily/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/inpachi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/insect_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/instant_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/interrupted_kaiju_slumber/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/island_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/isolde_two_tales_of_the_noble_knights/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jar_of_greed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jinzo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jioh_the_gravity_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jirai_gumo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jongleur_ghoul_illusionist/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jowgen_the_spiritualist/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/judge_man/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/judgment_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jurrac_guaiba/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/just_desserts/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kabazauls/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kagemusha_of_the_six_samurai/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kagero_the_cannon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kaibaman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kaiser_sea_horse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/karma_cut/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kashtira_birth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kashtira_fenrir/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kashtira_riseheart/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kashtira_unicorn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kashtiratheosis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/keeper_of_dragon_magic/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/keeper_of_the_shrine/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kelbek_the_ancient_vanguard/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/keldo_the_sacred_protector/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_dragun/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_of_the_feral_imps/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_of_the_swamp/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_tiger_wanghu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/knightmare_cerberus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/knightmare_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/knightmare_phoenix/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/knightmare_unicorn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmo_dark_destroyer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmo_farmgirl/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmo_sliprider/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmo_tincan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmojo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmoll_wickedwitch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kozmotown/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/krebons/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kumongous_the_sticky_string_kaiju/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kurikara_divincarnate/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kycoo_the_ghost_destroyer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/la_jinn_the_mystical_genie_of_the_lamp/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/labrynth_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/labyrinth_tank/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lacrima_the_crimson_tears/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lady_ninja_yae/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lancer_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/last_will/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/legendary_six_samurai_kizan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/leotron/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lesser_fiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/level_limit_area_b/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/levia_dragon_daedalus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/leviair_the_sea_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/libic_malebranche_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/light_and_darkness_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/light_of_intervention/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/light_imprisoning_mirror/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lightning_storm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lightning_vortex/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lightning_dragon_ruler_of_drafts/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lightpulsar_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/limiter_removal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/link_spider/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/linkuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lonefire_blossom/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lord_of_d_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lubellion_the_searing_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lucent_netherlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lucius_the_shadow_vassal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lullaby_of_obedience/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lumina_lightsworn_summoner/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lunalight_black_sheep/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/luster_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/luster_pendulum_the_dracoslayer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lyla_lightsworn_sorceress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/m_x_saber_invoker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/machine_duplication/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/macro_cosmos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mad_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mad_dog_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maestroke_the_symphony_djinn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mage_power/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magic_cylinder/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magic_deflector/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magic_jammer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_abductor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_android/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_merchant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_scientist/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_of_dark_illusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_of_faith/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_circle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_robe/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_rod/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_valkyria/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magicians_souls/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magikuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maiden_of_the_aqua/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maiden_of_white/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maiden_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/majespecter_raccoon_bunbuku/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/majespecter_unicorn_kirin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/majester_paladin_the_ascending_dracoslayer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/majesty_s_fiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/makyura_the_destructor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_blue_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_cyber_end_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_red_eyes_black_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malevolent_catastrophe/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maliss_in_underground/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maliss_p_dormouse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maliss_p_white_rabbit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/man_eater_bug/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/manju_of_the_ten_thousand_hands/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/manticore_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/marauding_captain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mask_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mask_of_restrict/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/masked_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/masked_ninja_ebisu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/masked_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_hyperion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_of_chaos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_of_oz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_peace_the_true_dracoslaying_king/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_pendulum_the_dracoslayer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mataza_the_zapper/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mathematician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/matriarch_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maxx_c_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mecha_phantom_beast_dracossack/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mechanicalchaser/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/megalosmasher_x/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/megamorph/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/meizen_the_battle_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mekk_knight_avram/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mereologic_aggregator/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mermaid_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssgaios/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mermail_abyssgunde/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/metal_reflect_slime/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metalflame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metalfoes_goldriver/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metalfoes_silverd/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metalfoes_steelen/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metalfoes_volflame/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metaltronus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metamorphosis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/meteor_black_comet_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/meteor_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mezuki/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/milus_radiant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/minar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mind_control/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mind_crush/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mind_protector/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mine_golem/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/miracle_restoring/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_of_nightmare/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirror_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirror_of_oaths/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/missus_radiant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mist_wurm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mistake/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mitsu_the_insect_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/moai_interceptor_cannons/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mobius_the_frost_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mobius_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monk_of_the_tenyi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monster_gate/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monster_reborn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monster_reincarnation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/moon_of_the_closed_heaven/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/morphing_jar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/morphing_jar_2/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mother_grizzly/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mudora_the_sword_oracle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mudragon_of_the_swamp/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/muka_muka/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mulcharmy_fuwalos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mulcharmy_meowls/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mulcharmy_purulia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/my_body_as_a_shield/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystery_shell_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_mine/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_swordsman_lv2/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_swordsman_lv4/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_tomato/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_elf_white_lightning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_space_typhoon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystik_wok/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/naelshaddoll_ariel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/necro_gardna/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/necrovalley/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/needle_ceiling/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/neko_mane_king/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_cycle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_kaleidoscope/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_mirror/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_of_brionac/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_of_clausolas/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_of_unicore/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nekroz_of_valkyrus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/neo_bug/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/neo_kaiser_sea_horse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/neo_the_magic_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/neo_spacian_dark_panther/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/newdoria/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nibiru_the_primal_being/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/night_assailant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/night_beam/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nightmare_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nightmare_wheel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nightmare_s_steelcage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nimble_angler/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nimble_beaver/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nimble_momonga/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nin_ken_dog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ninja_grandmaster_hanzo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ninja_grandmaster_sasuke/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nobleman_of_crossout/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nobleman_of_extermination/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_101_silent_honor_ark/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_11_big_eye/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_17_leviathan_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_30_acid_golem_of_destruction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_39_utopia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_41_bagooska_the_terribly_tired_tapir/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/number_66_master_key_beetle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/offerings_to_the_doomed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ojama_king/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ojama_trio/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ookazi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/oppressed_people/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/opticlops/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/orcust_cymbal_skeleton/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/orcust_harp_horror/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/orcust_knightmare/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/orcustrated_return/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/original_sinful_spoils_snake_eye/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/overload_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/painful_choice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/painful_decision/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paladin_of_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paleozoic_anomalocaris/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paleozoic_canadia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paleozoic_dinomischus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paleozoic_marrella/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paleozoic_olenoides/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paleozoic_opabinia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/palladium_oracle_mahad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pantheism_of_the_monarchs/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/parl_hermit_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/penguin_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/penguin_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performage_damage_juggler/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performage_hat_tricker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performage_mirror_conductor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performage_plushfire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performage_trapeze_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performage_trick_clown/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performapal_guitartle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performapal_lizardraw/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performapal_monkeyboard/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performapal_pendulum_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performapal_silver_claw/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/performapal_skullcrobat_joker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/phantom_gryphon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/phantom_knights_fog_blade/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/phoenix_wing_wind_blast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pikeru_s_circle_of_enchantment/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pinch_hopper/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pitch_black_power_stone/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/plaguespreader_zombie/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/poison_of_the_old_man/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/polymerization/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_avarice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_desires/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_duality/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_generosity/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_greed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_prosperity/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prank_kids_dodo_doodle_doo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prank_kids_dropsies/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prank_kids_fansies/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prank_kids_lampsies/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prank_kids_place/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prank_kids_rocksies/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/predaplant_dragostapelia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/predaplant_verte_anaconda/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/premature_burial/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pressured_planet_wraitsoth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prevent_rat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prickle_fairy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/priestess_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/primal_dragon_the_primordial/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/primeval_planet_perlereino/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/princess_of_tsurugi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prohibition/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/promethean_princess_bestower_of_flames/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/protector_of_the_sanctuary/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/protector_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/psi_blocker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/psy_frame_driver/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/psy_framegear_gamma/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pulling_the_rug/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/punished_eagle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/puppet_plant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pyramid_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/qadshaddoll_keios/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/qliphort_carrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/qliphort_disk/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/qliphort_helix/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/qliphort_scout/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/raigeki/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/raigeki_break/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/raiza_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/red_dragon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_reboot/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_alternative_black_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_baby_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_dragon_sword/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_fullmetal_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_metal_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_meteor_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_darkness_metal_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_retro_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_slash_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_soul/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_toon_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_wyvern/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_zombie_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/redox_dragon_ruler_of_boulders/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reeshaddoll_wendi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reflect_bounder/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reign_beaux_overking_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reign_beaux_overlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reinforcement_of_the_army/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reinforcements/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/relinkuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/relinquished/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/relinquished_anima/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reload/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/remove_trap/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/renge_gatekeeper_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rescue_cat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rescue_rabbit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/retaliating_c_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/return_from_the_different_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rider_of_the_storm_winds/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/right_arm_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/right_leg_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ring_of_destruction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rising_air_current/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rite_of_aramesir/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rivalry_of_warlords/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/roaring_ocean_snake/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/robbin_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ronintoadin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/roulette_barrel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/royal_decree/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/royal_magical_library/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/royal_oppression/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rubic_malebranche_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/runick_destruction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/runick_flashing_fire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/runick_freezing_curses/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/runick_tip/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rush_recklessly/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryko_lightsworn_hunter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryu_kokki/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryu_senshi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryzeal_cross/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryzeal_detonator/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryzeal_duo_drive/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/s_p_little_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/saber_beetle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sabersaurus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_crane/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_phoenix_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_sword_of_seven_stars/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sage_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sakuretsu_armor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamandra_the_flying_flame_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamangreat_balelynx/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamangreat_foxy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamangreat_raging_phoenix/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamangreat_spinny/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamangreat_sunlight_wolf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salvage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sand_moth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sangan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sangen_kaimen/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sangen_summoning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/saqlifice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sasuke_samurai/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sasuke_samurai_4/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/scapegoat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/scarm_malebranche_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/scarr_scout_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/scrap_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sea_serpent_warrior_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/second_coin_toss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/secret_barrel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/self_destruct_button/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/senior_silver_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/senju_of_the_thousand_hands/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/serial_spell/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/serpentine_princess/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/seven_tools_of_the_bandit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_falco/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_hedgehog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_hound/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_squamata/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shadow_imprisoning_mirror/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shared_ride/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shien_s_smoke_signal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shining_angel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shiny_black_c_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shiny_black_c_squadder/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shrink/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shuffle_reborn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shurit_strategist_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sillva_warlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/silpheed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sinister_serpent/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sinister_shadow_games/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/six_samurai_united/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skill_drain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_dark_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_red_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_white_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skull_dog_marron/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skull_lair/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_iris/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_scout/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_ace_kagari/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_ace_raye/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_ace_roze/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_ace_shizuku/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_maneuver_afterburners_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_mecha_hornet_drones/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_mecha_shark_cannon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_mecha_widow_anchor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_striker_mobilize_engage_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/slate_warrior/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/smashing_ground/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snake_eye_ash/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snake_eye_birch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snake_eye_oak/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snake_eyes_diabellstar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snake_eyes_flamberge_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snake_eyes_poplar/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/solemn_strike/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_warning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_wishes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sonic_bird/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/soul_charge/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/soul_exchange/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/soul_taker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/soul_tiger/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spear_cretin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spear_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/speedroid_taketomborg/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/speedroid_terrortop/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spell_canceller/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spell_reproduction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spell_shattering_arrow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_magician_of_prophecy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_judgment/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spellbook_of_secrets/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sphere_kuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spirit_of_the_harp/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spirit_reaper/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spiritual_earth_art_kurogane/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spiritual_water_art_aoi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spiritual_wind_art_miyabi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spiritualism/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_carrot/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_jet/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_red/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_smashers/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_sprind/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spright_starter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stardust_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/starlight_road/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stealth_bird/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/steelswarm_roach/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stone_statue_of_the_aztecs/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stop_defense/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stream_dragon_ruler_of_droplets/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/strike_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/substitoad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/summon_limit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/summoned_skull/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/summoner_monk/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/summoner_s_art/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/super_polymerization/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/super_rejuvenation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/super_soldier_soul/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/super_starslayer_ty_phon_sky_crisis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swap_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swarm_of_locusts/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swarm_of_scarabs/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swift_scarecrow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sword_ryzeal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swords_of_revealing_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swordsoul_blackout/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swordsoul_emergence/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swordsoul_grandmaster_chixiao/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swordsoul_of_mo_ye/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swordsoul_of_taia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swordsoul_strategist_longyuan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/system_down/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/t_a_d_p_o_l_e_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_rush_rhino/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_striker/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/t_g_warwolf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_cryme/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_havnis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_heartbeat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_kaleido_heart/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_kashtira/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_kitkallos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_merrli/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_reinoheart/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_rulkallos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_scheiren/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_scream/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tearlaments_sulliek/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tellarknight_ptolemaeus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tempest_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tempest_dragon_ruler_of_storms/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/temtempo_the_percussion_djinn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenacity_of_the_monarchs/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenmataitei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenpai_dragon_chundra/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenpai_dragon_fadra/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenyi_spirit_adhara/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenyi_spirit_ashuna/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenyi_spirit_vishuda/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/terraforming/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/terrorking_salmon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/test_tiger/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tg1_em1/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/that_grass_looks_greener/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_agent_of_miracles_jupiter/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_agent_of_mystery_earth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_big_march_of_animals/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_black_stone_of_legend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_bystial_aluber/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_bystial_lubellion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_dark_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_dark_magicians/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_dragon_dwelling_in_the_cave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_earth_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_fiend_megacyber/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_forceful_sentry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_forgiving_maiden/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_golden_swordsoul/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_last_warrior_from_another_planet/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_light_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_little_swordsman_of_aile/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_monarchs_stormforth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_phantom_knights_of_ancient_cloak/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_phantom_knights_of_break_sword/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_phantom_knights_of_silent_boots/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_prime_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_tricky/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_white_stone_of_ancients/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_white_stone_of_legend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_wicked_worm_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_winged_dragon_of_ra_sphere_mode/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/there_can_be_only_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_firestorm_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_shadowfire_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thought_ruler_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thousand_eyes_restrict/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/threatening_roar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/throwstone_unit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragon_colossus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragon_titan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragondark/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragonduo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragonhawk/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragonlord/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragonmatrix/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragonroar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_king_rai_oh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_nyan_nyan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_sea_horse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tidal_dragon_ruler_of_waterfalls/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/timaeus_the_united_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/time_seal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/time_space_trap_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/titaniklad_the_ash_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tlakalel_his_malevolent_majesty/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toadally_awesome/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tobari_the_sky_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/token_collector/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_cannon_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_cyber_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_dark_magician_girl/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_gemini_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_goblin_attack_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_masked_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_summoned_skull/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_table_of_contents/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tornado_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/torrential_tribute/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/totem_bird/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tour_guide_from_the_underworld/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tradetoad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tragoedia/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/traptrix_arachnocampa/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_atrax/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_dionaea/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_genlisea/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_mantis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_myrmeleo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_nepenthes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_pudica/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_rafflesia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_trap_hole_nightmare/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/traptrix_vesiculo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/treeborn_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tremendous_fire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tri_brigade_fraktall/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tri_brigade_kitt/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tri_brigade_nervall/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tri_brigade_revolt/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tribe_infecting_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tribute_to_the_doomed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trickstar_candina/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trickstar_light_stage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trickstar_lycoris/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trickstar_reincarnation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/triple_tactics_talent/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/triple_tactics_thrust/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trishula_dragon_of_the_ice_barrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/true_draco_heritage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/true_king_s_return/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tsukuyomi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twilight_ninja_getsuga_the_shogun/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twilight_ninja_nichirin_the_chunin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twilight_ninja_shingetsu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twin_twisters/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twin_headed_behemoth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twin_headed_thunder_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twister/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/typhoon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ufo_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_insect_lv3/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_insect_lv5/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_insect_lv7/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_offering/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_slayer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/united_we_stand/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/upstart_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/upstart_golden_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vampire_lord/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vanity_s_emptiness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vanity_s_fiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vector_pendulum_the_dracoverlord/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vessel_for_the_dragon_cycle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/virgil_rock_star_of_the_burning_abyss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vision_hero_vyon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/void_feast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/void_vanishment/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/volcanic_scattershot/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vorse_raider/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/waboku/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wall_of_illusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wall_of_revealing_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wandering_gryphon_rider/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wanted_seeker_of_sinful_spoils/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/water_enchantress_of_the_temple/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wave_motion_cannon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wavering_eyes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_dragon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_dragon_ritual/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_dragon_wyverburster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_magical_hat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_night_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/widespread_ruin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wind_up_factory/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/witch_of_the_black_forest/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wroughtweiler/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wulf_lightsworn_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/x_head_cannon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/x_saber_airbellum/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/x_saber_urbellum/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/xyz_encore/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yata_garasu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yellow_dragon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yellow_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yomi_ship/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zaborg_the_thunder_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zombie_master/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zombie_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zombino/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zombyra_the_dark/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_barrage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_boarbow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_broadbull/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_chakanine/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_combo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_drident/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_hammerkong/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_ramram/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_ratpier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_thoroughblade/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_tigermortar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zoodiac_whiptail/pic_large.gbapal: %.gbapal: %.pal
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
