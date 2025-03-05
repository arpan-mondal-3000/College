// Write a program that prints itself completely
#include <stdio.h>
int main()
{
    FILE *fp = fopen("main.c", "r");
    char buff[100];

    while (fgets(buff, 100, fp))
        printf("%s", buff);

    fclose(fp);
    return 0;
}
