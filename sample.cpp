//In The Name of AintAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int a[N];
ll t[N * 4], lazy[N * 4];
void push(int n, int b, int e) {
	if(lazy[n] == 0) return;
	t[n] = t[n] + 1ll * (e - b + 1) * lazy[n]; 
	if(b != e) {
		int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
	    lazy[l] += lazy[n];
	    lazy[r] += lazy[n];
	}
	lazy[n] = 0; 
}
void build(int n, int b, int e) {
	if(b == e) {
		t[n] = a[b];
		return;
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[n] = t[l] + t[r];
}

ll query(int n, int b, int e, int i, int j) {
	push(n, b, e);
	if(e < i or j < b) return 0;
	if(b >= i and e <= j) {
		return t[n];
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void update(int n, int b, int e, int i, int j, int x) {
	//push(n, b, e);
	if(e < i or b > j) return;
	if(b >= i and j >= e) {
		lazy[n] = x;
		push(n, b, e);
		return;
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
    update(l, b, mid, i, j, x);
    update(r, mid + 1, e, i, j, x);
    t[n] = t[l] + t[r];
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    build(1, 1, n);
    //for(int i = 1; i <= 4 * n; i++) cout << t[i] << "\n";
    while(q--) {
    	int typ; cin >> typ;
    	if(typ == 1) {
    		int i, j, x; cin >> i >> j >> x;
    		j--;
    		i++; j++;
    		update(1, 1, n, i, j, x);
    	}
    	else {
    		int i; cin >> i;
    		i++;
    		cout << query(1, 1, n, i, i) << "\n";
    	}
    }
    return 0;  
}