#include<stdio.h>
int n,i,j,a[10],temp;
int insert(int a[],int n){
    for(i=0;i<n;i++){
    temp=a[i];
    j=i-1;
    while(j>=0 && temp<=a[j])
    {
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=temp;
    }
}
int main()
{
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements_\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insert(a,n);
    printf("sorted array is ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}