//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
const int inf = 1e9;
vector<int> adj[N];
vector<int> bfs(int s) {
  vector<int> dis(N, inf);
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v : adj[u]) {
      if(dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  return dis;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t, cs = 0; cin >> t;
  while(t--) {
     int n, m; cin >> n >> m;
     while(m--) {
       int u, v; cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
     }
     int s, e; cin >> s >> e;
     auto ds = bfs(s);
     auto de = bfs(e);
     int ans = 0;

     for(int u = 0; u < n; u++) {
       ans = max(ans, ds[u] + de[u]);
     }
     cout << "Case " << ++cs << ": " << ans << "\n";
     for(int u = 0; u < n; u++) {
       adj[u].clear();
     }
  }
  return 0;
}
