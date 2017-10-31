#include <bits/stdc++.h>

using namespace std;
int inf = INT_MAX;
string grid[21];
int dp[1024][21][21];
int count1 = 0;
int ans = INT_MAX;
int h, w;
int x_d[] = {1, 0, 0, -1};
int y_d[] = {0, 1, -1, 0};

void bfs(int x, int y) {
  // x, y, mark. 
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(x, y), 0));
  dp[0][x][y] = 0;
  while (!q.empty()) {
    int x_ = q.front().first.first;
    int y_ = q.front().first.second;
    int mark_ = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x_i = x_ + x_d[i];
      int y_i = y_ + y_d[i];
      if (x_i >= 0 && x_i < h && y_i >= 0 && y_i < w && grid[x_i][y_i] != 'x') {
        int mark_i = mark_;
        if (grid[x_i][y_i] >= 'A' && grid[x_i][y_i] <= 'Z') {
          mark_i = mark_i | 1 << (grid[x_i][y_i] - 'A');
        }
        if (dp[mark_i][x_i][y_i] > dp[mark_][x_][y_] + 1) {
          dp[mark_i][x_i][y_i] = dp[mark_][x_][y_] + 1;
          if (mark_i == (1<<count1) - 1) {
            ans = min(ans, dp[mark_i][x_i][y_i]);
          }
          q.push(make_pair(make_pair(x_i, y_i), mark_i));
        }
      }
    }
  }
}

int main () {
   while (1) {
    cin >> w >> h;
    if (h == 0 && w == 0) {
      break;
    }
    count1 = 0;
    ans = INT_MAX;
    int source_x, source_y;
    for (int i = 0; i < h; i++) {
      cin>>grid[i];
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == '*') {
          grid[i][j] = 'A' + count1++;
        }
        if (grid[i][j] == 'o') {
          source_x = i;
          source_y = j;
        }
      }
    }
    for (int i = 0; i < 1024; i++) {
      for (int j = 0; j < 21; j++) {
        for (int k = 0; k < 21; k++) {
          dp[i][j][k] = inf;
        }
      }
    }
    bfs(source_x, source_y);
    if (ans == inf) {
      cout << "-1\n";
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
