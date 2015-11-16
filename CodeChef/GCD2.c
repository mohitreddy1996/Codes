#include<stdio.h>
char ch[251];
int rem(int a)
{
    int p=0,i;
    for(i=0;ch[i]!='\0';i++)
    p=((ch[i]-'0')+p*10)%a;
    return p;
}
int hcf(int a,int b)
{
    if(b==0)
    return a;
    return hcf(b,a%b);
}
int main()
{
    int a,t,p;
    scanf("%d",&t);
    while(t--)
    {   
        scanf("%d%s",&a,ch);
        if(a==0)
        printf("%s\n",ch);
        else
        {
         p=rem(a);
         printf("%d\n",hcf(a,p));
        }
    }
    return 0;
}
