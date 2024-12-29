#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Enter valid number of agruments!\n");
        return 1;
    }
    int n = atoi(argv[1]);
    int l = atoi(argv[2]);
    int h = atoi(argv[3]);
    srand(time(NULL));
    FILE *fp = fopen("input.txt", "w");
    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d\n", (rand() % h) + l);
    fclose(fp);
    printf("Written %d random numbers between %d and %d", n, l, h);
    return 0;
}