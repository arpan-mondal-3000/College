with open("log.txt", "r") as log:
    l = log.read()
    log.close()
logs = l.split("\n\n")
for i in logs:
    if "ERROR" in i:
        dt = i.split("]")[0][1:-4]

        thread = i.split("[")[2].split("]")[0]
        print("Date:", dt.split()[0], "Time:",
              dt.split()[1], "Thread:", thread)
