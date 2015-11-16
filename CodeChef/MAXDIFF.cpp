#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
int main() {
int t;
int n,k;
scanf("%d",&t);
long int a[101];
while(t--)
{
scanf("%d %d",&n,&k);
for(int i=0;i<n;i++)
{
scanf("%ld",&a[i]);
}
sort(a,a+n);
if(k<=n/2)
{
long int count1=0;
for(int i=0;i<k;i++)
{
count1+=a[i];
}
long int count2=0;
for(int i=k;i<n;i++)
{
count2+=a[i];
}
printf("%ld\n",abs(count2-count1));
}
else
{
    long int count1=0;
    for(int i=0;i<n-k;i++)
    {
        count1+=a[i];
    }
    long int count2=0;
    for(int i=n-k;i<n;i++)
    {
        count2+=a[i];
    }
    printf("%ld\n",abs(count2-count1));
}
}
return 0;
}
