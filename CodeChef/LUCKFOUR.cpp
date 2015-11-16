#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	long int n;
	scanf("%ld",&n);
	char ch[11];
	while(n--)
	{   int count=0;
	    scanf("%s",ch);
	    for(int i=0;ch[i]!='\0';i++)
	    {
	        if(ch[i]=='4')
	        count++;
	    }
	    printf("%d\n",count);
	}
	return 0;
}
