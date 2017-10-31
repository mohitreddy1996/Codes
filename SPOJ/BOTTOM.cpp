#include <bits/stdc++.h>

using namespace std;

vector<int> graph[5001], grapht[5001];
vector<int> stack_;
int scc_num[5001], is_sink[5001];

bool visited[5001];

void init (int n) {
  for (int i = 0; i <= n; i++) {
    graph[i].clear();
    grapht[i].clear();
    visited[i] = false;
    scc_num[i] = -1;
    is_sink[i] = false;
  }
  stack_.clear();
}

void dfs (int n) {
  visited[n] = true;
  for (auto v : graph[n]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
  stack_.push_back(n);
}

void dfs2 (int n, int num_comp) {
  scc_num[n] = num_comp;
  visited[n] = false;
  for (auto v : grapht[n]) {
    if (visited[v]) {
      dfs2 (v, num_comp);
    }
  }
}

int main () {
  while (1) {
    int n, m;
    cin >> n;
    if (n == 0) {
      break;
    }
    cin >> m;
    init (n);
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d  %d", &x, &y);
      graph[x].push_back(y);
      grapht[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    int num_comp = 0;
    for (int i = stack_.size()-1; i >= 0; i--) {
      if (visited[stack_[i]]) {
        num_comp++;
        dfs2 (stack_[i], num_comp);
        is_sink[num_comp] = true;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (auto v : graph[i]) {
        if (scc_num[i] != scc_num[v]) {
          is_sink[scc_num[i]] = false;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (is_sink[scc_num[i]]) {
        cout << i << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
