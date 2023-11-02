//In The Name of AllAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4 + 7;
int a[N], b[N], ans[N];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n, q; cin >> n >> q;
    	for(int i = 1; i <= n; i++) {
    		cin >> a[i] >> b[i];
    		for(int k = a[i]; k <= b[i]; k++) {
    			ans[k]++;
    		}
    	}
    	while(q--) {
    		int k; cin >> k;
    		cout << ans[k] << "\n";
    	}
    }
    
    return 0;  
}
// O(n * n)


//In The Name of AllAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4 + 7;
int a[N], b[N], Q[N], ans[3 * N];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
    	cout << "Case " << ++cs << ":\n";
    	int n, q; cin >> n >> q;
    	set<int> all;
    	for(int i = 1; i <= n; i++) {
    		cin >> a[i] >> b[i];
    		all.insert(a[i]);
    		all.insert(b[i]);
    	}
    	for(int i = 1; i <= q; i++) {
    		cin >> Q[i];
    		all.insert(Q[i]);
    	}
    	map<int, int> mp;
    	int id = 0;
    	for(auto x : all) {
    		mp[x] = ++id;
    	}
    	for(int i = 1; i <= n; i++) {
    		a[i] = mp[a[i]];
    		b[i] = mp[b[i]];
    	}
    	for(int i = 1; i <= q; i++) {
    		Q[i] = mp[Q[i]];
    	}
    	for(int i = 1; i <= n; i++) {
    		for(int k = a[i]; k <= b[i]; k++) {
    			ans[k]++;
    		}
    	}
    	for(int i = 1; i <= q; i++) {
    		int k = Q[i];
    		cout << ans[k] << "\n";
    	}
    	for(int i = 1; i <= id; i++) {
    		ans[i] = 0;
    	}
    }
    
    return 0;  
}
//https://prnt.sc/j0AT6y0uOETG
//https://prnt.sc/vcrXqtxCNwj6