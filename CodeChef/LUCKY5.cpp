#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
	    int t;
	    char ch[100002];
	    scanf("%d",&t);
	    while(t--)
	    {   
	        long int count=0;
	        scanf("%s",ch);
	        for(long int i=0;ch[i]!='\0';i++)
	        {
	            if(ch[i]!='4'&&ch[i]!='7')
	            {
	                count++;
	            }
	        }
	        printf("%ld\n",count);
	    }
	return 0;
}
