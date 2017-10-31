#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    string ans;
    for (int i = 0; i < 2*n; i+=2) {
        bool present[] = {false, false, false, false};
        present[s1[i]-'A'] = true;
        present[s1[i+1]-'A'] = true;
        int char_f = -1, char_s = -1;
        for (int j = 0; j < 4; j++) {
            if (!present[j]) {
                if (char_f == -1)
                    char_f = j;
                else
                    char_s = j;
            }
        }
        if (ans.empty()) {
            ans.push_back('A'+char_f);
            ans.push_back('A'+char_s);
        } else {
            if (ans[i-1]-'A' == char_f) {
                ans.push_back('A'+char_s);
                ans.push_back('A'+char_f);
            } else {
                ans.push_back('A'+char_f);
                ans.push_back('A'+char_s);
            }
        }
    }
    cout << ans;
    return 0;
}
