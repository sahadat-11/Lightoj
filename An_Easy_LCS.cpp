//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N][N];
string dp[N][N];
string a, b;
int n, m;
string f(int i, int j) {
	if(i >= n or j >= m) return "";
	if(vis[i][j]) return dp[i][j];
	string ans = "";
	if(a[i] == b[j]) {
    ans = string(1, a[i]) + f(i + 1, j + 1);
	}
	else {
		string x = f(i + 1, j);
		string y = f(i, j + 1);
		if(x.size() > y.size()) ans = x;
		else if(x.size() < y.size()) ans = y;
		else ans = min(x, y);
	}
	vis[i][j] = true;
	dp[i][j] = ans; 
	return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  cin >> a >> b;
  n = a.size(), m = b.size();
  string ans = f(0, 0);
  cout << "Case " << ++cs << ": ";
  if(ans.empty()) cout << ":(\n";
  else cout << ans << "\n";
  memset(vis, 0, sizeof vis);
 } 
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
string dp[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  a = '$' + a, b = '$' + b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + a[i];
      else {
      	if(dp[i][j - 1].size() > dp[i - 1][j].size()) dp[i][j] = dp[i][j - 1];
        else if(dp[i][j - 1].size() < dp[i - 1][j].size()) dp[i][j] = dp[i - 1][j];
        else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  if(dp[n][m].empty()) dp[n][m] = ":(";
  cout << dp[n][m] << "\n";
 }
  return 0;
}