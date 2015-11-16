#include <stack>
#include <ctype.h>
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
			if(isalphanum(ch[i])==0)
				printf("%c",ch[i]);
			else if(ch[i]==')')
			{
				while(s.top()!='(')
				{
					printf("%c",s.top());
					s.pop();
				}
				s.pop();
			}
			else
			{
				s.push(ch[i]);
			}
	}

return(0);
}
