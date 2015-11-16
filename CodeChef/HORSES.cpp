#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	long int n;
	for(int i=0;i<t;i++)
	{
	  cin>>n;
	 long long int a[n];
	 for(long int j=0;j<n;j++)
	 {
	     cin>>a[j];
	 }
	 std::sort(a,a+n);
	 long int diff=a[1]-a[0];
	 for(long int j=2;j<=n-1;j++)
	 {
	     if((a[j]-a[j-1])<diff)
	     diff=(a[j]-a[j-1]);
	 }
	 cout<<diff<<endl;
	}
	return 0;
}
