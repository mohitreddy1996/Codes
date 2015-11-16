#include <algorithm>
#include <stdio.h>
#include <map>
#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{   
    char ch[2002];
    int count=0;
    while(1)
    {
        scanf("%s",ch);
        if(ch[0]=='-')
            break;
        int ans=0;
        int left=0;
        int right=0;
        for(int i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='{')
            {
                left++;
            }
            else 
            {
                if(ch[i]=='}'&&left==0)
                {
                    left++;
                    ans++;
                }
                else
                {
                    left--;
                }
            }
        }
        count++;
        ans=ans+(left/2);
        printf("%d. %d\n",count,ans);
        
    }
    
    

return(0);    
}