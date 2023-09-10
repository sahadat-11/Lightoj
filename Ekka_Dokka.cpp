//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
      ll n; cin >> n;
      if(n % 2) {
         cout << "Impossible\n";
         return;
      }
      ll x = n;
      ll even = 1;
      while(n % 2 == 0) {
         even *= 2;
         n /= 2;
      }
      cout << x / even << " " << even << "\n";
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   int cs = 0;
   while(t--) {
      cout << "Case " << ++cs << ": ";
      solve();
   }
   
    return 0;
}