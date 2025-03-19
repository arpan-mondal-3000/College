#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int m, n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    int total_edges = (n * (n + 1)) / 2;

    if (m > total_edges)
    {
        printf("Invalid number of edges!\n");
        return 1;
    }

    FILE *fp = fopen("graph.txt", "w");
    int **adj_matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        adj_matrix[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                adj_matrix[i][j] = adj_matrix[j][i];
                fprintf(fp, "%d ", adj_matrix[i][j]);
                continue;
            }
            if (total_edges - (i * n + j) == m)
            {
                adj_matrix[i][j] = 1;
                fprintf(fp, "1 ");
                m--;
                continue;
            }
            int edge = rand() % 2;
            if (m && edge)
            {
                adj_matrix[i][j] = 1;
                fprintf(fp, "1 ");
                m--;
            }
            else
            {
                adj_matrix[i][j] = 0;
                fprintf(fp, "0 ");
            }
        }
        fprintf(fp, "\n");
    }

    for (int i = 0; i < n; i++)
        free(adj_matrix[i]);
    free(adj_matrix);

    fclose(fp);
    return 0;
}