#include <stdio.h>
#include <stdlib.h>

// void ways(int nums, int target, int *number_of_ways)
// {
//     if (nums == 0)
//         return;
//     if (nums <= 9 && nums == target)
//     {
//         (*number_of_ways)++;
//         return;
//     }

//     int last_digit = nums % 10;
//     nums = nums / 10;
//     ways(nums, target - last_digit, number_of_ways);
//     ways(nums, target + last_digit, number_of_ways);
//     // if (target % last_digit == 0)
//     //     ways(nums, target / last_digit, number_of_ways);
// }

int MAX_SIZE = 100;
int top = -1;
int stack[100];

void push(int n)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full!\n");
        return;
    }
    top++;
    stack[top] = n;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top--];
}

void generate_combs(char **combs, char *partial, int curr, int height, const char op)
{
    if (height == 0)
    {
        combs[curr] = partial;
        curr++;
        return;
    }
    partial[height - 1] = op;
    generate_combs(combs, partial, curr, height - 1, "+");
    generate_combs(combs, partial, curr, height - 1, "-");
    generate_combs(combs, partial, curr, height - 1, "*");
}

int ways(int nums, int target)
{
    int num_of_digits = 0;
    int temp = nums;
    for (; temp > 0; temp /= 10, num_of_digits++)
        ;
    int *digits = (int *)malloc(sizeof(int) * num_of_digits);
    temp = nums;
    for (int i = num_of_digits - 1; i >= 0; i--)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }

    char *operators = (char *)malloc(sizeof(char) * (num_of_digits - 1));
}

int main()
{
    FILE *fp = fopen("tests.txt", "r");
    int test_cases;
    fscanf(fp, "%d", &test_cases);
    while (test_cases)
    {
        int nums, target;
        fscanf(fp, "%d %d", &nums, &target);
        int number_of_ways = ways(nums, target);
        printf("%d\n", number_of_ways);
        test_cases--;
    }

    fclose(fp);
    return 0;
}