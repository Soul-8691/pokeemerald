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

graphics/cards/abyss_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/airknight_parshath/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amazoness_archer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amphibious_bugroth_mk_3/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/anti_spell_fragrance/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/aqua_madoor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/aqua_spirit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arsenal_bug/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arsenal_summoner/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/asura_priest/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/axe_of_despair/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/banisher_of_the_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/barrel_behind_the_door/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/battle_footballer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/battle_ox/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bazoo_the_soul_eater/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/black_illusion_ritual/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_luster_soldier_envoy_of_the_beginning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_pendant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_skull_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blade_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blast_with_chain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blazing_inpachi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blindly_loyal_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/block_attack/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blowback_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_ultimate_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_life/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_moon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/book_of_taiyou/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bottomless_trap_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bowganian/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brain_control/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/breaker_the_magical_warrior/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/broww_huntsman_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brron_mad_king_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/buster_blader/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/byser_shock/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/call_of_the_haunted/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cannon_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/card_destruction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/castle_of_dark_illusions/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/castle_walls/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/catapult_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ceasefire/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/chaos_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/charcoal_inpachi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chiron_the_mage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cipher_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cold_wave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/command_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/compulsory_evacuation_device/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/confiscation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crass_clown/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/creature_swap/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crush_card_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cursed_seal_of_the_forbidden_spell/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_end_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_harpie_lady/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_jar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_twin_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_stein/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_assailant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_crazy_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_survivor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_trainer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/d_d_warrior_lady/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_blade/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_blade_the_dragon_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_deal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magic_curtain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_of_chaos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_mimic_lv1/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_mimic_lv3/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_paladin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_ruler_ha_des/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_scorpion_chick_the_yellow/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_scorpion_cliff_the_trap_remover/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_world_lightning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/de_spell/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/deck_devastation_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dekoichi_the_battlechanted_locomotive/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/delinquent_duo/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/dian_keto_the_cure_master/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/don_zaloog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/doom_dozer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/doomcaliber_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragged_down_into_the_grave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_s_mirror/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dragon_s_rage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dream_clown/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/drillroid/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/drop_off/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dunames_dark_witch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dust_tornado/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/earthbound_spirit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/electric_snake/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_clayman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_flame_wingman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_wildheart/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emergency_provisions/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emissary_of_the_afterlife/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/enemy_controller/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/fake_trap/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_aussa/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_eria/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_hiita/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/familiar_possessed_wynn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fiber_jar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/final_flame/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fissure/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flying_kamakiri_1/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fusilier_dragon_the_dual_mode_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gagagigo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_power/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_the_dragon_champion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gatling_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gear_golem_the_moving_fortress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gearfried_the_iron_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gemini_elf/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/gil_garth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gilasaurus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_attack_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/goblin_elite_attack_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gokipon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/golem_sentry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gora_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/graceful_charity/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/guardian_sphinx/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gyaku_gire_panda/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gyakutenno_megami/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hallowed_life_barrier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hane_hane/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/harpie_s_feather_duster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/heavy_storm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hieracosphinx/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/horn_of_heaven/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/howling_insect/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/humanoid_slime/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hydrogeddon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hyper_hammerhead/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/imperial_order/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/inaba_white_rabbit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/indomitable_fighter_lei_lei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/injection_fairy_lily/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/inpachi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/insect_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/island_turtle/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/just_desserts/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kaiser_sea_horse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/karma_cut/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_dragun/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_of_the_swamp/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/king_tiger_wanghu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kycoo_the_ghost_destroyer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/la_jinn_the_mystical_genie_of_the_lamp/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/labyrinth_tank/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lady_ninja_yae/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/last_will/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/left_arm_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/left_leg_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/legendary_jujitsu_master/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/level_limit_area_b/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/levia_dragon_daedalus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/light_of_intervention/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lightning_vortex/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/limiter_removal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/luster_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mad_dog_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mage_power/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magic_cylinder/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magic_jammer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_merchant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magical_scientist/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_of_faith/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_circle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_valkyria/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maiden_of_the_aqua/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/makyura_the_destructor/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/masked_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mataza_the_zapper/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mechanicalchaser/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/megamorph/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mermaid_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/messenger_of_peace/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metal_reflect_slime/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metamorphosis/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/milus_radiant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/minar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mind_control/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mine_golem/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/miracle_restoring/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirage_of_nightmare/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mirror_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/moai_interceptor_cannons/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mobius_the_frost_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monster_gate/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monster_reborn/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/monster_reincarnation/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/morphing_jar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mother_grizzly/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/muka_muka/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_swordsman_lv2/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_swordsman_lv4/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystic_tomato/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_space_typhoon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystik_wok/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/newdoria/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/night_assailant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nightmare_wheel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nightmare_s_steelcage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nimble_momonga/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nin_ken_dog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ninja_grandmaster_sasuke/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nobleman_of_crossout/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/nobleman_of_extermination/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/painful_choice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/paladin_of_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/penguin_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/phoenix_wing_wind_blast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pikeru_s_circle_of_enchantment/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pinch_hopper/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pitch_black_power_stone/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/poison_of_the_old_man/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/polymerization/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_avarice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_generosity/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pot_of_greed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/premature_burial/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prevent_rat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/prickle_fairy/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/princess_of_tsurugi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/protector_of_the_sanctuary/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/pyramid_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/raigeki/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/raigeki_break/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reaper_on_the_nightmare/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reasoning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reckless_greed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reflect_bounder/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reinforcement_of_the_army/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reinforcements/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/relinquished/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reload/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/remove_trap/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rescue_cat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/return_from_the_different_dimension/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/right_arm_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/right_leg_of_the_forbidden_one/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ring_of_destruction/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rising_air_current/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/robbin_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/roulette_barrel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/royal_decree/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/royal_magical_library/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/royal_oppression/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rush_recklessly/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ryu_kokki/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/saber_beetle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_crane/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sacred_phoenix_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sakuretsu_armor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salvage/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sand_moth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sangan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sasuke_samurai/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sasuke_samurai_4/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/scapegoat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sea_serpent_warrior_of_darkness/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/second_coin_toss/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/secret_barrel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/self_destruct_button/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/serial_spell/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/serpentine_princess/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/seven_tools_of_the_bandit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shining_angel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shrink/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sillva_warlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/silpheed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sinister_serpent/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skill_drain/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_dark_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_white_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skull_dog_marron/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skull_lair/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sky_scout/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/slate_warrior/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/smashing_ground/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snatch_steal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_judgment/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/solemn_wishes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/soul_exchange/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/soul_tiger/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spear_cretin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spear_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spell_canceller/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/spell_reproduction/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/stealth_bird/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stone_statue_of_the_aztecs/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/stop_defense/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/summoned_skull/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swarm_of_locusts/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swarm_of_scarabs/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swords_of_revealing_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/terraforming/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_big_march_of_animals/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_dragon_dwelling_in_the_cave/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_fiend_megacyber/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_forceful_sentry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_forgiving_maiden/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_last_warrior_from_another_planet/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_little_swordsman_of_aile/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_wicked_worm_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_firestorm_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thousand_eyes_restrict/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/threatening_roar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/throwstone_unit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thunder_nyan_nyan/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/time_seal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_cannon_soldier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_dark_magician_girl/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_gemini_elf/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_goblin_attack_force/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_masked_sorcerer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_table_of_contents/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/torrential_tribute/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trap_dustshoot/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trap_hole/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/trap_master/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/treeborn_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tremendous_fire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tribe_infecting_virus/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tribute_to_the_doomed/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tsukuyomi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twin_headed_behemoth/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twin_headed_thunder_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_insect_lv3/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_insect_lv5/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_insect_lv7/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ultimate_offering/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/united_we_stand/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/upstart_goblin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vampire_lord/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vorse_raider/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/waboku/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wall_of_illusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wall_of_revealing_light/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wave_motion_cannon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_dragon_ritual/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_magical_hat/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/widespread_ruin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/witch_of_the_black_forest/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/x_head_cannon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/xing_zhen_hu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yata_garasu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yomi_ship/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zaborg_the_thunder_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zombyra_the_dark/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/zure_knight_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/albaz_the_ashen/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/albion_the_shrouded_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/aluber_the_jester_of_despia/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/amazoness_spiritualist/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_gear_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ancient_gear_golem_ultimate_pound/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/angmarl_the_fiendish_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/apprentice_illusion_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_cavalry/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_commander/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_giant/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_heiress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_interceptor/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_of_gilfer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/archfiend_s_advent/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ariel_priestess_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/arisen_gaia_the_fierce_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/armed_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/armored_cybern/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/avance_swordsman_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/baku_the_beast_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beast_of_talwar/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beast_of_talwar_the_sword_summit/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beginning_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/beiige_vanguard_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/berlineth_the_firestorm_vassal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_dragon_s_chick/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/black_metal_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blazing_cartesia_the_virtuous/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_alternative_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_jet_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/blue_eyes_toon_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/bone_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/brilliant_rose/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/buster_blader_the_destruction_swordmaster/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/caius_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/caius_the_shadow_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chaos_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/charging_gaia_the_fierce_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chronicle_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/chronicle_sorceress/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crimson_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/crystal_rose/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_drei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_vier/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_dragon_zwei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_eltanin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyber_larva/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/cyberdark_wurm/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dance_princess_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_eradicator_warlock/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_girl/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician_girl_the_magician_s_apprentice/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dark_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/deep_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/defender_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/delg_the_dark_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dictator_of_d_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dimension_conjurer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/disciple_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/dupe_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ehther_the_heavenly_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/eidos_the_underworld_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/eidos_the_underworld_squire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_blazeman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/elemental_hero_woodsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/emilia_dance_priestess_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/envoy_of_chaos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/erebus_the_underworld_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evening_twilight_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_heliotrope/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/evilswarm_ketos/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/exa_enforcer_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fallen_of_albaz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fighting_flame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/flip_flop_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/fusion_devourer/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gaia_the_fierce_knight/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/gem_knight_nepyrim/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_quartz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_sapphire/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_knight_tourmaline/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gem_turtle/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/genta_gateman_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/goblin_pothole_squad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/granmarg_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/granmarg_the_rock_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/grapha_dragon_lord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/green_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/gren_tactician_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/hand_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/heart_of_the_blue_eyes/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ice_knight/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/infernalqueen_salmon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/jioh_the_gravity_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kagero_the_cannon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/kaibaman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/keeper_of_dragon_magic/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/keeper_of_the_shrine/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/labrynth_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lancer_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lesser_fiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lord_of_d_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lucent_netherlord_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/lucius_the_shadow_vassal/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mad_archfiend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_of_dark_illusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_robe/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magician_s_rod/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magicians_souls/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/magikuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maiden_of_white/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/maiden_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_blue_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_cyber_end_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/malefic_red_eyes_black_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/masked_ninja_ebisu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/master_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/matriarch_of_nephthys/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/metalflame_swordsman/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/meteor_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mitsu_the_insect_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mobius_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/mystical_elf_white_lightning/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/naelshaddoll_ariel/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/neo_kaiser_sea_horse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ninja_grandmaster_hanzo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/palladium_oracle_mahad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/parl_hermit_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/penguin_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/priestess_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/protector_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/qadshaddoll_keios/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/raiza_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_dragon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_alternative_black_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_baby_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_meteor_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_darkness_metal_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_retro_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_soul/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_toon_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_wyvern/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_zombie_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reeshaddoll_wendi/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/reign_beaux_overking_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/relinkuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/renge_gatekeeper_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/rider_of_the_storm_winds/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/ronintoadin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sage_with_eyes_of_blue/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/salamandra_the_flying_flame_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/scarr_scout_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/senior_silver_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/senju_of_the_thousand_hands/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_beast/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_falco/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_hedgehog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shaddoll_hound/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/shurit_strategist_of_the_nekroz/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/skilled_red_magician/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/snoww_unlight_of_dark_world/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sonic_bird/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/sphere_kuriboh/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/substitoad/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/super_soldier_soul/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/swap_frog/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/t_a_d_p_o_l_e_/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tenmataitei/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/terrorking_salmon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_black_stone_of_legend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_bystial_aluber/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_bystial_lubellion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_dark_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_earth_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_golden_swordsoul/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_light_hex_sealed_fusion/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_white_stone_of_ancients/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/the_white_stone_of_legend/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_mega_monarch/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/thestalos_the_shadowfire_monarch/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/thunder_sea_horse/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/timaeus_the_united_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tlakalel_his_malevolent_majesty/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tobari_the_sky_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_cyber_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/toon_summoned_skull/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/tradetoad/pic_large.gbapal: %.gbapal: %.pal
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

graphics/cards/traptrix_vesiculo/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twilight_ninja_getsuga_the_shogun/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twilight_ninja_nichirin_the_chunin/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/twilight_ninja_shingetsu/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/upstart_golden_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/vision_hero_vyon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_dragon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_night_dragon/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/white_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/wroughtweiler/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yellow_dragon_ninja/pic_large.gbapal: %.gbapal: %.pal
		$(GFX) $< $@ -num_colors 64

graphics/cards/yellow_ninja/pic_large.gbapal: %.gbapal: %.pal
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
