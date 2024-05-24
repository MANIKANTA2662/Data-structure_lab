#include<stdio.h>
int linearSearch(int a[],int n,int target)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("enter size of arraya\n");
    scanf("%d",&n);
    int a[10];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int taraget;
    printf("enter the taraget value\n");
    scanf("%d",&taraget);
    int result=linearSearch(a,n,taraget);
    if(result==-1)
    {
        printf("element is not found\n");
    }else
    {
        printf("element is found:%d",result);
    }
}