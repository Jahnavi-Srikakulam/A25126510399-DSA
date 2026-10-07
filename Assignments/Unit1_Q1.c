/*A company stores employee IDs in ascending order.
Write a C program that accepts n employee IDs,
searches for a required ID using Binary Search,
displays its position when found, reports when it is absent,
and counts the number of comparisons. Test the program for both successful and unsuccessful searches. */
#include <stdio.h>
int main()
{
    int n,high,low,mid,emp_id,found=0;
    int comparisons=0;
    int a[100];
    printf("Enter number of employee ID's of array:");
    scanf("%d",&n);
    printf("Enter employee ID's in ascending order:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter employee id to search:");
    scanf("%d",&emp_id);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        comparisons++;
        if(a[mid]==emp_id)
        {
            found=1;
            break;
        }
        else if(emp_id<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(found)
    {
        printf("Employee id is found at position %d", mid+1);
    }
    else
    {
        printf("Employee id not found");
    }
    printf("\nNumber of comparisons:%d",comparisons);
}