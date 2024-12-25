#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

typedef struct queue
{
    node *front;
    node *rear;
} queue;

queue *init_queue()
{
    queue *my_queue = (queue *)malloc(sizeof(queue));
    my_queue->front = NULL;
    my_queue->rear = NULL;
    return my_queue;
}

void enqueue(queue *my_queue, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if (my_queue->front == NULL && my_queue->rear == NULL)
    {
        new_node->link = new_node;
        my_queue->front = new_node;
        my_queue->rear = new_node;
        return;
    }
    my_queue->rear->link = new_node;
    new_node->link = my_queue->front;
    my_queue->rear = new_node;
}

void dequeue(queue *my_queue)
{
    if (my_queue->front == NULL && my_queue->rear == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    else if (my_queue->front == my_queue->rear)
    {
        printf("Deleting element: %d\n", my_queue->front->data);
        node *e = my_queue->front;
        my_queue->front = NULL;
        my_queue->rear = NULL;
        free(e);
        return;
    }
    printf("Deleting element: %d\n", my_queue->front->data);
    node *e = my_queue->front;
    my_queue->rear->link = e->link;
    my_queue->front = e->link;
    free(e);
}

int main()
{
    int choice = -1;
    queue *my_queue = init_queue();
    while (choice != 6)
    {
        printf("Enter 0 to enqueue\n1 to dequeue\n2 to get number of elements\n3 to print front element\n4 to print rear element\n5 to print the whole queue\n6 to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
        {
            printf("Enter element: ");
            int e;
            scanf("%d", &e);
            enqueue(my_queue, e);
            break;
        }
        case 1:
        {
            dequeue(my_queue);
            break;
        }
        case 2:
        {
            int n = 0;
            node *ptr = my_queue->front;
            if (!ptr)
            {
                printf("There are no elements!\n");
                break;
            }
            while (ptr != my_queue->rear)
            {
                n++;
                ptr = ptr->link;
            }
            printf("There are %d elements.\n", n + 1);
            break;
        }
        case 3:
        {
            if (my_queue->front)
                printf("Front element: %d\n", my_queue->front->data);
            else
                printf("Queue is empty!\n");
            break;
        }
        case 4:
        {
            if (my_queue->rear)
                printf("Rear element: %d\n", my_queue->rear->data);
            else
                printf("Queue is empty!\n");
            break;
        }
        case 5:
        {
            node *ptr = my_queue->front;
            if (!ptr)
            {
                printf("There are no elements!\n");
                break;
            }
            while (ptr != my_queue->rear)
            {
                printf("%d ", ptr->data);
                ptr = ptr->link;
            }
            printf("%d\n", ptr->data);
            break;
        }
        case 6:
        {
            printf("Exiting...");
            break;
        }
        default:
        {
            printf("Enter a valid choice!");
            choice = -1;
            break;
        }
        }
    }
    return 0;
}