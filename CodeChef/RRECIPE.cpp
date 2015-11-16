#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d",&t);
    char ch[1000002];
    long long int mod=10000009;
    while(t--)
    {   long long int res=1;
        scanf("%s",ch);
        if(strlen(ch)==1)
        {
            if(ch[0]=='?')
            res=26;
            else
            res=1;
        }
        else
        {
            long int len=strlen(ch);
            long int i;
            for(i=0;i<strlen(ch)/2;i++)
            {
                if(ch[i]=='?')
                {
                    if(ch[len-i-1]!='?')
                    {
                        res=res*1;
                    }
                    else
                    {
                        res=((res%mod)*(26))%mod;
                    }
                }
                else
                {
                    if(ch[len-i-1]=='?')
                    {
                        res=res*1;
                    }
                    else if(ch[i]!=ch[len-i-1])
                        res=0*res;
                }
            }
            if(len%2!=0)
            {
                if(ch[i]=='?')
                {
                    res=((res%mod)*(26%mod))%mod;
                }
                else
                {
                    res=res*1;
                }
            }
        }
        printf("%lld\n",res);
    }
	return 0;
}
