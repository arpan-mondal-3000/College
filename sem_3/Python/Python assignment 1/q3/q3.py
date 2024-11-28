# Statement: merging multiple text files

n = int(input("Enter number of files: "))

contents = ["" for _ in range(0, n)]

for i in range(0, n):
    name = input(f"Enter name of file {i+1}: ")
    file = open(name, "r")
    contents[i] = file.read()
    file.close()

with open("merged.txt", "w") as merged_file:
    for content in contents:
        merged_file.write(content + "\n")
    merged_file.close()
