#include <bits/stdc++.h>
using namespace std;
int main()
{ long long int sum=0;int n;
    long long int t,a[100010];
    cin>>t;
    while(t--)
    {
        sum=0ll;
 
     cin>>n;
    for(int i=0;i<n;i++)
    {
     cin>>a[i];
 
     }
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        sum+=a[i]*a[0];
        a[i]=0;
        //cout<<sum;
    }
a[0]=0;
cout<<sum<<endl;
    }
 
    return 0;
}
