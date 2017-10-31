#include <bits/stdc++.h>

using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2;
        cin>>n1;
        vector<int> v;
        for (int i = 0; i < n1; i++) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        vector<int> vv;
        cin>>n2;
        for (int i = 0; i < n2; i++) {
            int x;
            scanf("%d", &x);
            vv.push_back(x);
        }
        sort(vv.begin(), vv.end());
        int ans = 1000000;
        for (int i = 0; i < n1; i++) {
            int val = v[i];
            int x = lower_bound(vv.begin(), vv.end(), val) - vv.begin();
            if (x>0) {
                ans = min(ans, min(abs(val - vv[x]), abs(val-vv[x-1])));
            } else {
                ans = min(ans, abs(val - vv[x]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
