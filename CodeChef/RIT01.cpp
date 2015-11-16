#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
 
int main()
{
    int n;
    char ch[100005];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",ch);
        int len=strlen(ch);
        long int count1=0;
        char top=ch[0];
        for(int i=0;i<len;i++)
        {
            if(top==ch[i])
                count1++;
        }
        if(count1==len)
        {
                printf("%ld\n",len-1);
        }
        else
        {   
            count1=0;
            for(int i=0;i<len;)
            {   
                if(ch[i]=='X')
                {   i++;
                     while(i<len&&ch[i]!='Y')
                    {
                      i++;    
                      count1++;
                         if(i>=len)
                               break;
                    
                     }
                }
                else
                {   i++;
                    while(i<len&&ch[i]!='X')
                    {
                     i++;
                        count1++;
                        if(i>=len)
                            break;
                    }
                }
            }
            printf("%ld\n",count1);
        }
    }
return(0);    
}
