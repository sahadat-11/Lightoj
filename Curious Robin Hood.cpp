//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int a[N], t[4 * N];
void build(int n, int b, int e) {
	if(b == e) {
		t[n] = a[b];
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[n] = t[l] + t[r];
}
ll query(int n, int b, int e, int i, int j) {
	if(i > e or b > j) return 0;
	if(b >= i and e <= j) return t[n];
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void update1(int n, int b, int e, int i) {
	if(i > e or b > i) return;
	if(b == e and b == i){
	  t[n] = 0;
	  return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	update1(l, b, mid, i);
	update1(r, mid + 1, e, i);
	t[n] = t[l] + t[r];
}
void update2(int n, int b, int e, int i, int x) {
	if(i > e or b > i) return;
	if(b == e and b == i){
	  t[n] += x;
	  return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	update2(l, b, mid, i, x);
	update2(r, mid + 1, e, i, x);
	t[n] = t[l] + t[r];
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
    	int n, q; cin >> n >> q;
    	cout << "Case " << ++cs << ":\n";
    	for(int i = 1; i <= n; i++) cin >> a[i];
    	build(1, 1, n);
    	while(q--) {
    		int typ; cin >> typ;
    		if(typ == 1) {
    			int i; cin >> i;
    			i++;
    			cout << query(1, 1, n, i, i) << "\n";
    			update1(1, 1, n, i);
    		}
    		else if(typ == 2) {
    			int i, x; cin >> i >> x;
    			i++;
    			update2(1, 1, n, i, x);
    		}
    		else {
    			int i, j; cin >> i >> j;
    			i++; j++;
    			cout << query(1, 1, n, i, j) << "\n";
    		}
    	}
    }
    return 0;
}
//