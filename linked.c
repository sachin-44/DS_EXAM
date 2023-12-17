#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list element
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void displayList(struct Node* head);
struct Node* insertAtBeginning(struct Node* head, int value);
struct Node* insertAtEnd(struct Node* head, int value);
struct Node* insertAtPosition(struct Node* head, int value, int position);
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteFromPosition(struct Node* head, int position);

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nLinked List Operations:\n");
        printf("a. Display\n");
        printf("b. Insert at Beginning\n");
        printf("c. Insert at End\n");
        printf("d. Insert at a specified Position\n");
        printf("e. Delete from Beginning\n");
        printf("f. Delete from End\n");
        printf("g. Delete from a specified Position\n");
        printf("h. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                displayList(head);
                break;

            case 'b':
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                displayList(head);
                break;

            case 'c':
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                displayList(head);
                break;

            case 'd':
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                displayList(head);
                break;

            case 'e':
                head = deleteFromBeginning(head);
                displayList(head);
                break;

            case 'f':
                head = deleteFromEnd(head);
                displayList(head);
                break;

            case 'g':
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                displayList(head);
                break;

            case 'h':
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 'h');

    // Free memory before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert an element at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error. Unable to insert element.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to insert an element at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error. Unable to insert element.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to insert an element at a specified position in the linked list
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error. Unable to insert element.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Insertion failed.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete an element from the beginning of the linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty. Deletion failed.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted element from the beginning.\n");
    return head;
}

// Function to delete an element from the end of the linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty. Deletion failed.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Deleted element from the end.\n");
    return head;
}

// Function to delete an element from a specified position in the linked list
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("Linked List is empty. Deletion failed.\n");
        return NULL;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted element from position %d.\n", position);
        return head;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Deletion failed.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted element from position %d.\n", position);
    return head;
}
