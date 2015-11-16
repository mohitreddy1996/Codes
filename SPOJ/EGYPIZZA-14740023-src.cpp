#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    int a=0,b=0,c=0;
    while(t--)
    {
        string str;
        cin>>str;
        if(str=="1/4")
            a++;
        if(str=="1/2")
            b++;
        if(str=="3/4")
            c++;
    }
    int count=1;

    if(a>=c)
        {
            a=a-c;
            count+=c;
            c=0;

        }
    else
        {
            c=c-a;
            count+=a;
            a=0;
        }
        if(c!=0)
        {
            count+=c;
            c=0;
            count+=(a/4);
            a=a%4;
            count+=(b/2);
            b=b%2;
            if(b==1)
            {
                count++;
                b=0;
                a=a-2;
            }
            if(a>0)
                count++;
        }
        else
        {
            count+=(a/4);
            a=a%4;
            count+=(b/2);
            b=b%2;
            if(b==1)
            {
                count++;
                b=0;
                a=a-2;
            }
            if(a>0)
                count++;

        }
        printf("%d",count);


    return 0;
}
