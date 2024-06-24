//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
int n, a[N], dp[N][N];
int func(int i, int last_is_taken) {
	if(i == n + 1) return 0;
	int ans = func(i + 1, 0); // not taken
	if(!last_is_taken) {
		ans = max(ans, a[i] + func(i + 1, 1));
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
  	cout << func(1, 0) << "\n";
  }
  return 0;
}

// this solution is only for not circular



//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
int n, a[N], dp[N][2][2];
int func(int i, int last_is_taken, int first_is_taken) {
	if(i == n + 1) return 0;
	int &ans = dp[i][last_is_taken][first_is_taken];
	if(ans != -1) return ans;
	ans = func(i + 1, 0, first_is_taken); // not taken;
	if(i == n) {
		if(!last_is_taken and !first_is_taken) {
			ans = max(ans, a[i] + func(i + 1, 1, first_is_taken));
		}
	}
	else {
	if(!last_is_taken) {
		ans = max(ans, a[i] + func(i + 1, 1, first_is_taken));
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
  	int ans = func(2, 0, 0);
  	ans = max(ans, a[1] + func(2, 1, 1));
  	cout << ans << "\n";
  }
  return 0;
}
