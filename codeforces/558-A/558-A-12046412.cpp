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

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int> > v1;
    vector<pair<int,int> > v2;
    while(n--)
    {
        int x,a;
        scanf("%d %d",&x,&a);
        
        if(x>=0)
        {
            v1.push_back(make_pair(x,a));
        }
        else
        {
            v2.push_back(make_pair(x,a));
        }
    }    
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        
        int k,l;
        int count=0;
        int prev;
        if(v1.size()>v2.size())
        {
            count+=v1[0].second;
            k=1;
            l=0;
            prev=1;
        }
        else
        {
            //cout<<v2[0].first<<" ";
            count+=v2[0].second;
            l=1;k=0;
            prev=0;
        }
        //cout<<k<<" "<<l;
        //cout<<count<<" ";
        while(k<v1.size()&& l<v2.size())
        {
            if(prev==0)
            {
                count+=v1[k++].second;
                prev=1;
            }
            else
            {
                count+=v2[l++].second;
                prev=0;
            }
            //cout<<count<<" ";
        }
        if(prev==0 && k<v1.size())
            count+=v1[k].second;
        if(prev==1 && l<v2.size())    
            count+=v2[l].second;
        printf("%d",count);
    
    
    


return(0);    
}