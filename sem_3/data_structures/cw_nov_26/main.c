#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    struct node *parent;
} node;

node *createBSTNode(int data)
{
    node *root = (node *)malloc(sizeof(node));
    root->data = data;
    root->parent = NULL;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

int search(node *root, int key)
{
    static int depth = 0;
    if (!root)
        return -1;
    if (root->data == key)
    {
        int temp = depth;
        depth = 0;
        return temp;
    }

    if (root->data < key)
    {
        depth++;
        search(root->rchild, key);
    }
    else
    {
        depth++;
        search(root->lchild, key);
    }
}

void insert(node *root, node *new_node)
{
    if (root->data == new_node->data)
    {
        printf("The node is already present!\n");
        return;
    }
    if (root->data < new_node->data && root->rchild == NULL)
    {
        root->rchild = new_node;
        new_node->parent = root;
        printf("Node with key %d inserted.\n", new_node->data);
        return;
    }
    else if (root->data > new_node->data && root->lchild == NULL)
    {
        root->lchild = new_node;
        new_node->parent = root;
        printf("Node with key %d inserted.\n", new_node->data);
        return;
    }

    if (root->data < new_node->data)
    {
        insert(root->rchild, new_node);
    }
    else
    {
        insert(root->lchild, new_node);
    }
}

void displayBST(node *root)
{
    if (root)
    {
        displayBST(root->lchild);
        printf("%d\n", root->data);
        displayBST(root->rchild);
    }
}

node *tree_min(node *root)
{
    if (root->lchild == NULL)
        return root;
    tree_min(root->lchild);
}

void transplant(node *u, node *v)
{
    if (u->parent == NULL)
        u = v;
    else if (u == u->parent->lchild)
        u->parent->lchild = v;
    else
        u->parent->rchild = v;
    if (v != NULL)
        v->parent = u->parent;
}

void delete(node *root, int key)
{
    if (!root)
    {
        printf("Node not found!\n");
        return;
    }
    if (root->data > key)
    {
        delete (root->lchild, key);
    }
    else if (root->data < key)
    {
        delete (root->rchild, key);
    }
    else
    {
        if (root->lchild == NULL)
        {
            transplant(root, root->rchild);
            return;
        }
        else if (root->rchild == NULL)
        {
            transplant(root, root->lchild);
            return;
        }
        else
        {
            node *y = tree_min(root);
            if (y->parent != root)
            {
                transplant(y, y->rchild);
                y->rchild = root->rchild;
                y->rchild->parent = y;
            }
            transplant(root, y);
            y->lchild = root->lchild;
            y->lchild->parent = y;
        }
    }
}

int main()
{
    int n;
    printf("Enter the key for the root node: ");
    scanf("%d", &n);
    node *root = createBSTNode(n);
    int choice = -1;
    while (choice != 4)
    {
        printf("Enter 0 to insert a new node\n\t1 to search for a node with key\n\t2 to display the whole tree\n\t3 to delete a node with key\n\tand 4 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
        {
            int n;
            printf("Enter key for the new node: ");
            scanf("%d", &n);
            node *new_node = createBSTNode(n);
            insert(root, new_node);
            break;
        }
        case 1:
        {
            int n;
            printf("Enter key to search: ");
            scanf("%d", &n);
            int depth = search(root, n);
            depth == -1 ? printf("Node not found!!!\n\n") : printf("Node is found at depth %d\n\n", depth);
            break;
        }
        case 2:
        {
            displayBST(root);
            break;
        }
        case 3:
        {
            int n;
            printf("Enter key to delete: ");
            scanf("%d", &n);
            delete (root, n);
        }
        }
    }
    return 0;
}