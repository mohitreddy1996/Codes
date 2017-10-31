#include <bits/stdc++.h>

using namespace std;

int cost[1001][1001];

vector<int> v[1001];

int dsu[1001], size_dsu[1001];

auto comp = [] (const pair<pair<int, int>, int>& x, const pair<pair<int, int>, int>& y) {return x.second > y.second;};

priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(comp)> pq(comp);

void initialize_dsu(int n) {
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
    size_dsu[i] = 1;
  }
}

int find_par(int x) {
  while (dsu[x] != x) {
    dsu[x] = dsu[dsu[x]];
    x = dsu[x];
  }
  return x;
}

void union_(int x, int y) {
  int par_x = find_par(x);
  int par_y = find_par(y);
  if (size_dsu[par_x] <= size_dsu[par_y]) {
    size_dsu[par_y] += size_dsu[par_x];
    dsu[par_y] = dsu[par_x];
  } else {
    size_dsu[par_x] += size_dsu[par_y];
    dsu[par_x] = dsu[par_y];
  }
}


int main () {
  int t;
  cin>>t;
  while (t--) {
    int p, n, m;
    scanf("%d %d %d", &p, &n, &m);
    initialize_dsu(n);
    for (int i = 0; i < m; i++) {
      int x, y, c;
      scanf("%d %d %d", &x, &y, &c);
      pq.push(make_pair(make_pair(x, y), c));
    }
    int ans = 0;
    while (!pq.empty()) {
      pair<pair<int, int>, int> cont = pq.top();
      pq.pop();
      int x = cont.first.first;
      int y = cont.first.second;
      int cost = cont.second;
      if (find_par(x) != find_par(y)) 
        union_(x, y);
      else
        continue;
      ans += cost;
    }
    cout << ans * p << endl;
  }
  return 0;
}
