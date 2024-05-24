#include<stdio.h>
int i,j,n,a[10];
int bubble_sort(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            
        }
    }
}
int main()
{
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elements in array\n");
    for( i=0;i<n;i++)
    scanf("%d",&a[i]);
    bubble_sort(a,n);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}