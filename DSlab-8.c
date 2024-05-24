#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}
struct node *front;
struct node *rear;
void insert();
void delete();
void display();
int main()
{
    while(1)
    {
        int ch;
        printf("\n1.insert\n2.delete\n3.display\n4.exit");
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
