#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node* head = NULL;

node* create_node(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void create_linkedlist() {
    head = NULL;
    node *temp = NULL;
    int data;
    char choice;
    printf("Enter elements (press 'n' to stop):\n");
    while (1) {
        if (scanf("%d", &data) != 1) {
            while (getchar() != '\n');
            break;
        }
        node *newNode = create_node(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->link = newNode;
            temp = temp->link;
        }
    }
}

void insert_at_beginning(int data) {
    node *newNode = create_node(data);
    newNode->link = head;
    head = newNode;
}

void insert_at_position(int data, int position) {
    node *newNode = create_node(data);
    if (position == 1) {
        newNode->link = head;
        head = newNode;
        return;
    }
    node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL) {
        free(newNode);
        return;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}

void delete_from_beginning() {
    if (head == NULL) return;
    node *temp = head;
    head = head->link;
    free(temp);
}

void delete_from_end() {
    if (head == NULL) return;
    if (head->link == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

void delete_from_position(int position) {
    if (head == NULL) return;
    if (position == 1) {
        node *temp = head;
        head = head->link;
        free(temp);
        return;
    }
    node *temp = head, *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) return;
    prev->link = temp->link;
    free(temp);
}

void display() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->link != NULL) printf(" -> ");
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, data, position;
    do {
        printf("\n1. Create LinkedList\n2. Insert at Beginning\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Display\n0. Exit\nYour choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_linkedlist();
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 3:
                printf("Enter element and position: ");
                scanf("%d %d", &data, &position);
                insert_at_position(data, position);
                break;
            case 4:
                delete_from_beginning();
                break;
            case 5:
                delete_from_end();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                delete_from_position(position);
                break;
            case 7:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
