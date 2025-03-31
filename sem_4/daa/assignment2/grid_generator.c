#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *fp = fopen("grid.txt", "w");
    if (!fp)
    {
        printf("File cannot be opened!\n");
        return 1;
    }

    int n;
    printf("Enter n(nxn grid will be created): ");
    scanf("%d", &n);

    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(fp, "%d ", rand() % 2);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}