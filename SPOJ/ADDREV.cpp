#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	
		int t;
		scanf("%d",&t);
		while(t--)
		{
			int n1,n2;
			scanf("%d %d",&n1,&n2);
			int temp1=0,temp2=0;
			while(n1)
			{
				temp1=temp1*10+(n1%10);
				n1=n1/10;
			}
			while(n2)
			{
				temp2=temp2*10+(n2%10);
				n2=n2/10;
			}
			temp1=temp1+temp2;
			temp2=0;
			while(temp1)
			{
				temp2=temp2*10+temp1%10;
				temp1=temp1/10;
			}
			printf("%d\n",temp2);
		}
	return 0;
}
