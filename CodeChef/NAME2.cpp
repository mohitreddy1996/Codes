#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	char m[25001],w[25001];
	while(t--)
	{
	    
	    scanf("%s %s",m,w);
	    if(strlen(m)<strlen(w))
	    {
	        int i;        
	            for(i=0;w[i]!='\0';i++)
	            {
	                if(w[i]==m[0])
	                break;
	            }
	            int k=1;
	            int count=1;
	            if(i==strlen(w))
	            printf("NO\n");
	            else
	            {
	                for(int j=i+1;w[j]!='\0';j++)
	                {
	                    if(m[k]==w[j])
	                    {
	                        k++;
	                        count++;
	                        
	                    }
	                }
	                if(count==strlen(m))
	                printf("YES\n");
	                else
	                printf("NO\n");
	            }
	        
	    }
	    else if(strlen(m)>strlen(w))
	    {
	        int i;        
	            for(i=0;w[i]!='\0';i++)
	            {
	                if(m[i]==w[0])
	                break;
	            }
	            if(i==strlen(m))
	                printf("NO\n");
	            else
	            {
	            int k=1;
	            int count=1;
	            
	                for(int j=i+1;m[j]!='\0';j++)
	                {
	                    if(w[k]==m[j])
	                    {
	                        k++;
	                        count++;
	                        
	                    }
	                }
	                if(count==strlen(w))
	                printf("YES\n");
	                else
	                printf("NO\n");
	            
	            }
	        
	    }
	    else
	    {
	        if(strcmp(m,w)==0)
	        {
	            printf("YES\n");
	        }
	        else
	        {
	            printf("NO\n");
	        }
	    }
	}
	    
	
	return 0;
}
