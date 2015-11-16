#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <limits.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define MAX 10001
 
/*
 
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
long int a[351][351];
static int prime[10000001];
int n;
void bfs(int i,int j,int flag)
{
    if(prime[a[i][j]]==-1)
    {
        if(a[i][j]!=-1 && a[i][j]%2==flag)
        {
            a[i][j]=-1;
            if(i+1<n)
                bfs(i+1,j,flag);
            if(j+1<n)
                bfs(i,j+1,flag);
            if(i-1>=0)
                bfs(i-1,j,flag);
            if(j-1>=0)
                bfs(i,j-1,flag);
        }
    }
}
void prigen()
{
    int mark=0;
    memset(prime,0,sizeof(prime));
    prime[0]=prime[1]=-1;
    for(long long int i=2;i<=10000000;i++)
    {
        if(prime[i]==0)
        {
        prime[i]=mark++;
        for(long long int j=(i*i);j<=10000000;j+=i)
        {
            prime[j]=-1;
        }
        }
    }
}
 
int main()
{
    int t,x,y,s,f;
    
    prigen();
    scanf("%d",&t);
    while(t--)
    {
        long long int ans=0;
       scanf("%d",&n);
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            scanf("%ld",&a[i][j]);
        }
       }
 
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(prime[a[i][j]]!=-1)
            {
                ans+=prime[a[i][j]];
                //cout<<"prime "<<ans<<" ";
                a[i][j]=-1;
            }
            else
            {
                if(a[i][j]%2==0)
                {
                    ans+=(a[i][j]/2);
                    bfs(i,j,0);
                }
                else
                {
                    ans+=(a[i][j]/2 +2);
                    bfs(i,j,1);
                }
 
            }
        }
       }
       printf("%lld\n",ans);
 
 
 
    }
 
 
 
return(0);    
}
