#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	 while(t--)
	 {
	   char ch1[101];
	   char ch2[101];
	   scanf("%s",ch1);
	   scanf("%s",ch2);
	   int count=0;
	   set<char> s;
	   for(int i=0;ch1[i]!='\0';i++)
	   {
	       s.insert(ch1[i]);
	   }
	   for(int i=0;ch2[i]!='\0';i++)
	   {
	       if(s.count(ch2[i]))
	        count++;
	   }
	   printf("%d\n",count);
	 }
	return 0;
}
