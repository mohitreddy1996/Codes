#include "bits/stdc++.h"

using namespace std;

int main () {
    int n;
    cin >> n;
    map<int, int> m;
    int arr[100005];
    bool visited[100005];
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    int ans  = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        m[x]++;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (m[i] == 0) {
            v.push_back(i);
            ans++;
        }
    }
    int ind = 0;
    set<int>::iterator it;
    for (int i = 1; i <= n; i++) {
        int val = v[ind];
        if (m[arr[i]] > 1) {
            if (arr[i] > val) {
                m[arr[i]]--;
                arr[i] = val;
                ind++;
            } else {
                if (!visited[arr[i]]) {
                    visited[arr[i]] = true;
                } else {
                    m[arr[i]]--;
                    arr[i] = val;
                    ind++;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
