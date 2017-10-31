#include "bits/stdc++.h"

using namespace std;

long long int levelone[100005];
long long int leveltwo[100005];
bool visited[100005];
vector<int> v[100005];

void bfs (int x, int color) {
    int level = 1;
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(x, make_pair(color, level)));
    while (!q.empty()) {
        pair<int, pair<int, int> > p = q.front();
        q.pop();
        if (visited[p.first])
            continue;
        if (p.second.first == 0) {
            levelone[p.second.second]++;
        } else {
            leveltwo[p.second.second]++;
        }
        visited[p.first] = true;
        for (int i = 0; i < v[p.first].size(); i++) {
            if (!visited[v[p.first][i]]) {
                q.push(make_pair(v[p.first][i], make_pair(1-p.second.first, p.second.second + 1)));
            }
        }
    }
}

int main () {
    int n;
    cin >> n;
    memset(levelone, 0, sizeof(levelone));
    memset(leveltwo, 0, sizeof(leveltwo));
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1, 0);
    for (int i = 100003; i >= 0; i--) {
        leveltwo[i] += leveltwo[i+1];
        levelone[i] += levelone[i+1];
    }
    long long int ans = leveltwo[0]*levelone[0];
    ans -= (n-1);
    cout << ans;
    return 0;
}
