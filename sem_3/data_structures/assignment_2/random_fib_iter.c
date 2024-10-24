#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *rand_num(int n, int low, int high)
{
  int *arr = (int *)malloc(n * sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    arr[i] = low + (rand() % (high - low + 1));
  }
  return arr;
}

int main()
{
  int n;
  printf("n: ");
  scanf("%d", &n);
  int low, high;
  printf("Range(low high): ");
  scanf("%d %d", &low, &high);
  int *arr = (int *)malloc(n * sizeof(int));
  arr = rand_num(n, low, high);
  for (int i = 0; i < n; i++)
  {
    int a = 0, b = 1, c = 0;
    int m = arr[i];
    while (m--)
    {
      a = b;
      b = c;
      c = a + b;
    }
    printf("Fibonnaci of %d using iteration: %d\n", arr[i], c);
  }
  return 0;
}
