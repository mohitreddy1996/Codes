#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{int t;
scanf("%d",&t);
while(t--)
 {int n;
  scanf("%d",&n);
  char a[1005]={0};
  int b[1005]={0};
  scanf("%s",a);
  int i;
  for(i=1;i<n-1;i++)
   {if(a[i]=='1')
    {b[i]=1;
     b[i-1]=1;
     b[i+1]=1;
    }
   }
  if(a[0]=='1') 
   {b[0]=1; b[1]=1; }
  if(a[n-1]=='1')
   {b[n-2]=1; b[n-1]=1;}
  int ans=0;
  for(i=0;i<n;i++)
   if(b[i]==0)
    ans++;
  printf("%d\n",ans);
     
	}
	return 0;
}
