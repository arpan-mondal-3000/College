#include <stdio.h>
#include <stdlib.h>

typedef struct hashNode
{
    int data;
    struct hashNode *link;
} hashNode;

void insert_chaining(hashNode *hash_array[], int data)
{
    int i = data % 50000;
    hashNode *newNode = (hashNode *)malloc(sizeof(hashNode));
    newNode->data = data;
    newNode->link = NULL;
    if (hash_array[i])
    {
        hashNode *temp = hash_array[i];
        while (temp->link)
            temp = temp->link;
        temp->link = newNode;
    }
    else
        hash_array[i] = newNode;
    return;
}

int linear_probe_insert(int *arr, int data)
{
    int probes = 0;
    int i = data % 50000;
    while (arr[i % 50000] != -1)
    {
        probes++;
        i++;
    }
    arr[i % 50000] = data;
    return probes;
}

int quadratic_hash_fn(int key, int probe)
{
    int i = ((key % 55000) + 3 * probe * probe + 7 * probe) % 55000;
    return i;
}

int quadratic_probing_insert(int *arr, int data)
{
    int probe = 0;
    int i = quadratic_hash_fn(data, probe);
    while (arr[i] != -1)
    {
        probe++;
        i = quadratic_hash_fn(data, probe);
    }
    arr[i] = data;
    return probe;
}

int double_hash_function(int key, int probe)
{
    return ((key % 48713) + probe * (key % 39287)) % 60000;
}

int double_hashing_insert(int *arr, int data)
{
    int probe = 0;
    int i = double_hash_function(data, probe);
    while (arr[i % 60000] != -1)
    {
        probe++;
        i = double_hash_function(data, probe);
    }
    arr[i % 60000] = data;
    return probe;
}

void display_chaining(hashNode *hash_array[])
{
    for (int i = 0; i < 50000; i++)
    {
        if (hash_array[i])
        {
            hashNode *temp = hash_array[i];
            while (temp)
            {
                printf("%d ", temp->data);
                temp = temp->link;
            }
            printf("\n");
        }
    }
}

int main()
{
    FILE *fp = fopen("data.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    printf("Enter 1 for chaining\n2 for Linear probing\n3 for Quadratic probing\n4 for Double hashing: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        // Chaining
        hashNode *hash_array[n];
        for (int i = 0; i < n; i++)
            hash_array[i] = NULL;
        for (int i = 0; i < n; i++)
        {
            int data;
            fscanf(fp, "%d", &data);
            insert_chaining(hash_array, data);
        }
        // display_chaining(hash_array);
        int min = 50000, max = -1, avg = 0;
        for (int i = 0; i < n; i++)
        {
            hashNode *temp = hash_array[i];
            int x = 0;
            while (temp)
            {
                x++;
                avg++;
                temp = temp->link;
            }
            min = min < x ? min : x;
            max = max > x ? max : x;
        }
        printf("The minimum chain length is %d maximum chain length is %d and average chain lenght is %d\n", min, max, avg / n);
        break;
    }
    case 2:
    {
        // Linear probing
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = -1;
        int avg = 0;
        for (int i = 0; i < n; i++)
        {
            // printf("Hello\n");
            int data;
            fscanf(fp, "%d", &data);
            int probes = linear_probe_insert(arr, data);
            avg += probes;
        }
        printf("Average number of probes in linear probing: %d\n", avg / n);
        break;
    }
    case 3:
    {
        // Quadratic probing
        int *arr = (int *)malloc(55000 * sizeof(int));
        for (int i = 0; i < 55000; i++)
            arr[i] = -1;
        int avg = 0;
        for (int i = 0; i < n; i++)
        {
            int data;
            fscanf(fp, "%d", &data);
            int probes = quadratic_probing_insert(arr, data);
            avg += probes;
        }
        printf("Average number of probes in quadratic probing: %d\n", avg / n);
        break;
    }
    case 4:
    {
        // Double hashing
        int *arr = (int *)malloc(60000 * sizeof(int));
        for (int i = 0; i < 60000; i++)
            arr[i] = -1;
        int avg = 0;
        for (int i = 0; i < n; i++)
        {
            int data;
            fscanf(fp, "%d", &data);
            int probes = double_hashing_insert(arr, data);
            avg += probes;
        }
        printf("Average number of probes in double hashing: %d\n", avg / n);
        break;
    }
    default:
    {
        printf("Enter a valid choice!\n");
        break;
    }
    }

    fclose(fp);
    return 0;
}