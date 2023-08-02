//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 7;
int money[N];
int totol_money, people;
vector<int> adj[N];
bool vis[N];

void dfs(int u) {
  vis[u] = true;
  people++;
  totol_money += money[u];
  for(auto v : adj[u]) {
    if(!vis[v]) {
      dfs(v);
    }
  }
}
void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> money[i];
  for(int i = 1; i <= n; i++) {
    vis[i] = false;
    adj[i].clear();
  }
  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  set<int> st;
  for(int u = 1; u <= n; u++) {
    if(!vis[u]) {
      totol_money = 0, people = 0;
      dfs(u);
      //cout << totol_money << " " << people << "\n";
      if(totol_money % people == 0) st.insert(totol_money / people);
      else {
        cout << "No\n";
        return;
      }
    }
  }
  if(st.size() == 1) cout << "Yes\n";
  else cout << "No\n";
}
int main() {
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ": ";
    solve();
  }
  
  return 0;
}