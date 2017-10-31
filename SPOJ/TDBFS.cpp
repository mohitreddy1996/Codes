#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];

void DFS (int x, bool visited []) {
  if (visited[x]) {
    return;
  }
  visited[x] = true;
  cout << x << " ";
  for (int i = 0; i < v[x].size(); i++) {
    if (!visited[v[x][i]]) {
      DFS (v[x][i], visited);
    }
  }
}

void DFS_ (int x) {
  bool visited[1001];
  memset (visited, false, sizeof(visited));
  DFS (x, visited);
}

void BFS (int x) {
  bool visited[1001];
  memset (visited, false, sizeof(visited));
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    if (visited[x]) {
      continue;
    }
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < v[x].size(); i++) {
      int y = v[x][i];
      if (!visited[y]) {
        q.push(y);
      }
    }
  }
}

int main () {
  int t;
  cin>>t;
  int count = 0;
  while (t--) {
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) {
      int m;
      int y;
      cin >> y;
      cin >> m;
      for (int j = 1; j <= m; j++) {
        int x;
        scanf ("%d", &x);
        v[y].push_back(x);
      }
    }
    count++;
    cout << "graph " << count << endl;
    while (1) {
      int v, w;
      cin >> v >> w;
      if (v == 0 && w == 0) {
        break;
      }
      if (w == 0) {
        DFS_ (v);
      } else {
        BFS (v);
      }
      cout << endl;
    }
    for (int i = 0; i <= n; i++) {
      v[i].clear();
    }
  }
  return 0;
}
