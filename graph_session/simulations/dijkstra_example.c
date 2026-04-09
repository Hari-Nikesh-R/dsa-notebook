/* Same graph and logic as simulations/dijkstra.html — compile: gcc -o dijkstra dijkstra_example.c */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 100
#define INF INT_MAX

struct WNode {
    int vertex;
    int weight;
    struct WNode* next;
};

struct WNode* createWNode(int v, int w) {
    struct WNode* n = (struct WNode*)malloc(sizeof(struct WNode));
    n->vertex = v;
    n->weight = w;
    n->next = NULL;
    return n;
}

void addWEdge(struct WNode* adj[], int u, int v, int w) {
    struct WNode* a = createWNode(v, w);
    a->next = adj[u];
    adj[u] = a;
    struct WNode* b = createWNode(u, w);
    b->next = adj[v];
    adj[v] = b;
}

void dijkstra(struct WNode* adj[], int V, int src, int dist[], int parent[]) {
    int settled[MAXV];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
        settled[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        int best = INF;
        for (int i = 0; i < V; i++) {
            if (!settled[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }
        if (u < 0 || best == INF)
            break;

        settled[u] = 1;

        for (struct WNode* t = adj[u]; t != NULL; t = t->next) {
            int v = t->vertex;
            int w = t->weight;
            if (settled[v])
                continue;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
}

void printPath(int parent[], int j) {
    if (j < 0)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

int main(void) {
    int V = 5;
    struct WNode* adj[MAXV] = { NULL };

    addWEdge(adj, 0, 1, 4);
    addWEdge(adj, 0, 2, 2);
    addWEdge(adj, 1, 3, 5);
    addWEdge(adj, 1, 4, 10);
    addWEdge(adj, 2, 3, 3);
    addWEdge(adj, 2, 4, 1);
    addWEdge(adj, 3, 4, 2);

    int dist[MAXV];
    int parent[MAXV];
    int src = 0;

    dijkstra(adj, V, src, dist, parent);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d: unreachable\n", i);
        else {
            printf("%d: distance %d, path: ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
    return 0;
}
