#include <bits/stdc++.h>

using namespace std;

#define len 200005

int a[len];
struct node {
  int sum, best_suffix_sum, best_prefix_sum, best_sum;

  node () {
    sum = best_prefix_sum = best_suffix_sum = best_sum = 0;
  }

  node (int val) {
    sum = best_prefix_sum = best_suffix_sum = best_sum = val;
  }

  void merge (node left, node right) {
    sum = left.sum + right.sum;
    best_prefix_sum = max (left.best_prefix_sum, left.sum + right.best_prefix_sum);
    best_suffix_sum = max (right.best_suffix_sum, right.sum + left.best_suffix_sum);
    best_sum = max(left.best_sum, right.best_sum);
    best_sum = max(best_sum, left.best_suffix_sum + right.best_prefix_sum);
  }

} tree[4*len];

void build_tree (int index, int left1, int right1) {
  if (left1 == right1) {
    tree[index] = a[left1];
    return;
  }

  int mid = left1 + (right1 - left1)/2;
  build_tree (2*index, left1, mid);
  build_tree (2*index + 1, mid + 1, right1);
  tree[index] = node ();
  tree[index].merge(tree[2*index], tree[2*index+1]);
  // cout << "Build Successful: " << index << endl;
}

node query (int index, int start, int end, int query_start, int query_end) {
  if (query_end < start || end < query_start || query_start > query_end) {
    node ans = node(-100000);
    ans.sum = 0;
    return ans;
  }
  if (start >= query_start && query_end >= end) {
    return tree[index];
  }
  int mid = start + (end - start)/2;
  // cout << "Mid: " << mid << endl;
  node left = query (2*index, start, mid, query_start, query_end);
  node right = query (2*index + 1, mid + 1, end, query_start, query_end);
  node temp = node();
  // cout << "Query: " << index << endl;
  temp.merge (left, right);
  return temp;
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    build_tree(1, 0, n-1);
    int m;
    cin >> m;
    while (m--) {
      int x1, x2, y1, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      x1--, x2--, y1--, y2--;
      int ans;
      // overlapping cases and non-overlapping cases.
      if (x2 > y1) {
        ans = query(1, 0, n-1, x1, y1).best_suffix_sum + query(1, 0, n-1, y1 + 1, x2 - 1).sum + query (1, 0, n-1, x2, y2).best_prefix_sum;
      } else {
        ans = query (1, 0, n-1, x1, x2-1).best_suffix_sum + query (1, 0, n-1, x2, y2).best_prefix_sum;
        ans = max (ans, query(1, 0, n-1, x2, y1).best_suffix_sum + query(1, 0, n-1, y1+1, y2).best_prefix_sum);
        ans = max(ans, query(1, 0, n-1, x2, y1).best_sum);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
