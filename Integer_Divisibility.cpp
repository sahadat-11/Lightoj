//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t, cs = 0; cin >> t;
   while(t--) {
      cout << "Case " << ++cs << ": ";
      ll n, d; cin >> n >> d;
      ll a = 0;
      for(int i = 1; ; i++) {
        a = (a * 10 + d) % n;
        if(a == 0) {
          cout << i << "\n";
          break;
        }
      }
   }
   return 0;
}

//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   int cs = 0;
   while(t--) {
      ll n, m; cin >> n >> m;
      int curr = 0, len = 0;
      while(1) {
         curr = (curr * 10 + m) % n;
         len++;
         if(curr == 0) break;
      }
      cout << "Case " << ++cs << ": ";
      cout << len << "\n";
   }
   
    return 0;
}