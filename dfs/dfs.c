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

int stack[MAX];
int top = 0;

// Set values in the adjacencey matrix as 1 to store that there is an edge
void add_edge(int a, int b) {
    adj[a][b] = 1;
    adj[b][a] = 1;
}

void dfs(int src_node) {
    stack[top++] = src_node;

    while (top >= 0) {
        // Dequeue a node and print it
        int node = stack[--top];
        if (!visited[node]) {
            visited[node] = true;
            printf("%d ", node);
        }

        for (int i = 0; i < num; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                stack[top++] = i;
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

    // Set a starting node and call the dfs function with it
    int start = 1;
    printf("The BFS of the graph starting from %d is:\n", start);
    dfs(start);
}
