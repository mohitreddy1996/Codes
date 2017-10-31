#include "bits/stdc++.h"

using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    cin>>s;
    map<char, int> m;
    vector<int> v;
    int max_ans = 0;
    for (int i = 0; i < n; i++) {
        if (isupper(s[i])) {
            max_ans = max(max_ans, (int) v.size());
            v.clear();
            m.clear();
        } else {
            if (!m.count(s[i])) {
                m[s[i]]++;
                v.push_back(i);
            } else {
                continue;
            }
        }
    }
    max_ans = max(max_ans, (int) v.size());
    cout << max_ans;
    return 0;
}
