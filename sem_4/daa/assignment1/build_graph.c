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

    int total_edges = n * n;

    if (m > total_edges)
    {
        printf("Invalid number of edges!\n");
        return 1;
    }

    FILE *fp = fopen("graph.txt", "w");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (total_edges - (i * n + j) == m)
            {
                fprintf(fp, "1 ");
                m--;
                continue;
            }
            int edge = rand() % 2;
            if (m && edge)
            {
                fprintf(fp, "1 ");
                m--;
            }
            else
                fprintf(fp, "0 ");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}