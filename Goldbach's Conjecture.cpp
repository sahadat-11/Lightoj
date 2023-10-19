//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e7 + 9;
bitset<N>f;
void sieve () {
   f[0] = f[1] = true; 
    for(int i = 4; i <= N; i = i + 2) f[i] = true;
    for(int i = 3; i * i < N; i += 2) {
      if(!f[i]){ 
         for(int j = i * i; j < N; j += 2*i) f[j] = true;
     }
   }
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   sieve();
   vector<ll> prime;
   for(ll i = 2; i < N; i++) {
      if(!f[i]) prime.push_back(i);
   }
   ll t; cin >> t;
   for(ll cs = 1; cs <= t; cs++) {
      ll n; cin >> n;
      ll cnt = 0;
      for(auto a : prime) {
         if(a > n) break;
         ll b = n - a;
         if(!f[b] and a <= b) cnt++;
      }
      cout << "Case " << cs << ": " << cnt << "\n";
   }
  return 0;
 }
 