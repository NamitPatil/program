#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node 
{
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
struct Node* insertNode(struct Node* head, int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main()
{
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes into the linked list
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);

    // Display the linked list
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}//end main