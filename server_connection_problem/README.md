# Minimum Cost to Connect Servers

## Problem Statement

You are given *n servers*.

Each server can either:
•⁠  ⁠Be *installed individually*, or
•⁠  ⁠Be *connected to another server*

Your goal is to *connect all the servers* such that the *total cost is minimized*.

The total cost includes:
•⁠  ⁠The *cost to install servers*
•⁠  ⁠The *cost to connect servers*

You may choose:
•⁠  ⁠To install servers individually, or
•⁠  ⁠Connect servers in a way that minimizes the overall cost.

---

## Input Format

1.⁠ ⁠An integer *n* — number of servers
2.⁠ ⁠An array of size *n* — installation cost of each server
3.⁠ ⁠A *n × n matrix* — connection cost between every pair of servers

---

## Output Format

Print a *single integer* — the *minimum total cost* required to connect all servers.

---

## Constraints

•⁠  ⁠⁠ 1 ≤ n ≤ 1000 ⁠
•⁠  ⁠⁠ 0 ≤ installationCost[i] ≤ 10^5 ⁠
•⁠  ⁠⁠ 0 ≤ connectionCost[i][j] ≤ 10^5 ⁠
•⁠  ⁠⁠ connectionCost[i][i] = 0 ⁠

---

## Example Input


3
5 4 6
0 1 3
1 0 2
3 2 0


## Example Output
6

## Prims Algorithm 
Growing the network step by step, Always picking the cheapest next connection.

### Understanding problem
- We need install a server
- Or Connect the servers

But what we need to ensure is:
```
Every server becomes reachable at minimum cost 
```

(1) = (Neighbours) (2, 4) -> (3, 2)
(2) = (Neighbours) (1, 4) -> (3, 1)
(3) = (Neighbours) (1, 2) -> (2, 1)

### Algorithm
1. Start with no nodes connected.
2. Pick the cheapest way to connect to the next node.
3. Repeat until all the nodes are connected or visited.

### Graph representation
#### Adjacency List
- TODO: Will do it later once sathya learn this.