#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue yapisi
struct Queue {
    int front, rear;
    int items[MAX];
};

// Queue islemleri
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[++(q->front)];
}

// Graph yapisi
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};

// BFS algoritmasi
void BFS(struct Graph *graph, int start, int end) {
    struct Queue queue;
    queue.front = -1;
    queue.rear = -1;

    int visited[MAX] = {0};
    int parent[MAX];

    enqueue(&queue, start);
    visited[start] = 1;
    parent[start] = -1;

    while (queue.front != queue.rear) {
        int current = dequeue(&queue);

        if (current == end) {
            // En kisa yolu yazdir
            printf("Shortest path between %d and %d: ", start, end);

            int node = end;
            while (node != -1) {
                printf("%d ", node);
                node = parent[node];
            }

            return;
        }
		int i;
        for (i = 0; i < graph->vertices; ++i) {
            if (graph->adjMatrix[current][i] && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
                parent[i] = current;
            }
        }
    }

    printf("There is no path between %d and %d\n", start, end);
}

int main() {
    struct Graph graph;
    graph.vertices = 4;

    // Örnek bir graf matrisi
    int adjacencyMatrix[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    
    int yolMatrix [MAX][MAX] = {0};

    // Graf matrisini struct'a kopyala
    int i,j;
    for (i = 0; i < graph.vertices; ++i) {
        for (j = 0; j < graph.vertices; ++j) {
            graph.adjMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }

    int startNode = 0;
    int endNode = 3;

    BFS(&graph, startNode, endNode);

    return 0;
}

