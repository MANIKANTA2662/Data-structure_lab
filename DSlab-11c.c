 #include<stdio.h>
 int n,a[10],i,j;
 int partition(int a[],int start,int end)
 {
    int pivot=a[end];
    i=start-1;
    for(j=start;j<=end-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[i+1];
    a[i+1]=a[end];
    a[end]=t;
    return (i+1);
 }
 int quick(int a[],int start,int end)
 {
    if(start<end)
    {
        int p=partition(a,start,end);
        quick(a,start,p-1);
        quick(a,p+1,end);
    }
 }
 int main()
 {
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elements in array\n");
    for( i=0;i<n;i++)
    scanf("%d",&a[i]);
    quick(a,0,n-1);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
 }