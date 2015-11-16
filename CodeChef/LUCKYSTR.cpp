#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
    int k,n;
    char a[54][54],b[54];
    scanf("%d %d",&k,&n);
    for(int i=0;i<k;i++)
    {
        scanf("%s",a[i]);
    }
    for(int i=0;i<n;i++)
    {   int mark=1;
        scanf("%s",b);
        for(int i=0;i<k;i++)
        {   
            if(strlen(b)>=47)
            {
                printf("Good\n");
                mark=0;
                break;
            }
            else
            {
                
                if(strstr(b,a[i]))
                {
                    printf("Good\n");
                    mark=0;
                    break;
                }
            }
        }
        if(mark)
        printf("Bad\n");
    
    }
	return 0;
}
