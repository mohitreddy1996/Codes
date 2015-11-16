#include <iostream>
#include<algorithm>
using namespace std;
 
int main() {
	int t;
	 cin>>t;
	 while(t--)
	 {
	     int n,k;
	     cin>>n;
	     long int a[n+1];
	     for(int i=0;i<n;i++)
	     cin>>a[i];
	     cin>>k;
	     long int mark=a[k-1];
	     std::sort(a,a+n);
	     for(int i=0;i<n;i++)
	     if(mark==a[i])
	     cout<<i+1<<"\n";
	 }
	return 0;
}
