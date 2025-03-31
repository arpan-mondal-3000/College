#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("grid.txt", "r");
    if (!fp)
    {
        printf("Failed to read grid.txt!\n");
        return 1;
    }

    int n; // nxn grid
    fscanf(fp, "%d", &n);
    int xs, ys, xd, yd;
    printf("Enter source coordinates(xs, ys): ");
    scanf("%d %d", &xs, &ys);

    printf("Enter destination coordinates(xd, yd): ");
    scanf("%d %d", &xd, &yd);

    // Allocating memory for the grid
    int **grid;
    grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        grid[i] = (int *)malloc(n * sizeof(int));

    // Reading the grid from the file
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &grid[i][j]);

    // Deallocating memory of the grid
    for (int i = 0; i < n; i++)
        free(grid[i]);
    free(grid);

    fclose(fp);
    return 0;
}