#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number_of_comparisions = 0;

void merge(int *arr, int low, int mid, int high)
{
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));
    int left = low;
    int right = mid + 1;
    int i = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[i] = arr[left];
            left++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
        }
        i++;
        number_of_comparisions++;
    }
    while (left <= mid)
    {
        temp[i] = arr[left];
        left++;
        i++;
    }
    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    free(temp);
}

void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
    // Array before sorting
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    mergeSort(arr, 0, n - 1);
    // Array after sorting
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n%d\n", number_of_comparisions);
    return 0;
}
