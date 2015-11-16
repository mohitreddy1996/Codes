#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string name;
        char ch;
        int count=0;
        map<string,char> m;
        while(n--)
        {
            cin>>name>>ch;
            m[name]=ch;
        }
        for(map<string,char>::iterator it=m.begin(); it!=m.end() ; it++)
        {
            if((*it).second=='+')
            count++;
            else
            count--;
        }
        printf("%d\n",count);
    }
	return 0;
}
