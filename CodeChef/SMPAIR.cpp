#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  long int t;
 cin>>t;
 for(long int i=0;i<t;i++)
 {
  long int n;
  cin>>n;
  long int a[n];
  for(long int j=0;j<n;j++)
  cin>>a[j];
  std::sort(a,a+n);
  cout<<(a[0]+a[1])<<"\n";
  }
  return(0);
  }
