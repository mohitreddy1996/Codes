
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000000000

using namespace std;

int n,m;
string s[52];
int dp[52][52][52];
bool vis[52][52][52];

int f(int idx, int pos1, int pos2)
{
    
    if ( idx == n ) return 0;
    if (  pos1 == pos2 ) return -INF;
    if ( pos1 < 0 || pos2 < 0 || pos1 >= m || pos2 >= m ) return -INF;
    if ( s[idx][pos1] == '#' || s[idx][pos2] == '#' ) return -INF;
    
    if ( vis[idx][pos1][pos2] ) return dp[idx][pos1][pos2];
    vis[idx][pos1][pos2] = true;
    
    int ans = -INF;
    
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1, pos2));
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1+1, pos2));
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1-1, pos2));
        
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1, pos2+1));
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1+1, pos2+1));
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1-1, pos2+1));
    
    
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1, pos2-1));
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1+1, pos2-1));
    ans = max(ans, (abs(pos1-pos2) == 1) + f(idx+1, pos1-1, pos2-1));
    
    dp[idx][pos1][pos2] = ans;
    
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while ( t-- ) {
          cin >> n >> m;
          for ( int i = 0; i < n; i++ ) cin >> s[i];
          int ans = -INF;
          memset(vis, false, sizeof(vis));
          for ( int j = 0; j < m; j++ ) {
              for ( int k = 0; k < m; k++ ) {
                  ans = max(ans, f(0,j,k));
              }
          }
          if ( ans < 0 ) cout << "Detour" << endl;
          else cout << ans << endl;
    }
    
    return 0;
}