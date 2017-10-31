#include <bits/stdc++.h>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <pair<int, int>> v;
    for (int i = 0; i <= n; i++) {
      int dist, cost;
      cin >> dist >> cost;
      v.push_back(make_pair(dist, cost));
    }
    v.push_back(make_pair(0, 0));
    sort (v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return b.first < a.first;});
    int petrol_ = 0;
    int dist_ = v[0].first;
    int index = 0;
    int ans = -1;
    bool flag = true;
    priority_queue <int> pq;
    for (index = 0; index <= n + 1; index++) {
      petrol_ -= (dist_ - v[index].first);
      dist_ = v[index].first;
      // cout << "Index: " << index << " dist_: " << dist_ << " petrol_: " << petrol_ << endl;
      while (petrol_ < 0) {
        if (pq.empty()) {
          ans = -1;
          flag = false;
          break;
        }
        // cout << index << " : index, top: " << pq.top() << endl; 
        int X = pq.top();
        pq.pop();
        petrol_ += X;
        ans++;
      }
      if (!flag) {
        break;
      }
      // cout << "Pushing: " << v[index].second << endl;
      pq.push(v[index].second);
      // cout << "Top right now: " << pq.top() << endl;
    }
    cout << ans << endl;
  }
  return 0;
}
