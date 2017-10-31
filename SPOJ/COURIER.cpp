#include <bits/stdc++.h>
#define inf 1<<26

long long int dist[101][101];
long long int dp[1 << 12][101];
int src_[100], dest_[100];

using namespace std;

void init() {
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      dist[i][j] = inf;
    }
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < 101; i++) 
    dist[i][i] = 0;
}

void floyd_warshall(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (dist[j][k] > dist[j][i] + dist[i][k]) 
          dist[j][k] = dist[j][i] + dist[i][k];
      }
    }
  }
}

long long int solve(int mask, int prev, int k, int home) {
  if (dp[mask][prev] != -1)
    return dp[mask][prev];
  bool flag = false;
  long long ans = inf, cost;
  for (int i = 0; i < k; i++) {
    if (!(mask & (1 << i))) {
      flag = true;
      cost = dist[prev][src_[i]] + dist[src_[i]][dest_[i]] + solve(mask|(1<<i), dest_[i], k, home);
      if (cost < ans) {
        ans = cost;
      }
    }
  }
  if (!flag)
    return dp[mask][prev] = dist[prev][home];
  else
    return dp[mask][prev] = ans;
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, m, home;
    cin >> n >> m >> home;
    init();
    for (int i = 0; i < m; i++) {
      int x, y, c;
      scanf("%d %d %d", &x, &y, &c);
      dist[x][y] = c;
      dist[y][x] = c;
    }
    floyd_warshall(n);
    int q;
    int k = 0;
    cin >> q;
    while (q--) {
      int src, dest, num;
      cin >> src >> dest >> num;
      while (num--) {
        src_[k] = src;
        dest_[k] = dest;
        k++;
      }
    }
    cout << solve (0, home, k, home) << endl;
  }
  return 0;
}
