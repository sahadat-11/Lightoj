//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
void solve() {
   int n, q; cin >> n >> q;
   vector<int> left(n), right(n);
   for(int i = 0; i < n; i++) {
   	cin >> left[i] >> right[i];
   }
   sort(left.begin(), left.end());
   sort(right.begin(), right.end());
   while(q--) {
   	int x; cin >> x;
   	int up = upper_bound(left.begin(), left.end(), x) - left.begin();
   	int lw = lower_bound(right.begin(), right.end(), x) - right.begin();
    cout << up - lw << "\n";
   }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, cs = 0; 
  cin >> t;
  while(t--) {
  	cout << "Case " << ++ cs << ":\n";
    solve();
  }
  return 0;
}

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
// n = 10^5, l, r(0 to 10^8);
// O(n * r) == (10^5 * 10^8)

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

    	// doing co_ordinate compression
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

// n = 10^5, l, r(0 to 10^8);
// O(n * n) == (10^5 * 10^5)
// https://lightoj.com/problem/points-in-segments-ii


//In The Name of AllAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4 + 7;
int a[N], b[N], Q[N];
int t[3 * 4 * N];
int combine(int a, int b) { // change this
  return a + b;
}
void pull(int n, int l, int r) { // change this
  t[n] = t[l] + t[r];
}
void build(int n, int b, int e) {
	if(b == e) {
		t[n] = 0;
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	build(l, b, mid);
	build(r, mid + 1, e);
	pull(n, l, r);
}
ll query(int n, int b, int e, int i, int j) { //(i, j) = range
	if(b > j or e < i) return 0; // totally out
	if(b >= i and e <= j) {// totally in
		return t[n];
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	return combine(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
void update(int n, int b, int e, int i, int x) {
	if(b > i or e < i) return;
	if(b >= i and e <= i) {
		t[n] += x;
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b + e) / 2;
	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);
	pull(n, l, r);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
    	cout << "Case " << ++cs << ":\n";
    	int n, q; cin >> n >> q;

    	// doing co_ordinate compression
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
    	// Co ordinate Compression Done

    	build(1, 1, id);
    	for(int i = 1; i <= n; i++) {
    	  int l = a[i], r = b[i];
    	  update(1, 1, id, l, 1);
    	  update(1, 1, id, r + 1, -1); 
    	}
    	for(int i = 1; i <= q; i++) {
    		int x = Q[i];
    		//cout << ans[k] << "\n";
    		cout << query(1, 1, id, 1, x) << "\n";
    	}
    }
    return 0;  
}