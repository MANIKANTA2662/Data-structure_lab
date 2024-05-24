// Online C compiler to run C program online
// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
int a[10],n,i,ch,ind=0;
void read_array();
void display();
void Update();
void insert_beg();
void insert();
void delete();
int main()
{
    while(1)
    {
        printf("1. Read the array\n");
        printf("2. Insert element into the array\n");
        printf("3. Display the array\n");
        printf("4. Insert element at beginning\n");
        printf("5. Update  the array\n");
        printf("6. Delete element in array\n");
        printf("7. exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:read_array();break;
            case 2:insert(); break;
            case 3:display();break;
            case 4:insert_beg();break;
            case 5:Update();break;
            case 6:delete();break;
            case 7: exit(0);
        }

    }
    return 0;
}
void read_array()
{
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        ind++;
    }
}
void display(){ printf("The elements in array\n");
    for(i=0;i<ind;i++)
    printf("%d ",a[i]);
    printf("\n");
    
}
void Update(){
    int index,value;
    printf("enter the index and value\n");
    scanf("%d%d",&index,&value);
    a[index]=value;
    display();
}
void insert_beg(){
    int value;
    printf("Enter the element - \n");
    scanf("%d",&value);


    for(i = ind-1;i>=0;i--){
        a[i+1] = a[i];
    }
    a[0] = value;
    ind++;
    display();
}
void insert(){
    int n;
    printf("Enter the element\n ");
    scanf("%d",&n);
    for(int i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
        display();
    }
}
void delete(){
    int value;
    printf("Enter the element - \n");
    scanf("%d",&value);
    int index = -1;

    for(int i=0;i<10;i++){
        if(a[i] == value){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Element Not found");
        return;
    }

    for(i=index+1;i<ind;i++){
        a[i-1] = a[i];
    } 

    ind--;
    display();
}
