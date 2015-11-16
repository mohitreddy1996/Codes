#include <iostream>
using namespace std;
 
int main() {
	int t;
	int n;
	cin>>t;
	long long int c;
	for(int i=0;i<t;i++)
	{
	    cin>>n>>c;
	    long int a[n];
	    long long int sum=0;
	    //int flag=1;
	    for(long int j=0;j<n;j++)
	    {
	        cin>>a[j];
	        sum=sum+a[j];
	        
	    }
	    if(sum<=c)
	        {cout<<"Yes\n";}
	    else
	    cout<<"No\n";
	    
	}
	return 0;
}
