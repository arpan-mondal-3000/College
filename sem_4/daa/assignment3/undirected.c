#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct graphNode
{
    char label;
    struct graphNode *link;
} graphNode;

graphNode **graph;

int main()
{
    srand(time(NULL));
    int n; // number of vertices
    printf("Enter number of vertices for the undirected graph: ");
    scanf("%d", &n);
    char *labels = "abcdefghijklmnopqrstuvwxyz";
    graph = (graphNode **)malloc(n * sizeof(graphNode *));
    for (int i = 0; i < n; i++)
    {
        graphNode *vertex = (graphNode *)malloc(sizeof(graphNode));
        vertex->label = labels[i % 26];
        vertex->link = NULL;
        graph[i] = vertex;
    }

    // Randomly generating edges
    for (int i = 0; i < n; i++)
    {
        graphNode *temp = graph[i];
        int l = rand() % n;
        for (int j = 0; j <= l; j++)
        {
            graphNode *newNode = (graphNode *)malloc(sizeof(graphNode));
            newNode->label = graph[rand() % n]->label;
        }
    }

    // deallocating memory for the graph
    for (int i = 0; i < n; i++)
    {
        graphNode *temp = graph[i];
        while (temp)
        {
            graphNode *t = temp;
            temp = temp->link;
            free(t);
        }
        free(temp);
    }
    free(graph);
    return 0;
}