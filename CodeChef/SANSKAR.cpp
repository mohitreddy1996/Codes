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
 
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,z;
        scanf("%d %d",&n,&z);
        long long int a[n+1];
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        if(sum%z!=0)
        {
            printf("no\n");
            continue;
        }
        if(sum==0)
        {
            printf("yes\n");
            continue;
        }
        if(n<z)
		{
			int flag = 0;
			
			for(int i=0; i<z; i++)
			{
				if(a[i]!=0)
				{
					flag = 1;
					break;
				}
			}
			
			if(flag==0)
				printf("yes\n");
			
			else
				printf("no\n");
			
			continue;
		}
		
		if(n==z)
		{
			int flag = 0;
			
			for(int i=0; i<n-1; i++)
			{
				if(a[i]!=a[i+1])
				{
					flag = 1;
					break;
				}
			}
			
			if(flag==0)
				printf("yes\n");
			
			else
				printf("no\n");
			
			continue;
		}
        long long l=(1<<n);
        sum=sum/z;
        int count1=0;
        vector<int> v;
        for(long long int i=1;i<=l;i++)
        {   
            int mark=1;
            int k=n-1;
            long long int sum1=0;
            long long int temp=i;
            while(temp)
            {
                if(temp%2)
                {
                    if(a[k]==-1)
                    {
                        mark=0;
                        break;
                    }
                    sum1+=a[k];
                    v.push_back(k);
                }
                k--;
                temp=temp/2;
            }
           
            if(sum1==sum&&mark)
            {
                count1++;
                for(int j=0;j<v.size();j++)
                    a[v[j]]=-1;
 
            }
            v.clear();
        }
        if(count1==z)
            printf("yes\n");
        else
            printf("no\n");
    }
 
 
 
return(0);    
} 
