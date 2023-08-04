//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1005;
const int inf = 1e9;
int cnt[N];
vector<int> adj[N];
bool visited[N];
int person[N];

void dfs(int u) {
   visited[u] = true;
   cnt[u]++;
   for(auto v : adj[u]) {
     if(!visited[v]) {
       dfs(v);
     }
   }
}
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
       adj[u].push_back(v);
       //adj[v].push_back(u);
     }
     for(int i = 1; i <= k; i++) {
       for(int u = 1; u <= n; u++) {
         visited[u] = false;
       }
       dfs(person[i]);
     }
     int ans = 0;
     for(int u = 1; u <= n; u++) {
       if(cnt[u] == k) ans++;
     }
     cout << "Case " << ++cs << ": " << ans << "\n";
     for(int u = 1; u <= n; u++) {
       adj[u].clear();
       visited[u] = false;
       cnt[u] = 0;
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
vector<int> adj[N];
bool visited[N];
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
       adj[u].push_back(v);
       //adj[v].push_back(u);
     }
     for(int i = 1; i <= k; i++) {
       for(int u = 1; u <= n; u++) {
         visited[u] = false;
       }
       queue<int> q;
       q.push(person[i]);
       visited[person[i]] = true;
       while(!q.empty()) {
         int u = q.front();
         cnt[u]++;
         q.pop();
         for(auto v : adj[u]) {
           if(!visited[v]) {
             q.push(v);
             visited[v] = true;
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
       adj[u].clear();
       visited[u] = false;
       cnt[u] = 0;
     }
  }
  return 0;
}
