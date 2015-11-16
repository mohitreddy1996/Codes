#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    int n,k,l,c,d,p,nl,np;
    scanf("%d %d %d %d %d %d %d %d",&n,&k,&l,&c,&d,&p,&nl,&np);
    int min1=min(min((k*l)/nl,(c*d)),(p/np));
    printf("%d\n",(min1/n));
    
return(0);    
}