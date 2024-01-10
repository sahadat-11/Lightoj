//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7, mod = 1000003;
int fact[N];
int binexp(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) { // if b in odd
			ans = (ans * 1ll * a) % mod; // type cast for integer overflow
		}
		a = (a * 1ll * a) % mod;
		b >>= 1; // b / 2;
	}
	return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for(int i = 1; i < N; i++) {
  	fact[i] = (fact[i - 1] * 1ll * i) % mod;
  }
  int q, cs = 0; cin >> q;
  while(q--) {
  	cout << "Case " << ++ cs << ": ";
  	int n, r; cin >> n >> r;
  	int ans = fact[n]; // ncr = n! / ((n - r)! * r!);
  	int den = (fact[n - r] * 1ll * fact[r]) % mod;
  	ans = (ans * 1ll * binexp(den, mod - 2)) % mod; //(a / b) = a * (b ^-1);
  	cout << ans << "\n";
  }
   
  return 0;
}