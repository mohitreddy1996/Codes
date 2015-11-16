#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{   while(1)
    {
        long int n1,n2;
        scanf("%ld",&n1);
        long int a[10003],b[10003];
        if(n1!=0)
        {
            for(int i=0;i<n1;i++)
            {
                scanf("%ld",&a[i]);
            }
            scanf("%ld",&n2);
            for(int i=0;i<n2;i++)
            {
                scanf("%d",&b[i]);
            }
            long long int L[max(n1,n2)+2]={0};
            long long int R[max(n1,n2)+2]={0};
            long int h=1,k=1;
            for(long int i=0,j=0;i<n1||j<n2;)
            {
                if(i>=n1)
                {
                    while(j<n2)
                    {
                        R[k]=R[k-1]+b[j];
                        j++;
                        k++;
                    }
                }
                else if(j>=n2)
                {
                    while(i<n1)
                    {
                        L[h]=L[h-1]+a[i];
                        i++;
                        h++;
                    }
                }
                else if(a[i]>b[j])
                {
                    R[k]=R[k-1]+b[j];
                    j++;
                    k++;
                }
                else if(a[i]<b[j])
                {
                    L[h]=L[h-1]+a[i];
                    i++;
                    h++;
                }
                else if(a[i]==b[j]&&i<n1&&j<n2)
                {
                    L[h]=L[h-1]+a[i];
                    R[k]=R[k-1]+b[j];
                    L[h]=R[k]=max(L[h],R[k]);
                    h++,k++,i++,j++;
                }
            }
            printf("%lld\n",max(L[h-1],R[k-1]));
            
        }
        else
        {
            break;
        }
    }
return(0);    
}