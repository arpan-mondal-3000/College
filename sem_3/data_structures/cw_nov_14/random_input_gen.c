#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Not a valid number of argument!");
        return 1;
    }
    int input_size = atoi(argv[1]);
    int lower_bound = atoi(argv[2]);
    int upper_bound = atoi(argv[3]);
    srand(time(NULL));
    FILE *fp = fopen("input.txt", "w");
    fprintf(fp, "%d\n", input_size);
    for (int i = 0; i < input_size; i++)
        fprintf(fp, "%d\n", (rand() % upper_bound) + lower_bound);
    printf("Written %d random inputs between %d and %d in input.txt", input_size, lower_bound, upper_bound);
    fclose(fp);
    return 0;
}