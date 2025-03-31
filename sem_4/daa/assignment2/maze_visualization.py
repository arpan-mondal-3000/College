import numpy as np
import matplotlib.pyplot as plt

# Convert the given string to a 2D list
maze_string = ""

with open("grid.txt", "r") as file:
    maze_string = file.read()[2:]
    file.close()


# Convert string to a numpy array
maze = np.array([list(map(int, row.split())) for row in maze_string.strip().split("\n")])

# Plot the maze
plt.figure(figsize=(6,6))
plt.imshow(maze, cmap="gray_r")  # 'gray_r' makes 1s black and 0s white
plt.xticks([])  # Hide x-axis ticks
plt.yticks([])  # Hide y-axis ticks
plt.grid(False)
# plt.show()
plt.savefig("maze.png") 
