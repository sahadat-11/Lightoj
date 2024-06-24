//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 205, M = 12, D = 22, mod = 1e9 + 7;
#define int long long
int dp[N][M][D], a[N];
int n, m, d;

int func(int i, int cnt, int sum) {
	if(cnt > m) return 0;
	if(i == n + 1) {
		if(cnt == m and sum == 0) return 1;
		return 0;
	}
	if(dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
  int ans = func(i + 1, cnt, sum); // not taken
  ans += func(i + 1, cnt + 1, (sum + (a[i] % d) + d) % d); // taken
  dp[i][cnt][sum] = ans;
  return dp[i][cnt][sum];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  	cout << "Case " << ++ cs << ":\n";
  	int q; cin >> n >> q;
  	for(int i = 1; i <= n; i++) cin >> a[i];
  	while(q--) {
      memset(dp, -1, sizeof dp);
  		cin >> d >> m;
      cout << func(1, 0, 0) << "\n";
  	}
  }
  return 0;
}
// https://prnt.sc/aeI-2JR6j2FO