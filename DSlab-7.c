#include<stdio.h>
#include<stdlib.h>
int a[5],ch,i,n,front=-1,rear=-1,max=4;
void enqueue();
void dequeue1();
void display();
int main()
{
    while(1)
    {
        printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter the ur choice \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:enqueue();break;
            case 2:dequeue1();break;
            case 3:display();break;
            case 4:exit(0);
        }
    }
}
void enqueue(){
    if(rear==max)
    {
        printf("Queue is full\n");
    }
    else{
        printf("enter element value\n");
        scanf("%d",&n);
        rear=rear+1;
        a[rear]=n;
        display();
    }
}
void dequeue1(){
    if(front==max)
    printf("Queue is empty");
    else
    {
        front=front+1;
        printf("deleted element is %d\n",a[front]);
        display();
    }
}
void display(){
    printf("Queue elements \n");
    for(i=front+1;i<=rear;i++)
    printf("%d ",a[i]);
}
