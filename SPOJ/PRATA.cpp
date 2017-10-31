#include <bits/stdc++.h>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int pratas, chefs;
    cin >> pratas >> chefs;
    vector<int> v, rank, times;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < chefs; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
      rank.push_back(x);
      times.push_back(1);
      pq.push(x);
    }
    int time = 0, count = 0;
    while (1) {
      time = pq.top ();
      // cout << "Time: " << time << " Count: " << count << endl;
      pq.pop();
      while (!pq.empty() && pq.top() == time) {
        pq.pop();
      }
      for (int i = 0; i < chefs; i++) {
        if (v[i] == time) {
          times[i]++;
          count++;
          v[i] = v[i] + times[i]*rank[i];
          // cout << "Pushing: " << v[i] << endl;
          pq.push(v[i]);
        }
      }
      if (count >= pratas) {
        break;
      }
    }
    cout << time << endl;
  }
  return 0;
}
