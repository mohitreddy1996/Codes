#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin>>n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin>>x;
    v.push_back(x);
  }
  vector<long long int> sum_left;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        sum_left.push_back(v[i]*v[j] + v[k]);
      }
    }
  }
  vector<long long int> sum_right;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        if (v[k] != 0) 
          sum_right.push_back(v[k]*(v[i]+v[j]));
      }
    }
  }
  sort(sum_left.begin(), sum_left.end());
  sort(sum_right.begin(), sum_right.end());
  long long int ans = 0;
  for (int i = 0; i < sum_left.size(); i++) {
    int low = lower_bound(sum_right.begin(), sum_right.end(), sum_left[i]) - sum_right.begin();
    int high = upper_bound(sum_right.begin(), sum_right.end(), sum_left[i]) - sum_right.begin();
    ans += (high - low);
  }
  cout << ans;

  return 0;
}
