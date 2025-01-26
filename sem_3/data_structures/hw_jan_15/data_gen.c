#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *fp = fopen("data.txt", "w");
    fprintf(fp, "50000\n");
    for (int i = 0; i < 50000; i++)
    {
        fprintf(fp, "%d\n", rand() % 60000);
    }
    fclose(fp);
    return 0;
}