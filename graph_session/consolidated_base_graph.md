# 📘 Graphs in C — Consolidated Learning Guide (Beginner to Intermediate)

---

## 🎯 Goal

By the end of this guide, you will:

* Understand graph fundamentals
* Represent graphs in C using adjacency list
* Implement DFS and BFS
* Solve shortest path problems (unweighted & intro to weighted)
* Implement the `hasPath` problem

---

# 🔹 1. Graph Basics

## What is a Graph?

A **graph** is a collection of:

* **Vertices (nodes)**
* **Edges (connections)**

Example:

```
A — B
|   |
C — D
```

---

## Types of Graphs

### Undirected Graph

* A — B means both ways

### Directed Graph

* A → B (one direction)

### Weighted Graph

* Edges have cost

```
A --5--> B
```

---

# 🔹 2. Graph Representation in C

## Why Not Dictionary?

C does not support:

```
{1: [2,3]}
```

So we use:

---

## Adjacency List (Best Approach)

### Structure

```c
struct Node {
    int vertex;
    struct Node* next;
};
```

---

## Key Idea

```
adj[0] → 1 → 2 → NULL
adj[1] → 0 → NULL
```

---

# 🔹 3. addEdge() — Core Logic 🔥

```c
void addEdge(struct Node* adj[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}
```

---

## Important Concepts

### 1. Insert at Head

```
newNode->next = adj[src];
adj[src] = newNode;
```

👉 Prevents data loss and is O(1)

---

### 2. Why Two Insertions?

For:

```
addEdge(0,1)
```

We create:

```
0 → 1
1 → 0
```

👉 Because graph is **undirected**

---

# 🔹 4. DFS (Depth First Search)

## Idea

👉 Go deep first, then backtrack

---

## Stack-Based DFS (Core Logic)

```c
push(start);

while (!isEmpty(stack)) {
    current = pop();

    if (!visited[current]) {
        visit(current);

        for (neighbors)
            push(neighbor);
    }
}
```

---

## Key Points

* Uses **stack (LIFO)**
* Good for:

  * Path existence
  * Backtracking

---

# 🔹 5. BFS (Breadth First Search)

## Idea

👉 Traverse level by level

---

## Queue-Based BFS (Core Logic)

```c
enqueue(start);
visited[start] = 1;

while (!queue empty) {
    current = dequeue();

    for (neighbors) {
        if (!visited) {
            enqueue(neighbor);
            visited[neighbor] = 1;
        }
    }
}
```

---

## Key Points

* Uses **queue (FIFO)**
* Guarantees **shortest path (unweighted)**

---

# 🔹 6. Shortest Path

---

## ✅ Unweighted Graph (Using BFS)

### Formula

```
distance[neighbor] = distance[current] + 1;
```

---

### Key Idea

👉 First time visiting a node = shortest path

---

## ✅ Weighted Graph (Intro — Dijkstra)

### Formula

```
dist[v] = min(dist[v], dist[u] + weight)
```

---

### Key Idea

👉 Always choose minimum distance node

---

# 🔹 7. hasPath Problem 🔥

## Problem

Check if path exists between two nodes

---

## DFS Solution

```c
int hasPath(struct Node* adj[], int src, int dest, int visited[]) {

    if (src == dest)
        return 1;

    visited[src] = 1;

    struct Node* temp = adj[src];

    while (temp) {
        if (!visited[temp->vertex]) {
            if (hasPath(adj, temp->vertex, dest, visited))
                return 1;
        }
        temp = temp->next;
    }

    return 0;
}
```

---

## Key Points

* Uses **DFS**
* Stops early if destination found
* Requires `visited[]` to avoid infinite loops

---

# 🔹 8. Common Mistakes

❌ Forgetting `visited[]`
❌ Confusing directed vs undirected
❌ Losing nodes in linked list
❌ Not initializing structures

---

# 🔹 9. Interview Insights 🔥

* BFS → Shortest path (unweighted)
* DFS → Path existence
* Adjacency list → Most efficient
* Always explain logic before coding

---

# 🔹 10. Practice Suggestions

* Dry run DFS and BFS manually
* Modify graph and test outputs
* Try:

  * Print path
  * Count components
  * Detect cycles

---

# 🧠 Final Summary

👉 Graph = Nodes + Connections
👉 Store using **Adjacency List in C**
👉 Traverse using:

* DFS (stack / recursion)
* BFS (queue)

👉 Solve problems using:

* BFS → shortest path
* DFS → path existence

---

# 🚀 Next Level

* Dijkstra (optimized)
* Grid-based BFS
* Real-world problems

---

**Golden Rule:**

> Graphs become easy only with practice + visualization

---

