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

int fibo(int n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return fibo(n - 1) + fibo(n - 2);
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
    printf("Fibonnaci of %d using recurtion: %d\n", arr[i], fibo(arr[i]));
  }
  return 0;
}
