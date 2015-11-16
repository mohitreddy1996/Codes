#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	   int a[n];
	   for(int j=0;j<n;j++)
	   {
	       cin>>a[j];
	   }
	   int small=a[0];
	   int count=0;
	   for(int j=0;j<n;j++)
	   {
	       if(a[j]<=small)
	       {count=count+1;small=a[j];}
	   }
	   cout<<count<<endl;
	     
	}
	return 0;
}
