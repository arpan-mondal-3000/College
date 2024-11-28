with open("input.txt", "r") as input_file:
    contents = input_file.read()

frequencies = {}

for word in contents.split():
    if word in frequencies:
        frequencies[word] += 1
    else:
        frequencies[word] = 1

print(frequencies)


def key_fn(i):
    return frequencies[i]


sorted_freq = sorted(frequencies, key=key_fn, reverse=True)

sorted_dict = {}
for key in sorted_freq:
    sorted_dict[key] = frequencies[key]

print(sorted_dict)
input_file.close()
