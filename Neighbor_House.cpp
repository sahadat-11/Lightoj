//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
int n, a[N], b[N], c[N], dp[N][N];
int f(int i, int current) {
	if(i == n + 1) return 0;
	int &ans = dp[i][current];
	if(ans != -1) return ans;
	ans = inf;
	for(int k = 0; k < 3; k++) {
		if(k == current) continue;
		if(k == 0) ans = min(ans, a[i] + f(i + 1, 0));
		if(k == 1) ans = min(ans, b[i] + f(i + 1, 1));
		if(k == 2) ans = min(ans, c[i] + f(i + 1, 2));
	}
	return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  	cin >> n;
  	for(int i = 1; i <= n; i++) {
  		cin >> a[i] >> b[i] >> c[i];
  	}
  	memset(dp, -1, sizeof dp);
  	cout << "Case " << ++cs << ": ";
  	cout << f(1, -1) << "\n";
  }
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define ll long long
int n, a[N], b[N], c[N], dp[N][3]; 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i][0] = a[i] + min(dp[i - 1][1] , dp[i - 1][2]);
    dp[i][1] = b[i] + min(dp[i - 1][0] , dp[i - 1][2]);
    dp[i][2] = c[i] + min(dp[i - 1][1] , dp[i - 1][0]);
  }
  cout << "Case " << ++cs << ": ";
  cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
 }
  return 0;
}
