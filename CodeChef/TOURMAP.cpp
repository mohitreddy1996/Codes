#include <iostream>
#include<stdio.h>
#include <map>
#include <utility>
#include<string.h>
#include<stdlib.h>
#include <string>
#include<bits/stdc++.h>
using namespace std;
long int sum=0;
string temp1,temp2,temp3;
string dummy;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {  
        sum=0;
	    int n;
	    cin>>n;
	    map<string,pair<string,string> > m;
	    map<string,int> m2;
	    pair<string,string> p;
	
	    for(int i=0;i<n-1;i++)
	    {
		    cin>>temp1>>temp2>>temp3;
		    p.first=temp2;
		    p.second=temp3;
	    	m[temp1]=p;
		    m2[temp2]=1;
	    }
	
	
	    for(map<string,pair<string,string> >::iterator it=m.begin(); it!=m.end(); ++it)
	    {
	        if(m2[it->first]==0)
	        {
	            dummy=it->first;
	            break;
	        }
	    }
	  
	
	    for(int i=0;i<n-1;i++)
	    {
	        p=m[dummy];
	        cout<<dummy<<" "<<p.first<<" "<<p.second<<"\n";
	        int z=0;
			for(int j=0;p.second[j]!='$';j++)
				z=z*10+(p.second[j]-'0');
			sum+=z;	
	        dummy=p.first;
	    }
	    printf("%ld$\n",sum);
    }	
return(0);
}
