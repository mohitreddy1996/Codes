#include <bits/stdc++.h>

using namespace std;

vector<string> words;
string acry;
set<string> inapprop;

int dp[151][151][151];

int solve(int word_ind, int str_ind, int acry_ind) {
    // cout << acry <<" " << word_ind << " " << str_ind << " " << acry_ind << endl;
    if (acry_ind == acry.size()) {
        if (word_ind == words.size()) {
            return 1;
        } else {
            return 0;
        }
    }
    if (word_ind == words.size())
        return 0;
    if (str_ind == words[word_ind].size()) {
        return 0;
    }
    if (dp[word_ind][str_ind][acry_ind] != -1)
        return dp[word_ind][str_ind][acry_ind];
    if ((words[word_ind][str_ind] -'a') == (acry[acry_ind]-'A')) {
        dp[word_ind][str_ind][acry_ind] = solve(word_ind+1, 0, acry_ind+1) + solve(word_ind, str_ind+1, acry_ind+1) + solve(word_ind, str_ind+1, acry_ind);
    } else {
        dp[word_ind][str_ind][acry_ind] = solve(word_ind, str_ind+1, acry_ind);
    }
    return dp[word_ind][str_ind][acry_ind];
}

int main () {
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++) {
            string s;
            cin>>s;
            inapprop.insert(s);
        }

        while (1) {
            int index = 0;
            bool done = false;
            cin >> acry; cin.ignore();
            string phrase; getline(cin, phrase);
            if (phrase == "CASE") break;
            istringstream iss(phrase);
            for (;;) {
                string word; iss >> word;
                if (word == "") break;
                if (inapprop.find(word) == inapprop.end()) {
                    words.push_back(word);
                }
            }
            memset(dp, -1, sizeof(dp));
            int ans = solve (0, 0, 0);
            if (ans == 0) {
                cout << acry << " is not a valid abbreviation\n";
            } else {
                cout << acry << " can be formed in " << ans << " ways\n";
            }
            words.clear();
        }
        words.clear();
        inapprop.clear();
    }
    return 0;
}
