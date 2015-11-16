#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,k,ans=0,num;
    char query[20];
    scanf("%d %d",&n,&k);
    bool arr[n];
    for(int i=0;i<n;i++)
        arr[i]=false;
    while(k--)
    {
        scanf("%s",&query);
        if(query[2]=='I')
        {
            for(int i=0;i<n;i++)
            scanf("%d",&num);
            if(arr[num-1])
            {
                arr[num-1]=false;
                ans--;
            }
            else
            {
                arr[num-1]=true;
                ans++;
            }
        }
        else
        {
            ans=0;
            for(int i=0;i<n;i++)
                arr[i]=false;
        }
        printf("%d\n",ans);
    }
    return(0);
}
