#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
 
int main() {
	int t;
	int n;
	scanf("%d",&t);
	
	while(t--)
	{   int temp;
	    set<int> s;
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&temp);
	        s.insert(temp);
	    }
	    int fr=s.size();
	    printf("%d\n",fr);
	}
	return 0;
}
