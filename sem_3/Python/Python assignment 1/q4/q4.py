with open("file1.txt", "r") as f1:
    file1 = f1.read()
    f1.close()
with open("file2.txt", "r") as f2:
    file2 = f2.read()
    f2.close()
list1 = file1.split("\n")
list2 = file2.split("\n")
for i in range(0, max(len(list1), len(list2))):
    print(i+1, end=":")
    if i >= len(list1):
        print(f"file2:{list2[i]}")
        continue
    if i >= len(list2):
        print(f"file1:{list1[i]}")
        continue
    if list1[i] == list2[i]:
        print("same")
    else:
        print(f"file1:{list1[i]} file2:{list2[i]}")
