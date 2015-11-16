#include <iostream>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int a[n+2],b[n+2];
	for(int i=1;i<=n;i++)
	{cin>>a[i];b[i]=a[i];}int k=1,i=1;
	int count=0;
	while(i<=n)
	{
	    if(b[i]==-1)
	    {
	        i++;
	       
	    }
	    else
	    {   
	        k=i;
	        int mark=b[k];
	        int mark1=b[k];
	       // cout<<k<<" ";
	        do
	        {
	            k=mark;
	            mark=b[k];
	            b[k]=-1;
	      //      cout<<k<<" ";
	            
	        }while(mark1!=mark);
	    //cout<<"\n";
	        i++;
	        count++;
	        
	    }
	    
	}
	cout<<count<<"\n";
	i=1;
	k=1;
	while(i<=n)
	{
	    if(a[i]==-1)
	    {
	        i++;
	    }
	    else
	    {   k=i;
	        int mark=a[k];
	        int mark1=a[k];
	       
	        cout<<k<<" ";
	        do
	        {
	            k=mark;
	            mark=a[k];
	            a[k]=-1;
	            cout<<k<<" ";
	            
	        }while(mark1!=mark);
	    cout<<"\n";
	        i++;
	    }
	    
	}
	return 0;
}
