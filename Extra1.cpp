//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int spf[N];
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   for(int i = 1; i < N; i++) spf[i] = i;
   for(int i = 2; i < N; i++) {
     if(spf[i] == i) {
       for(int j = i; j < N; j += i) {
         spf[j] = min(spf[j], i);
       }
     }
   }
   int t; cin >> t;
   while(t--) {
     int n; cin >> n;
     int lpf = spf[n];
     int gpf = 0;
     int total_prime = 0, distinct_prime = 0;
     ll sum_of_divisors = 1;
     int numbers_of_divisors = 1;
     while(n > 1) {
       int k = spf[n];
       gpf = max(gpf, k);
       distinct_prime++;
       int exp = 0;
       int prime_power = 1;
       while(n % k == 0) {
         n /= k;
         total_prime++;
         exp++;
         prime_power *= k;
       }
       numbers_of_divisors = numbers_of_divisors * (exp + 1); 
       sum_of_divisors *= (1LL * prime_power * k - 1) / (k - 1);
       //n /= k;
     }
     cout << lpf <<" " << gpf << " ";
     cout << distinct_prime << " " << total_prime;
     cout << " " << numbers_of_divisors << " "; 
     cout << sum_of_divisors << "\n";
   }
   return 0;
}
// complexity O(nlogn)