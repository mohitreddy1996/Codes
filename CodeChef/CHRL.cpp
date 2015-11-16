#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
	    char ch[1000001];
	    scanf("%s",ch);
	    
	    int j=0;
	    int count=0;
	    int c=0,h=0,e=0,f=0;
	    for(int i=0;ch[i]!='\0';i++)
	    {
	       if(ch[i]=='C')
	       {
	            c++; 
	       }
	       else if(ch[i]=='H'&&c>h)
	       {
	           h++;
	           
	       }
	       else if(ch[i]=='E'&&h>e)
	       {
	           e++;
	           
	       }
	       else if(ch[i]=='F'&&e>f)
	       {
	           f++;
	           
	       }
	    }
	    printf("%d",f);
	return 0;
}

