#include <bits/stdc++.h>

using namespace std;

int inf = 2000;

int main () {
  int N, T;
  cin >> N >> T;
  vector<pair<pair<int, int>, int> > v;
  for (int i = 0; i < N; i++) {
    int w, p, c;
    cin >> w >> p >> c;
    v.push_back(make_pair(make_pair(w, p), c));
  }
  sort(v.begin(), v.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {return a.first.first < b.first.first;});
  int dp[7][1001];
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 1001; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= T; j++) {
      int x = v[i].first.first;
      int p = v[i].first.second;
      int c = v[i].second;
      if (p <= j) {
        if (x == 1) {
          dp[x][j] = c;
        } else {
          dp[x][j] = max (dp[x][j], min (dp[x-1][j-p], c));
        }
      }
    }
  }
  cout << dp[6][T] << endl;
  return 0;
}
