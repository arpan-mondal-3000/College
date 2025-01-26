import random

with open("large.txt", "a") as file:
    for _ in range(100):
        buffer = (str(random.randint(1, 10**5)) for _ in range(0, 100_000))
        file.write("\n".join(buffer) + "\n")
