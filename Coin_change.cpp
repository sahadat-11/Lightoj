//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int  N = 105, K = 1005, mod = 100000007;
int a[N], c[N], dp[N][K], n, k; 
int f(int i, int cur_val) {
  if(cur_val > k) return 0;
  if(i == n + 1) {
    if(cur_val == k) return 1;
    return 0;
  }
  int &ans = dp[i][cur_val];
  if(ans != -1) return ans;
  ans = 0; // 0 kore nite hobe na hoi ans er vitor -1 ase;
  for(int cnt = 0; cnt <= c[i]; cnt++) {
    ans += f(i + 1, cur_val + a[i] * cnt);
    //ans %= mod;
    if(ans >= mod) ans -= mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> c[i];
  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": ";
  cout << f(1, 0) << "\n";
 }
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int  N = 105, K = 1005, mod = 100000007;
int a[N], c[N], dp[N][K], n, k; 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> c[i];
  for(int i = n + 1; i >= 1; i--) {
    for(int cur_val = 0; cur_val <= k; cur_val++) {
      int &ans = dp[i][cur_val];
      if(i == n + 1) {
        if(cur_val == k) ans = 1;
        else ans = 0;
      }
      else {
        ans = 0;
        for(int cnt = 0; cnt <= c[i]; cnt++) {
          int next_val = cur_val + a[i] * cnt;
          if(next_val <= k) {
            ans += dp[i + 1][next_val];
            if(ans >= mod) ans -= mod;
          }
        }
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  cout << dp[1][0] << "\n";
 }
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int  N = 105, K = 1005, mod = 100000007;
int a[N], c[N], dp[N][K], n, k; 
int f(int i, int cur_val) {
  if(cur_val < 0) return 0;
  if(i == n + 1) {
    if(cur_val == 0) return 1;
    return 0;
  }
 if(dp[i][cur_val] != -1) return dp[i][cur_val];
  int ans = 0;
  for(int cnt = 0; cnt <= c[i]; cnt++) {
    if(k - (a[i] * cnt) >= 0) {
    ans += f(i + 1, cur_val - (a[i] * cnt));
    ans %= mod;
   } 
  }
  return dp[i][cur_val] = ans;
} 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> c[i];
  cout << "Case " << ++cs << ": ";
  memset(dp, -1, sizeof dp);
  cout << f(1, k) << "\n";
 }
  return 0;
}
