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

int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long long int c;
            scanf("%lld",&c);
            int count1=0;
            while(c%2==0)
            {
                c=c/2;
                count1++;

            }
            vector<pair<int,int> > v;
            v.push_back(make_pair(2,count1));
            count1=0;
            for(long long int i=3;i<=sqrt(c);i++)
            {
                count1=0;
                while(c%i==0)
                {
                    c=c/i;
                    count1++;
                }
                if(count1!=0)
                v.push_back(make_pair(i,count1));

            }
            if(c!=0)
            {
                v.push_back(make_pair(c,1));
            }
            int ans=0;
            int flag=0;
            for(int i=0;i<v.size();i++)
            {
                int x=v[i].first;
                int y=v[i].second;
                if(x%4==3)
                {
                    if(y%2==1)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }



        }

return(0);
}
