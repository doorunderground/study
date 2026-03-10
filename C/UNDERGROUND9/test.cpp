#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node * createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

    // (*newNode).data = data;
    // (*newNode).next = NULL;
}

void insertNode (Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", (*current).data);
        current = (*current).next;
    }
    printf("NULL \n");
}

int main()
{
    Node *head = NULL;

    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 12);
    insertNode(&head, 9);


    printf("연결 리스트 : ");
    printList(head);

    insertNode(&head, 15);

    printf("갱신된 연결 리스트 :");
    printList(head);

    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = (*current).next;
        free(temp);
    }
}
