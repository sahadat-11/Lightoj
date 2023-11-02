// //In The Name of AintAH
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main() {
// 	ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t; cin >> t;
//     while(t--) {
//     	int n, q; cin >> n >> q; int a[n];
//     	for(int i = 0; i < n; i++) cin >> a[i];
//     	while(q--) {
//     		int tp; cin >> tp;
//     		if(tp == 1) {
//     			ll sum = 0;
//     			for(int i = 0; i < n; i++) {
//                    sum += (1ll * a[i] * (n - 2 * i - 1));
//     			}
//     			cout << sum << "\n";
//     		}
//     		else {
//     			int i, x; cin >> i >> x;
//     			a[i] = x;
//     		}
//     	}
//     }
//     return 0;
// }
// // O(t * n * q)

//In The Name of AintAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
    	cout << "Case " << ++ cs << ":\n";
    	int n, q; cin >> n >> q; int a[n];
    	for(int i = 0; i < n; i++) cin >> a[i];
    	ll sum = 0;
		for(int i = 0; i < n; i++) {
           sum += (1ll * a[i] * (n - 2 * i - 1));
		}
    	while(q--) {
    		int tp; cin >> tp;
    		if(tp == 1) {
    			// ll sum = 0;
    			// for(int i = 0; i < n; i++) {
                //  sum += (1ll * a[i] * (n - 2 * i - 1));
    			// }
    			cout << sum << "\n";
    		}
    		else {
    			int i, x; cin >> i >> x;
    			sum -= (1ll * a[i] * (n - 2 * i - 1));
    			a[i] = x;
    			sum += (1ll * a[i] * (n - 2 * i - 1));
    		}
    	}
    }
    return 0;
}
// O(t * q)
//https://prnt.sc/E8PLMaVwxfN8