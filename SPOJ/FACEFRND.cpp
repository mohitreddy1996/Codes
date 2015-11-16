#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
//using namespace std;

int main()
{	int temp;
	int n;
	scanf("%d",&n);
	std::set<int> s;
	int a[101];
	int sum=0;
	int m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		a[i]=temp;
		scanf("%d",&m);
		
		for(int j=0;j<m;j++)
		{
			scanf("%d",&temp);
			s.insert(temp);
		}
	}
	  for(int i=0;i<n;i++)
	    {
	           s.erase(a[i]);
	    }
	int count=s.size();
	printf("%d",count);
return(0);
}
