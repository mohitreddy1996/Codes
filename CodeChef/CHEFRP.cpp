#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long int n;
	    long long int sum=0;
	    cin>>n;
	    int a[n+1];
	    int flag=1;
	    for(long int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]<2)
	         flag=0;
	    }
	    if(flag)
	    {
	        std::sort(a,a+n);
	        for(long int i=1;i<n;i++)
	        {
	            sum=sum+a[i];
	        }
	        sum=sum+2;
	        cout<<sum<<"\n";
	    }
	    else
	    {
	        cout<<"-1\n";
	    }
	    
	}
 
 
	return 0;
}
