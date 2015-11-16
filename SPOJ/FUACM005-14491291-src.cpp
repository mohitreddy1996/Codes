#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    char ch[100];
    char s;
    int count=0;
    scanf("%s",ch);
    cin>>s;
    for(int i=0;ch[i]!='\0';i++)
        {if(ch[i]==s)
            count++;
    }
    printf("%d",count);
return(0);    
}