//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
void solve() {
   int n; cin >> n;
   vector<int> ans;
   ans.push_back(1);
   for(int i = 2; i * i <= n; i++) {
    int cnt = 0;
    while(n % i == 0) {
        n /= i;
        cnt++;
    }
    int sz = ans.size(), x = i;
    bool flag = false;
    while(cnt) {
        if(flag) {
            for(int j = 0; j < sz; j++) {
                ans.push_back(x * ans[j]);
            }
        }
        else {
            for(int j = sz - 1; j >= 0; j--) {
                ans.push_back(x * ans[j]);
            }
        }
        x *= i;
        flag ^= true;
        cnt--;
    }
   }
   if(n > 1) {
     for(int i = ans.size() - 1; i >= 0; i--) {
        ans.push_back(n * ans[i]);
     }
   }
   for(auto u : ans) cout << u << " ";
   cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, cs = 0; 
  cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ":\n";
    solve();
  }
  return 0;
}