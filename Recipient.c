#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each recipient
struct Recipient {
    int id;
    char name[50];
    float balance;
    struct Recipient* next;
};

// Function to display all recipient details
void displayAllRecipients(struct Recipient* head) {
    struct Recipient* current = head;

    if (current == NULL) {
        printf("No recipients in the list.\n");
        return;
    }

    printf("ID\tName\tBalance\n");

    while (current != NULL) {
        printf("%d\t%s\t%.2f\n", current->id, current->name, current->balance);
        current = current->next;
    }
}

// Function to compare recipient IDs for binary search
int compareRecipientIDs(const void* a, const void* b) {
    return ((struct Recipient*)a)->id - ((struct Recipient*)b)->id;
}

// Function to perform binary search and display details of a particular recipient
void searchRecipientDetails(struct Recipient* recipients, int numRecipients, int searchID) {
    struct Recipient key;
    key.id = searchID;

    struct Recipient* result = (struct Recipient*)bsearch(&key, recipients, numRecipients, sizeof(struct Recipient), compareRecipientIDs);

    if (result != NULL) {
        printf("Recipient found:\n");
        printf("ID: %d\n", result->id);
        printf("Name: %s\n", result->name);
        printf("Balance: %.2f\n", result->balance);
    } else {
        printf("Recipient with ID %d not found.\n", searchID);
    }
}

// Function to free memory used by the linked list
void freeList(struct Recipient* head) {
    struct Recipient* current = head;
    struct Recipient* nextRecipient;

    while (current != NULL) {
        nextRecipient = current->next;
        free(current);
        current = nextRecipient;
    }
}

int main() {
    struct Recipient* head = NULL;
    int numRecipients;

    // Input the number of recipients
    printf("Enter the number of recipients: ");
    scanf("%d", &numRecipients);

    // Input recipient details
    for (int i = 0; i < numRecipients; i++) {
        struct Recipient* newRecipient = (struct Recipient*)malloc(sizeof(struct Recipient));

        printf("Enter details for recipient %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &newRecipient->id);
        printf("Name: ");
        scanf("%s", newRecipient->name);
        printf("Balance: ");
        scanf("%f", &newRecipient->balance);

        newRecipient->next = head;
        head = newRecipient;
    }

    // Sort the array of recipients by ID for binary search
    struct Recipient* recipientsArray = (struct Recipient*)malloc(numRecipients * sizeof(struct Recipient));
    struct Recipient* current = head;
    for (int i = 0; i < numRecipients; i++) {
        recipientsArray[i] = *current;
        current = current->next;
    }
    qsort(recipientsArray, numRecipients, sizeof(struct Recipient), compareRecipientIDs);

    // Display all recipients
    printf("All Recipients:\n");
    displayAllRecipients(head);

    // Get recipient details by ID using binary search
    int searchID;
    printf("\nEnter ID to search: ");
    scanf("%d", &searchID);

    searchRecipientDetails(recipientsArray, numRecipients, searchID);

    // Free the memory used by the linked list and array
    freeList(head);
    free(recipientsArray);

    return 0;
}


















Initialize the head of the linked list to NULL.
Read the number of recipients (numRecipients) from the user.
Input Recipient Details:

Loop i from 1 to numRecipients.
Read recipient details (ID, Name, Balance) from the user.
Insert the new recipient at the beginning of the linked list.
Display All Recipients:

Display a header for the recipient details.
Traverse the linked list and print the details of each recipient.
Convert Linked List to Array:

Allocate memory for an array of recipients (recipientsArray) of size numRecipients.
Traverse the linked list and copy recipient details to the array.
Sort Array by ID:

Use qsort to sort recipientsArray based on recipient IDs.
Binary Search for Recipient:

Read the recipient ID (searchID) to be searched.
Initialize low to 0 and high to numRecipients - 1.
While low is less than or equal to high:
Compute mid as the average of low and high.
If recipientsArray[mid].id is equal to searchID, display recipient details and return.
If recipientsArray[mid].id is less than searchID, update low to mid + 1.
If recipientsArray[mid].id is greater than searchID, update high to mid - 1.
Display Search Result:

If the recipient is not found during binary search, print a message indicating that the recipient with the specified ID was not found.
Free Memory:

Free the memory used by the linked list and the array.


















