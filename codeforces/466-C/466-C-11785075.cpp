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

int main()
{
    long int n;
    scanf("%ld",&n);
    long long int a[n+1];
    long long int sum=0;
    long long int count[n+1];
    memset(count,0,sizeof(count));
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3!=0)
    {
        printf("0");
        return 0;
    }
    sum=sum/3;
    long long int s=0;
    
    for(long int i=n-1;i>=0;i--)
    {
        s+=a[i];
        if(s==sum)
            count[i]=1;
    }
    for(long int i=n-2;i>=0;i--)
    {
        count[i]+=count[i+1];
    }
    s=0;
    long long int ans=0;
    for(long int i=0;(i+2)<n;i++)
    {
        s+=a[i];
        if(s==sum)
            ans+=count[i+2];
    }
    cout<<ans;

return(0);    
}