with open("input.txt", "r") as input_file:
    inp = input_file.read()

with open("output.txt", "w") as output_file:
    output_file.write(inp)

input_file.close()
output_file.close()
