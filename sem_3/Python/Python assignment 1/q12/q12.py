import os
import hashlib

dir_name = input("Enter the directory path: ")
file_names = os.listdir(dir_name)

file_hashes = {}
for file in file_names:
    with open(os.path.join(dir_name, file), "rb") as f:
        file_contents = f.read()
        f.close()
    sha256 = hashlib.sha256(file_contents)
    hash_hex = sha256.hexdigest()
    if hash_hex in file_hashes.keys():
        print(file, "is a duplicate of", file_hashes[hash_hex])
    else:
        file_hashes[hash_hex] = file
