//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int a[N];
int t[4 * N];
int combine(int a, int b) { // change this
  return a + b;
}
void pull(int n, int l, int r) { // change this
  t[n] = t[l] + t[r];
}
void build(int n, int b, int e) {
	if(b == e) {
		t[n] = a[b];
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	pull(n, l, r);
}
int query(int n, int b, int e, int i, int j) { //(i, j) = range
	if(b > j or e < i) return 0; // totally out
	if(b >= i and e <= j) {// totally in
		return t[n];
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	return combine(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
void update1(int n, int b, int e, int i) {
	if(b > i or e < i) return;
	if(b >= i and e <= i) {
		t[n] = 0;
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	update1(l, b, mid, i);
	update1(r, mid + 1, e, i);
	pull(n, l, r);
}
void update2(int n, int b, int e, int i, int x) {
	if(b > i or e < i) return;
	if(b >= i and e <= i) {
		t[n] += x;
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	update2(l, b, mid, i, x);
	update2(r, mid + 1, e, i, x);
	pull(n, l, r);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t, cs = 0; cin >> t;
	while(t--) {
		cout << "Case " << ++ cs << ":\n";
        int n, q; cin >> n >> q;
	    for(int i = 1; i <= n; i++) cin >> a[i];
	    build(1, 1, n);
	    while(q--) {
	     int op; cin >> op;
	     if(op == 1) {
	       int i; cin >> i;
	       i++; // for 1 indexing
	       int ans = query(1, 1, n, i, i);
	       cout << ans << "\n";
	       update1(1, 1, n, i);
	     }
	     else if(op == 2) {
	     	int i, x; cin >> i >> x;
	     	i++;
            update2(1, 1, n, i, x);
	     }
	     else {
	       int i, j; cin >> i >> j;
	       i++; j++;// for 1 indexing
	       int ans = query(1, 1, n, i, j);
	       cout << ans << "\n";
	     }
	   }
	}
}
