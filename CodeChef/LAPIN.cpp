#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
//	char l[1002],r[1002];
	char s[1002];
	while(t--)
	{
	    scanf("%s",s);
	    int len=strlen(s);
	    int k=0;
	    int i;
	    char l[(len/2)+1],r[(len/2)+1];
	    if(len%2==0)
	    {
	        for(i=0;i<len/2;i++)
	         l[i]=s[i];
	        for(int j=len/2;j<len;j++)
	         r[k++]=s[j];
	        std::sort(l,l+i);
	        std::sort(r,r+k);
	        l[i]='\0';
	        r[i]='\0';
	        //cout<<l<<"\n"<<r<<"\n";
	        if(strcmp(l,r)==0)
	        cout<<"YES\n";
	        else
	        cout<<"NO\n";
	    }
	    else
	    {
	      for(i=0;i<len/2;i++)
	       l[i]=s[i];
	      for(int j=(len/2)+1;j<len;j++)
	       r[k++]=s[j];
	       l[i]='\0';
	       r[k]='\0';
	      std::sort(l,l+i);
	      std::sort(r,r+k);
	      //cout<<l<<"\n"<<r<<"\n";
	      if(strcmp(l,r)==0)
	      cout<<"YES\n";
	      else
	      cout<<"NO\n";
	    } 
	    
	}
	
	
	return 0;
}
