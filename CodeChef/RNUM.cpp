#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	int t;
	long int n;
	long int temp;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%ld",&n);
	    long int a[1000003]={0},b[1000003]={0};
	    for(long int i=0;i<n;i++)
	    {
	        scanf("%ld",&temp);
	        a[temp]++;
	        b[temp]++;
	    }
	    long int case1=0;
	    long int case2=0;
	    for(long int i=1;i<1000001;i++)
	    {  if(i<=999998)
	       { 
	        if(a[i])
	        {
	            if(a[i+1])
	            {
	                if(a[i+2])
	                {
	                    a[i]=0;
	                    a[i+1]=0;
	                    a[i+2]=0;
	                }
	                else
	                {
	                    a[i]=0;
	                    a[i+1]=0;
	                }
	            }
	            else
	            {
	                a[i]=0;
	            }
	            case1++;
	        }
	       }
	       else
	       {
	           if(a[i])
	           {
	               if(a[i+1])
	               {
	                   a[i]=0;
	                   a[i+1]=0;
	                   case1++;
	                   break;
	               }
	               else
	               {
	                   a[i]=0;
	                   case1++;
	                   break;
	               }
	           }
	       }
	    }
	    for(long int i=1;i<=1000000;i++)
	    {   if(i<=999999)
	        {
	        if(b[i])
	        {
	            if(b[i+1])
	            {
	                b[i]=0;
	                b[i+1]=0;
	            }
	            else
	            {
	                b[0];
	            }
	            case2++;
	        }
	        }
	        else
	        {
	            if(b[i])
	                case2++;
	            b[i]=0;    
	            
	        }
	    }
	    printf("%ld %ld\n",case1,case2);
	    
	}
	
	return 0;
}
