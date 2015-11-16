#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	long int a[2001];
	while(1)
	{
	    scanf("%d",&t);
	    if(t!=0)
	    {
	    for(int i=0;i<t;i++)
	        scanf("%d",&a[i]);
	    sort(a,a+t);
	    int count=0;
	    for(int i=0;i<t;i++)
	    {
	        for(int j=i+1;j<t-1;j++)
	        {
	            int sum=a[i]+a[j];
	            long long int temp=(upper_bound(a+j+1,a+t,sum)-&a[0]);
	            
	            count=count+(t-temp);
	        }
	    }
	    printf("%d\n",count);
	    }
	    else
	    {
	        break;
	    }
	}
	return 0;
}
