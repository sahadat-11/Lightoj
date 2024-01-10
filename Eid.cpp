//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9;
ll lcmfind(ll a, ll b) {
	return a / (__gcd(a, b)) * b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	int t, cs = 0; cin >> t;
	while(t--) {
		cout << "Case " << ++cs << ": ";
		int n; cin >> n; int a[n];
		ll lcm = 1;
		for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
    	lcm = lcmfind(lcm, a[i]);
    }
    cout << lcm << "\n";
	}
  return 0;
}