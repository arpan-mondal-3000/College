#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    int coeff;
    int expo;
    struct term *link;
} term;

term *availList = NULL;

term *getTerm()
{
    if (availList)
    {
        printf("Getting term from avail list.\n");
        term *availTerm = availList;
        availList = availList->link;
        return availTerm;
    }
    term *newNode = (term *)malloc(sizeof(term));
    return newNode;
}

void returnTerm(term *termNode)
{
    if (availList)
    {
        termNode->link = availList;
        availList = termNode;
        return;
    }
    termNode->link = NULL;
    availList = termNode;
}

typedef struct polynomial
{
    term *head;
    struct polynomial *link;
} polynomial;

polynomial *polyList = NULL;

term *createPolynomial()
{
    printf("Enter number of terms of polynomial: ");
    int deg;
    scanf("%d", &deg);
    int i = 1;
    int exp, coef;
    printf("Enter exponent for term %d: ", i);
    scanf("%d", &exp);
    printf("Enter coefficient for term %d: ", i);
    scanf("%d", &coef);
    i++;
    deg--;
    term *newPoly = getTerm();
    newPoly->expo = exp;
    newPoly->coeff = coef;
    newPoly->link = NULL;

    term *temp = newPoly;
    while (deg)
    {
        printf("Enter exponent for term %d: ", i);
        scanf("%d", &exp);
        printf("Enter coefficient for term %d: ", i);
        scanf("%d", &coef);
        i++;
        term *newTerm = getTerm();
        newTerm->expo = exp;
        newTerm->coeff = coef;
        newTerm->link = NULL;
        temp->link = newTerm;
        temp = newTerm;
        deg--;
    }

    polynomial *poly = (polynomial *)malloc(sizeof(polynomial));
    poly->head = newPoly;
    poly->link = NULL;
    if (!polyList)
        polyList = poly;
    else
    {
        polynomial *tempo = polyList;
        while (tempo->link)
            tempo = tempo->link;
        tempo->link = poly;
    }
    return newPoly;
}

void displayAPolynomial(term *head)
{
    if (!head)
    {
        printf("This is a NULL polynomial!\n");
        return;
    }
    term *temp = head;
    printf("Polynomial: ");
    while (temp)
    {
        temp->coeff < 0 ? printf("%dx^%d", temp->coeff, temp->expo) : printf("+%dx^%d", temp->coeff, temp->expo);
        temp = temp->link;
    }
    printf("\n");
}

void displayAllPolynomials()
{
    if (!polyList)
    {
        printf("There are no polynomials in the list!\n");
        return;
    }
    polynomial *tempo = polyList;
    int i = 0;
    while (tempo)
    {
        term *temp = tempo->head;
        printf("Polynomial %d: ", i);
        while (temp)
        {
            temp->coeff < 0 ? printf("%dx^%d", temp->coeff, temp->expo) : printf("+%dx^%d", temp->coeff, temp->expo);
            temp = temp->link;
        }
        tempo = tempo->link;
        printf("\n");
        i++;
    }
}

polynomial *findPolynomial(int n) // returns the previous polynomial
{
    if (!polyList)
    {
        printf("There are no polynomials in the list!\n");
        return NULL;
    }
    int i = 0;
    polynomial *temp = polyList;
    polynomial *temp_prev = temp;
    while (temp && i != n)
    {
        temp_prev = temp;
        temp = temp->link;
        i++;
    }
    if (i == n)
        return temp_prev;
    else
    {
        printf("Polynomial %d not found!\n", n);
        return NULL;
    }
}

void erasePolynomial(int n)
{
    polynomial *temp_prev = findPolynomial(n);
    polynomial *temp;
    if (temp_prev && n == 0)
        temp = temp_prev;
    else
        temp = temp_prev->link;

    if (temp_prev)
    {
        term *t = temp->head;
        if (n == 0)
            polyList = temp->link;
        else
            temp_prev->link = temp->link;
        free(temp);
        printf("Erasing ");
        displayAPolynomial(t);
        int j = 0;
        while (t)
        {
            term *nxt = t->link;
            returnTerm(t);
            t = nxt;
            j++;
        }
        return;
    }
}

