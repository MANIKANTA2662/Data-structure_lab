#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete();
void display();
int main()
{
    printf("1.insert\n2.delete\n3.display\n4.exit");
    while(1)
    {
        int ch;
        printf("Enter the ur choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: insert();break;
        case 2: delete();break;
        case 3: display();break;
        case 4: exit(0);
        }
    }
    return 0;
}
void insert() 
{
    int value;
    printf("Enter element value\n");
    scanf("%d",&value);
    struct node * ptr;
    ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL))
     {
        front = rear = ptr;
        display();
    } 
    else
     {
        rear -> next = ptr;
        rear = ptr;
        display();
    }
    
}
void delete()
 {
    if (front == NULL)
    {
        printf("Underflow\n");
    }
     else 
    {
        struct node * temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
        display();
    }
}
void display()
{
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) 
    {
        printf("Queue is Empty\n");
    } 
    else
    {
        printf("The queue elements are \n");
        temp = front;
        while (temp)
        {
            printf("%d->", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}

   
