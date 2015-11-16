#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
 
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    char ch[204];
            
	    cin>>ch;
	    //cout<<ch<<endl;
	    int len;
	    len=strlen(ch);
	    std::sort(ch,ch+len);
	    int j=0;
	    int count,count1=0;
	    while(j<len)
	    {
	    count=std::count(ch,ch+len,ch[j]);
	    j=j+count;
	    if(count%2==0)
	    {
	        count1=count1+(count/2);
	    }
	    else
	        count1=count1+(count/2)+1;
	    }
	
	    cout<<count1<<endl;
	}
	
	return 0;
}
