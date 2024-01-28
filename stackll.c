#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

void main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
            printf("\nEnter value:");
            scanf("%d",&value);
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid");
        }
    }
}

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(top==NULL)
    newNode->next = NULL;
    else
    newNode->next = top;
    top = newNode;
    printf("\nInsertion successful!");
}

void pop()
{
    if(top==NULL)
    printf("\nStack is empty");
    else
    {
        struct Node *temp = top;
        printf("\nDeleted element is %d",temp->data);
        top = temp->next;
        free(temp);
    }
}

void display()
{
    if(top==NULL)
    printf("\nStack is empty");
    else
    {
        struct Node *temp = top;
        while(temp->next!=NULL)
        {
            printf("%d--->",temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL",temp->data);
    }
}