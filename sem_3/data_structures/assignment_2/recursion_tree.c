#include <stdio.h>

int print_fib_rec_tree(int n, int s)
{
  int sp = s;
  if (n == 0)
  {
    while (sp--)
      printf("----");
    printf("|-> fib(0)\n");
    return 0;
  }
  if (n == 1)
  {
    while (sp--)
      printf("----");
    printf("|-> fib(1)\n");
    return 1;
  }
  while (sp--)
    printf("----");
  printf("|-> fib(%d)\n", n);
  s += 1;
  return print_fib_rec_tree(n - 1, s) + print_fib_rec_tree(n - 2, s);
}

int main()
{
  int n;
  printf("n: ");
  scanf("%d", &n);
  int fib = print_fib_rec_tree(n, 0);
  return 0;
}
