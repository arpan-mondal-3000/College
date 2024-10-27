import matplotlib.pyplot as plt
import subprocess
import os

if os.name == "nt":
    bin_extension = ".exe"
else:
    bin_extension = ""

number_of_points = input("Enter number of random points: ")
range_of_points = input("Enter range of points: ")

subprocess.run(["gcc", "-o", "data_generator", "data_generator.c", "-lm"])
subprocess.run(["./data_generator"+bin_extension,
               number_of_points, range_of_points])
subprocess.run(["gcc", "main.c", "-lm"])
subprocess.run(["./a"+bin_extension])

colors = {
    0: "red",
    1: "blue",
    2: "green",
    3: "yellow",
    4: "purple",
    5: "orange",
    6: "black",
    7: "white",
    8: "pink",
    9: "brown"
}

with open("result.txt", "r") as file:
    points = file.read().split()

# Total number of points
n = int(points[0])

# Number of clusters
k = int(points[1])

x = []
y = []
cluster_ids = []

# Put the coordinates in lists
for i in range(2, (3*n)+1, 3):
    x.append(float(points[i]))
    y.append(float(points[i+1]))
    cluster_ids.append(int(points[i+2]))

point_colors = [colors[id] for id in cluster_ids]

# Create the plot
plt.scatter(x, y, c=point_colors)
plt.title(f"Scatter plot of {n} points in {k} clusters")
plt.xlabel("x values")
plt.ylabel("y values")
plt.grid(True)
plt.show()

file.close()
