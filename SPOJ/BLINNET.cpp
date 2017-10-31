#include <bits/stdc++.h>

using namespace std;

int size[10002], root[10002];

void init(int n) {
  for (int i = 0; i <=n; i++) {
    size[i] = 0;
    root[i] = i;
  }
}

int find (int x) {
  if (x != root[x]) 
    root[x] = find(root[x]);
  return root[x];
}

void union_(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);
  if (size[root_x] > size[root_y]) {
    size[root_x] += size[root_y];
    root[root_y] = root[root_x];
  } else {
    size[root_y] += size[root_x];
    root[root_x] = root[root_y];
  }
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    init(n);
    priority_queue<pair<int, pair<int, int>>, std::vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> pq;
    for (int i = 1; i <= n; i++) {
      string s;
      cin>>s;
      int m;
      cin >> m;
      while (m--) {
        int x, c;
        scanf("%d %d", &x, &c);
        pq.push(make_pair(c, make_pair(i, x)));
      }
    }
    int ans = 0;
    while (!pq.empty()) {
      pair<int, pair<int, int>> p = pq.top();
      pq.pop();
      int x = p.second.first;
      int y = p.second.second;
      int c = p.first;
      if (find(x) != find (y)) {
        union_(x, y);
        ans += c;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
