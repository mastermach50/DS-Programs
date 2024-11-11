#include <stdbool.h>
#include <stdio.h>

#define MAX 100

// Create an adjacency matrix in which the position mat[a][b] and mat[b][a] will be 1 if
// there is an edge between a and b. By default all values in the adjacency matrix are 0.
// Also define the number of nodes [num]
int adj[MAX][MAX] = {0};
int num;

// An array in which nodes can be marked as visited
bool visited[MAX] = {false};

// A queue to store the elements for processing
// Note that [rear] always points to a free space
int queue[MAX];
int front = 0, rear = 0;

// Set values in the adjacencey matrix as 1 to store that there is an edge
void add_edge(int a, int b) {
    adj[a][b] = 1;
    adj[b][a] = 1;
}

void bfs(int src_node) {
    // Mark the node as visited and insert it into the queue
    visited[src_node] = true;
    queue[rear++] = src_node;

    // Loop until the queue is empty
    // Note that [rear] is pointing to an empty position
    while (front < rear) {
        // Dequeue a node and print it
        int node = queue[front++];
        printf("%d ", node);

        // Get all the adjacent nodes of the dequeued node, if the adjacent node
        // is not in [visited] then instert it into the queue and mark it as visited
        for (int i = 0; i < num; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

void main() {
    // Add a set of edges
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(3, 5);
    add_edge(4, 5);
    add_edge(4, 6);
    num = 7;

    // Set a starting node and call the bfs function with it
    int start = 1;
    printf("The BFS of the graph starting from %d is:\n", start);
    bfs(start);
}
