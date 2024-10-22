#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node{
    struct node *next;
    int data;
};
struct node *head;
int ch;
int main(){
    while(1){
    printf("1. push element into stack\n");
    printf("2. pop element from stack\n");
    printf("3. Display the stack\n");
    printf("4. exit\n");
    
    printf("enter the ur choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: push();break;
        case 2: pop();break;
        case 3: display();break;
        case 4: exit(0);
    }
}
return 0;
}
void push(){
    int data;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("overflow");
    }
    else{
        printf("Enter the value\n");
        scanf("%d",&data);
        if(head==NULL)
        {
            ptr->data=data;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->data=data;
            ptr->next=head;
            head=ptr;
        }
        display();
    }
}
void pop(){
    int data;
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("Underflow");
    }
    else{
       ptr=head;
        printf("pop element is %d",ptr->data);
        head=ptr->next;
        free(ptr);
        display();
    }
}
void display(){
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements\n");
        while(ptr!=NULL)
        {
            printf("%d-> ",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
}
