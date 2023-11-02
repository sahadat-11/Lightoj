//In The Name of AintAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+ 7;
int a[N];
struct node {
	int first_element, first_element_occ;
	int last_element, last_element_occ;
	int strong_community;
};
node t[4 * N];
node merge(node l, node r) {
	if(l.first_element == -1) {
		return r;
	}
	if(r.first_element == -1) {
		return l;
	}
	node ans;
	ans.first_element = l.first_element;
	ans.first_element_occ = l.first_element_occ;
	if(l.first_element == r.first_element) {
		ans.first_element_occ += r.first_element_occ;
	}
	ans.last_element = r.last_element;
	ans.last_element_occ = r.last_element_occ;
	if(r.last_element == l.last_element) {
		ans.last_element_occ += l.last_element_occ;
	}
	ans.strong_community = max(l.strong_community, r.strong_community);
    if(l.last_element == r.first_element) {
    	ans.strong_community = max(ans.strong_community, l.last_element_occ + r.first_element_occ);
    }
	return ans;
}
void build(int n, int b, int e) {
	if(b == e) {
		t[n].first_element = a[b], t[n].first_element_occ = 1; 
		t[n].last_element = a[b], t[n].last_element_occ = 1;
		t[n].strong_community = 1;
		return; 
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[n] = merge(t[l], t[r]);
}
node query(int n, int b, int e, int i, int j) {
	if(e < i or j < b) return {-1, -1, -1, -1, -1};
	if(b >= i and j >= e) {
		return t[n]; 
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);  
    int t, cs = 0; cin >> t;
    while(t--) {
    	cout << "Case " << ++cs << ":\n";
    	int n, c, q; cin >> n >> c >> q;
    	for(int i = 1; i <= n; i++) cin >> a[i];
    	build(1, 1, n);
    	while(q--) {
    		int i, j; cin >> i >> j;
    		node ans = query(1, 1, n, i, j);
    		cout << ans.strong_community << endl;
    	}
    }
}
//https://prnt.sc/qfDWYCu-h27r
//https://prnt.sc/uBqaN6W3eQDr