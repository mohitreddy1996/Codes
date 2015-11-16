#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    while(1)
    {
        char ch[5];
        scanf("%s",ch);
        if(ch[0]=='0'&&ch[1]=='0'&&ch[3]=='0')
            break;
        long long int res=0;    
        if(ch[0]!='0')
            res=(ch[0]-'0')*10;
        if(ch[1]!='0')
            res=res+(ch[1]-'0');
        
        
        int k=(ch[3]-'0');
        while(k--)
        {
            res=res*10;
        }
        
        long long int ans;
        long long int c=1;
        while(c<=res)
        	c=c<<1;
        ans=((res-(c>>1))<<1)+1;
        cout<<ans<<"\n";
        
    }
return(0);    
}
