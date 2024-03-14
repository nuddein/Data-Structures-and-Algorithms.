#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

struct Stack {
    int* data;
    int top;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    int i,j;
    for (i = 0; i < vertices; ++i) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (j = 0; j < vertices; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->data[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
}

void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Stack* stack) {
    visited[v] = 1;
	int i;
    for (i = 0; i < graph->numVertices; ++i) {
        if (graph->adjacencyMatrix[v][i] == 1 && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    push(stack, v);
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES];
    struct Stack* stack = createStack(graph->numVertices);
	int i;
    for (i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    for (i = 0; i < graph->numVertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    printf("Topological Sort: ");
    while (stack->top != -1) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}

