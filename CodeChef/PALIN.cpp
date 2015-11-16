#define N 100000
#include <iostream>
#include <map>
#include <string.h>
 
using namespace std;
 
void smallestPalindromeOfLength(char *result, int len)
{
	result[0] = '1';
	for (int i = 1; i < len - 1; i++) {
		result[i] = '0';
	}
	result[len - 1] = '1';
	result[len] = '\0';
	return;
}
 
int main() {
	int k;
	char number[1000010];
	char dest[1000010];
	char res[1000010];
 
	cin >> k;
 
 
	for (int i = 0; i < k; i++) {
		cin >> number;
		int halflen = (strlen(number) + 1 )/ 2;
 
		for (int j = 0; j < halflen; j++) {
			dest[j] = number[halflen - 1 - j];
		}
 
		//compare
		int target;
		int position = halflen;
		bool extend = true;
 
		if (halflen * 2 == strlen(number)) {
			target = halflen - 1;
		}
		else {
			target = halflen - 2;
		}
 
		while (target >= 0) {
			if (number[position] > number[target]) {
				extend = true;
				break;
			}
			else if (number[position] < number[target]){
				extend = false;
				break;
			}
			target--;
			position++;
		}
		int carry = 0;
		if (extend) {
			carry = 1;
			for (int j = halflen - 1; carry == 1 && j >= 0; j--) {
				if (number[j] == '9') {
					number[j] = '0';
				}
				else {
					number[j]++;
					carry = 0;
				}
			}
		}
 
		if (carry == 1) {
			smallestPalindromeOfLength(number, strlen(number) + 1);
		}
		else{
			position = halflen;
 
			if (halflen * 2 == strlen(number)) {
				target = halflen - 1;
			}
			else {
				target = halflen - 2;
			}
 
			while (target >= 0) {
				number[position] = number[target];
				target--;
				position++;
			}
 
		}
		cout << number << endl;
 
	}
 
	return 0;
}
