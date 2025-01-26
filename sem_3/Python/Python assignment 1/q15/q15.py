import os
import time

dir_name = r".\myfiles"
file_names = os.listdir(dir_name)

file_paths = [os.path.join(dir_name, f) for f in file_names]

for file in file_paths:
    stat = os.stat(file)
    print("File name:", file_names[file_paths.index(file)])
    print("File size:", stat.st_size, "bytes")
    print("Creation date:", time.ctime(stat.st_ctime))
    print("Last modified:", time.ctime(stat.st_mtime))
    print()
