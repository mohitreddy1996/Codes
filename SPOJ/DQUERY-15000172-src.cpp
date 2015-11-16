#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <set>
#include <algorithm>
#define len 1e5
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;
int a[311111];
int count1[1111111];
int ans[311111];
#define block 555
struct node
{
    int L,R,ind;
}tree[311111];

bool cmp(struct node x,struct node y)
{
    if(x.L/block != y.L/block)
    {
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}
int ans1=0;
void add(int pos)
{
    count1[a[pos]]++;
    if(count1[a[pos]]==1)
    {
        ans1++;
    }
}
void remove(int pos)
{
    count1[a[pos]]--;
    if(count1[a[pos]]==0)
    {
        ans1--;
    }
}

int main() {

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanint(a[i]);
    }
    int q;
    scanint(q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanint(l);
        scanint(r);
        tree[i].L=(--l);
        tree[i].R=(--r);
        tree[i].ind=i;
    }

    sort(tree,tree+q,cmp);

    int currentL=0,currentR=0;

    for(int i=0;i<q;i++)
    {
        int L=tree[i].L;
        int R=tree[i].R;
        while(currentL<L)
        {
            remove(currentL);
            currentL++;
        }
        while(currentL>L)
        {
            add(currentL-1);
            currentL--;
        }
        while(currentR>R+1)
        {
            remove(currentR-1);
            currentR--;
        }
        while(currentR<=R)
        {
            add(currentR);
            currentR++;
        }
        ans[tree[i].ind]=ans1;
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
	return 0;
}

