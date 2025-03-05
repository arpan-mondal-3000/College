#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void exitProgram();

int main()
{
    int choice; // To store user choice

    while (1)
    { // Infinite loop for menu
        // Display menu
        printf("\n========= MENU =========\n");
        printf("1. Add Two Numbers\n");
        printf("2. Subtract Two Numbers\n");
        printf("3. Multiply Two Numbers\n");
        printf("4. Divide Two Numbers\n");
        printf("5. Exit\n");
        printf("========================\n");

        // Input user choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            exitProgram();
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add two numbers
void add()
{
    int a, b;
    printf("Enter two numbers to add: ");
    scanf("%d %d", &a, &b);
    printf("The sum is: %d\n", a + b);
}

// Function to subtract two numbers
void subtract()
{
    int a, b;
    printf("Enter two numbers to subtract: ");
    scanf("%d %d", &a, &b);
    printf("The difference is: %d\n", a - b);
}

// Function to multiply two numbers
void multiply()
{
    int a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &a, &b);
    printf("The product is: %d\n", a * b);
}

// Function to divide two numbers
void divide()
{
    float a, b;
    printf("Enter two numbers to divide: ");
    scanf("%f %f", &a, &b);
    if (b == 0)
    {
        printf("Error! Division by zero is not allowed.\n");
    }
    else
    {
        printf("The result of division is: %.2f\n", a / b);
    }
}

// Function to exit the program
void exitProgram()
{
    printf("Exiting the program. Goodbye!\n");
    exit(0);
}