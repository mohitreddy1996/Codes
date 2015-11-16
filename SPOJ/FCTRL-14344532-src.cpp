#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int count=n/5+n/25+n/125+n/625+n/3125+n/15625+n/(15625*5)+n/(15625*25)+n/(15625*125)+n/(15625*625)+n/(15625*3125)+n/(15625*15625)+n/1220703125+n/6103515625+n/30517578125;
		cout<<count<<"\n";
	}

	return 0;
}