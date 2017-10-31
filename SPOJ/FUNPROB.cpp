#include <bits/stdc++.h>

using namespace std;

int main () {
	while (1) {
		int n, m;
		cin>> n >> m;
		if (n == 0 && m == 0)
			break;
		if (n > m) {
			printf("0.000000\n");
		} else {
			printf("%0.6f\n", (m-n+1)*1.0/(m+1));
		}
	}
	return 0;
}
