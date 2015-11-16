#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	char ch[100002];
	while(t--)
	{
	    scanf("%s",ch);
	    long int i,j;
	    for(i=0,j=strlen(ch)-1;i<j;i++,j--)
	    {
	        if(ch[i]!=ch[j])
	        {
	            break;
	        }
	    }
	    if(i<j)
	    {
	        printf("2\n");
	    }
	    else
	    {
	        printf("1\n");
	    }
	}
	return 0;
}
