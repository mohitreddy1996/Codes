#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==y)
		{	if(x%2==0)
			{
			printf("%d\n",x*2);
			}
			else
			{
				printf("%d\n",x*2-1);
			}
		}
		else if(x==y+2)
		{
			if(x%2==0)
			{
				printf("%d\n",x+y);
			}
			else
			{
				printf("%d\n",x+y-1);
			}
		}
		else
		{
			printf("No Number\n");
		}
		
	}
	

	return 0;
}