#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
 
int main() {
        int t,n;
        scanf("%d",&t);
        char ch[1002];
        while(t--)
        {
            scanf("%d",&n);
            
                scanf("%s",ch);
            
            int counti=0,county=0,countn=0;
            for(int i=0;ch[i]!='\0';i++)
            {
                if(ch[i]=='I')
                {
                    counti++;
                }
                else if(ch[i]=='Y')
                {
                    county++;
                }
                else
                {
                    countn++;
                }
            }
            if(countn==n)
            {
                printf("NOT SURE\n");
            }
            else if(counti>0)
            {
                printf("INDIAN\n");
            }
            else
            {
                printf("NOT INDIAN\n");
            }
            
        }
	return 0;
}
