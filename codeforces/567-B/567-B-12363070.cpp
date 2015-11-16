#include <iostream>
#include <stdio.h>
#include <set>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    set<int> s;
    set<int>::iterator it=s.begin();
    char ch;
    int num;
    int max1=0;
    int ans=0;
    int mark=0;
    while(n--)
    {
        cin>>ch>>num;
        if(ch=='+')
        {
           s.insert(num);
           
        }
        else
        {
           if(s.find(num)==s.end())
           {
               mark=1;
           }
           else
           {
               s.erase(s.find(num));
           }
       
           
        }
        if(mark==1)
        {
            ans++;
            mark=0;
        }
        else
        {
            int k=s.size();
            ans=max(ans,k);
        }
       
    }
    printf("%d\n",ans);
}