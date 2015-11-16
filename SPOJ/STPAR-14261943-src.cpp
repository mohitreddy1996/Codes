#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
	    break;
	    else
	    {   stack<int> s;
	        int a[n+1];
	        for(int i=0;i<n;i++)
	        {
	            scanf("%d",&a[i]);
	        }   
	        int k=1;
	        int mark=1;
	        for(int i=0;i<n;i++)
	        {
	            while(!s.empty()&&s.top()==k)
	            {
	                s.pop();
	                k++;
	            }
	            if(a[i]==k)
	            {
	                k++;
	            }
	            else if(!s.empty() && s.top()<a[i])
	            {
	                mark=0;
	                break;
	            }
	            else
	            {
	                s.push(a[i]);
	            }
	            
	        }
	        if(mark==1)
	        printf("yes\n");
	        else
	        printf("no\n");
	        
	       
	        
	    }
	}
	return 0;
}
