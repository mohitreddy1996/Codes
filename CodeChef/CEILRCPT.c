#include <stdio.h>
#include<math.h>
int main(void) 
{
	int t;
	scanf("%d",&t);
	long int z;
	for(int i=0;i<t;i++)
	{   int count=0;
	  long int p;
	  int i;
	  scanf("%ld",&p);
	     if(p==1)
	     count=1;
	     else if(p==2)
	     count=1;
	     else if(p<4)
	     {  i=1;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	             i--;
	         }
	     }
	     else if(p<8)
	     {  i=2;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	             i--;
	         }
	     }
	     else if(p<16)
	     {  i=3;
	         while(p>0)
	         {    z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	             i--;
	             
	         }
	     }
	     else if(p<32)
	     {  i=4;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	             i--;
	         }
	     }
	     else if(p<64)
	     {  i=5;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	         i--;
	             
	         }
	     }
	     else if(p<128)
	     {  i=6;
	         while(p>0)
	         { z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	         
	             i--;
	         }
	     }
	     else if(p<256)
	     {  i=7;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	         
	             i--;
	         }
	     }
	     else if(p<512)
	     {  i=8;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	            if(z!=0)
	            p=p-pow(2,i);
	         i--;
	             
	         }
	     }
	     else if(p<1024)
	     {  i=9;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	         i--;
	             
	         }
	     }
	     else if(p<2048)
	     {  i=10;
	         while(p>0)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-pow(2,i);
	         
	             i--;
	         }
	     }
	     else 
	     {  i=11;
	         while(p)
	         {  z=p/pow(2,i);
	             count=count+z;
	             if(z!=0)
	             p=p-(z*pow(2,i));
	        
	             i--;
	         }
	     }
	
	    printf("%d\n",count);
	}
	return 0;
}
