import json

with open("data.json", "r") as datafile:
    data = json.load(datafile)
    datafile.close()

id = int(input("Enter problem statement ID: "))

for ps in data:
    if ps["id"] == id:
        print("Title: ", ps["problem_statement_title"])
        print("Theme: ", ps["theme"])
        print("Total submissions: ", ps["total_submissions"])
