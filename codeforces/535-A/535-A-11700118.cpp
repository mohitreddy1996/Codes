#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int m=n;
    int count=0;
    int i=0;
    int a[2];
    a[1]=a[0]=0;
    do
    {
        a[i++]=m%10;
        m=m/10;
        count++;
        
    }while(m);
   
        if(a[1]==1)
        {
            if(a[0]==0)
                printf("ten");
            if(a[0]==1)
                printf("eleven");
            if(a[0]==2)
                printf("twelve");
            if(a[0]==3)
                printf("thirteen");
            if(a[0]==4)
                printf("fourteen");
            if(a[0]==5)
                printf("fifteen");
            if(a[0]==6)
                printf("sixteen");
            if(a[0]==7)
                printf("seventeen");
            if(a[0]==8)
                printf("eighteen");
            if(a[0]==9)
                printf("nineteen");
            
                
        }
        else if(a[1]==2)
        {
            printf("twenty");
                
        }
        else if(a[1]==3)
        {
            printf("thirty");
        }
        else if(a[1]==4)
        {
            printf("forty");
        }
        else if(a[1]==5)
        {
            printf("fifty");
        }
        else if(a[1]==6)
        {
            printf("sixty");
        }
        else if(a[1]==7)
        {
            printf("seventy");
            
        }
        else if(a[1]==8)
        {
            printf("eighty");
        }
        else if(a[1]==9)
        {
            printf("ninety");
        }
    
    if(a[1]!=0&&a[0]!=0&&a[1]!=1)
    {   printf("-");
        if(a[0]==1)
            printf("one");
        if(a[0]==2)
            printf("two");
        if(a[0]==3)
            printf("three");
        if(a[0]==4)
            printf("four");
        if(a[0]==5)
            printf("five");
        if(a[0]==6)
            printf("six");
        if(a[0]==7)
            printf("seven");
        if(a[0]==8)
            printf("eight");
        if(a[0]==9)
            printf("nine");
        
    }
    else
    {
        if(a[1]==0)
        {
        if(a[0]==1)
            printf("one");
        if(a[0]==2)
            printf("two");
        if(a[0]==3)
            printf("three");
        if(a[0]==4)
            printf("four");
        if(a[0]==5)
            printf("five");
        if(a[0]==6)
            printf("six");
        if(a[0]==7)
            printf("seven");
        if(a[0]==8)
            printf("eight");
        if(a[0]==9)
            printf("nine");
        if(a[0]==0)
            printf("zero"); 
        }
    }

return(0);    
}