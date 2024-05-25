// Online C compiler to run C program online
#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};
struct node *ptr; 
struct node *head;  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
int main ()  
{   while(1)
    {
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        int ch;
        printf("enter ur choice ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 1: beginsert (); break;
            case 2: lastinsert ();break;
            case 3: randominsert();break;
            case 4: begin_delete();break;
            case 5: last_delete();break;
            case 6: random_delete();break;
            case 7: search(); break;
            
            case 8: display();break;
            case 9: exit(0);
        }
    }
    return 0;  
} 
//Insert elements at beginning. 
void beginsert()  
{  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;  
        display();
    }  
      
} 
//Insert element at end of list. 
void lastinsert()  
{  
    struct node *temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            display();
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            display();
        }  
    }  
}  
//Insert element with loctaion of list.
void randominsert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value ");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location  which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc-1;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        display();
    }  
}  
//Delete element at beginning.
void begin_delete()  
{  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");
        display();
    }  
}  
//Delete element at last.
void last_delete()  
{  
    struct node *ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");
        display();
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last ...\n");
        display();
    }     
}  
//Delete element with loctaion of list.
void random_delete()  
{  
    struct node *ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after  you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<=loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);
    display();
}  
//Search element in list.
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag=-1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i);  
                flag=0;  
            }    
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==-1)  
        {  
            printf("Item not found\n");  
        }  
    }            
}  
//Display the list.
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        while (ptr!=NULL)  
        {  
            printf("%d->",ptr->data);  
            ptr = ptr -> next;  
        }  
        printf("NULL\n");
    }  
}     
