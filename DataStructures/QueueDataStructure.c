#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

int isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->rear == MAX_SIZE - 1) {
        queue->rear = -1; 
    }
    queue->items[++queue->rear] = value;
    queue->size++;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    int removed = queue->items[queue->front++];
    queue->size--;
    if (queue->front == MAX_SIZE) {
        queue->front = 0; 
    }
    if (queue->size == 0) {
        queue->front = queue->rear = -1;
    }
    return removed;
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    return 0;
}

