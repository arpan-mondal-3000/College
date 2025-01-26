with open("file.txt", "r") as file:
    contents = file.read()
    file.close()

print("Number of lines: ", len(contents.split("\n")))
print("Number of words: ", len(contents.split()))
print("Number of characters: ", len(contents)-len(contents.split("\n"))+1)
