import os

dir_name = r".\myfiles"
file_names = os.listdir(dir_name)

for file in file_names:
    if file.endswith(".txt"):
        try:
            os.rename(os.path.join(dir_name, file),
                      os.path.join(dir_name, "old_"+file))
        except Exception as e:
            print(f"An error occured: {e}")
