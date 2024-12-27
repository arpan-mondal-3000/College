#include <stdio.h>
#include <stdlib.h>

int num_of_comps = 0;

int partition(int *arr, int l, int h)
{
    int left = l;
    int right = h - 1;
    int p = h;
    while (left <= right)
    {
        num_of_comps++;
        if (arr[p] < arr[left])
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            right--;
        }
        else if (arr[p] >= arr[left])
            left++;
    }
    int temp = arr[left];
    arr[left] = arr[p];
    arr[p] = temp;
    return left;
}

void quickSort(int *arr, int l, int h)
{
    if (l >= h)
        return;
    int p = partition(arr, l, h);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, h);
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);
    // printf("Before sorting: ");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", arr[i]);
    // printf("\n");

    quickSort(arr, 0, n - 1);

    // printf("After sorting: ");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", arr[i]);
    printf("Number of comparisons: %d\n", num_of_comps);
    fclose(fp);
    return 0;
}