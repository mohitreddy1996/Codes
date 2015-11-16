#include <stdio.h>
void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
     L[i]=a[l+i];
    for(int j=0;j<n2;j++)
     R[j]=a[m+j+1];
     int i=0,j=0,k=l;
     while(i<n1&&j<n2)
     {
         if(L[i]<R[j])
         {
             a[k]=L[i];
             i++;
         }
         else
         {
             a[k]=R[j];
             j++;
         }
         k++;
     }
     while(i<n1)
     {
         a[k]=L[i];
         i++;
         k++;
     }
     while(j<n2)
     {
         a[k]=R[j];
         j++;
         k++;
     }
}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    { int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(void) {
	long int n;
	scanf("%ld",&n);
	int a[n+1];
	for(long int i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	for(long int i=0;i<n;i++)
	printf("%d\n",a[i]);
	return 0;
}
