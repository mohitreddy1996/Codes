#include <bits/stdc++.h>

using namespace std;
int ans=-1;
int dist[1010];
int visited[1010];
vector<int> v[1010];
void dfs(int x)
{
    visited[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(!visited[y])
            dfs(y);
        dist[x]=max(dist[x],dist[y]+1);
    }
    dist[x]=max(dist[x],1);
    ans=max(ans,dist[x]);
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int pos[k+1][n+1];
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int temp;
            scanf("%d",&temp);
            pos[i][temp]=j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int flag=1;
            for(int l=1;l<=k;l++)
            {
                if(pos[l][i]>=pos[l][j])
                    flag=0;
            }
            if(flag)
            {
                v[i].push_back(j);
            }
        }
    }

    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}