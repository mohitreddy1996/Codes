#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int t;
   string ch;
   cin>>t;
   int m;
   while(t--)
   {    cin>>m;
       cin>>ch;
       int a[8]={0};
       
       for(int i=0;i<=37;i++)
       {    string str;
           str=ch.substr(i,3);
           
            if(str=="TTT")
                a[0]++;
            else if(str=="TTH")
                a[1]++;
            else if(str=="THT")
                a[2]++;
            else if(str=="THH")  
                a[3]++;
            else if(str=="HTT")  
                a[4]++;
            else if(str=="HTH")  
                a[5]++;
            else if(str=="HHT")    
                a[6]++;
            else if(str=="HHH")  
                a[7]++;
                
            str.clear();    
       }
       cout<<m<<" ";
       for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
        cout<<"\n";    
   }
   
return(0);    
}
 