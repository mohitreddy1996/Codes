#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    long long int n;
    cin>>n;
    long long int temp=9;
    long long int count1=1;
    long long int i=0;
    while(n>=temp)
    {
        i+=(count1*temp);
        n=n-temp;
        temp=temp*10;
        count1++;
    }
    i=i+count1*n;
    cout<<i;
    
        
    
return(0);    
}