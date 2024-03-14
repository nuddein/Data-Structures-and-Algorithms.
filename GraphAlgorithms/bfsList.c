#include <stdio.h>
#include <stdlib.h>

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue a vertex to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue a vertex from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Structure to represent a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent an undirected graph
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
	int i;
    for (i = 0; i < numVertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Add edge from dest to src since the graph is undirected
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    struct Queue* queue = createQueue(graph->numVertices);

    // Mark all vertices as not visited
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int i;
    for (i = 0; i < graph->numVertices; ++i)
        visited[i] = 0;

    // Enqueue the start vertex and mark it as visited
    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                enqueue(queue, adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }

    // Free allocated memory
    free(queue->array);
    free(queue);
    free(visited);
}

// Driver program to test the BFS function
int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    // Perform BFS starting from vertex 0
    printf("BFS traversal starting from vertex 0: ");
    BFS(graph, 0);

    // Free allocated memory
    free(graph->adjacencyList);
    free(graph);

    return 0;
}

