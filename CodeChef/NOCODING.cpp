#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
	int t;
	char ch[1001];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%s",ch);
	    int res=1;
	    int i;
	    for(i=1;ch[i]!='\0';i++)
	    {
	        char a=ch[i];
	        char b=ch[i-1];
	        if(a>=b)
	        {
	            res=res+(a-b);
	            //cout<<res<<" ";
	        }
	        else
	        {
	            res=res+26+(a-b);
	            //cout<<res<<" ";
	        }
	        
	    }
	    res=res+i;
	    //printf("%d",res);
	    if(res<=(11*strlen(ch)))
	        printf("YES\n");
	    else
	        printf("NO\n");
	} 
	return 0;
}
