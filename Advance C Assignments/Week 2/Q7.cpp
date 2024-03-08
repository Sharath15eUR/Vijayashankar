#include <stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE]; // Declare an array to store elements of the queue
int front = -1; // Initialize front of the queue
int back = -1; // Initialize back of the queue

// Function to insert an element into the queue
void enqueue(int item) {
    if (back == MAX_SIZE - 1) { // Check if the queue is full
        printf("Error: Queue is full\n"); // Print error message if the queue is full
        return;
    }
    if (front == -1) {
        front = 0; // Set front to 0 if it's the first element being inserted
    }
    back++; // Increment the rear pointer
    queue[back] = item; // Insert the item into the queue
}

// Function to display the elements in the queue
void display() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Queue is empty\n"); // Print message if the queue is empty
        return;
    }
    printf("Queue elements are: "); // Print message to indicate displaying queue elements
    for (int i = front; i <= back; i++) { // Loop through the queue elements
        printf("%d ", queue[i]); // Print each element
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to remove an element from the front of the queue
void dequeue() {
    if (front == -1 || front > back) { // Check if the queue is empty
        printf("Error: Queue is empty\n"); // Print error message if the queue is empty
        return;
    }
    front++; // Increment the front pointer to remove the element
}

// Function to check whether the queue is empty
int is_empty() {
    if (front == -1 || front > back) { // Check if the queue is empty
        return 1; // Return 1 if the queue is empty
    }
    return 0; // Otherwise, return 0
}

// Function to count the number of elements in the queue
int count() {
    int count = 0; // Initialize count variable to store the number of elements
    if (front != -1 && back != -1) { // Check if the queue is not empty
        for (int i = front; i <= back; i++) { // Loop through the queue elements
            count++; // Increment count for each element
        }
    }
    return count; // Return the total count of elements in the queue
}

int main() {
    printf("Initialize a queue!"); // Print message to indicate initializing a queue
    // Insert some elements into the queue.
    printf("\nCheck the queue is empty or not? %s\n", is_empty() ? "Yes" : "No"); // Check if the queue is empty
    printf("Number of elements in queue: %d\n", count()); // Display the number of elements in the queue
    printf("\nInsert some elements into the queue:\n"); // Print message to indicate inserting elements into the queue
    enqueue(1); // Insert element 1 into the queue
    enqueue(2); // Insert element 2 into the queue
    enqueue(3); // Insert element 3 into the queue
    display(); // Display the elements of the queue
    // Display the number of elements in the queue
    printf("Number of elements in queue: %d\n", count());
    printf("\nDelete two elements from the said queue:\n"); // Print message to indicate deleting elements from the queue
    dequeue(); // Delete one element from the queue
    dequeue(); // Delete another element from the queue
    display(); // Display the updated elements of the queue
    printf("Number of elements in queue: %d\n", count()); // Display the updated number of elements in the queue
    printf("\nInsert another element into the queue:\n"); // Print message to indicate inserting another element
    enqueue(4); // Insert element 4 into the queue
    display(); // Display the updated elements of the queue
    printf("Number of elements in the queue: %d\n", count()); // Display the updated number of elements in the queue
    return 0; // Return from the main function
}
