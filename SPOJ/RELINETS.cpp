#include <bits/stdc++.h>
#define inf 100000000
using namespace std;

vector<int> graph[22];
int visited[22], parent[22], is_bride[22];
int disc[22], low[22];

void init_graph(int n) {
  for (int i = 0; i <= n; i++) {
    visited[i] = false;
    graph[i].clear();
  }
}

void dfs(int n) {
  visited[n] = true;
  for (auto v : graph[n]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

bool is_single_comp (int n) {
  int comp = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      comp++;
      dfs(i);
    }
  }
  return comp == 1;
}

int time_;

void dfs2 (int n) {
  visited[n] = true;
  disc[n] = low[n] = ++time_;
  for (auto v : graph[n]) {
    if (!visited[v]) {
      parent[v] = n;
      dfs2 (v);
      low[n] = min (low[n], low[v]);
      if (low[v] > disc[n]) {
        is_bride[n] = true;
      }
    } else if (parent[n] != v) {
      low[n] = min (low[n], disc[v]);
    }
  }
}

bool has_bridge(int n) {
  for (int i = 0; i <=n; i++) {
    visited[i] = false;
    is_bride[i] = false;
    disc[i] = 0;
    low[i] = 0;
    parent[i] = -1;
  }
  time_ = 0;
  dfs2 (1);
  for (int i = 1; i <= n; i++) {
    if (is_bride[i]) {
      return true;
    }
  }
  return false;
}

int main () {
  int test_ = 0;
  while (1) {
    test_++;
    int n, m;
    cin >> n >> m;
    if ( n == 0 && m == 0) {
      break;
    }
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
      int x, y, c;
      scanf ("%d %d %d", &x, &y, &c);
      edges.push_back(make_pair(x, make_pair(y, c)));
    }
    int ans = inf;
    for (int i = 0; i < (1 << m); i++) {
      int k = i;
      int index = 0;
      int num_edge = 0;
      init_graph(n);
      int cost = 0;
      while (k > 0) {
        if (k&1) {
          int x = edges[index].first;
          int y = edges[index].second.first;
          int c = edges[index].second.second;
          graph[x].push_back(y);
          graph[y].push_back(x);
          cost += c;
          num_edge++;
        }
        index++;
        k = k >> 1;
      }
      if (num_edge < n - 1) {
        continue;
      }
      if (is_single_comp(n) && !has_bridge(n)) {
        ans = min (ans, cost);
      }
    }
    if (ans == inf) {
      cout << "There is no reliable net possible for test case " << test_ << ".\n";
    } else {
      cout << "The minimal cost for test case " << test_ << " is " << ans << ".\n";
    }
  }
  return 0;
}
