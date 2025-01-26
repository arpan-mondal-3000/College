choice = input("Press e to encrypt and d to decrypt: ")
filename = input("Enter file name: ")
shift = int(input("Enter displacement: "))

with open(filename, "r") as file:
    org = file.read()
    file.close()
modified = ""
if choice == "e":
    for l in org:
        if ord(l) >= 65 and ord(l) <= 90:
            modified += chr(ord("A")+(ord(l) - ord("A") + shift) % 26)
        elif ord(l) >= 97 and ord(l) <= 122:
            modified += chr(ord("a")+(ord(l) - ord("a") + shift) % 26)
        else:
            modified += l
    with open("encrypted.txt", "w") as enc:
        enc.write(modified)
elif choice == "d":
    for l in org:
        if ord(l) >= 65 and ord(l) <= 90:
            modified += chr(ord("Z")-(ord("Z") - ord(l) + shift) % 26)
        elif ord(l) >= 97 and ord(l) <= 122:
            modified += chr(ord("z")-(ord("z") - ord(l) + shift) % 26)
        else:
            modified += l
    with open("decrypted.txt", "w") as enc:
        enc.write(modified)
else:
    print("Enter a valid choice!")
