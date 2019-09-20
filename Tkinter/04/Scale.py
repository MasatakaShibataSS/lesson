import tkinter as tk

# Main Window
root = tk.Tk()
root.title("Tkinter:Scale")
root.geometry("300x200")

# Define the scales
red = tk.IntVar()
red.set(0)
blue = tk.IntVar()
blue.set(0)
green = tk.IntVar()
green.set(0)

# Change background color
def change_color( n ):
#   color = '#%02x%02x%02x' % (red.get(), green.get(), blue.get())
    color = '#{:02x}{:02x}{:02x}'.format(red.get(), green.get(), blue.get())
    color_label.configure(bg = color)

# color_Label
color_label = tk.Label(root, text = 'COLOR', bg = '#000')
color_label.pack(fill = 'both');

# Scale
s1 = tk.Scale(root, label = 'red', orient = 'h',
           from_ = 0, to = 255, variable = red,
           command = change_color)

s2 = tk.Scale(root, label = 'blue', orient = 'h',
           from_ = 0, to = 255, variable = blue,
           command = change_color)

s3 = tk.Scale(root, label = 'green', orient = 'h',
           from_ = 0, to = 255, variable = green,
           command = change_color)

# Layout and styling widged
s1.pack(fill = 'both')
s2.pack(fill = 'both')
s3.pack(fill = 'both')

# Main
root.mainloop();
