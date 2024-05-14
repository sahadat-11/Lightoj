// //In The Name of ALLAH
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6 + 9;
// bitset<N> f; 
// vector<int> prime;
// void sieve() {
//    f[0] = f[1] = true;
//    for(int i = 4; i <= N; i += 2) f[i] = true;
//    for(int i = 3; i * i <= N; i += 2) {
//       if(!f[i]) {
//          for(int j = i * i; j <= N; j += 2 * i) f[j] = true;
//       }
//    }
//    for(int i = 2; i < N; i++) {
//      if(!f[i]) prime.push_back(i);
//    } 
//    //for(int i = 0; i < prime.size(); i = i + 100) cout << prime[i] << "\n";
// }
// int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    sieve();
//    // for(int i = 1; i < N; i++) {
//    //   for(int j  = i; j < N; j += i) divs[j]++; // divisors pre calculate;
//    // }
//    ll t; cin >> t;
//    for(ll i = 1; i <= t; i++) {
//       ll n; cin >> n;
//       ll div = 1;
//       for(auto p : prime) {
//          if(p * p > n) break;
//          ll power_of_p = 0;
//          while(n % p == 0) {
//             power_of_p++;
//             n /= p;
//          }
//          div *= (power_of_p + 1);
//       }
//       if(n > 1) {
//          ll power_of_p = 1;
//          div *= (power_of_p + 1);
//       }
      
//      cout << "Case " << i << ": " << div - 1 << "\n";
//    }
//    return 0;
// }
// // https://prnt.sc/YS4sjDUoFgWn 
// // https://prnt.sc/zDdoPEslmt-e
// // https://prnt.sc/XCc9dNzLdOLz
// // problem : https://lightoj.com/problem/trailing-zeroes-i