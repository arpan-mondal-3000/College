#include <stdio.h>
#include <stdlib.h>

int fibo(int n, int *arr)
{
  if (n == 0)
  {
    arr[n]++;
    return 0;
  }
  if (n == 1)
  {
    arr[n]++;
    return 1;
  }
  arr[n]++;
  return fibo(n - 1, arr) + fibo(n - 2, arr);
}

int main()
{
  int n;
  printf("n: ");
  scanf("%d", &n);
  int c;
  printf("Press 0 for iteration and 1 for recursion: ");
  scanf("%d", &c);
  switch (c)
  {
  case 0:
  {
    int a = 0, b = 1, c = 0;
    int m = n;
    while (m--)
    {
      a = b;
      b = c;
      c = a + b;
    }
    printf("Fibonnaci of %d using iteration: %d\n", n, c);
    break;
  }
  case 1:
  {
    int *arr = (int *)calloc(n + 1, sizeof(int));
    printf("Fibonnaci of %d using recursion: %d\n", n, fibo(n, arr));
    int total = 0;
    for (int i = 0; i < n + 1; i++)
    {
      total += arr[i];
      printf("Number of times fib(%d) was called: %d\n", i, arr[i]);
    }
    printf("Total number of recursive calls: %d\n", total);
    free(arr);
    break;
  }
  default:
    printf("Not a valid input!\n");
    break;
  }
  return 0;
}
