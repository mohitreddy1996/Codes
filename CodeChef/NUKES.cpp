#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
 
int main() {
	long long int s;
	int n,k;
	cin>>s>>n>>k;
	int j=0;
	int a[k+1];
	for(int i=0;i<k;i++)
	a[i]=0;
	while (j<k) {
		
		a[j+1]=s/(n+1);
		a[j]=s%(n+1);
		j++;
		s=a[j];
	}
	
	for (int i=0; i<k; i++) {
		cout<<a[i]<<" ";
	}
	
	
	
	return 0;
}
