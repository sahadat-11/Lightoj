//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 10000019;
#define int long long
bitset<N>ff;
vector<int> prime;
int binexp(int a, int b) {
	int ans = 1 % mod; a %= mod; if (a < 0) a += mod;
	while(b) {
		if(b & 1) {
			ans = (ans * 1ll * a) % mod;
		}
		a = (a * 1ll * a) % mod;
		b >>= 1;
	}
	return ans;
}
void solve() {
  int n, t; cin >> n >> t;
  int b = 1;
  for(auto p : prime) {
  	if(p > n) break;
  	int e = 0;
  	int x = n;
  	while(x) {
  	  e += x / p;
  	  x /= p;
  	}
    int f = e / t;
    b = (b * binexp(p, f)) % mod;
  }
  if(b == 1) b = -1;
  cout << b << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ff[0] = ff[1] = true; 
  for(int i = 4; i <= N; i += 2) ff[i] = true;
  for(int i = 3; i * i <= N; i += 2) {
    if(!ff[i]) {
    for(int j = i * i; j <= N; j += 2 * i) ff[j] = true;
   } // i*i because (i+i) always a even number large from 2, which is already cut in 2 er condition
  }
  for(int i = 2; i <= N; i++) {
    if(!ff[i]) prime.push_back(i);
  }
  int tt = 1, cs = 0; 
  cin >> tt;
  while(tt--) {
  	cout << "Case " << ++ cs << ": ";
    solve();
  }
  return 0;
}