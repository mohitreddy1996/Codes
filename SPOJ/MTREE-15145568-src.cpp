#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

#define mod 1000000007
int n;
vector<pair<int,int> > v[100002];
long long int divi=500000004;
int visited[100002];
long long int path[100002],weight[100002];
int parent[100002];
void dfs(int x)
{
    if(visited[x]==1)
        return;
    long long int ret=0;
    long long int sum=0;
    long long int sq=0;
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i].first;
        int w=v[x][i].second;
        if(parent[x]!=y)
        {
            parent[y]=x;
            dfs(y);
            long long int temp=((1+path[y])*w)%mod;
            sum+=(temp);
            sum%=mod;
            sq+=(temp*temp);
            sq%=mod;
            ret+=(weight[y]);
        }
    }
    ret+=(sum);
    ret%=mod;
    ret+=(((sum*sum-sq)%mod)*(divi%mod))%mod;
    ret%=mod;
    visited[x]=1;
    path[x]=sum;
    weight[x]=ret;


}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {

        int  x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));

    }
    for(int i=1;i<=100000;i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }
    dfs(1);
    printf("%lld",weight[1]);

    return 0;
}
