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
int pr[100002];
int isprime(int i)
{
    if(i%2==0)
        return 0;
    for(int j=3;j<=(i/2);j+=2)
    {
        if(i%j==0)
            return 0;
    }
    return 1;
}
void prime()
{
    for(int i=1000;i<=10000;i++)
    {
        pr[i]=isprime(i);
    }
}
struct node
{
    int val;
    int pos;
};

int dig[50];

void getrem(int n)
{
   dig[1]=n%10;
   dig[2]=(n%100)/10;
   dig[3]=(n%1000)/100;
   dig[4]=(n%10000)/1000;
}   
int main()
{
   int t;
   int n,m;
   
   scanf("%d",&t);
   prime();
   while(t--)
   {
       scanf("%d %d",&n,&m);
       int mark=0;
       int ans;
       node n1;
       n1.val=n;
       n1.pos=0;
       int visited[10004];
       for(int i=0;i<=10000;i++)
            visited[i]=0;
       queue<node> q;
       q.push(n1);
       if(n==m)
        {
            printf("0\n");
            continue;
        }
       while(1)
       {
        node w=q.front();
        if(q.empty()==false)
            q.pop();
        getrem(w.val);
        visited[w.val]=1;
        for(int i=1;i<=4;i++)
        {
           int temp=w.val-(dig[i]*pow(10.0,i-1));
           //cout<<"temp: "<<temp<<"\n";
           for(int j=0;j<=9;j++)
           {
               int temp1=temp+(j*pow(10.0,i-1));
               //cout<<"temp1: "<<temp1<<"\n";
               if(temp1==m)
               {
                   mark=1;
                   ans=w.pos;
                   break;
               }
               if(temp1<1000 || pr[temp1]==0 || visited[temp1])
                    continue;
                visited[temp1]=1;    
                node l;
                l.val=temp1;
                l.pos=w.pos+1;
                q.push(l);
                
           }
           if(mark)
            break;
        }
        if(mark)
            break;
        }
        printf("%d\n",ans+1);
   }    
    
    


return(0);    
}