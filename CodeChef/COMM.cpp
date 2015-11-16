#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int r;
	    cin>>r;
	    int d=0;
	    int x1,x2,x3,y1,y2,y3;
	    cin>>x1>>y1>>x2>>y2>>x3>>y3;
	    if(r*r>=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)))
	     d=d+1;
	    if(r*r>=((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)))
	     d=d+1;
	    if(r*r>=((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))
	     d=d+1;
	    if(d>=2)
	    cout<<"yes"<<endl;
	    else
	    cout<<"no"<<endl;
	     
	}
	return 0;
}
