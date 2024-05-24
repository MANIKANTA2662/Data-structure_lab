#include<stdio.h>
int binarySearch(int a[],int l,int h,int x)
{
    if(h>l)
    {
        int mid=l+(h-l)/2;
        if(a[mid]==x)
        return mid;
        if(a[mid]>x)
        {
            return binarySearch(a,l,mid-1,x);
        }
            return binarySearch(a,mid+1,h,x);
    }
    return -1;
}
int a[10],n,x,i;
int main()
{
    printf("enter the size of arrya- ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the x value \n");
    scanf("%d",&x);
    int index = binarySearch(a, 0, n-1, x);
 
    if (index == -1) {
        printf("Element is not present in array");
    }
    else {
        printf("Element is present at index %d", index);
    }

}
