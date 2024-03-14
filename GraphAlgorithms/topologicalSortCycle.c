
#include <stdio.h>
#include <stdlib.h>
#define max 100
struct Node {
    int data;
    struct Node* next;
};
struct Stack{
    struct Node* top;
};
struct Graph{
    int numVertices;
    struct Node** adjList;
};
struct Node* createNode (int data){
    struct Node* newNode = (struct Node*)malloc (sizeof (struct Node));
    newNode->data =data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph (int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices*sizeof(struct Node*));
    int i;
    for (i=0;i<vertices;i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}
struct Stack* createStack (){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push (struct Stack* stack, int data){
    struct Node* newNode = createNode (data);
    newNode -> next = stack->top;
    stack->top = newNode;
}
int pop (struct Stack* stack){
    if (stack->top == NULL){
        printf ("stack is empty");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}
void addEdge (struct Graph* graph, int src, int dest){
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

int topologicalSortUtil (int v, struct Graph* graph, struct Stack* stack, int visited[]) {
    visited[v] = 1;
    struct Node* temp = graph->adjList[v];
    while (temp) {
        int adjVertex = temp->data;
        if (visited[adjVertex] == 0) {
            if (!topologicalSortUtil(adjVertex, graph, stack, visited)) {
                // If a cycle is detected, return 0
                return 0;
            }
        } else if (visited[adjVertex] == 1) {
            // If an already visited vertex is encountered again, a cycle is detected
            return 0;
        }
        temp = temp->next;
    }
    visited[v] = 5; // Mark the vertex as processed
    push(stack, v);
    return 1;
}

int topologicalSort(struct Graph* graph) {
    struct Stack* stack = createStack();
    int visited[max];
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < graph->numVertices; i++) {
        if (visited[i] == 0) {
            if (!topologicalSortUtil(i, graph, stack, visited)) {
                // If a cycle is detected, return 0
                return 0;
            }
        }
    }

    printf("Topological sort: \n");
    while (stack->top != NULL) {
        printf("%d ", pop(stack));
    }
    return 1;
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    if (!topologicalSort(graph)) {
        printf("\nTopological sort is not possible due to the presence of a cycle.\n");
    }

    return 0;
}
