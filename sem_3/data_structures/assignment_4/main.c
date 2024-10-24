#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int isSorted(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int n;
    printf("n: ");
    scanf("%d", &n);
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    arr[0] = (rand() % 100000) + 1;
    int comp = 0;
    for (int i = 0; i <= n; i++)
    {
        int j = i;
        arr[j] = (rand() % 100000) + 1;
        while (j-- && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            comp++;
        }
    }
    printf("Number of comparisons: %d\n", comp);
    isSorted(arr, n) ? printf("It is sorted indeed.\n") : printf("It is not sorted.\n");
    return 0;
}
