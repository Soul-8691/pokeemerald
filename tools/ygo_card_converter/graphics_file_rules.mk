graphics/cards/relinquished/pic_large.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 64

