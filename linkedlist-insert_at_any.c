//insert at any position
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *insert_at_any(int data, int pos)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    struct node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr->next == NULL)
    {
        curr->next->next = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

struct node *insert_at_end(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temporary = head;
        while (temporary->next != NULL)
        {
            temporary = temporary->next;
        }
        temporary->next = temp;
    }
    return head;
}
struct node *display()
{
    struct node *temporary = head;
    while (temporary != NULL)
    {
        printf("%d\t", temporary->data);
        temporary = temporary->next;
    }
    return head;
}
int main()
{
    int n;
    printf("ENter the nnumber of nodes you want\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insert_at_end(data);
    }
    display();
    printf("\n");
    printf("Linked list after adding the element\n");
    insert_at_any(100, 2);
    display();
    return 0;
}