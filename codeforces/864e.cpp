#include "bits/stdc++.h"

using namespace std;

struct cont {
    int p, t, i, d;
};

vector<struct cont> v;

int dp[101][2001];
pair<int, int> dpp[101][2001];

int solve (int index, int time) {
    if (index == v.size()) {
        return 0;
    }
    if (dp[index][time] != -1) {
        return dp[index][time];
    }
    int d = v[index].d;
    struct cont temp = v[index];
    if (time + temp.t < d) {
        int temp1 = solve (index + 1, time);
        int temp2 = temp.p + solve (index + 1, time + temp.t);
        if (temp1 > temp2) {
            dpp[index][time] = make_pair(index + 1, time);
            dp[index][time] = temp1;
        } else {
            dpp[index][time] = make_pair(index + 1, time + temp.t);
            dp[index][time] = temp2;
        }
        return max(temp1, temp2);
    } else {
        dpp[index][time] = make_pair(index + 1, time);
        return dp[index][time] = solve(index + 1, time);
    }
}

class compare {
    public:
    bool operator() (const struct cont& a, const struct cont& b){
        return a.d < b.d;
    }
};

int main () {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        int t, d, p;
        cin >> t >> d >> p;
        struct cont temp;
        temp.p = p;
        temp.t = t;
        temp.d = d;
        temp.i = i + 1;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare());
    cout << solve(0, 0) << endl;
    vector<int> ans;
    pair<int, int> pp;
    pp.first = 0;
    pp.second = 0;
    while (pp.first < n) {
    // cout << pp.first << " " << pp.second << endl;
        if (pp.second != dpp[pp.first][pp.second].second) {
            ans.push_back(v[pp.first].i);
        }
        pp = dpp[pp.first][pp.second];
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
