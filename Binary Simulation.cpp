//In The Name of AintAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
struct node {
	int one, zero;
};
node t[4 * N];
string s; 
bool lazy[N * 4];
void push(int n, int b, int e) {
	if(lazy[n] == false) return;
	swap(t[n].one, t[n].zero);
	if(b != e) {
		int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
	    // lazy[l] = lazy[l] == true ? false : true;
	    // lazy[r] = lazy[r] == true ? false : true;
	    lazy[l] ^= true;
	    lazy[r] ^= true;
	}
	lazy[n] = false; 
}
node merge(node l, node r) {
	node ans;
	ans.one = l.one + r.one;
	ans.zero = l.zero + r.zero;
	return ans;
}
void build(int n, int b, int e) {
	lazy[n] = false;
	if(b == e) {
		t[n].one = 0, t[n].zero = 0;
		if(s[b] == '1') {
			t[n].one = 1;
		}
		else {
			t[n].zero = 1;
		}
		return;
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[n] = merge(t[l], t[r]);
}
void update(int n, int b, int e, int i, int j) {
	push(n, b, e);
	if(e < i or b > j) return;
	if(b >= i and j >= e) {
		lazy[n] = true;
		//push(n, b, e);
		return;
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
    update(l, b, mid, i, j);
    update(r, mid + 1, e, i, j);
    t[n] = merge(t[l], t[r]);
}
node query(int n, int b, int e, int i, int j) {
	push(n, b, e);
	if(e < i or j < b) return {0, 0};
	if(b >= i and e <= j) {
		return t[n];
	}
	int l = 2 * n, r = 2 * n + 1, mid = (b + e) / 2;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
    	cin >> s;
    	int n = s.size();
    	build(1, 0, n - 1);
    	int q; cin >> q;
    	while(q--) {
    		char type; cin >> type;
    		if(type == 'I') {
    			int i, j; cin >> i >> j;
    			--i; --j;
    			update(1, 0, n - 1, i, j);
    		}
    		else {
    			int i; cin >> i;
    			--i;
    			node ans = query(1, 0, n - 1, i, i);
    			if(ans.one) {
    				cout << 1 << "\n";
    			}
    			else {
    				cout << 0 << "\n";
    			}
    		}
    	}
    }
    return 0;  
}