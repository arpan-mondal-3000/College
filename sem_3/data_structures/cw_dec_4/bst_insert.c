#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *lchild;
    struct bstNode *rchild;
} bstNode;

int num_of_comps = 0;

void insert(bstNode *root, bstNode *element)
{
    if (element->data == root->data)
    {
        num_of_comps++;
        return;
    }
    else if (element->data < root->data && root->lchild == NULL)
    {
        num_of_comps++;
        root->lchild = element;
        return;
    }
    else if (element->data > root->data && root->rchild == NULL)
    {
        num_of_comps++;
        root->rchild = element;
        return;
    }

    if (element->data < root->data)
    {
        num_of_comps++;
        insert(root->lchild, element);
    }
    else if (element->data > root->data)
    {
        num_of_comps++;
        insert(root->rchild, element);
    }
}

void display_bst(bstNode *root)
{
    if (root)
    {
        display_bst(root->lchild);
        printf("%d ", root->data);
        display_bst(root->rchild);
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");

    if (!fp)
    {
        printf("input.txt file not found!\n");
        return 1;
    }
    int n;
    fscanf(fp, "%d", &n);
    bstNode *root = (bstNode *)malloc(sizeof(bstNode));
    fscanf(fp, "%d", &root->data);
    root->lchild = NULL;
    root->rchild = NULL;
    n--;

    for (int i = 0; i < n; i++)
    {
        bstNode *newNode = (bstNode *)malloc(sizeof(bstNode));
        fscanf(fp, "%d", &newNode->data);
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        insert(root, newNode);
    }
    printf("Inserted %d random nodes\nTotal number of comparisions: %d\n", n + 1, num_of_comps);
    fclose(fp);
    return 0;
}