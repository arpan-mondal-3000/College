#include <stdio.h>

int main()
{
    FILE *fp = fopen("tests.txt", "r");
    int t;
    fscanf(fp, "%d", &t);
    while (t)
    {
        int m, n;
        fscanf(fp, "%d %d", &m, &n);
        printf("%d\n", (m * n) % 2 == 0 ? (m * n) / 2 : (m * n / 2) + 1);
        t--;
    }
    fclose(fp);
    return 0;
}