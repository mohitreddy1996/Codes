#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{	
	long long t,n,i,a[102],min,s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0,min=10002;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
			if(a[i]<min)
			min=a[i];
		}
		cout<<s-n*min<<endl;
	}
	return 0;
}
