#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  int xx = n;
  map<int, int> m;
  while (n--) {
    int x;
    cin >> x;
    m[x]++;
  }
  // cout << m.size() << endl;
  if (m.size() > 2) {
    cout << "NO";
    return 0;
  }
  for (auto p : m) {
    // cout << p.first << " " << p.second << endl;
    if (p.second == xx/2) {
      cout << "YES\n";
      for (auto pp : m) {
        cout << pp.first << " ";
      }
    } else {
      cout << "NO";
    }
    return 0;
  }
  return 0;
}
