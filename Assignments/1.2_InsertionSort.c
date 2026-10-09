/*A teacher wants to arrange student marks in ascending order
and also measure how much rearrangement is necessary. 
Write a C program using Insertion Sort that accepts n marks, 
displays the array after every pass, counts the total number of element shifts,
and displays the final sorted list and shift count. */
#include <stdio.h>
int main()
{
    int i,j,n,key;
    int shifts=0;
    printf("Enter no.of students:");
    scanf("%d",&n);
    int a[n];
    printf("Enter marks of students:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            shifts++;
            j--;
        }
        a[j+1]=key;
        printf("After pass:%d ",i);
        for(int k=0;k<n;k++)
        {
        printf("%d ",a[k]);
        }
        printf("\n");
    } 
    printf("Final sorted list:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nTotal shifts: %d", shifts);
    return 0;
}
