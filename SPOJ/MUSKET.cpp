#include "bits/stdc++.h"

using namespace std;
int win[102][102];
int dp[102][102];

int dp_solve(int i, int j, int n) {
    if (i == j || (i+1)%n == j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int meet = (i+1)%n; meet != j; meet = (meet+1)%n) {
        if (win[i][meet] || win[j][meet]) {
            if (dp_solve(i, meet, n) && dp_solve(meet, j, n)) {
                dp[i][j] = 1;
                return dp[i][j];
            }
        }
    }
    dp[i][j] = 0;
    return dp[i][j];
}

void solve(int n) {
    int ans[102];
    int ind = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || !win[i][j]) {
                continue;
            }
            if (dp_solve(i, j, n) && dp_solve(j, i, n)) {
                ans[ind++] = i+1;
                break;
            }
        }
    }
    cout << ind << endl;
    for (int i = 0; i < ind; i++) {
        cout << ans[i] << endl;
    }
}

int main () {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                win[i][j] = s[j] - '0';
                dp[i][j] = -1;
            }
        }
        solve(n);
    }
    return 0;
}
