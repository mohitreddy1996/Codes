#include "bits/stdc++.h"

int last1 = (1<<18);
int last2 = (1<<19);
using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
    }
    if (n == 2 && x == 0) {
        cout << "NO\n";
    } else if (n==2) {
        cout << "YES" << endl;
        cout << "0 " << x << endl;
    } else {
        int ans = 0;
        cout << "YES" << endl;
        for (int i = 1; i <= n-3; i++) {
            cout << i << " ";
            ans ^= i;
        }
        if (ans == x) {
            cout << last1 << " " << last2 << " " << last1+last2 << endl;
        } else {
            cout << "0 " << last1 << " " << ((last1^ans)^x) << endl;
        }
    }
    return 0;
}
