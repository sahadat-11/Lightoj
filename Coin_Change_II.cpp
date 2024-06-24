// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 105, K = 1e4 + 7, mod = 100000007;
// #define int long long
// int a[N], dp[N][K];
// int n, k; 

// int func(int i, int s) {
//   if(i == n + 1) return s == 0;
//   int &ans = dp[i][s];
//   if(ans != -1) return ans;
//   ans = 0;
//   ans += func(i + 1, s); // not take
//   if(s >= a[i]) ans += func(i, s - a[i]);// take
//   ans %= mod;
//   return ans;
// }

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   int t, cs = 0; cin >> t;
//   while(t--) {
// 	  memset(dp, -1, sizeof dp);
// 	  cout << "Case " << ++ cs << ": ";
// 	  cin >> n >> k;
// 	  for(int i = 1; i <= n; i++) {
// 	  	cin >> a[i];
// 	  }
// 	  cout << func(1, k) << "\n"; 
//   }
//   return 0;
// }

// (100 * 100 * 10000) // O(10^8);
// its a tight complexity for this iterative is efficien

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, K = 1e4 + 7, mod = 100000007;
#define int long long
int a[N], dp[N][K];
int n, k; 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
	  memset(dp, -1, sizeof dp);
	  cout << "Case " << ++ cs << ": ";
	  cin >> n >> k;
	  for(int i = 1; i <= n; i++) {
	  	cin >> a[i];
	  }
	  for(int i = n + 1; i >= 1; i--) {
	  	for(int s = 0; s <= k; s++) {
	  	  int &ans = dp[i][s];
	  	  if(i == n + 1) {
	  	  	ans = s == 0;
	  	  }
	  	  else {
            ans = 0;
            ans += dp[i + 1][s];
            if(s >= a[i]) ans += dp[i][s - a[i]];
            ans %= mod;
	  	  }
	  	}
	  }
	  cout << dp[1][k] << "\n"; 
  }
  return 0;
}
