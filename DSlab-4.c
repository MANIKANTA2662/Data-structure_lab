#include<stdio.h>
#include<stdlib.h>
int a[15],ch,i,n,sp=-1,max=4;
void push();
void pop();
void display();
int main()
{
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter the ur choice \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:exit(0);
        }
    }
    return 0;
}
void push(){
    if(sp==max)
    {
        printf("stack is full\n");
    }
    else{
        printf("enter element value\n");
        scanf("%d",&n);
        sp=sp+1;
        a[sp]=n;
        display();
    }
}
void pop(){
    if(sp==-1)
    printf("under flow");
    else
    {
        printf("deleted element is %d\n",a[sp]);
        sp=sp-1;
        display();
    }
}
void display(){
    printf("stack elements \n");
    for(i=sp;i>=0;i--)
    printf("%d ",a[i]);
}
