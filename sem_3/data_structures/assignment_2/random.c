#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  int n, low, high;
  printf("n: ");
  scanf("%d", &n);
  printf("Range(low high): ");
  scanf("%d %d", &low, &high);
  srand(time(NULL));
  while (n--)
    printf("%d ", low + (rand() % (high - low + 1)));
  printf("\n");
  return 0;
}
