import os
import random

dir_name = r".\logs"

for i in range(1, 11):
    with open(os.path.join(dir_name, "log.txt"), "w") as logfile:
        while True:
            file_stat = os.stat(os.path.join(dir_name, "log.txt"))
            if file_stat.st_size > 10000:
                break
            buffer = (str(random.randint(1, 10**5)) for _ in range(100))
            logfile.write("\n".join(buffer) + "\n")
        logfile.close()
    os.rename(os.path.join(dir_name, "log.txt"),
              os.path.join(dir_name, f"log{i}.txt"))
