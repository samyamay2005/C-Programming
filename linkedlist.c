#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node* head = NULL;

node* create(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void display(node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("%d \n ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

node* insert_at_start(node *head, int data) {
    node *newNode = create(data);
    newNode->link = head;
    return newNode;
}

node* insert_at_end(node *head, int data) {
    node *newNode = create(data);
    if (head == NULL) {
        return newNode;
    }
    node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return head;
}

node* insert_at_position(node *head, int data, int position) {
    node *newNode = create(data);
    if (position == 1) {
        newNode->link = head;
        return newNode;
    }
    node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    return head;
}
node* delete_from_start(node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

node* delete_from_end(node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    if (head->link == NULL) {
        free(head);
        return NULL;
    }
    node *temp = head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
    return head;
}

node* delete_from_position(node *head, int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    if (position == 1) {
        node *temp = head;
        head = head->link;
        free(temp);
        return head;
    }
    node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL || temp->link == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    node *temp2 = temp->link;
    temp->link = temp2->link;
    free(temp2);
    return head;
}
node* delete_first_repeated_element(node *head) {
    if (head == NULL || head->link == NULL) return head;

    node *temp = head, *prev = NULL;
    while (temp != NULL && temp->link != NULL) {
        node *runner = temp->link, *runnerPrev = temp;
        while (runner != NULL) {
            if (temp->data == runner->data) {
                runnerPrev->link = runner->link;
                free(runner);
                return head;
            }
            runnerPrev = runner;
            runner = runner->link;
        }
        temp = temp->link;
    }
    return head;
}

void free_list(node* head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    int choice, element, position, n;

    do {
        printf("\nEnter choice:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Start\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("6. Display Linked List\n");
        printf("7. Delete from Start\n");
        printf("8. Delete from End\n");
        printf("9. Delete from Position\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                head = NULL; // Reset the list
                for (int i = 0; i < n; i++) {
                    printf("Enter element: ");
                    scanf("%d", &element);
                    head = insert_at_end(head, element);
                }
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                head = insert_at_start(head, element);
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d", &element);
                head = insert_at_end(head, element);
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insert_at_position(head, element, position);
                break;

            case 5:
                head = delete_first_repeated_element(head);
                break;

            case 6:
                printf("Linked List: ");
                display(head);
                break;

            case 7:
                head = delete_from_start(head);
                break;

            case 8:
                head = delete_from_end(head);
                break;
            
            case 9:
                printf("Enter position: ");
                scanf("%d", &position);
                head = delete_from_position(head, position);
                break;
            case 0:
                printf("Exiting...\n");
                free_list(head); 
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
