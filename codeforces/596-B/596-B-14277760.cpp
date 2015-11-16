#include <bits/stdc++.h>

using namespace std;
long long int b[220202];
long long int count1=0;
long long int prev=0;
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    for(int i=0;i<n;i++)
    {
        if(prev==b[i])
        {
            continue;
        }
        else
        {
            count1+=abs(b[i]-prev);
            prev=b[i];
        }
    }
    cout<<count1;
return 0;
}