#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
    
}*root=NULL,*temp=NULL,*prev=NULL,*i=NULL;
void insert(int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int ch,n;
int main()
{
    printf("\n1.insert\n2.preorder\n3.inorder\n4.postorder\n5.exit\n");
    while(1)
    {
        printf(" enter ur choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter the number\n");
            scanf("%d",&n);
            insert(n);
        }
        if(ch==2)
        preorder(root);
        if(ch==3)
        inorder(root);
        if(ch==4)
        postorder(root);
        if(ch==5)
        exit(0);
    }
    return 0;
}
void insert(int n)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else{
        i=prev=root;
        while(i!=NULL)
        {
            prev=i;
            if(n<=i->data)
            {
                i=i->left;
            }
            else
            {
                i=i->right;
            }
        }
        if(n<=prev->data)
        prev->left=temp;
        else
        prev->right=temp;
    }
}
void preorder(struct node *r)
{
    if(r!=NULL)
    {
        printf("%d-",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d-",r->data);
        inorder(r->right);
    }
}
void postorder(struct node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d-",r->data);
        
    }
}