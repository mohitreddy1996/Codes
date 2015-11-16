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
            res=ch[0]-'0';
        if(ch[1]!='0')
            res=res*10+(ch[1]-'0');
        int k=(ch[3]-'0');
        while(k--)
        {
            res=res*10;
        }
        
        long long int ans;
        long int q=log2(res);
        q=pow(2,q);
        ans=2*(res-q)+1;
        cout<<ans<<"\n";
    }
return(0);    
}
