import random

def xor(a, b):
    result = []
    for i in range(1, len(b)):
        result.append('0' if a[i] == b[i] else '1')
    return ''.join(result)

def mod2div(dividend, divisor):
    pick = len(divisor)
    tmp = dividend[:pick]

    while pick < len(dividend):
        if tmp[0] == '1':
            tmp = xor(divisor, tmp) + dividend[pick]
        else:
            tmp = xor('0' * pick, tmp) + dividend[pick]
        pick += 1

    if tmp[0] == '1':
        tmp = xor(divisor, tmp)
    else:
        tmp = xor('0' * pick, tmp)

    return tmp

def generate_codeword(dataword, generator):
    appended_data = dataword + '0' * (len(generator) - 1)
    remainder = mod2div(appended_data, generator)
    return dataword + remainder

def introduce_error(codeword):
    error_pos = random.randint(0, len(codeword) - 1)
    corrupted = list(codeword)
    corrupted[error_pos] = '1' if corrupted[error_pos] == '0' else '0'
    return ''.join(corrupted), error_pos

def check_codeword(received, generator):
    remainder = mod2div(received, generator)
    return '1' not in remainder

# ---------------- MAIN ----------------
dataword = input("Enter Dataword (binary): ")
generator = "1101"

print("\n--- SENDER SIDE ---")
codeword = generate_codeword(dataword, generator)
print("Generated Codeword:", codeword)

# Transmission
choice = input("\nIntroduce random error during transmission? (y/n): ")

if choice.lower() == 'y':
    transmitted, pos = introduce_error(codeword)
    print(f"Error introduced at bit position: {pos}")
else:
    transmitted = codeword

print("\n--- CHANNEL ---")
print("Transmitted Codeword:", transmitted)

print("\n--- RECEIVER SIDE ---")
if check_codeword(transmitted, generator):
    print("CRC Check: No Error Detected")
else:
    print("CRC Check: Error Detected")
