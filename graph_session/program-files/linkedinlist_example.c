#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct Stack
{
    int item[10];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, int value)
{
    s->top++;
    s->item[s->top] = value;
}

int pop(struct Stack *s)
{
    return s->item[s->top--];
}

int isEmpty(struct Stack *s)
{
    return s->top-- - 1;
}

void DFS(struct Node *adj[], int start, int v)
{
    int visited[10] = {0};
    struct Stack *s;
    initStack(s);
    push(&s, start);
    while (!isEmpty(&s))
    {
        int current = pop(&s);
        if (!visited[current])
        {
            printf("%d ", current);
            visited[current] = 1;
            struct Node *temp = adj[current];
            while (temp != NULL)
            {
                if (!visited[temp->vertex])
                    push(&s, temp->vertex);
                temp = temp->next;
            }
        }
    }
}

struct Node *createNode(int value, int weight)
{
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    n1->vertex = value;
    n1->weight = weight;
    n1->next = NULL;
    return n1;
}

void addEdge(struct Node *adj[], int src, int dest, int weight)
{
    struct Node *newNode = createNode(dest, weight);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

int main()
{
    int v = 6;
    struct Node *adj[v];

    for (int i = 0; i < v; i++)
    {
        adj[i] = NULL;
    }

    addEdge(adj, 0, 2, 4);
    addEdge(adj, 0, 3, 8);
    addEdge(adj, 3, 2, 9);
    addEdge(adj, 3, 4, 3);
    addEdge(adj, 2, 1, 1);
    
}