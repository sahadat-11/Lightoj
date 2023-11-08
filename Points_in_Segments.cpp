//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t, cs = 0; cin >> t;
   while(t--) {
      cout << "Case " << ++cs << ": \n";
      int n, q; cin >> n >> q; int a[n];
      for(int i = 0; i < n; i++) cin >> a[i];
      sort(a, a + n);
      while(q--) {
         int x, y; cin >> x >> y;
         int lb = lower_bound(a, a + n, x) - a;
         int ub = upper_bound(a, a + n, y) - a;
         cout << ub - lb << "\n";
      }
   }
   return 0;
}