#include "bits/stdc++.h"

using namespace std;

int main () {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int ans = 0;
    int fuel = b;
    int times = 0;
    while (k--) {
        //cout << k << endl;
        if (!(times&1)) {
            if (f > fuel) {
                cout << "-1";
                return 0;
            }
            fuel = fuel - f;
            if (k == 0 && fuel < (a-f)) {
                fuel = b;
                ans++;
                if (fuel < a-f) {
                    cout << "-1";
                    return 0;
                }
            } else if ( k != 0 && fuel < 2 * (a - f)) {
                fuel = b;
                ans++;
            }
            fuel = fuel - (a-f);
        } else {
            if (fuel < (a-f)) {
                cout << "-1";
                return 0;
            }
            fuel = fuel - (a-f);
            if (k == 0 && fuel < f) {
                fuel = b;
                ans++;
                if (fuel < f) {
                    cout << "-1";
                    return 0;
                }
            } else if (k != 0 && fuel < 2*f){
                fuel = b;
                ans++;
            }
            fuel = fuel - f;
        }
        times++;
    }
    cout << ans;
    return 0;
}
