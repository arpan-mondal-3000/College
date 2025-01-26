import csv
list = []
fields = []
with open("file.csv", "r") as inputfile:
    file = csv.DictReader(inputfile)
    fields = file.fieldnames

    for i in file:
        list.append(i)
    inputfile.close()

name = input("Enter the name: ")
email = input("Enter new email: ")
for row in list:
    if name == row[fields[0]]:
        row[fields[1]] = email

with open("output.csv", "w") as out:
    writer = csv.DictWriter(out, fieldnames=fields)
    writer.writeheader()
    writer.writerows(list)
    out.close()
