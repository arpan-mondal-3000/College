from PIL import Image

WIDTH = int(input("Enter width of canvas: "))
HEIGHT = int(input("Enter height of canvas: "))
x1 = int(input("x1: "))
y1 = HEIGHT - int(input("y1: "))
x2 = int(input("x2: "))
y2 = HEIGHT - int(input("y2: "))

if x1 < 0 or x1 > WIDTH or x2 < 0 or x2 > WIDTH:
    print("X coordinate must be positive and within width of the canvas!")
    exit(1)

if y1 < 0 or y1 > HEIGHT or y2 < 0 or y2 > HEIGHT:
    print("Y coordinate must be positive and within height of the canvas!")
    exit(1)

img = Image.new('RGB', (WIDTH, HEIGHT), color='white')

pixels = img.load()

black = (0, 0, 0)
def setPixel(x, y):
    pixels[x, y] = black

# DDA
dx = x2 - x1
dy = y2 - y1
x = x1
y = y1

if abs(dx) >= abs(dy):
    steps = abs(dx)
else:
    steps = abs(dy)

xincr = dx/steps
yincr = dy/steps
setPixel(x, y)

for k in range(0, steps+1):
    x = x + xincr
    y = y + yincr
    setPixel(x, y)


img.save('output.png')
img.show()