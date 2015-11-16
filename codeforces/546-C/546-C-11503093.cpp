#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int n;
    int k1,k2;
    cin>>n;
    cin>>k1;
    int temp;
   queue<int> q1;
   queue<int> q2;
    for(int i=0;i<k1;i++)
    {
        cin>>temp;
        q1.push(temp);
    }


    cin>>k2;
    for(int i=0;i<k2;i++)
    {
        cin>>temp;
        q2.push(temp);
        
    }
    
    int k=0;
    while((!q1.empty())&&(!q2.empty())&&(k<=(1000)))
    {
        if(q1.front()>q2.front())
        {
            temp=q2.front();
            q2.pop();
            q1.push(temp);
            temp=q1.front();
            q1.pop();
            q1.push(temp);
        }
        else
        {
             temp=q1.front();
            q1.pop();
            q2.push(temp);
            temp=q2.front();
            q2.pop();
            q2.push(temp);
        }
        k++;
    }
    if(q1.empty())
    {
        cout<<k<<" "<<"2";
    }
    else if(q2.empty())
    {
        cout<<k<<" "<<"1";
    }
    else
    {
        cout<<"-1";
    }
    
return(0);    
}