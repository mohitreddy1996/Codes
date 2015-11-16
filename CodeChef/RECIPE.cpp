#include <iostream>
#include <algorithm>
using namespace std;
 
int gcd(int num1,int num2)
{   int temp;
     while(num1!=num2)
    {
        if(num1>num2)
            num1-=num2;
        else
            num2-=num1;
    }
    return(num1);
}
int main(void) {
	int t;
  cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    for(int j=0;j<n;j++)
	    {
	        cin>>a[j];
	        b[j]=a[j];
	    }
	    std::sort(b,b+n);
	    int mark=b[0];
	    for(int j=1;j<n;j++)
	    {
	        mark=gcd(mark,b[j]);
	        
	    }
	    
	    for(int j=0;j<n;j++)
	    {
	        a[j]=(a[j]/mark);
	        cout<<a[j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
