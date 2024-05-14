//In The Name of AintAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int lazy[N * 4];
struct node {
	int mod[3];
};
node t[N * 4];
void push(int n, int b, int e) {
	if(lazy[n] == 0) return;
	node cur = t[n];
	for(int i = 0; i < 3; i++) {
		t[n].mod[(i + lazy[n]) % 3] = cur.mod[i];
	} 
	if(b != e) {
		int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
	    lazy[l] = (lazy[l] + lazy[n]) % 3;
	    lazy[r] = (lazy[r] + lazy[n]) % 3;
	}
	lazy[n] = 0; 
}
node merge(node l, node r) {
	node ans;
	for(int i = 0; i < 3; i++) {
		ans.mod[i] = l.mod[i] + r.mod[i];
	}
	return ans;
}
void build(int n, int b, int e) {
	lazy[n] = 0;
	if(b == e) {
		t[n].mod[0] = 1;
		t[n].mod[1] = 0;
	    t[n].mod[2] = 0;
		return;
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[n] = merge(t[l], t[r]);
}

int query(int n, int b, int e, int i, int j) {
	push(n, b, e);
	if(e < i or j < b) return 0;
	if(b >= i and e <= j) {
		return t[n].mod[0];
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void update(int n, int b, int e, int i, int j, int x) {
	push(n, b, e);
	if(e < i or b > j) return;
	if(b >= i and j >= e) {
		lazy[n] = x;
		push(n, b, e);
		return;
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
    update(l, b, mid, i, j, x);
    update(r, mid + 1, e, i, j, x);
    t[n] = merge(t[l], t[r]);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
    	cout << "Case " << ++cs << ": \n";
    	int n, q; cin >> n >> q;
        build(1, 1, n);
        //for(int i = 1; i <= 4 * n; i++) cout << t[i] << "\n";
        while(q--) {
    	    int typ; cin >> typ;
    	    if(typ == 0) {
    		   int i, j; cin >> i >> j;
    		   i++; j++;
    		   update(1, 1, n, i, j, 1);
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