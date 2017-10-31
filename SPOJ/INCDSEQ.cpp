#include "bits/stdc++.h"

using namespace std;

#define mod 5000000
int MAX = 10001, lim = 0;

int bit[51][10002], visited[51][10002];

void update(int *b, int ind, int val) {
    while (ind < MAX) {
        b[ind] += val;
        if (b[ind] >= mod)
            b[ind] -= mod;
        ind += (ind & -ind);
    }
}

int query (int *b, int ind) {
    if (b == bit[0])
        return 1;
    int ans = 0;
    while (ind > 0) {
        ans += b[ind];
        if (ans >= mod)
            ans -= mod;
        ind -= (ind & -ind);
    }
    return ans;
}

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> v, dummy;
    map<long long int, int> m;
    map<long long int, int> index;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        dummy.push_back(temp);
    }
    sort(dummy.begin(), dummy.end());
    m[dummy[0]] = ++lim;
    for (int i = 1; i < n; i++) {
        if (dummy[i] == dummy[i-1]) {
            m[dummy[i]] = lim;
        } else {
            m[dummy[i]] = ++lim;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        int temp = m[v[i]];
        for (int j = 0; j < k; j++) {
            int x = query(bit[j], temp-1);
            int y = visited[j][temp-1];
            if (x != y) {
                visited[j][temp-1] = x;
                x = x - y;
                if (x < 0)
                    x += mod;
                update(bit[j+1], temp, x);
            }
        }
    }
    cout << query(bit[k], MAX);
    return 0;
}
