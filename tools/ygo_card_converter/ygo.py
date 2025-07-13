from PIL import Image
import os
import subprocess
import re

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

image_cropped = 'in/4-Starred Ladybug of Doom_83994646_Cropped.jpg'

# Icon (Tiny)
size = 16, 16
master = Image.new(
    mode='RGBA',
    size=(16, 24),
    color=(57,255,20,0))
folder_path = 'out/'
if not os.path.exists(folder_path):
    os.mkdir(folder_path)
outfile = folder_path + re.sub(r'\W+', '_', '4-Starred Ladybug of Doom').lower() + '_icon_tiny.png'
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
subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.pal')])
out_pal = open(outfile.replace('.png', '.pal'), 'r')
lines = out_pal.readlines()
out_pal = open(outfile.replace('.png', '.pal'), 'w')
lines[2] = '16\n'
lines.append('0 0 0\n')
out_pal.writelines(lines)
out_pal.close()

# Icon (Small)
size = 24, 24
master = Image.new(
    mode='RGBA',
    size=(24, 32),
    color=(57,255,20,0))
folder_path = 'out/'
if not os.path.exists(folder_path):
    os.mkdir(folder_path)
outfile = folder_path + re.sub(r'\W+', '_', '4-Starred Ladybug of Doom').lower() + '_icon_small.png'
im = Image.open(image_cropped)
im.thumbnail(size, Image.Resampling.LANCZOS)
im.save(outfile, 'PNG')
master.paste(im, box=(0,4))
master.save(outfile, "PNG")
# master = Image.open(outfile)
# master = master.convert(
#     "P", palette=Image.ADAPTIVE, colors=15
# )
# master = move_palette_color(master, 15, 0)
master.save(outfile, "PNG")
subprocess.run(['./magick', outfile, '-colors', "16", '-define', 'png:exclude-chunk=bKGD', outfile])
master = Image.open(outfile)
master = master.convert(
    "P"
)
master = move_palette_color(master, 0, 0)
master.save(outfile, "PNG")
# subprocess.run(['../gbagfx/gbagfx', outfile, outfile.replace('.png', '.pal')])
# out_pal = open(outfile.replace('.png', '.pal'), 'r')
# lines = out_pal.readlines()
# out_pal = open(outfile.replace('.png', '.pal'), 'w')
# lines[2] = '16\n'
# lines.append('0 0 0\n')
# out_pal.writelines(lines)
# out_pal.close()