import gzip

choice = input("Enter c to compress and d to decompress: ")

if choice == "c":
    inp = input("Input file: ")
    with open(inp, "rb") as f_in:
        with gzip.open("data.gz", "wb") as f_out:
            f_out.writelines(f_in)
    print(f"Compressed {inp} to data.gz.")
elif choice == "d":
    comp = input("Compressed file: ")
    with gzip.open(comp, "rb") as f_in:
        with open("decompressed.txt", "wb") as f_out:
            f_out.writelines(f_in)
    print(f"Decompressed {comp} to decompressed.txt.")
