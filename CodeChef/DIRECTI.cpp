#include<stdio.h>
#include<string.h>
int main(){
int t,i,n;
char l[40][6];
char on[3];
char road[40][44];
scanf("%d",&t);
while(t--){
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s%s",l[i],on);
gets(road[i]);
 
}
i--;
printf("Begin on");
puts(road[i]);
i--;
for(;i>-1;i--){
if('R'==l[i+1][0])
{
printf("Left on");
}
else printf("Right on");
puts(road[i]);
}
printf("\n");
}
return 0;
} 
