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
long long int arr[200004];
struct Tree
{
    long long int first,second;
}tree[400008];

void build_tree(int node,int a,int b)
{
    if(a>b)
        return;
    if(a==b)
    {
        tree[node].first=arr[a];
        tree[node].second=-1;
        return;
        
    }
    
    build_tree(2*node,a,(a+b)/2);
    build_tree(2*node+1,(a+b)/2+1,b);
    tree[node].first=max(tree[2*node].first,tree[2*node+1].first);
    tree[node].second=min(max(tree[2*node].first,tree[2*node+1].second),max(tree[2*node].second,tree[2*node+1].first));
}

void update(int node,int a,int b,int i,int x)
{
    if(a>b||(a>i&&b>i)||(a<i && b<i))
        return;
    if(a==i && b==i)
    {
        tree[node].first=x;
        tree[node].second=-1;
        return;
    }
    update(2*node,a,(a+b)/2,i,x);
    update(2*node+1,(a+b)/2+1,b,i,x);
    tree[node].first=max(tree[2*node].first,tree[2*node+1].first);
    tree[node].second=min(max(tree[2*node].first,tree[2*node+1].second),max(tree[2*node].second,tree[2*node+1].first));
        
}

Tree query(int node,int a,int b,int i,int j)
{
    if(a>b||a>j||i>b)
    {
        Tree dum;
        dum.first=-1;
        dum.second=-1;
        return dum;
    }
    if(a>=i && b<=j)
    {
        return tree[node];
    }
    //cout<<i<<" "<<j<<"\n";
    Tree q1=query(2*node,a,(a+b)/2,i,j);
    Tree q2=query(2*node+1,(a+b)/2+1,b,i,j);
    Tree res;
    res.first=max(q1.first,q2.first);
    res.second=min(max(q1.first,q2.second),max(q2.first,q1.second));
    return res;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    int m;
    
    scanf("%d",&m);
    build_tree(1,0,n-1);
    while(m--)
    {
        char ch;
        
        
        cin>>ch;
        if(ch=='U')
        {
            int x,y;
            long long int r;
            scanf("%d %lld",&x,&r);
            update(1,0,n-1,x-1,r);
            //cout<<"U\n";
        }
        else if(ch=='Q')
        {
            int x,y;
            scanf("%d %d",&x,&y);
            Tree res=query(1,0,n-1,x-1,y-1);
            printf("%lld\n",(res.first+res.second));
            //cout<<"Q\n";
        }    
    }
    
    

return(0);    
}