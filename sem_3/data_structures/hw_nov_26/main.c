#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char data;
    struct tnode *left;
    struct tnode *right;
} tnode;

int max_stack_size = 100;
tnode *stack[100];
int top = -1;

void push(tnode *a)
{
    if (top == max_stack_size - 1)
    {
        printf("Stack is full!\n");
        return;
    }
    top++;
    stack[top] = a;
}

tnode *pop()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    tnode *a = stack[top];
    top--;
    return a;
}

tnode *convert_to_tree(char *postfix, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (postfix[i] >= 48 && postfix[i] <= 57)
        {
            tnode *int_node = (tnode *)malloc(sizeof(tnode));
            int_node->data = postfix[i];
            int_node->left = NULL;
            int_node->right = NULL;
            push(int_node);
        }
        else
        {
            tnode *rchild = pop();
            tnode *lchild = pop();
            tnode *opr_node = (tnode *)malloc(sizeof(tnode));
            opr_node->data = postfix[i];
            opr_node->left = lchild;
            opr_node->right = rchild;
            push(opr_node);
        }
    }
    tnode *result = pop();
    return result;
}

void inorder_traversal(tnode *root)
{
    if (!root)
        return;
    inorder_traversal(root->left);
    printf("%c", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(tnode *root)
{
    if (!root)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%c", root->data);
}

void preorder_traversal(tnode *root)
{
    if (!root)
        return;
    printf("%c", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int int_stack[100];
int intTop = -1;
void pushInt(int n)
{
    if (intTop == max_stack_size - 1)
    {
        printf("Stack is full!\n");
        return;
    }
    intTop++;
    int_stack[intTop] = n;
}

int popInt()
{
    if (intTop == -1)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    int n = int_stack[intTop];
    intTop--;
    return n;
}

int evaluate(char *postfix, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (postfix[i] >= 48 && postfix[i] <= 57)
        {
            pushInt(postfix[i] - 48);
        }
        else
        {
            int r = popInt();
            int l = popInt();
            if (postfix[i] == '+')
                pushInt(l + r);
            else if (postfix[i] == '-')
                pushInt(l - r);
            else if (postfix[i] == '*')
                pushInt(l * r);
            else
                pushInt(l / r);
        }
    }
    return popInt();
}

int main()
{
    printf("Enter the lenght of the expression: ");
    int n;
    scanf("%d", &n);
    printf("Enter the postfix expression: ");
    char *postfix = (char *)malloc(n * sizeof(char));
    scanf("%s", postfix);
    tnode *expression_tree = convert_to_tree(postfix, n);
    printf("Inorder traversal: ");
    inorder_traversal(expression_tree);
    printf("\n");
    printf("Postorder traversal: ");
    postorder_traversal(expression_tree);
    printf("\n");
    printf("Preorder traversal: ");
    preorder_traversal(expression_tree);
    printf("\n");

    int ans = evaluate(postfix, n);
    printf("Evaluated answer: %d", ans);

    return 0;
}