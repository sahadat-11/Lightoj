//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 35, mod = 1e9 + 7;
#define int long long
int C[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < N; i++) {
    C[i][i] = 1;
    for(int j = 0; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }

  int t = 1, cs = 0; 
  cin >> t;
  while(t--) {
  	cout << "Case " << ++ cs << ": ";
    int n, k; cin >> n >> k;
    int fact = 1;
    for(int i = 1; i <= k; i++) {
      fact *= i;
    }
    int ans = 1;
    if(k > n) ans = 0;
    ans *= C[n][k] * C[n][k] * fact;
    cout << ans << "\n";
  }
  return 0;
}

// https://prnt.sc/3pHfpzj3bHjQ