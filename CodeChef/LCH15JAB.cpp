#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	char s[52];
	scanf("%d",&t);
	
	while(t--)
	{   int sum=0;
	    int b[26]={0};
	    scanf("%s",s);
	    for(int i=0;s[i]!='\0';i++)
	    {
	        b[s[i]-'a']++;
	    }
	    sort(b,b+26);
	    int mark=b[25];
	    for(int i=0;i<25;i++)
	    {   
	        sum=sum+b[i];
	    }
	    
	    if(sum==mark)
	    {
	        printf("YES\n");
	        
	    }
	    else
	    {
	        printf("NO\n");
	    }
	   
	}
	return 0;
}
