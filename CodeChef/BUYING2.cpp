#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,x;
        long int sum=0;
        cin>>n>>x;
        int a[n];
        for(int j=0;j<n;j++)
        cin>>a[j];
        std::sort(a,a+n);
        for(int j=0;j<n;j++)
        sum=sum+a[j];
        if(sum/x==(sum-a[0])/x)
        cout<<"-1"<<endl;
        else
        cout<<sum/x<<endl;
    }
	
	return 0;
}
