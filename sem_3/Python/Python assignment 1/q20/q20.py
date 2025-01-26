import os
import stat

dir_name = r".\myfiles"
file_names = os.listdir(dir_name)

for file in file_names:
    file_stat = os.stat(os.path.join(dir_name, file))
    if file_stat.st_mode & stat.S_IWOTH:
        print(file, oct(file_stat.st_mode), "is world writable!")
