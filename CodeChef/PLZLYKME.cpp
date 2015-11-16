#include<iostream>
using namespace std;
int main()
{
	unsigned long long int l,d,s,c,i;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> l >> d >> s >> c;
		for(i=1 ; i<d ; i++)
		{
			s = s*(c+1);
			if(s >= l)
			{
				break;
			}
		}
		if(s >= l)
		{
			cout << "ALIVE AND KICKING" << "\n"	;
		}
		else
			cout << "DEAD AND ROTTING" << "\n" ;
		
	} 
    return(0);
}
