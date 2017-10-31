#include <bits/stdc++.h>

using namespace std;

string grid[55];
int dp[55][55];

int x[] = {1, 1, 1, -1, -1, -1, 0, 0};
int y[] = {1, 0, -1, 1, 0, -1, 1, -1};

int dfs(int i, int j, int h, int w, int currLen) {
  if (dp[i][j] != -1)
    return dp[i][j];
  int ans = 1;
  for (int ind = 0; ind < 8; ind++) {
    int new_x = i + x[ind];
    int new_y = j + y[ind];
    if (new_x >= 0 && new_x < h && new_y >= 0 && new_y < w && grid[new_x][new_y] == ('A' + currLen)) {
      ans = max(ans, 1 + dfs(new_x, new_y, h, w, currLen + 1));
    }
  }
  dp[i][j] = ans;
  return ans;
}

int main () {
  int count = 0;
  while (1) {
    int h, w;
    scanf("%d %d", &h, &w);
    if (h == 0 && w == 0) 
      break;
    for (int i = 0; i < h; i++) {
      cin >> grid[i];
    }
    int ans = 0;
    for (int i = 0; i < 55; i++) {
      for (int j = 0; j < 55; j++) {
        dp[i][j] = -1;
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == 'A') {
          ans = max(ans, dfs(i, j, h, w, 1));
        }
      }
    }
    ++count;
    cout << "Case " << count << ": " << ans <<endl;
  }
  return 0;
}
