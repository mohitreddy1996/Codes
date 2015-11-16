#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
 
int main() {
	int t;
	long int n;
	long int temp;
	scanf("%d",&t);
	
	while(t--)
	{   set<long int> s;
	    scanf("%ld",&n);
	    while(n--)
	    {
	        scanf("%ld",&temp);
	        s.insert(temp);
	    }
	    printf("%ld\n",s.size());
	}
	return 0;
}
