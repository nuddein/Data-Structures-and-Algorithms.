#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack {
    int* items;
    int top;
    unsigned int capacity;
};

struct Stack* createStack(unsigned int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1)
        printf("\nStack is full");
    else
        stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nStack is empty");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
	int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dfs(struct Graph* graph, int startVertex) {
    struct Stack* stack = createStack(graph->numVertices);

    graph->visited[startVertex] = 1;
    printf(" %d", startVertex);
    push(stack, startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->data;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                printf(" %d", adjVertex);
                push(stack, adjVertex);
            }

            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Depth First Search using a stack starting from vertex 0:\n");
    dfs(graph, 0);

    return 0;
}

