#include <bits/stdc++.h>

using namespace std;
int N, T;

int cost[150][150], time_[150][150];

int inf = 1000000;

int main () {
  int t;
  cin>>t;
  while (t--) {
    cin>>N>>T;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int time1;
        cin>>time1;
        time_[i][j] = time1;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int cost1;
        cin>>cost1;
        cost[i][j] = cost1;
      }
    }

    // Dp logic. 
    int dp[120][270];

    for (int i = 0; i < 120; i++) {
      for (int j = 0; j <= T; j++) {
        dp[i][j] = inf;
      }
    }
    
    for (int i = 0; i <= T; i++) {
      dp[0][i] = 0;
    }

    for (int ti = 1; ti <= T; ti++) {
      for (int i = 1; i < N; i++) {
        int temp = inf;
        for (int k = 0; k < N; k++) {
          if (ti >= time_[k][i]) {
            temp = min(temp, dp[k][ti - time_[k][i]] + cost[k][i]);
          }
        }
        dp[i][ti] = min(temp, dp[i][ti-1]);
      }
    }
    if (dp[N-1][T] == inf) {
      cout << "-1\n";
      continue;
    }
    int min_cost = dp[N-1][T], min_time = T;
    for (int ti = T; ti >= 1; ti--) {
      if (dp[N-1][ti] != dp[N-1][T]) {
        min_time = ti;
        break;
      }
    }
    cout << min_cost << " " << min_time + 1 << endl;
  }
  return 0;
}
