#include <stdio.h>
#include <stdlib.h>

float num_stack[100];
int top = -1;

void push(float n)
{
   top++;
   if (top >= 100)
   {
      printf("Stack is full!");
      return;
   }
   num_stack[top] = n;
}

float pop()
{
   if (top == -1)
   {
      printf("Stack is empty!");
      return -1;
   }
   return num_stack[top--];
}

float evaluate(char operator, float op1, float op2)
{
   if (operator== '+')
      return op1 + op2;
   else if (operator== '-')
      return op1 - op2;
   else if (operator== '*')
      return op1 * op2;
   else
      return op1 / op2;
}

int main()
{
   // Taking input from user
   int length_of_expression;
   printf("Enter length of expression: ");
   scanf("%d", &length_of_expression);
   char *postfix_expression = (char *)malloc(length_of_expression * sizeof(char));
   // char *infix_expression = (char *)malloc(length_of_expression * sizeof(char));
   printf("Enter the postfix expression: ");
   scanf("\n%[^\n]s", postfix_expression);

   // Evaluating the expression
   // int last_num = 0;
   // int last_op = 0;

   for (int i = 0; i < length_of_expression; i++)
   {
      if (postfix_expression[i] >= 48 && postfix_expression[i] <= 57)
      {
         push(postfix_expression[i] - 48);
         // infix_expression[last_num] = postfix_expression[i];
         // last_op = last_num - 1;
         // last_num += 2;
      }
      else
      {
         float op2 = pop();
         float op1 = pop();
         // infix_expression[last_op] = postfix_expression[i];
         // last_op -= 2;
         push(evaluate(postfix_expression[i], op1, op2));
      }
   }

   // Output
   printf("The evaluated answer is: %.2f\n", pop());
   // printf("The infix expression is: %s", infix_expression);

   // Freeing memory to avoid memory leaks
   free(postfix_expression);
   // free(infix_expression);
   return 0;
}