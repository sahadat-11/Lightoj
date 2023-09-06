//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string a, b, c;
int n, m, p, dp[N][N][N];
int f(int i, int j, int k) {
  if(i >= n or j >= m or k >= p) return 0;
  int &ans = dp[i][j][k];
  if(ans != -1) return ans;
  if(a[i] == b[j] and b[j] == c[k]) {
    ans = 1 + f(i + 1, j + 1, k + 1);
  }
  else {
    ans = max({f(i, j, k + 1), f(i, j + 1, k), f(i + 1, j, k)});
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), p = c.size();
    cout << "Case " << ++cs << ": ";
    cout << f(0, 0, 0) << "\n";;
  }
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string a, b, c;
int n, m, p, dp[N][N][N];
int f(int i, int j, int k) {
  if(i < 0 or j < 0 or k < 0) return 0;
  int &ans = dp[i][j][k];
  if(ans != -1) return ans;
  if(a[i] == b[j] and b[j] == c[k]) {
    ans = 1 + f(i - 1, j - 1, k - 1);
  }
  else {
    ans = max({f(i, j, k - 1), f(i, j - 1, k), f(i - 1, j, k)});
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), p = c.size();
    cout << "Case " << ++cs << ": ";
    cout << f(n - 1, m - 1, p - 1) << "\n";;
  }
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string a, b, c;
int n, m, p, dp[N][N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), p = c.size();
    a = '$' + a, b = '$' + b, c = '$' + c;
    cout << "Case " << ++cs << ": ";
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
        for(int k = 0; k <= p; k++) {
          int &ans = dp[i][j][k];
          if(i == 0 or j == 0 or k == 0) ans = 0;
          else {
            ans = 0;
            if(a[i] == b[j] and b[j] == c[k]) {
            ans = 1 + dp[i - 1][j - 1][k - 1];
           }
           else {
            ans = max({dp[i][j][k- 1], dp[i][j - 1][k], dp[i - 1][j][k]});
           }
          }
        }
      }
    }
    cout << dp[n][m][p] << endl;
  }
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string a, b, c;
int n, m, p, dp[N][N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), p = c.size();
    cout << "Case " << ++cs << ": ";
    for(int i = n; i >= 0; i--) {
      for(int j = m; j >= 0; j--) {
        for(int k = p; k >= 0; k--) {
          int &ans = dp[i][j][k];
          if(i == n or j == m or k == p) ans = 0;
          else {
            ans = 0;
            if(a[i] == b[j] and b[j] == c[k]) {
            ans = 1 + dp[i + 1][j + 1][k + 1];
           }
           else {
            ans = max({dp[i][j][k + 1], dp[i][j + 1][k], dp[i + 1][j][k]});
           }
          }
        }
      }
    }
    cout << dp[0][0][0] << endl;
  }
  return 0;
}
