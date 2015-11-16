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

static long long int arr[100002];
static long long int tree[200006];
static long long int sqtree[200006];


void build_tree(int node,int a,int b)
{
	if(a>b)
		return;
	if(a==b)
		{
			tree[node]=arr[a];
			sqtree[node]=tree[node]*tree[node];
			return;
		}

	build_tree(2*node,a,(a+b)/2);
	build_tree(2*node+1,(a+b)/2+1,b);
	//tree[node]=tree[2*node]+tree[2*node+1];
	sqtree[node]=sqtree[2*node]+sqtree[2*node+1];
}

void update1(int node,int i,int j,int a,int b,int v)
{
	if(a>b||a>j||i>b)
		return;
	if(a==b)
	{
		tree[node]=tree[node]+v;
		sqtree[node]=tree[node]*tree[node];
		return;
	}
	update1(2*node,i,j,a,(a+b)/2,v);
	update1(2*node+1,i,j,(a+b)/2+1,b,v);
	sqtree[node]=sqtree[2*node]+sqtree[2*node+1];
}

void update2(int node,int i,int j,int a,int b,int v)
{
	if(a>b||a>j||i>b)
		return;
	if(a==b)
	{
		tree[node]=v;
		sqtree[node]=tree[node]*tree[node];
		return;
	}
	update2(2*node,i,j,a,(a+b)/2,v);
	update2(2*node+1,i,j,(a+b)/2+1,b,v);
	sqtree[node]=sqtree[2*node]+sqtree[2*node+1];
}

long long int query(int node,int i,int j,int a,int b)
{
	if(a>b||a>j||i>b)
		return 0;
	if(a>=i && b<=j)
	{
		return sqtree[node];
	}
	
	long long int q1=query(2*node,i,j,a,(a+b)/2);
	long long int q2=query(2*node+1,i,j,(a+b)/2+1,b);
	return q1+q2;
}





int main()
{
    int t;
    scanf("%d",&t);
    int count=1;
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        build_tree(1,0,n-1);
        printf("Case %d:\n",count);
        count++;
        while(m--)
        {
            int x,y,z,a;
            scanf("%d",&x);
            if(x==0)
            {
                scanf("%d %d %d",&y,&z,&a);
                update2(1,y-1,z-1,0,n-1,a);
            }
            if(x==1)
            {
                scanf("%d %d %d",&y,&z,&a);
                update1(1,y-1,z-1,0,n-1,a);
            }
            else if(x==2)
            {
                scanf("%d %d",&y,&z);
                printf("%lld\n",query(1,y-1,z-1,0,n-1));
            }
        }
    }
    
    


return(0);    
}