//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   vector<pair<int, int>> v;
   for(int i = 1; i <= 1000; i++) {
      int cnt = 0;
      for(int j = 1; j * j <= i; j++) {
         if(i % j == 0) {
            cnt++;
            if(j != i / j) {
               cnt++;
            }
         }
      }
      v.push_back({cnt, -i});
   }
   sort(v.begin(), v.end());
   int t, cs = 0; cin >> t;
   while(t--) {
      cout << "Case " << ++cs << ": ";
      int n; cin >> n; 
      cout << -v[n - 1].second << "\n";
   }
   return 0;
}