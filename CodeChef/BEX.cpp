#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
using namespace std;
struct book
{
    int ex,topbooks;
    string name;
    book()
    {
        topbooks=0;
    }
};
int main() {
	long int t;
	stack<book> s;
	struct book b;
	scanf("%ld",&t);
	while(t--)
	{
	long int n;
	scanf("%ld",&n);
	if(n!=-1)
	{   string name;
	    cin>>name;
	    b.name=name;
	    b.ex=n;
	    if(n==0)
	     continue;
	    if(s.size()==0)
	    {
	        s.push(b);
	    }
	    else    
	    {
	        if((s.top()).ex>=b.ex)
	        {
	            s.push(b);
	            //(s.top()).topbooks++;
	        }
	        else
	        {
	            (s.top()).topbooks++;
	        }
	    }
	}
	else
	{   printf("%d ",(s.top()).topbooks);	    cout<<(s.top()).name<<"\n";
	    s.pop();
	}
	}
	return 0;
}
