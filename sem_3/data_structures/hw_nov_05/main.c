#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node
{
    char data;
    struct stack_node *nxt;
    struct stack_node *prev;
} stack_node;

typedef struct stack
{
    stack_node *top;
} stack;

stack *init_stack()
{
    stack *my_stack = (stack *)malloc(sizeof(stack));
    my_stack->top = NULL;
    return my_stack;
}

void push(stack *my_stack, char data)
{
    stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
    new_node->data = data;
    new_node->nxt = NULL;
    new_node->prev = my_stack->top;
    if (my_stack->top)
        my_stack->top->nxt = new_node;
    my_stack->top = new_node;
}

char pop(stack *my_stack)
{
    if (my_stack->top == NULL)
        return '\0';
    stack_node *top = my_stack->top;
    if (top->prev)
        top->prev->nxt = NULL;
    my_stack->top = top->prev;
    char data = top->data;
    free(top);
    return data;
}

int main()
{
    printf("Enter the lenght of expression: ");
    int n;
    scanf("%d", &n);
    char *infix = (char *)malloc(n * sizeof(char));
    char *postfix = (char *)malloc(n * sizeof(char));
    printf("Enter the expression: ");
    scanf("%s", infix);
    stack *my_stack = init_stack();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (infix[i] >= 97 && infix[i] <= 122)
        {
            postfix[j] = infix[i];
            j++;
        }
        else
        {
            if (my_stack->top == NULL)
                push(my_stack, infix[i]);
            else
            {
                if (infix[i] == '+' || infix[i] == '-')
                {
                    while (my_stack->top)
                    {
                        postfix[j] = pop(my_stack);
                        j++;
                    }
                    push(my_stack, infix[i]);
                }
                else if (infix[i] == '*')
                {
                    while (my_stack->top && my_stack->top->data != '+' && my_stack->top->data != '-')
                    {
                        postfix[j] = pop(my_stack);
                        j++;
                    }
                    push(my_stack, infix[i]);
                }
                else
                    push(my_stack, infix[i]);
            }
        }
    }
    while (j <= n)
    {
        postfix[j] = pop(my_stack);
        j++;
    }
    printf("%s\n", infix);
    printf("%s\n", postfix);
    return 0;
}