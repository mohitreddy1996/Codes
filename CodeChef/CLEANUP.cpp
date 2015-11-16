#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
      int t;
      int m,n;
      cin>>t;
      for(int i=0;i<t;i++)
      {
          cin>>n>>m;
          int a[m];
          int chef[n],assis[n];
          for(int j=0;j<m;j++)
          cin>>a[j];
          std::sort(a,a+m);
          int k=0,l=0,z=0;
          int q=1;
          int flag=1;
          while(q<=n)
          {
              if(q==a[z])
          {z++;q++;}
          else if(flag==1)
          {
              chef[k++]=q;
              q++;
              flag=0;
          }
          else
          {
              assis[l++]=q;
              q++;
              flag=1;
          }
          
          
      }
      std::sort(chef,chef+k);
      std::sort(assis,assis+l);
      if(k==0)
      cout<<endl;
      else{
      for(int j=0;j<k;j++)
      cout<<chef[j]<<" ";
      cout<<endl;}
      if(l==0){cout<<endl;}
      else {
      for(int j=0;j<l;j++)
      cout<<assis[j]<<" ";
	  cout<<endl;}
      } 
	return 0;
}
