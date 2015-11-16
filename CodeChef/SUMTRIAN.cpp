#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	int a[101][101];
	scanf("%d",&t);
	int n;
	while(t--)
	{
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<=i;j++)
	        {
	            scanf("%d",&a[i][j]);
	        }
	    }
	    int temp[101][101]={0};
	    temp[0][0]=a[0][0];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<=i;j++)
	        {
	            if(j==0)
	            {
	                temp[i][j]=temp[i-1][j]+a[i][j];
	            }
	            else
	            {
	                temp[i][j]=max(temp[i-1][j]+a[i][j] , temp[i-1][j-1]+a[i][j]); 
	            }
	           
	        }
	    }
	    long int res=temp[n-1][0];
	    for(int j=1;j<n;j++)
	    {
	        if(temp[n-1][j]>res)
	        {
	            res=temp[n-1][j];
	        }
	    }
	    printf("%ld\n",res);
	}
	return 0;
}
