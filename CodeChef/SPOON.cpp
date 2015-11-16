#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <ctype.h>
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
    
    int t;
    int n,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&c);
        char ch[n+1][c+1];
        for(int i=0;i<n;i++)
        {
            scanf("%s",ch[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c;j++)
            {
                ch[i][j]=tolower(ch[i][j]);
            }
        }
        bool status=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c;j++)
            {
                
                if(j<=c-5)
                {
                    if(ch[i][j]=='s'&&ch[i][j+1]=='p'&&ch[i][j+2]=='o'&&ch[i][j+3]=='o'&&ch[i][j+4]=='n')
                        {
                            status = true;
                            break;
                        }
                        
                }
                if(i<=n-5)
                {
                    if(ch[i][j]=='s'&&ch[i+1][j]=='p'&&ch[i+2][j]=='o'&&ch[i+3][j]=='o'&&ch[i+4][j]=='n')
                    {
                        status = true;
                        break;
                    }
                }
            }
            if(status)
                break;
            
        }
        if(status)
        {
            printf("There is a spoon!\n");
        }
        else
        {
            printf("There is indeed no spoon!\n");
        }
    }
    
 
 
return(0);    
}
