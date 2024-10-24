#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int m, n;
  printf("Enter length of first number: ");
  scanf("%d", &m);
  char *fnum = (char *)malloc(m * sizeof(char));
  printf("Enter first number: ");
  scanf("\n%[^\n]s", fnum);
  printf("Enter length of second number: ");
  scanf("%d", &n);
  char *snum = (char *)malloc(n * sizeof(char));
  printf("Enter second number: ");
  scanf("\n%[^\n]s", snum);

  char *ans = (char *)malloc((m + n) * sizeof(char));
  memset(ans, '0', sizeof(char) * (m + n));
  for (int i = m - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      int intd = (fnum[i] - '0') * (snum[j] - '0');
      if (ans[i + j + 1] + intd % 10 > '9')
      {
        ans[i + j + 1] += (intd % 10 - 10);
        ans[i + j] += 1;
      }
      else
        ans[i + j + 1] += intd % 10;

      intd /= 10;

      if (ans[i + j] + intd % 10 > '9')
      {
        ans[i + j] += (intd % 10 - 10);
        ans[i + j - 1] += 1;
      }
      else
        ans[i + j] += intd % 10;
    }
  }
  for (int i = 0; i < m + n; i++)
    printf("%c", ans[i]);
  printf("\n");
  return 0;
}
