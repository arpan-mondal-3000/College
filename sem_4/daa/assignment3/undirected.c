#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int no_of_comp = 0;

typedef struct graphNode
{
    char label;
    struct graphNode *link;
} graphNode;

graphNode **graph;

void addEdge(int u, int v, char *labels)
{
    // Add edge u -> v
    graphNode *newNode = (graphNode *)malloc(sizeof(graphNode));
    newNode->label = labels[v];
    newNode->link = graph[u]->link;
    graph[u]->link = newNode;

    // Add edge v -> u
    newNode = (graphNode *)malloc(sizeof(graphNode));
    newNode->label = labels[u];
    newNode->link = graph[v]->link;
    graph[v]->link = newNode;
}

void DFSvisit(graphNode *u, int *mark)
{
    mark[u->label - 'a'] = 1;
    graphNode *temp = u->link;
    while (temp)
    {
        if (mark[temp->label - 'a'] == 0)
        {
            DFSvisit(temp, mark);
        }
        temp = temp->link;
    }
    mark[u->label - 'a'] = 2;
}

void DFS(graphNode **graph, int n)
{
    int *mark = (int *)malloc(n * sizeof(int)); // 0: undiscovered 1: discovered 2: finished
    for (int i = 0; i < n; i++)
        mark[graph[i]->label - 'a'] = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark[graph[i]->label - 'a'] == 0)
        {

            no_of_comp++;
            printf("Creating a tree from %c\n", graph[i]->label);
            DFSvisit(graph[i], mark);
        }
    }
    free(mark);
}

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
        graph[i] = (graphNode *)malloc(sizeof(graphNode));
        graph[i]->label = labels[i % 26];
        graph[i]->link = NULL;
    }

    // Create edges randomly
    int maxEdges = n * (n - 1) / 2;
    int numEdges = rand() % maxEdges; // Random number of edges

    for (int i = 0; i < numEdges; i++)
    {
        int u = rand() % n;
        int v = rand() % n;

        // Avoid self-loops
        if (u == v)
            continue;

        // Check if edge already exists
        graphNode *temp = graph[u]->link;
        int exists = 0;
        while (temp)
        {
            if (temp->label == labels[v])
            {
                exists = 1;
                break;
            }
            temp = temp->link;
        }
        if (!exists)
        {
            addEdge(u, v, labels);
        }
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c -> ", graph[i]->label);
        graphNode *temp = graph[i]->link;
        while (temp)
        {
            printf("%c ", temp->label);
            temp = temp->link;
        }
        printf("\n");
    }

    DFS(graph, n);
    printf("The number of components is: %d\n", no_of_comp);

    // Deallocate memory
    for (int i = 0; i < n; i++)
    {
        graphNode *temp = graph[i];
        while (temp)
        {
            graphNode *t = temp;
            temp = temp->link;
            free(t);
        }
    }
    free(graph);

    return 0;
}
