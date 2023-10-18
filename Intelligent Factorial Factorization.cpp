//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isprime(int n) {
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
  int t; cin >> t;
  int cs = 0;
  while(t--) {
  	int n; cin >> n;
  	cout << "Case " << ++cs << ": " << n << " = ";
  	for(int i = 2; i <= n; i++) {
  		if(isprime(i)) {
  			int c = 0;
  			for(int j = 2; j <= n; j++) {
                 int x = j;
                 while(x % i == 0) {
                 	c++;
                 	x /= i;
                 }
  			}
  			if(i != 2) cout << " * ";
  			cout << i << " (" << c << ")";
  		}
  		
  	}
  	cout << "\n";
  }

  return 0;
}

// approach 2:
//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
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
   ll t; cin >> t;
   for(ll cs = 1; cs <= t; cs++ ) {
      ll n; cin >> n;
      cout << "Case " << cs << ": " << n << " = ";
      for(ll i = 1; i <= n; i++) {
         if(!f[i]) {
            ll exp = 0;
            for(ll p = i; p <= n; p += i) {
               ll x = p;
               while(x % i == 0) {
                  exp++;
                  x /= i;
               }
            }
            if(i != 2) cout << " * ";
            cout << i << " (" << exp << ")";
         }
      }
      cout << "\n";
   }
  return 0;
 }
 
 // approach 3:
 
 //In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 9;
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
   vector<int>prime;
   for(int i = 2; i < N; i++) {
      if(!f[i]) prime.push_back(i);
   }
   ll t; cin >> t;
   for(ll cs = 1; cs <= t; cs++ ) {
      ll n; cin >> n;
      cout << "Case " << cs << ": " << n << " = ";
      for(auto p : prime) {
            if(p > n) break;
            ll exp = 0;
            for(ll i = p; i <= n; i += p) {
               ll x = i;
               while(x % p == 0) {
                  exp++;
                  x /= p;
               }
            }
            if(p != 2) cout << " * ";
            cout << p << " (" << exp << ")";
         }
      cout << "\n";
   }
  return 0;
 }
