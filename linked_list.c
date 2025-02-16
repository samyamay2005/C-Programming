#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node* head = NULL;

// Function to create a new node
node* create_node(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to insert at any position
void insert_at_position(int data, int position) {
    node *newNode = create_node(data);
    
    if (position == 1 || head == NULL) {
        newNode->link = head;
        head = newNode;
        return;
    }

    node *temp = head;
    for (int i = 1; i < position - 1 && temp->link != NULL; i++) {
        temp = temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

// Function to delete at any position
void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    
    if (position == 1) {
        head = head->link;
        free(temp);
        return;
    }

    node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

// Function to remove elements that were repeated first
void remove_repeated_elements() {
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL) {
        node *runner = temp->link;
        node *runnerPrev = temp;
        int foundDuplicate = 0;

        while (runner != NULL) {
            if (temp->data == runner->data) {
                foundDuplicate = 1;
                runnerPrev->link = runner->link;
                free(runner);
                runner = runnerPrev->link;
            } else {
                runnerPrev = runner;
                runner = runner->link;
            }
        }

        if (foundDuplicate) {
            if (prev == NULL) { // Removing the head node
                node *delNode = head;
                head = head->link;
                free(delNode);
                temp = head;
            } else {
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
        } else {
            prev = temp;
            temp = temp->link;
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%d\n ", temp->data);
        temp = temp->link;
    }
}

void free_list() {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    int choice, data, position;

    do {
        printf("\nEnter choice:\n");
        printf("1. Insert data at any position\n");
        printf("2. Delete data from any position\n");
        printf("3. Remove first repeated elements\n");
        printf("4. Display linked list\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(data, position);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;

            case 3:
                remove_repeated_elements();
                break;

            case 4:
                printf("Linked List: \n");
                display();
                break;

            case 0:
                printf("Exiting...\n");
                free_list();
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
