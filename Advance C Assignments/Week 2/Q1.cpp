#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* current = head;

    // Traverse the linked list
    while (current->next != NULL) {
        // Check if the current node has the same value as the next node
        if (current->data == current->next->data) {
            // If yes, skip the next node by adjusting the pointers
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            // Move to the next node
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a new node at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Main function to test the program
int main() {
    struct Node* head = NULL;
	int a,b,c,d,e;
    printf("Enter five numbers in sorted form: ");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	insert(&head, a);
    insert(&head, b);
    insert(&head, c);
    insert(&head, d);
	insert(&head, e);
	
    printf("Original Linked List: ");
    printList(head);

    removeDuplicates(head);

    printf("Linked List after removing duplicates: ");
    printList(head);

    return 0;
}
