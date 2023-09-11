//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int check(string s) {
   int dec = 0;
   for(int i = 0; i < s.size(); i++) {
      int bit = s[i] - '0';
      dec = dec * 2 + bit;
   }
   return dec;
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t; cin >> t;
   int cs = 0;
   while(t--) {
      int a, b, c, d; char ch;
      cin >> a >> ch >> b >> ch >> c >> ch >> d;
      string s; cin >> s;
      int x = check(s.substr(0,8));
      int y = check(s.substr(9,8));
      int z = check(s.substr(18,8));
      int xx = check(s.substr(27,8));
      cout << "Case " << ++cs << ": ";
      if(a == x and b == y and c == z and d == xx) cout << "Yes\n";
      else cout << "No\n";
   }
   return 0;
}

// https://prnt.sc/QTiXEBvGmLhF 