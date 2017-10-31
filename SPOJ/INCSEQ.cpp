#include "bits/stdc++.h"

using namespace std;

#define mod 5000000
#define MAX 100000

int bit[51][100002];

void update(int *b, int ind, int val) {
    while (ind < MAX) {
        b[ind] += val;
        if (b[ind] >= mod)
            b[ind] -= mod;
        ind = ind | (ind+1);
    }
}

int query (int *b, int ind) {
    int ans = 0;
    while (ind >= 0) {
        ans += b[ind];
        if (ans >= mod)
            ans -= mod;
        ind = (ind&(ind+1))-1;
    }
    return ans;
}

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        update(bit[1], x, 1);
        for (int i = 2; i <= k; i++) {
            update(bit[i], x, query(bit[i-1], x-1));
        }
    }
    cout << query(bit[k], 99999);
    return 0;
}
