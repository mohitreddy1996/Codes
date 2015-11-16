#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
int main() {
	        int t;
	        scanf("%d",&t);
	        char ch[100001];
	        while(t--)
	        {
	            scanf("%s",ch);
	            char dum1[]="010";
	            char dum2[]="101";
	            if(strstr(ch,dum1)||strstr(ch,dum2))
	            {
	                printf("Good\n");
	            }
	            else
	            {
	                printf("Bad\n");
	            }
	        }
		return 0;
}
