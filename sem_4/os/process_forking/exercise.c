#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Process forking demo\n");
    pid_t pid = fork();
    if (pid == 0)
    {
        // child
        execlp("ls", "-al", NULL);
        perror("execlp failed!\n");
    }
    else if (pid > 0)
    {
        // parent
        int status;
        waitpid(pid, &status, 0);
        printf("Parent waited for the child: %d\n", pid);
    }
    else
    {
        printf("Fork failed!\n");
    }
    return 0;
}