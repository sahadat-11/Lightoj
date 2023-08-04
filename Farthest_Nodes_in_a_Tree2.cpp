//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e4 + 7;
vector<pair<int, int>> adj[N];
ll dis1[N], dis2[N];
void dfs(int u, int p, int q) {
  for(auto [v, w] : adj[u]) {
    if(v != p) {
      if(q == 1) dis1[v] = dis1[u] + w; // akhane u + hove;
      else dis2[v] = dis2[u] + w;
      dfs(v, u, q);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ":\n";
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
      int u, v, w; cin >> u >> v >> w;
      u++; v++;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    dis1[1] = 0;
    dfs(1, 0, 1);
    int mx = -1, s = 0, e = 0;
    for(int i = 1; i <= n; i++) {
      if(dis1[i] > mx) {
        mx = dis1[i];
        s = i;
      }
    }
    mx = -1;
    dis1[s] = 0;
    dfs(s, 0, 1); // s theke all node distance ds1 array te;
    for(int i = 1; i <= n; i++) {
      if(dis1[i] > mx) {
        mx = dis1[i];
        e = i;
      }
    }
    dfs(e, 0, 2); // e theke all node distance ds1 array te;
    for(int i = 1; i <= n; i++) {
       cout << max(dis1[i], dis2[i]) << "\n";
    }
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
      dis1[i] = 0;
      dis2[i] = 0;
    }
  }
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 7, inf = 1e9;
vector<pair<int, int>> adj[N];
int n; 
int fartest_node(int s, vector<int> &d) {
  d.resize(n + 1, inf);
  vector<bool> vis(n + 1, false);
  queue<int> q;
   q.push(s);
   d[s] = 0;
   vis[s] = true;
   while(!q.empty()) {
     int u = q.front();
     q.pop();
     for(auto [v, w] : adj[u]) {
       if(!vis[v]) {
         d[v] = d[u] + w;
         vis[v] = true;
         q.push(v);
       }
     }
   }
   int mx_dis = -1, fartest;
   for(int i = 1; i <= n; i++) {
    if(d[i] > mx_dis) {
      mx_dis = d[i];
      fartest = i;
    }
   }
   return fartest;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ": \n";
    cin >> n;
    for(int i = 1; i < n; i++) {
      int u, v, w; cin >> u >> v >> w;
      u++, v++;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    vector<int> ds, de;
    int s = fartest_node(1, ds); // 1 theke bfs chaliye s er index;
    int e = fartest_node(s, ds); // s theke bfs chaliye e er index;
                                 // s theke sobar distance ds a ase;
    fartest_node(e, de);    // e theke sobar distance de  a ase
    for(int i = 1; i <= n; i++) {
      cout << max(de[i], ds[i]) << "\n";
    }
    for(int i = 1; i <= n; i++) {
      adj[i].clear();
    }
  }
  return 0;
}
