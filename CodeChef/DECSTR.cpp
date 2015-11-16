#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
 
int main() {
	int t;
	char ch[27];
	scanf("%d",&t);
	char g='a';
	for(int i=0;i<26;i++)
	{
	    ch[i]=g;
	    g++;
	    
	}
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int temp=n%25;
	    n=n/25;
	    if(temp)
	    {
	    for(int k=temp;k>=0;k--)
	        printf("%c",ch[k]);
	    }    
	    while(n--)
	    {
	        for(int k=25;k>=0;k--)
	        {
	            printf("%c",ch[k]);
	        }
	    }
	    printf("\n");
	}
	return(0);
}
