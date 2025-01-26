import hashlib

file1 = input("Enter path of original file: ")
file2 = input("Enter path of file you want to compare: ")

with open(file1, "rb") as file:
    contents1 = file.read()
    file.close()
with open(file2, "rb") as f:
    contents2 = f.read()
    f.close()

sha2561 = hashlib.sha256(contents1)
sha2562 = hashlib.sha256(contents2)
print("Checksum 1:", sha2561.hexdigest())
print("Checksum 2:", sha2562.hexdigest())

if sha2561.hexdigest() == sha2562.hexdigest():
    print("They are same")
else:
    print("One has been tampered")
