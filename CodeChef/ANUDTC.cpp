#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d",&t);
    char ch[3];
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char ch1='n',ch2='n',ch3='n';
		
		int res=360%n;
		
		if(res==0)ch1='y';
		if(n<=360)ch2='y';
		if((n*(n+1)/2)<=360)ch3='y';
		printf("%c %c %c",ch1,ch2,ch3);
		printf("\n");
    }
	return 0;
}
