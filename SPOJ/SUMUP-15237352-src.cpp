#include <stdio.h>
int main()
{
int tN;
scanf("%d",&tN);
int* n=new int[tN];
for(int i=0;i<tN;i++)
scanf("%d",&n[i]);
for(int i=0;i<tN;i++)
printf("%.5lf\n",0.5-0.5/(n[i]*n[i]+n[i]+1));
delete n;
}