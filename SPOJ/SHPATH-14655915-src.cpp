#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define MAX 10001
/*
long long modular_pow(long long base, long long exponent, int modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


int solve()
{
      ....
      Base Cases
      ....
      if ( DP[i][j] is calculated) // Already calculated so just reuse
               return DP[i][j];
      else // Calculate DP[i][j] and return it
           put recurrence algo
           DP[i][j] = ans of recurrence algo 
           return DP[i][j]
}

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}



int visited[200000]
vector <int> list[200000]
void bfs(int i)
{
	queue <int> q;
	q.push(i);
	visited[i]=1;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int j=0;j<list[k].size();j++)
		{
			if(visited[list[k][j]]==0)
			{
				q.push(list[k][j]);
				visited[list[k][j]]=1;
			}
		}
	}
}


struct node
{
    int v,dist;
    node(){}
    node(int _v,int _dist)
    {
        v=_v,dist=_dist;
    }
}aux;

#define MAX 10000
bool visited[MAX];
vector <int> L[MAX];
node search(int v)
{
    node ans=node(v,0);
    queue<node> q;
    q.push(node(v,0));
    
    memset(visited,false,sizeof(visited));
    visited[v]=true;
    
    while(!q.empty())
    {
        aux=q.front();
        q.pop();
        
        ans=aux;
        
        for(int i=L[aux.v].size()-1;i>=0;i--)
        {
            if(visited[L[aux.v][i]])   continue;
            visited[L[aux.v][i]]=true;
            q.push(node(L[aux.v][i],aux.dist+1));
        }
    }
    return ans;
    
}
*/
/*
void dfs(int i)
{
    stack<int> s;
    s.push(i);
    while(s.empty()==false)
    {
        int k=s.top();
        s.pop();
        if(visited[k]==false)
            visited[k]=true;
        else
        {
            continue;
        }
            for(int j=0;j<List[k].size();j++)
            {
                if(visited[List[k][j]==false)
                    visited[List[k][j]]=true;
                else
                    continue;
                s.push(List[k][j]);    
            }
    }
}
*/
#define pii pair<int,int> 
struct comp 
{
    bool operator() (const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.second>b.second;
    }
    
};
int main()
{
    
    int t;
    string str1,str2;
    int x,y;
    int n;
    int m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector<pii> v[n+2];
        priority_queue<pii,vector<pii>,comp> q;
        map<string,int> ma;
        for(int i=1;i<=n;i++)
        {
            cin>>str1;
            ma[str1]=i;
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d %d",&x,&y);
                v[i].push_back(pii(x,y));
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            cin>>str1>>str2;
            x=ma[str1],y=ma[str2];
            int distance[n+2];
            int visited[n+2];
            for(int i=0;i<=n+1;i++)
            {
                distance[i]=mod;
                visited[i]=0;
            }
            distance[x]=0;
            q.push(pii(x,distance[x]));
            while(q.empty()==false)
            {
                pii p=q.top();
                q.pop();
                if(visited[p.first])
                    continue;
                for(int i=0;i<v[p.first].size();i++)
                {
                if(distance[v[p.first][i].first] > distance[p.first] + v[p.first][i].second)
                {
                    distance[v[p.first][i].first] = distance[p.first] + v[p.first][i].second;
                    q.push(pii(v[p.first][i].first,distance[v[p.first][i].first]));
                }
                }
                visited[p.first]=1;
                    
            }
            printf("%d\n",distance[y]);
        }
    }
    


return(0);    
}