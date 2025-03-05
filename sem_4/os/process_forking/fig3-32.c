/**
 * Figure 3.32
 */

#include <stdio.h>
#include <unistd.h>

void main()
{
    int i;

    for (i = 0; i < 3; i++)
    {
        fork();

        // This printf statement is for debugging purposes
        // getppid(): gets the parent process-id
        // getpid(): get child process-id

        printf("[%d] [%d] i=%d\n", getppid(), getpid(), i);
    }

    printf("[%d] [%d] hi\n", getppid(), getpid());
}