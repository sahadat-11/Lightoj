//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
int n, a[N], dp[N][N];
int f(int i, int is_take) {
	if(i == n + 1) return 0;
	int ans = f(i + 1, 0);
	if(!is_take) {
		ans = max(ans, a[i] + f(i + 1, 1));
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
  		cin >> a[i];
  	}
  	memset(dp, -1, sizeof dp);
  	cout << "Case " << ++cs << ": ";
  	cout << f(1, 0) << "\n";
  }
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
int n, a[N], dp[N][2][2];
int f(int i, int is_take_last, int is_take_first) {
	if(i == n + 1) return 0;
	int &ans = dp[i][is_take_last][is_take_first];
	if(ans != -1) return ans;
	ans = f(i + 1, 0, is_take_first); // not taken;
	if(i == n) {
		if(!is_take_last and !is_take_first) {
			ans = max(ans, a[i] + f(i + 1, 1, is_take_first));
		}
	}
	else {
	if(!is_take_last) {
		ans = max(ans, a[i] + f(i + 1, 1, is_take_first));
	 }
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
  		cin >> a[i];
  	}
  	memset(dp, -1, sizeof dp);
  	cout << "Case " << ++cs << ": ";
  	int ans = f(2, 0, 0);
  	ans = max(ans, a[1] + f(2, 1, 1));
  	cout << ans << "\n";
  }
  return 0;
}