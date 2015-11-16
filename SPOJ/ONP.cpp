#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <ctype.h>
using namespace std;
int main()
{
	int t;
	char ch[402];
	scanf("%d",&t);
	while(t--)
	{
		stack<char> s;	
		scanf("%s",ch);
		for(int i=0;ch[i]!='\0';i++)
		{
			
			if(ch[i]==')')
			{
				while(s.top()!='(')
				{
					printf("%c",s.top());
					s.pop();
				}
				s.pop();
			}
			else if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='^'||ch[i]=='(')
			{
				s.push(ch[i]);
			}
			else
			    printf("%c",ch[i]);
		}
		printf("\n");
	}
 
return(0);
}
