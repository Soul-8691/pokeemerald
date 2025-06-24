graphics/cards/blue_eyes_white_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/dark_magician/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

graphics/cards/red_eyes_black_dragon/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

