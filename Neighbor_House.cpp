//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 25, inf = 1e9 + 7;
#define int long long
int dp[N][4];
int a[N], b[N], c[N], n;

int func(int i, int pre) {
  if(i == n + 1) return 0;
  if(dp[i][pre] != -1) return dp[i][pre];
  int ans = inf;
  for(int j = 1; j <= 3; j++) {
    if(j != pre) {
      if(j == 1) ans = min(ans, func(i + 1, j) + a[i]);
      if(j == 2) ans = min(ans, func(i + 1, j) + b[i]);
      if(j == 3) ans = min(ans, func(i + 1, j) + c[i]);
    }
  }
  dp[i][pre] = ans;
  return dp[i][pre];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++ cs << ": ";
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    } 
    cout << func(1, 0) << "\n";
  }
  return 0;
}

// n to 1


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, inf = 1e9 + 7;
#define int long long
int dp[N][4];
int a[N], b[N], c[N], n;

int func(int i, int pre) {
  if(i == 0) return 0;
  if(dp[i][pre] != -1) return dp[i][pre];
  int ans = inf;
  for(int j = 1; j <= 3; j++) {
    if(j != pre) {
      if(j == 1) ans = min(ans, func(i - 1, j) + a[i]);
      if(j == 2) ans = min(ans, func(i - 1, j) + b[i]);
      if(j == 3) ans = min(ans, func(i - 1, j) + c[i]);
    }
  }
  dp[i][pre] = ans;
  return dp[i][pre];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++ cs << ": ";
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    } 
    cout << func(n, 0) << "\n";
  }
  return 0;
}

// 1 to n;

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 25, inf = 1e9 + 7;
#define int long long
int dp[N][4];
int a[N], b[N], c[N], n;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++ cs << ": ";
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    } 
    
    dp[0][1] = 0, dp[0][2] = 0, dp[0][2] = 0;

    for(int i = 1; i <= n; i++) {
      dp[i][1] = a[i] + min(dp[i - 1][2] , dp[i - 1][3]);
      dp[i][2] = b[i] + min(dp[i - 1][1] , dp[i - 1][3]);
      dp[i][3] = c[i] + min(dp[i - 1][1] , dp[i - 1][2]);
    }
    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]) << "\n";
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j < 4; j++) {
        dp[i][j] = 0;
      }
    }
  }
  
  return 0;
}

// 1 to n;


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 25, inf = 1e9 + 7;
#define int long long
int dp[N][4];
int a[N], b[N], c[N], n;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++ cs << ": ";
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> c[i];
    } 
    
    dp[n + 1][1] = 0, dp[n + 1][2] = 0, dp[n + 1][2] = 0;

    for(int i = n; i >= 1; i--) {
      dp[i][1] = a[i] + min(dp[i + 1][2] , dp[i + 1][3]);
      dp[i][2] = b[i] + min(dp[i + 1][1] , dp[i + 1][3]);
      dp[i][3] = c[i] + min(dp[i + 1][1] , dp[i + 1][2]);
    }
    cout << min(min(dp[1][1], dp[1][2]), dp[1][3]) << "\n";
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j < 4; j++) {
        dp[i][j] = 0;
      }
    }
  }
  
  return 0;
}

// n to 1