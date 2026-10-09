#include<stdio.h>
int main()
{
int i,n,key,found=0;
printf("Enter size of array:");
scanf("%d",&n);
int a[n];
printf("Enter elements of the array:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter element to search:");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(a[i]==key)
{
found=1;
printf("The element %d is found at = %d\n",key,i);
break;
}
}
if(!found)
{
printf("The element is not found");
}
}
