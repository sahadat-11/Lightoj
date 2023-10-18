//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
      ll p, l; cin >> p >> l;
      ll x = p - l;
      vector<ll> divs;
      for(ll i = 1; i * i <= x; i++) {
        if(x % i == 0) {
          if(i > l) divs.push_back(i);
          if(i != x / i) {
            if(x / i > l) divs.push_back(x / i);
          } 
        }
      }
      cout << "Case " << ++cs << ": ";
      if(divs.size() == 0) cout << "impossible\n";
      else {
        sort(divs.begin(), divs.end());
        for(auto u : divs) cout << u << " ";
        cout << "\n";
      }
    } 
    return 0;
}

// https://prnt.sc/0nLMyGxq2toL


