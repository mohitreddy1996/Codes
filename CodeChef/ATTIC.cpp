#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	long int t;
	char ch[1000002];
	scanf("%ld",&t);
	
	while(t--)
	{
	    scanf("%s",ch);
	    long int count=0;
	    long int maxjump=0;
	    long int days=0;
	    for(long int i=0;ch[i]!='\0';i++)
	    {
	        if(ch[i]=='.')
	        {
	            count++;
	        }
	        else
	        {
	            if(count>maxjump)
	            {
	                days++;
	                maxjump=count;
	            }
	            count=0;
	        }
	        
	    }
	    printf("%ld\n",days);
	}
	return 0;
}
