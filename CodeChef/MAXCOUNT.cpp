#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main(void) {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{ int count=0,marker,max=0;
	    int n;
	    cin>>n;
	    long int a[n];
	    for(int j=0;j<n;j++)
	    cin>>a[j];
	    std::sort(a,a+n);
	    marker=a[n-1];
	    for(int k=0;k<n;)
	    {
	        count=std::count(a+k,a+n,a[k]);
	        if(count>max)
	        {
	            max=count;
	            //if(a[k]<marker)
	            marker=a[k];
	        }
	        k=k+count;
	        
	    }
 cout<<marker<<" "<<max<<endl;
	    
	}
	return 0;
}
