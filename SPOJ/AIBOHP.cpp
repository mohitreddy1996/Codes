#include <algorithm>
#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int t;
    char ch[10000],s[10000];
    static int S[6420][6420];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",ch);
        int len=strlen(ch);
        
        int k=0;
        for(int i=len-1;i>=0;i--)
        {
            s[k++]=ch[i];
        }
        
        for(int i=0;i<=len;i++)
        {
            for(int j=0;j<=len;j++)
            {
                if(i==0||j==0)
                    S[i][j]=0;
                else if(ch[i-1]==s[j-1])
                    S[i][j]=S[i-1][j-1]+1;
                else
                    S[i][j]=max(S[i-1][j],S[i][j-1]);
            }
        }
        int ans=len-S[len][len];
        printf("%d\n",ans);
    }
return(0);    
}
