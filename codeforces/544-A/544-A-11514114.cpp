#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <string.h>
#include <string>
#include <vector>
using namespace std;


int main()
{
    int k;
    scanf("%d",&k);
    char ch[105];
    scanf("%s",ch);
    int len=strlen(ch);
    char c[27]={0};
    int count1=0;
    for(int i=0;ch[i]!='\0';i++)
    {
        c[ch[i]-'a']++;
        if(c[ch[i]-'a']>1)
            count1++;
    }
    if(k>(len-count1))
        printf("NO");
    else
        {
            int i=0;
            cout<<"YES\n";
            vector<char> v;
            
            while(k)
            {
                v.push_back(ch[i]);
                string l;
                l=l+ch[i];
                i++;
                while(find(v.begin(),v.end(),ch[i])!=v.end())
                {
                    l=l+ch[i];
                    i++;
                }
                if(k==1)
                {
                    while(ch[i]!='\0')
                        l=l+ch[i++];
                }
                cout<<l<<"\n";
                k--;
            }
            
        }
    
return(0);    
}