#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define n 1024

double A[n][n];
double B[n][n];
double C[n][n];

float tdiff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec);
}

int main(int argc, const char *argv[])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                A[i][j] = (double)rand() / (double)RAND_MAX;
                B[i][j] = (double)rand() / (double)RAND_MAX;
                C[i][j] = 0;
            }
        }
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    gettimeofday(&end, NULL);

    printf("%0.6f\n", tdiff(&start, &end));

    return 0;
}