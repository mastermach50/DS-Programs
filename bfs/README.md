# [Program-28] BFS
## Aim:-
Write a program to traverse a graph using BFS algorirthm.

## Algorithm:-
1. START
2. Define MAX as 100.
3. Declare an adjacency matrix `int adj[MAX][MAX] = {0}`, a boolen array `bool visited[MAX] = {false}`, a queue `int queue[MAX]` with `front=rear=0` and num to store the total number of nodes.
4. Create a function `add_edge(a,b)` that sets `adj[a][b]=adj[b][a]=1`.
5. Decide a node to be the source node and mark it as visited and enqueue it.
6. While (front < rear) dequeue a node, print it and find it's adjacent nodes. If any of the adjacent nodes are not marked as visited then mark it as visited and enqueue it.
7. STOP
   
## Result:-
A graph was traversed using BFS algorithm.