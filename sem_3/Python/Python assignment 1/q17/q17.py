with open("log.txt", "r") as log:
    logs = log.read()
    log.close()

modified = logs.replace("ERROR", "WARNING")

with open("modified.txt", "w") as output:
    output.write(modified)
    output.close()
