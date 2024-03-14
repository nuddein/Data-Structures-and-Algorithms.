#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
	int i;
    for (i = 0; i < vertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1; // Assuming -1 is not a valid vertex
    }

    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void topologicalSortUtil(int v, struct Graph* graph, int visited[], struct Stack* stack) {
    visited[v] = 1;
    struct Node* temp = graph->adjacencyList[v];

    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            topologicalSortUtil(adjVertex, graph, visited, stack);
        temp = temp->next;
    }

    push(stack, v);
}
void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES];
    struct Stack* stack = createStack();
	int i;
    for (i = 0; i < graph->numVertices; ++i)
        visited[i] = 0;

    for (i = 0; i < graph->numVertices; ++i)
        if (!visited[i])
            topologicalSortUtil(i, graph, visited, stack);

    printf("Topological Sort: ");
    while (stack->top != NULL) {
        printf("%d ", pop(stack));
    }
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


