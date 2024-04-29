/* */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int x);

struct Graph
{
    int numData;
    int *visited;

    struct node **adjLists;
};

void DFS(struct Graph *graph, int data)
{
    struct node *adjList = graph->adjLists[data];
    struct node *temp = adjList;

    graph->visited[data] = 1;
    printf("Visited %d \n", data);

    while (temp != NULL)
    {
        int connecteddata = temp->data;

        if (graph->visited[connecteddata] == 0)
        {
            DFS(graph, connecteddata);
        }
        temp = temp->next;
    }
}

struct node *createNode(int x)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numData = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{

    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
    int x;
    for (x = 0; x < graph->numData; x++)
    {
        struct node *temp = graph->adjLists[x];
        printf("\n Adjacency list of data %d\n ", x);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    system("cls");
    struct Graph *graph = createGraph(8);
    addEdge(graph, 5, 2);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 3);

    printGraph(graph);
    DFS(graph, 2);
    return 0;
}