void addSubPolynomials(int m, int n, int operation)
{
    polynomial *op1 = findPolynomial(m);
    polynomial *op2 = findPolynomial(n);
    if (!op1 || !op2)
    {
        printf("Enter valid operands!\n");
        return;
    }
    if (m)
        op1 = op1->link;
    if (n)
        op2 = op2->link;

    term *result = NULL;
    term *temp;
    term *temp1 = op1->head;
    term *temp2 = op2->head;

    while (temp1 && temp2)
    {
        if (temp1->expo > temp2->expo)
        {
            if (!result)
            {
                // result = temp1;
                result = getTerm();
                result->coeff = temp1->coeff;
                result->expo = temp1->expo;
                result->link = NULL;
                temp = result;
            }
            else
            {
                // temp->link = temp1;
                // temp = temp->link;
                term *newTerm = getTerm();
                newTerm->coeff = temp1->coeff;
                newTerm->expo = temp1->expo;
                newTerm->link = NULL;
                temp->link = newTerm;
                temp = temp->link;
            }
            temp1 = temp1->link;
        }
        else if (temp1->expo < temp2->expo)
        {
            if (!result)
            {
                // result = temp2;
                result = getTerm();
                if (operation == 0)
                    result->coeff = temp2->coeff;
                else
                    result->coeff = -temp2->coeff;
                result->expo = temp2->expo;
                result->link = NULL;
                temp = result;
            }
            else
            {
                // temp->link = temp2;
                // temp = temp->link;
                term *newTerm = getTerm();
                newTerm->coeff = temp2->coeff;
                newTerm->expo = temp2->expo;
                newTerm->link = NULL;
                temp->link = newTerm;
                temp = temp->link;
            }
            temp2 = temp2->link;
        }
        else
        {
            // if (operation == 0 && temp1->coeff + temp2->coeff == 0)
            //     continue;
            // if (operation == 1 && temp1->coeff - temp2->coeff == 0)
            //     continue;
            if (!result)
            {
                result = getTerm();
                if (operation == 0)
                    result->coeff = temp1->coeff + temp2->coeff;
                else
                    result->coeff = temp1->coeff - temp2->coeff;
                result->expo = temp1->expo;
                result->link = NULL;
                temp = result;
            }
            else
            {
                term *newTerm = getTerm();
                if (operation == 0)
                    newTerm->coeff = temp1->coeff + temp2->coeff;
                else
                    newTerm->coeff = temp1->coeff - temp2->coeff;
                newTerm->expo = temp1->expo;
                newTerm->link = NULL;
                temp->link = newTerm;
                temp = temp->link;
            }
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
    }

    if (temp1)
    {
        temp->link = temp1;
    }
    else if (temp2)
    {
        temp->link = temp2;
        term *temp22 = temp2;
        if (operation == 1)
        {
            while (temp22)
            {
                temp22->coeff = -temp22->coeff;
                temp22 = temp22->link;
            }
        }
    }

    printf("Ans ");
    displayAPolynomial(result);

    polynomial *poly = (polynomial *)malloc(sizeof(polynomial));
    poly->head = result;
    poly->link = NULL;

    polynomial *tempo = polyList;
    while (tempo->link)
        tempo = tempo->link;
    tempo->link = poly;
}

int main()
{
    int choice = -1;
    while (choice != 6)
    {
        printf("Enter 0 to create a polynomial\n1 to add two polynomials\n2 to subtract one polynomial from another\n3 to multiply two polynomials\n4 to display polynomials\n5 to erase a polynomial\n6 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0: // Create a polynomial
        {
            term *newPoly = createPolynomial();
            break;
        }
        case 1: // Addition
        {
            int m, n;
            printf("Enter polynomial numbers to add(from display chart): ");
            scanf("%d %d", &m, &n);
            addSubPolynomials(m, n, 0);
            break;
        }
        case 2: // Subtraction
        {
            int m, n;
            printf("Enter polynomial numbers to subtract(from display chart): ");
            scanf("%d %d", &m, &n);
            addSubPolynomials(m, n, 1);
            break;
        }
        case 3: // Multiplication
        {
            break;
        }
        case 4: // Display all polynomials
        {
            displayAllPolynomials();
            break;
        }
        case 5: // Erasing a polynomial
        {
            int n;
            printf("Enter the polynomial to erase: ");
            scanf("%d", &n);
            erasePolynomial(n);
            break;
        }
        case 6: // Exit
        {
            printf("Exiting...\n");
            break;
        }
        default:
        {
            printf("Enter a valid choice: ");
            choice = -1;
            break;
        }
        }
    }
    return 0;
}