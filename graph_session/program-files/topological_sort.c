#include <stdio.h>
#include <stdlib.h>

#define V 5

struct Node
{
    int value;
    struct Node *next;
};

struct Node *createNodes(int value)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->value = value;
    nn->next = NULL;
    return nn;
}

void addEdge(struct Node *adj[], int src, int dest)
{
    struct Node *newNode = createNodes(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

struct Queue
{
    int items[1000];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue *q, int value)
{
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q)
{
    return q->items[q->front++];
}

int isEmpty(struct Queue *q)
{
    return q->front > q->rear;
}

void topoSort(struct Node *adj[])
{
    int indegree[V] = {0};
    // Calculate the indegree
    for (int i = 0; i < V; i++)
    {
        struct Node *temp = adj[i];
        while (temp != NULL)
        {
            indegree[temp->value]++;
            temp = temp->next;
        }
    }
    // pushing indegree 0 vertice to the queue
    struct Queue q;
    initQueue(&q);
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            enqueue(&q, i);

    while (!isEmpty(&q))
    {
        int current = dequeue(&q);
        printf("%d ", current);
        struct Node *temp = adj[current];
        while (temp != NULL)
        {
            indegree[temp->value]--;
            if (indegree[temp->value] == 0)
                enqueue(&q, temp->value);
            temp = temp->next;
        }
    }
}

int main()
{
    struct Node *adj[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL;
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);

    topoSort(adj);
}