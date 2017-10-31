#include "bits/stdc++.h"

using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    int ans = 0;
    for (int i = 0; i < x; i++) {
        if (s.find(i) == s.end()) {
            ans++;
        }
    }
    if (s.find(x) != s.end()) {
        ans++;
    }
    cout << ans;
    return 0;
}
