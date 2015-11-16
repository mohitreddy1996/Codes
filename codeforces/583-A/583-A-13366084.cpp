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
#define inf 1e9
#define inf 1000000000
#define pii pair<int,int>



int main()
{
   int n;
   scanf("%d",&n);
   vector<int> v[2502];
    for(int i=0;i<n*n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[i].push_back(x);
        v[i].push_back(y);
    }
    int hvis[2502],vvis[2502];
    memset(hvis,0,sizeof(hvis));
    memset(vvis,0,sizeof(vvis));
    for(int i=0;i<n*n;i++)
    {

        if(hvis[v[i][0]]==0 && vvis[v[i][1]]==0)
        {
            //mark=1;
            hvis[v[i][0]]=1;
            vvis[v[i][1]]=1;
            printf("%d ",i+1);
        }

    }




   return 0;
}