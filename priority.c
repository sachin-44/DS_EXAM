#include <stdio.h>

#define MAX_SIZE 10

// Priority Queue structure
struct PriorityQueue {
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;
};

// Function prototypes
void insertElement(struct PriorityQueue* pq, int element, int priority);
void deleteElement(struct PriorityQueue* pq);
void displayPriorityQueue(struct PriorityQueue* pq);

int main() {
    struct PriorityQueue pq;
    pq.size = 0;
    int choice, element, priority;

    do {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (pq.size < MAX_SIZE) {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    printf("Enter the priority of the element: ");
                    scanf("%d", &priority);
                    insertElement(&pq, element, priority);
                    displayPriorityQueue(&pq);
                } else {
                    printf("Priority Queue is full. Cannot insert element.\n");
                }
                break;

            case 2:
                if (pq.size > 0) {
                    deleteElement(&pq);
                    displayPriorityQueue(&pq);
                } else {
                    printf("Priority Queue is empty. Cannot delete element.\n");
                }
                break;

            case 3:
                displayPriorityQueue(&pq);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert an element into the Priority Queue
void insertElement(struct PriorityQueue* pq, int element, int priority) {
    int i;

    // Find the position to insert the new element based on priority
    for (i = pq->size - 1; i >= 0 && priority > pq->priorities[i]; i--) {
        pq->elements[i + 1] = pq->elements[i];
        pq->priorities[i + 1] = pq->priorities[i];
    }

    pq->elements[i + 1] = element;
    pq->priorities[i + 1] = priority;
    pq->size++;
    printf("Element %d with priority %d inserted successfully.\n", element, priority);
}

// Function to delete an element from the Priority Queue
void deleteElement(struct PriorityQueue* pq) {
    int deletedElement = pq->elements[0];
    int deletedPriority = pq->priorities[0];

    // Shift the elements to fill the gap
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }

    pq->size--;
    printf("Deleted element %d with priority %d.\n", deletedElement, deletedPriority);
}

// Function to display the elements of the Priority Queue
void displayPriorityQueue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, %d) ", pq->elements[i], pq->priorities[i]);
    }
    printf("\n");
}
