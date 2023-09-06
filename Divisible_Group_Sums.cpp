//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 205, M = 12, D = 22;
int n, d, m, a[N];
long long dp[N][M][D];
long long f(int i, int cnt, int sum) {
	if(cnt > m) return 0;
	if(i == n + 1) {
		if(cnt == m and sum == 0) {
			return 1;
		}
		return 0;
	}
  long long &ans = dp[i][cnt][sum];
	if(ans =! -1) return ans;
	ans = f(i + 1, cnt, sum); // not taking
	ans += f(i + 1, cnt + 1, (sum + (a[i] % d + d) % d) % d);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  	cin >> n;
  	int q; cin >> q;
  	for(int i = 1; i <= n; i++) cin >> a[i];
  	cout << "Case " << ++cs << ":\n";
  	while(q--) {
  		memset(dp, -1, sizeof dp);
  		cin >> d >> m;
  		cout << f(1, 0, 0) << '\n';
  	}
  }
  return 0;
}