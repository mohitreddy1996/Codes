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
char ch[30001];
struct Tree
{
    int left,right;
}tree[100002];

void build_tree(int node,int a,int b)
{
    if(a>b)
        return;
    if(a==b)
    {
        if(ch[a]=='(')
        {
            tree[node].left=1;
            tree[node].right=0;
        }
        else
        {
            tree[node].left=0;
            tree[node].right=1;
        }
        return;
    }
    build_tree(2*node,a,(a+b)/2);
    build_tree(2*node+1,(a+b)/2+1,b);
    int num=min(tree[2*node].left,tree[2*node+1].right);
    tree[node].left=tree[2*node].left+tree[2*node+1].left-num;
    tree[node].right=tree[2*node].right+tree[2*node+1].right-num;
    
}

void update(int node,int a,int b,int x)
{
    if(a>b || (x>a && x>b ) || (x<a && x<b))
        return;
        
    if(a==x && b==x)
    {
        tree[node].left=1-tree[node].left;
        tree[node].right=1-tree[node].right;
        return;
    }
    
    update(2*node,a,(a+b)/2,x);
    update(2*node+1,(a+b)/2+1,b,x);
    int num=min(tree[2*node].left,tree[2*node+1].right);
    tree[node].left=tree[2*node].left+tree[2*node+1].left-num;
    tree[node].right=tree[2*node].right+tree[2*node+1].right-num;
    
}



int main()
{
    int t=10;
    int count=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        scanf("%s",ch);
        int m;
        scanf("%d",&m);
        printf("Test %d:\n",count);
        count++;
        build_tree(1,0,n-1);
        while(m--)
        {
            int x;
            scanf("%d",&x);
            if(x==0)
            {
                if(tree[1].left==0 && tree[1].right==0)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                if(ch[x-1]=='(')
                    ch[x-1]=')';
                else
                    ch[x-1]='(';
                update(1,0,n-1,x-1);    
            }
        }
    }
    
    


return(0);    
}