#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void insert(int);
void delete();
void display();

void main()
{
    int choice,value;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("\nEnter value:");
            scanf("%d",&value);
            insert(value);
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("\nInvalid choice.");
        }
    }
}

void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front==NULL)
    front=rear=newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInsertion successful!\n");
}

void delete()
{
    if(front==NULL)
    printf("\nQueue is empty\n");
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("\nDeleted element is %d",temp->data);
        free(temp);
    }
}

void display()
{
    if(front==NULL)
    printf("\nQueue is empty\n");
    else
    {
       struct Node *temp = front;
       while(temp->next!=NULL)
       {
        printf("%d--->",temp->data);
        temp = temp->next;
       } 
       printf("%d--->NULL",temp->data);
    }
}