#include<stdio.h>
int main()
{
	long int t;
	scanf("%ld",&t);
	long int n,k;
	char a[100005];
	char b[100005];
	char c[100005];
	char mark;
	long int count,count1;
	while(t--)
	{	count=0,count1=0;
		scanf("%ld %ld",&n,&k);
		scanf("%s",a);	
		if(k!=1)
		{	
			for(int i=0;i<n;)
			{       count1=0;
				int mark1=i;
				mark=a[i];
				while(mark==a[i])		
				{
					count1++;
					i++;
				}
				while(count1>k)
				{
					if(count1==(2*k+1))
					{
						if(a[mark1+k]=='1')
						{
							a[mark1+k]='0';
							count++;
							
						}
						else
						{
							a[mark1+k]='1';
							count++;
							
						}
						//i=i+2*k+1;
						count1=count1-2*k-1;
						
					}
					else					
					{
						if(count1==k+1)
						{
							if(a[mark1+k-1]=='1')
							{
								a[mark1+k-1]='0';
								count++;
								
							}
							else
							{
								a[mark1+k-1]='1';
								count++;
								
							}
							count1=count1-k-1;
							//i=i+k+1;
						}
						else
						{
							if(a[mark1+k]=='1')
							{
								a[mark1+k]='0';
								count++;
								
							}
							else
							{
								a[mark1+k]='1';
								count++;
								
							}
							//i=i+k+1;
							count1=count1-k-1;
							mark1=mark1+k+1;
						}
					}
				}
			}
			printf("%ld\n%s\n",count,a);				
		}
		else
		{	
			
			char flag='0';
			for(int i=0;i<n;i++)
			{	
				b[i]=flag;
				if(flag=='0')
					flag='1';
				else
					flag='0';
			}
			b[n]='\0';
			flag='1';
			for(int i=0;i<n;i++)
			{	
				c[i]=flag;
				if(flag=='0')
					flag='1';
				else
					flag='0';
			}
			 c[n]='\0';
			long int x1=0;
			long int x2=0;
			for(int i=0;i<n;i++)
			{
				x1+=(a[i]^b[i]);
				x2+=(a[i]^c[i]);
			}
			if(x1<x2)
				printf("%ld\n%s\n",x1,b);
			else
				printf("%ld\n%s\n",x2,c);
			
		}
		
	}
 
return(0);
 
}
