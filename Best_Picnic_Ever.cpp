//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
const int N = 1007;
vector<int> g[N];
bool vis[N];
int n, k, m;
int a[N], cnt[N];

void dfs(int u) {
  vis[u] = true;
  cnt[u]++;

  for(auto v : g[u]) {
    if(!vis[v]) {
      dfs(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++) cin >> a[i];
    while(m--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
    }
    for(int i = 1; i <= k; i++) {
      dfs(a[i]);
      for(int j = 1; j <= n; j++) {
        vis[j] = false;
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      //cout << cnt[i] << " ";
      if(cnt[i] == k) ans++;
    }
    cout << "Case " << ++ cs << ": " << ans << "\n";
    for(int i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = false;
      cnt[i] = 0;
    }
  }
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1005;
const int inf = 1e9;
int cnt[N];
vector<int> g[N];
bool vis[N];
int person[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t, cs = 0; cin >> t;
  while(t--) {
     int k, n, m; cin >> k >> n >> m;
     for(int i = 1; i <= k; i++) {
       cin >> person[i];
     }
     while(m--) {
       int u, v; cin >> u >> v;
       g[u].push_back(v);
       //g[v].push_back(u);
     }
     for(int i = 1; i <= k; i++) {
       for(int u = 1; u <= n; u++) {
         vis[u] = false;
       }
       queue<int> q;
       q.push(person[i]);
       vis[person[i]] = true;
       while(!q.empty()) {
         int u = q.front();
         cnt[u]++;
         q.pop();
         for(auto v : g[u]) {
           if(!vis[v]) {
             q.push(v);
             vis[v] = true;
           }
         }
       }
     }
     int ans = 0;
     for(int u = 1; u <= n; u++) {
       if(cnt[u] == k) ans++;
     }
     cout << "Case " << ++cs << ": " << ans << "\n";
     for(int u = 1; u <= n; u++) {
       g[u].clear();
       vis[u] = false;
       cnt[u] = 0;
     }
  }
  return 0;
}
