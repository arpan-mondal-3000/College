with open("image.jpg", "rb") as imagefile:
    img = imagefile.read()
    imagefile.close()

modified = (img[:len(img)//2] + b"\x01" * 100 + img[len(img)//2+100:])

with open("modified.jpg", "wb") as output:
    output.write(modified)
    output.close()
