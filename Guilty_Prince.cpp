//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 25, mod = 1e9 + 7;
#define int long long
int n, m, ans;
bool vis[N][N];
char a[N][N];

int dx[] = {0, 0, -1, +1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

bool isValid(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < m;
}

void dfs(int i, int j) {
  vis[i][j] = true;
  ans++;
  for(int k = 0; k < 4; k++) {
    int x = i + dx[k];
    int y = j + dy[k];
    if(isValid(x, y) and a[x][y] == '.' and !vis[x][y]) {
      dfs(x, y);
   }
 }
}
void solve() {
   cin >> m >> n;
   int st_x, st_y;
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      if(a[i][j] == '@') {
        st_x = i, st_y = j;
      }
    }
   }
   ans = 0;
   dfs(st_x, st_y);
   cout << ans << "\n";
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      vis[i][j] = false;
    }
   }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, cs = 0; 
  cin >> t;
  while(t--) {
    cout << "Case " << ++ cs << ": ";
    solve();
  }
  return 0;
}

