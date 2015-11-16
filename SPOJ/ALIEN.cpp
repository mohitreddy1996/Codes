#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    long int a[100005];
    long int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&m);
        for(long int i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
        }
        long int pos=0,res=0,x=0,resn=0,resm=0;
        for(long int j=0;j<n;j++)
        {
            
            if((a[j]+res)<=m)
            {
                res=res+a[j];
                pos++;
                
            }
            else
            {   
                while((a[j]+res)>m)
                {
                    res=res-a[x];
                    x++;
                    pos--;
                }
                res=res+a[j];
                pos++;
            }
            
            if(pos>=resn)
            {
                if(pos==resn)
                {
                    if(res<=resm)
                        resm=res;
                }
                else
                {
                    resn=pos;
                    resm=res;
                }
            }
            
            
        }
        printf("%ld %ld\n",resm,resn);
    }
    
    
return(0);    
}
