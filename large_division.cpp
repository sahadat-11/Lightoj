//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll reduce(string a, int b) {
   ll rem = 0;
   for(int i = 0; i < a.size(); i++) {
      rem = (rem * 10 + (a[i] - '0')) % b;
   }
   return rem;
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t, cs = 0; cin >> t;
   while(t--) {
      string a; int b; cin >> a >> b;
      if(a[0] == '-') a.erase(a.begin() + 0);
     // cout << a << " " << b << endl;
      ll x = reduce(a, b);
      cout << "Case " << ++cs << ": ";
      if(x % b == 0) cout << "divisible\n";
      else cout << "not divisible\n";
   }
   return 0;
}