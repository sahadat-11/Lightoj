//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t, cs = 0; cin >> t;
   while(t--) {
      ll n, m; cin >> n >> m;
      ll sum = (n / (2 * m)) * (m * m);
      cout << "Case " << ++cs << ": ";
      cout << sum << endl;
   }
   return 0;
}

// https://prnt.sc/lwz1w9hQNTnu 

//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t, cs = 0; cin >> t;
   while(t--) {
      ll n, m; cin >> n >> m;
      ll sum = 0;
      int c = 0;
      for(ll i = m; i <= n; i += m) {
          ll sum1 = i * (i + 1) / 2;
          ll x = i - m;
          ll sum2 = x * (x + 1) / 2;
          ll sum3 = sum1 - sum2;
          c++;
          if(c % 2) {
            sum -= sum3;
          }
          else sum += sum3;
      }
      cout << "Case " << ++cs << ": ";
      cout << sum << endl;
   }
   return 0;
}
//brute force TLE