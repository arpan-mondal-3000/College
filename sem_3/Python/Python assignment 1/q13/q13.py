import os


def recursive_directory_search(dir_name=".", indent=0):
    file_names = os.listdir(dir_name)
    file_paths = [os.path.join(dir_name, f) for f in file_names]
    files = []
    dirs = []
    for file in file_paths:
        if os.path.isfile(file):
            files.append(file)
        elif os.path.isdir(file):
            dirs.append(file)
    for d in dirs:
        print(" "*indent, d)
        recursive_directory_search(d, indent+4)
    for f in files:
        print(" "*indent, f)


dir_name = input("Enter directory path to recursively search: ")

recursive_directory_search(dir_name)
