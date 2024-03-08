#include <stdio.h>
#include <stdlib.h>

// Definition for a doubly-linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to rotate a doubly linked list by N nodes
struct Node* rotateDoublyList(struct Node* head, int N) {
    if (head == NULL || N == 0) {
        return head;
    }

    // Find the last node of the current linked list
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Make the list circular by connecting the last node to the head
    current->next = head;
    head->prev = current;

    // Move to the Nth node from the beginning
    for (int i = 0; i < N; ++i) {
        head = head->next;
    }

    // Update the head and its previous node
    head->prev->next = NULL;
    head->prev = NULL;

    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a new node at the end of the doubly linked list
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Main function to test the program
int main() {
    struct Node* head = NULL;

    // Example usage
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);

    printf("Original Doubly Linked List: ");
    printList(head);

    int N;
    printf("Enter the number of nodes to rotate: ");
    scanf("%d",&N);
    head = rotateDoublyList(head, N);

    printf("Doubly Linked List after rotating by %d nodes: ", N);
    printList(head);

    return 0;
}
