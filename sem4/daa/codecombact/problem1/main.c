#include <stdio.h>
#include <stdlib.h>

void flip(int m, int n, int k, int type, int **arr)
// k: number of row or column
// type: 0 for row and 1 for column
{
    if (type == 0)
        for (int i = 0; i < n; i++)
            arr[k][i] = arr[k][i] ? 0 : 1;
    else
        for (int i = 0; i < m; i++)
            arr[i][k] = arr[i][k] ? 0 : 1;
}

int calculate_score(int m, int n, int **arr)
{
    int score = 0;
    for (int i = 0; i < m; i++)
    {
        int curr = 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[i][j] == 1)
                score += curr;
            curr *= 2;
        }
    }
    return score;
}

int highest_score(int m, int n, int **arr)
{
    for (int i = 0; i < m; i++)
        if (arr[i][0] == 0)
            flip(m, n, i, 0, arr);
    for (int i = 1; i < n; i++)
    {
        int isMax = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] == 1)
                isMax++;
            else
                isMax--;
        }
        if (isMax < 0)
            flip(m, n, i, 1, arr);
    }
    return calculate_score(m, n, arr);
}

int main()
{
    FILE *fp = fopen("tests.txt", "r");

    int test_cases;
    fscanf(fp, "%d", &test_cases);

    while (test_cases)
    {
        int m, n;
        fscanf(fp, "%d %d", &m, &n);
        int **arr = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++)
            arr[i] = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                fscanf(fp, "%d", &arr[i][j]);

        printf("Before maximizing: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }

        printf("Highest score: %d\n", highest_score(m, n, arr));

        printf("After maximizing: \n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }

        for (int i = 0; i < m; i++)
            free(arr[i]);
        free(arr);
        test_cases--;
    }

    fclose(fp);
    return 0;
}