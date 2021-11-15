#include<stdio.h>
int main()
{
int N;

printf("enter case number:\n1=binary search\n2=linear search\n3=bubble sort\n4=merging");
scanf("%d",&N);
switch(N)
{
    case 1:
    binary_search();
    case 2:
    linear_search();
    case 3:
    bubble_sort();
    case 4:
    merging();
}
}
int binary_search()
{

    int arr[1000],temp,len,i,j;
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("\nEnter the elements in the array:\n");
    for(i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    //BUBBLE SORT
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //BINARY SEARCH
    int high,low,mid,target;
    printf("\nEnter the search key: ");
    scanf("%d",&target);
    low=0;
    high=len-1;
    while(high>=low)
    {
        mid=(low+(high-low))/2;
        if(arr[mid]==target)
        {
            printf("Your Search key %d is found in the given array!",target);
            break;
        }
        else if(arr[mid]<target)
        {
           low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
return 0;

}
int linear_search()
{
    
    int arr[1000],len,i,j,temp=0,index,search_key;
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("\nEnter the numbers in array: ");
    for(i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n\n\t Enter the search key: ");
    scanf("%d",&search_key);
    for(i=0;i<len;i++)
    {
        if(arr[i]==search_key)
        {
            index=i;
            temp=1;
            printf("HURRAY! your search key %d is found in given array at index = %d",search_key,index);
            break;
        }
    }
    if(temp==0)
    printf("-1");
return 0;
}
int bubble_sort()
{
    int i,j,n,temp=0;
    int a[10];
    printf("enter the size of the array: ");
    scanf("%d",&n);
    printf("enter the array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("your entered elements: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    //bubble sorting
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("sorted elements: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
return 0;
}
int merging()
{
   int i,j,n1,n2,n;
   int a1[10],a2[10],a3[10];
   printf("\n enter the size of array1:");
   scanf("%d",&n1);
   printf("\nenter the size of array2: ");
   scanf("%d",&n2);
   printf("\nenter the elements of array1: ");
   n=n1+n2;
   for(i=0;i<n1;i++)
   {
       scanf("%d",&a1[i]);
   }
   printf("\narray1: ");
   for(i=0;i<n1;i++)
   printf("%d ",a1[i]);
   printf("\nenter array2 elements: ");
   for(i=0;i<n2;i++)
   scanf("%d",&a2[i]);
   printf("\narray2: ");
   for(i=0;i<n2;i++)
   printf("%d ",a2[i]);
   for(i=0;i<n1;i++)
   {
       a3[i]=a1[i];
   }
   for(i=n1;i<n;i++)
   {
       a3[i]=a2[i-n1];
   }
   printf("\nMerged Array: ");
   for(i=0;i<n;i++)
   {
       printf("%d ",a3[i]);
   }
   
}