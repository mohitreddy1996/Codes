#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int a[4];
	while(1)
	{	int count=0;
		for(int i=0;i<3;i++)
		{	
			scanf("%d",&a[i]);
			if(a[i]==0)
			{
				count++;
			}
		}
		if(count!=3)
		{
			if(a[1]-a[0]==a[2]-a[1])
			{
				printf("AP %d\n",a[2]+(a[2]-a[1]));
			}
			else
			{
				printf("GP %d\n",a[2]*a[2]/a[1]);
			}
		}
		else
		{
			break;
		}
	}

	return 0;
}
