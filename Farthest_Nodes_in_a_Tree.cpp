//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
vector<pair<int, int>> g[N];
int depth[N];

void dfs(int u, int p) {
  for(auto [v, w] : g[u]) {
    if(v != p) {
      depth[v] = depth[u] + w;
      dfs(v, u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ": ";
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
      int u, v, w; cin >> u >> v >> w;
      u++; v++;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    depth[1] = 0;
    dfs(1, 0);
    int mx = -1, fartest_node = 0;
    for(int i = 1; i <= n; i++) {
      if(depth[i] > mx) {
        mx = depth[i];
        fartest_node = i;
      }
    }
    mx = -1;
    depth[fartest_node] = 0;
    dfs(fartest_node, 0);
    for(int i = 1; i <= n; i++) {
      if(depth[i] > mx) {
        mx = depth[i];
      }
    }
    cout << mx << endl;
    for(int i = 1; i <= n; i++) {
      g[i].clear();
      depth[i] = 0;
    }
  }
  return 0;
}
