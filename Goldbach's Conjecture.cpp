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
 
 //In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
bitset<N>f; // initially false;
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   f[0] = f[1] = true; 
   for(int i = 4; i <= N; i += 2) f[i] = true;
   for(int i = 3; i * i <= N; i += 2) {
      if(!f[i]) {
      for(int j = i * i; j <= N; j += 2 * i) f[j] = true;
     } // i*i because (i+i) always a even number large from 2, which is already cut in 2 er condition
   }
   int t, cs = 0; cin >> t;
   while(t--) {
      cout << "Case " << ++cs << ": ";
      int n; cin >> n;
      int ways = 0;
      if(n == 4) ways = 1;
      for(int i = 3; i <= n / 2; i += 2) {
         if(!f[i] and !f[n - i]) ways++;
      }
      cout << ways << "\n";
   }
   return 0;
}


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
   int t, cs = 0; cin >> t;
   while(t--) {
      int n; cin >> n;
      int cnt = 0;
      for(int i = 2; i <= n / 2; i++) {
         if(!f[i] and !f[n - i]) cnt++;
      }
      cout << "Case " << ++cs << ": ";
      cout << cnt << "\n";
   }
  return 0;
 }