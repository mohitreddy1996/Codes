#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
    long long int a;
    scanf("%lld",&a);
    a=a%6;
    if(a==0)
    printf("yes");
    else if(a==1)
    printf("yes");
    else if(a==3)
    printf("yes");
    else
    printf("no");
	return 0;
}
