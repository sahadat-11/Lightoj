//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
int count_traling_zeroes(int n) {
	int cnt = 0;
	while(n) {
		cnt += n / 5;
		n /= 5;
	}
	return cnt;
}
void solve() {
   int q; cin >> q;
   int l = 1, r = 5 * q; // highest 5 * q  te q trailing zeroes thak
   int ans = 0;
   while(l <= r) {
   	int mid = l + (r - l) / 2;
   	int k = count_traling_zeroes(mid);
   	if(k == q) {
      ans = mid;
      r = mid - 1;
   	}
   	else if(k > q) {
   		r = mid - 1;
   	}
   	else if(k < q) {
   		l = mid + 1;
   	}
   }
   if(ans == 0) {
   	cout << "impossible\n";
   }
   else {
   	cout << ans << "\n";
   }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, cs = 0; 
  cin >> t;
  while(t--) {
  	cout << "Case " << ++ cs << ": ";
    solve();
  }
  return 0;
}

// https://prnt.sc/q8HiaXdwK8Ks