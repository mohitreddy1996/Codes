#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
 
int main() {
	int t;
	char ch[27];
	scanf("%d %s",&t,ch);
	char pro[27];
	char c='a';
	for(int i=0;ch[i]!='\0';i++)
	{
	    pro[int(ch[i]-'a')]=c;
	    c++;
	}
	while(t--)
	{
	    char temp[101];
	    scanf("%s",temp);
	    for(int i=0;temp[i]!='\0';i++)
	    {   char g;
	        if(temp[i]=='_')
	        {
	            cout<<" ";
	        }
	        else if(isalpha(temp[i]))
	        {
	            if(isupper(temp[i]))
	            {
	                g=tolower(temp[i]);
	                
	                cout<<char(toupper(ch[g-'a']));
	            }
	            else
	            {
	                cout<<ch[temp[i]-'a'];
	            }
	        }
	        else
	        {
	            cout<<temp[i];
	        }
	    }
	    cout<<"\n";
	}
	
	
	return 0;
}
