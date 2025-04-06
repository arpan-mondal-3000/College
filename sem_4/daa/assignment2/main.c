#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    int y;
    struct node *link;
} node;

node *path = NULL;
node *temp = NULL;
int df = 1;

void DFS(int **grid, int xs, int ys, int xd, int yd, int **mark, int n)
{
    // initialize path at source node
    if (!path)
    {
        node *start = (node *)malloc(sizeof(node));
        start->x = xs;
        start->y = ys;
        path = start;
        temp = path;
    }
    else // add each node to the path
    {
        printf("Visiting: %d, %d\n", xs, ys);
        node *next = (node *)malloc(sizeof(node));
        next->x = xs;
        next->y = ys;
        temp->link = next;
        temp = next;
        mark[xs][ys] = 1;
    }
    // End if destinaiton reached
    if (xs == xd && ys == yd)
    {
        temp->link = NULL;
        printf("Destination reached: %d, %d\n", xs, ys);
        mark[xs][ys] = 1;
        df = 0;
        return;
    }

    // check top
    if (xs != 0 && grid[xs - 1][ys] == 0 && mark[xs - 1][ys] == 0 && df)
    {
        DFS(grid, xs - 1, ys, xd, yd, mark, n);
    }
    // check right
    if (ys != n - 1 && grid[xs][ys + 1] == 0 && mark[xs][ys + 1] == 0 && df)
    {
        DFS(grid, xs, ys + 1, xd, yd, mark, n);
    }
    // check bottom
    if (xs != n - 1 && grid[xs + 1][ys] == 0 && mark[xs + 1][ys] == 0 && df)
    {
        DFS(grid, xs + 1, ys, xd, yd, mark, n);
    }
    // check left
    if (ys != 0 && grid[xs][ys - 1] == 0 && mark[xs][ys - 1] == 0 && df)
    {
        DFS(grid, xs, ys - 1, xd, yd, mark, n);
    }
}

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
    printf("Enter source coordinates(xs, ys): "); // e.g : 0 6
    scanf("%d %d", &xs, &ys);

    printf("Enter destination coordinates(xd, yd): "); // e.g : 10 18
    scanf("%d %d", &xd, &yd);

    // Allocating memory for the grid
    int **grid;
    grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        grid[i] = (int *)malloc(n * sizeof(int));

    // Allocating memory for mark array
    int **mark; // 0: undiscovered; 1: discovered; 2: finished
    mark = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        mark[i] = (int *)calloc(n, sizeof(int));

    // Reading the grid from the file
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &grid[i][j]);

    DFS(grid, xs, ys, xd, yd, mark, n);

    node *temp = path;
    while (temp)
    {
        if (temp->link)
            printf("(%d, %d) -> ", temp->x, temp->y);
        else
            printf("(%d, %d)\n", temp->x, temp->y);
        temp = temp->link;
    }

    // Deallocating memory of the grid
    for (int i = 0; i < n; i++)
        free(grid[i]);
    free(grid);

    // Deallocating memory of the mark
    for (int i = 0; i < n; i++)
        free(mark[i]);
    free(mark);

    fclose(fp);
    return 0;
}