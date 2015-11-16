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
#define inf -1000000000

int arr[100002];
struct Tree
{
    long long int left,right,sum,maxsum;
}tree[200006],y;



void build_tree(int node,int a,int b)
{
    if(a>b)
        return;
    if(a==b)
    {
        tree[node].left=tree[node].right=tree[node].sum=tree[node].maxsum=arr[a];
        return;
    }

    build_tree(2*node,a,(a+b)/2);
    build_tree(2*node+1,(a+b)/2+1,b);
    //cout<<node<<" "<<tree[2*node]<<" "<<tree[2*node+1]<<"\n";
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].left=max(tree[2*node].left,tree[2*node].sum+tree[2*node+1].left);
    tree[node].right=max(tree[2*node+1].right,tree[2*node+1].sum+tree[2*node].right);
    tree[node].maxsum=max(tree[node].left,max(tree[node].right,max(tree[2*node].maxsum,max(tree[2*node+1].maxsum,tree[2*node].right+tree[2*node+1].left))));
}

Tree query(int node,int a,int b,int i,int j)
{
    if(a>b||a>j||i>b)
       {
        y.left=inf,y.right=inf,y.sum=inf,y.maxsum=inf;
        return y;
    }
    if(a>=i && b<=j)
        return tree[node];

    Tree q1=query(2*node,a,(a+b)/2,i,j);
    Tree q2=query(2*node+1,(a+b)/2+1,b,i,j);
    Tree result;
    result.sum=q1.sum+q2.sum;
    result.left=max(q1.left,q1.sum+q2.left);
    result.right=max(q2.right,q2.sum+q1.right);
    result.maxsum=max(result.left,max(result.right,max(q1.maxsum,max(q2.maxsum,q1.right+q2.left))));
    return result;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int m;
    scanf("%d",&m);
    build_tree(1,0,n-1);
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%lld\n",query(1,0,n-1,x-1,y-1).maxsum);
    }

return(0);
}
