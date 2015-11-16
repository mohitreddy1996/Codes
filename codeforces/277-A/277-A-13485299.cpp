#include <bits/stdc++.h>

using namespace std;
vector<int>  v[1000];
int visited[1000];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(q.empty()==false)
    {
        int y=q.front();
        q.pop();
        if(visited[y])
            continue;
        visited[y]=1;
        for(int i=0;i<v[y].size();i++)
        {
            int z=v[y][i];
            if(!visited[z])
            {
                q.push(z);
            }
        }
    }
}

int main()
{

    int n,m;
    scanf("%d %d",&n,&m);
    set<int> s;
    int count1=0;
    memset(visited,0,sizeof(visited));
    int countz=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==0)
            countz++;
        while(k--)
        {
            int temp;
            scanf("%d",&temp);
            v[i+200].push_back(temp);
            v[temp].push_back(i+200);
        }
    }
    int flag=0;
    for(int i=201;i<=200+n;i++)
    {
        if(!visited[i])
        {
            bfs(i);
            count1++;
        }
    }
        count1--;
    if(countz==n)
        cout<<n;
    else
        cout<<count1;


return 0;

}