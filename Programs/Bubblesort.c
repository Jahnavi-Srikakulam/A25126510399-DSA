#include <stdio.h>
int main(){
    int n,i,j,t;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of array:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Elements before sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    for(i=0;i<n-1;i++){
       for(j=0;j<n-1-i;j++){
        if(a[j]>a[j+1]){
          t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;
        }
       }
    }
    printf("\nElements after sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}