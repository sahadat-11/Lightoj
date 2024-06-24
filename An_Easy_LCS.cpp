//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7;
#define int long long
string dp[N][N];
bool vis[N][N];
int n, m;
string a, b;

string func(int i, int j) {
  if(i == n or j == m) return "";
  if(vis[i][j]) return dp[i][j];
  vis[i][j] = true;
  string ans = "";
  if(a[i] == b[j]) {
    ans = string(1, a[i]) + func(i + 1, j + 1);
  }
  else {
    string x = func(i, j + 1);
    string y = func(i + 1, j);
    if(x.size() > y.size()) {
      ans = x;
    }
    else if(x.size() < y.size()) {
      ans = y;
    }
    else {
      ans = min(x, y);
    }
  }
  dp[i][j] = ans;
  return dp[i][j];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
   cout << "Case " << ++ cs << ": ";
   cin >> a >> b;
   n = a.size(), m = b.size();
   memset(vis, 0, sizeof vis);
   string ans = func(0, 0);
   if(ans.size() == 0) {
    cout << "(\n";
   }
   else {
    cout << ans  << "\n";
   }
  }
  return 0;
}



//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7;
#define int long long
string dp[N][N];
int n, m;
string a, b;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
   cout << "Case " << ++ cs << ": ";
   cin >> a >> b;
   n = a.size(), m = b.size();
   dp[n][m] = "";
   for(int i = n - 1; i >= 0; i--) {
    for(int j = m - 1; j >= 0; j--) {
      if(a[i] == b[j]) {
        dp[i][j] = string(1, a[i]) + dp[i + 1][j + 1];
      }
      else {
        string ans;
        string x = dp[i][j + 1];
        string y = dp[i + 1][j];
        if(x.size() > y.size()) {
          ans = x;
        }
        else if(x.size() < y.size()) {
          ans = y;
        }
        else {
          ans = min(x, y);
        }
        dp[i][j] = ans;
      }
    }
   }
   if(dp[0][0].size() == 0) {
    cout << ":(\n";
   }
   else cout << dp[0][0] << "\n";
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dp[i][j] = "";
    }
   }
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
