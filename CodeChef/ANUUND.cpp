#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
	long int n;
	int t;
	long int a[100001];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%ld",&n);
	    for(long int i=0;i<n;i++)
	    {
	        scanf("%ld",&a[i]);
	    }
	    std::sort(a,a+n);
	    for(long int i=0;i<n-1;i++)
	    {
	        if(i%2==0)
	        {
	            if(a[i]>=a[i+1])
	            {
	                long int temp=a[i];
	                a[i]=a[i+1];
	                a[i+1]=temp;
	            }
	        }
	        else
	        {
	            if(a[i]<=a[i+1])
	            {
	                long int temp=a[i];
	                a[i]=a[i+1];
	                a[i+1]=temp;
	            }
	        }
	    }
	    for(long int i=0;i<n;i++)
	    {
	        printf("%ld ",a[i]);
	    }
	    printf("\n");
	}
	return(0);
}
