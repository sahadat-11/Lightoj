//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7;
vector<pair<int, int>> adj[N];
int dep[N];
void dfs(int u, int p) {
  for(auto [v, w] : adj[u]) {
    if(v != p) {
      dep[v] = dep[u] + w;
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
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    dep[1] = 0;
    dfs(1, 0);
    int mx = -1, fartest_node = 0;
    for(int i = 1; i <= n; i++) {
      if(dep[i] > mx) {
        mx = dep[i];
        fartest_node = i;
      }
    }
    mx = -1;
    dep[fartest_node] = 0;
    dfs(fartest_node, 0);
    for(int i = 1; i <= n; i++) {
      if(dep[i] > mx) {
        mx = dep[i];
      }
    }
    cout << mx << endl;
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
      dep[i] = 0;
    }

  }
  return 0;
}
