#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int s1,s2,e1,e2,b1,b2;
        scanf("%d %d %d %d %d %d",&s1,&s2,&e1,&e2,&b1,&b2);
        int  steps=(abs(e1-s1)+abs(e2-s2));
        int steps_b=abs(s1-b1)+abs(s2-b2);
        if((b1==e1&&s1==b1)||(b2==e2&&b2==s2))
        {
            if(steps_b<=steps)
            steps=steps+2;
        }
        printf("%d\n",steps);
           
    
    }
return(0);    
}
