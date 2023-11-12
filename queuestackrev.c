#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Structure for a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

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
int isEmptyQueue(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmptyQueue(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to reverse the elements in a queue using a stack
void reverseQueue(struct Queue* queue) {
    struct Stack* stack = createStack(MAX_SIZE);

    // Dequeue all elements from the queue and push them onto the stack
    while (!isEmptyQueue(queue)) {
        push(stack, dequeue(queue));
    }

    // Pop all elements from the stack and enqueue them back into the queue
    while (!isEmpty(stack)) {
        enqueue(queue, pop(stack));
    }
}

// Function to print the elements of a queue
void printQueue(struct Queue* queue) {
    printf("Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);

    // Enqueue elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the original queue
    printf("Original ");
    printQueue(queue);

    // Reverse the queue
    reverseQueue(queue);

    // Print the reversed queue
    printf("Reversed ");
    printQueue(queue);

    return 0;
}

