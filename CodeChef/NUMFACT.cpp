#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	int n;
	long int temp;
	
	while(t--)
	{   long long int count=1;
	    int b[1000002]={0};
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
	        scanf("%ld",&temp);
	        long int q=temp;
	        while(q%2==0)
	        {
	           
	                b[2]++;
	                q=q/2;
	            
	        }
	       
	        for(int j=3;j<=sqrt(q);j+=2)
	        {
	            while(q%j==0)
	            {
	                
	                   b[j]++;
	                   q=q/j;
	                
	            }
	            
	        }
	        if(q>2)
	        {
	            b[q]++;
	        }
	    }
	    
	    for(long int j=1;j<=1000001;j++)
	    {
	        if(b[j]!=0)
	        {
	            count=count*(b[j]+1);
	        }
	    }
	    printf("%lld\n",count);
	        
	        
	}
	return 0;
}
