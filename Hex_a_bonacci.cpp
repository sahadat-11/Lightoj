//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 7,mod = 10000007;
int a, b, c, d, e, f;
int dp[N];

int func(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n] != -1) return dp[n];
    dp[n] = (func(n - 1) + func(n - 2))% mod;
    dp[n] = (dp[n] + func(n - 3)) % mod; 
    dp[n] = (dp[n] + func(n - 4)) % mod; 
    dp[n] = (dp[n] + func(n - 5)) % mod; 
    dp[n] = (dp[n] + func(n - 6)) % mod;     
    return dp[n];
}

int32_t main() {
   int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", caseno, func(n) % mod);
    }
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 7,mod = 10000007;
int a, b, c, d, e, f;
int dp[N];
int32_t main() {
   int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        dp[0] = a, dp[1] = b, dp[2] = c, dp[3] = d;
        dp[4] = e, dp[5] = f;
        for(int i = 6; i <= n; i++) {
          dp[i] = dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod + dp[i - 4] % mod + dp[i - 5] % mod + dp[i - 6] % mod;
        }
        printf("Case %d: %d\n", caseno, dp[n] % mod);
    }
  return 0;
}

