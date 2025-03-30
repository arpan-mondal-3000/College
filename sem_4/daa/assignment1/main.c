#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *mark; // 0: undiscovered, 1: discovered, 2: finished
int *d;
int *pred;
// Circular queue implementation
int queue[100];
int front = 0;
int rear = 0;

void enqueue(int n){
    if((rear+1)%100 == front){
        printf("Queue is full!\n");
        return;
    }
    rear = (rear+1)%100;
    queue[rear] = n;
}

int dequeue(){
    if(front == rear){
        printf("Queue is empty!\n");
        return -1;
    }
    front = (front+1)%100;
    return queue[front];
}

int** build_graph(int n, int m){
    srand(time(NULL));

    int total_edges = (n * (n + 1)) / 2;

    if (m > total_edges)
    {
        printf("Invalid number of edges!\n");
        return NULL;
    }

    FILE *fp = fopen("graph.txt", "w");
    int **adj_matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        adj_matrix[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                adj_matrix[i][j] = adj_matrix[j][i];
                fprintf(fp, "%d ", adj_matrix[i][j]);
                continue;
            }
            if (total_edges - (i * n + j) == m)
            {
                adj_matrix[i][j] = 1;
                fprintf(fp, "1 ");
                m--;
                continue;
            }
            int edge = rand() % 2;
            if (m && edge)
            {
                adj_matrix[i][j] = 1;
                fprintf(fp, "1 ");
                m--;
            }
            else
            {
                adj_matrix[i][j] = 0;
                fprintf(fp, "0 ");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return adj_matrix;
}

void free_matrix(int **adj_matrix, int n){
    for (int i = 0; i < n; i++)
        free(adj_matrix[i]);
    free(adj_matrix);
}

void BFSearch(int n, int s, int **adj_matrix){
    for(int i = 0; i < n; i++){
        mark[i] = 0;
        d[i] = __INT_MAX__;
        pred[i] = -1;
    }

    mark[s] = 1;
    d[s] = 0;
    enqueue(s);

    while(front != rear){ // Queue is not empty
        int u = dequeue();
        for(int i = 0; i < n; i++){
            if(adj_matrix[u][i] == 1 && u != i && mark[i] == 0){
                mark[i] = 1;
                d[i] = d[u] + 1;
                pred[i] = u;
                enqueue(i);
            }
        }
        mark[u] = 2;
    }
}

int main()
{
    int m, n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    int **adj_matrix = build_graph(n, m);
    if(adj_matrix){
        printf("Adjacency matrix:\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", adj_matrix[i][j]);
            }
            printf("\n");
        }

        printf("Enter the source vertex(0-%d): ", n-1);
        int s;
        scanf("%d", &s);
        
        // Initiaization of required arrays
        mark = (int *) malloc(n * sizeof(int));
        d = (int *) malloc(n * sizeof(int));
        pred = (int *) malloc(n * sizeof(int));

        BFSearch(n, s, adj_matrix);

        printf("Source vertex: %d\n", s);
        printf("Length of the shortest path from source:\n");
        for(int i = 0; i < n; i++){
            if(i == s) continue;
            printf("%d: %d\n", i, d[i]);
        }

        free_matrix(adj_matrix, n);
    }else{
        printf("Adjacency matrix creation failed!\n");
    }
    
    return 0;
}