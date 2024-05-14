//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
void solve() {
   int n, q; cin >> n >> q;
   vector<int> v(n);
   for(int i = 0; i < n; i++) cin >> v[i];
   int sum = 0;
   for(int i = 0; i < n; i++) {
   	sum += (n - 1 - i) * v[i] - i * v[i]; // (n - 2*i - 1)
   }
   //cout << sum << "\n";
   while(q--) {
   	int type; cin >> type;
   	if(type == 0) {
      int x, val; cin >> x >> val;
      sum -= (n - 1 - x) * v[x] - x * v[x];
      v[x] = val;
      sum += (n - 1 - x) * v[x] - x * v[x];
   	}
   	else {
   	  cout << sum << "\n";
   	}
   }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, cs = 0; 
  cin >> t;
  while(t--) {
  	cout << "Case " << ++ cs << ":\n";
    solve();
  }
  return 0;
}