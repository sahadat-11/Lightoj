// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6 + 7;
// double presum[N];
// int main() {
// 	//int n; cin >> n;
// 	// cout << (int) floor(log10(n) + 1); // for n number er digits
//     // double sum = 0;
// 	// for(int i = 1; i <= n; i++) {
// 	// 	sum += log10(i);
// 	// }
// 	// cout << (int) floor(sum + 1) << "\n"; // for n factorial digits
//     //int n, b; cin >> n >> b;
//     //cout << (int) floor((log2(n) / log2(b)) + 1);
//     // double sum = 0;
//     // for(int i = 1; i <= n; i++) {
//     // 	sum += (log2(i) / log2(b));
//     // }
//     // cout << (int) floor(sum + 1); // for b base a factoria of n er digits
//     for(int i = 1; i < N; i++) {
//     	presum[i] = presum[i - 1] + log2(i);
//     }
//     int t; cin >> t;
//     int cs = 0;
//     while(t--) {
//     cout << "Case " << ++cs << ": ";
//     int n, b; cin >> n >> b;
//     double ans = presum[n] / (log2(b));
//     cout << (int) floor(ans + 1) << "\n";
//     }
// 	return 0;
// }

//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
double digit[N];
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   // for(int i = 0; i < N; i++) {
   //   digit[i] = 
   // }
   // int t; cin >> t;
   // while(t--) {
     
   // }
   int n; cin >> n;
   double digit = 0;
   for(int i = 1; i <= n; i++) {
     digit += log10(i);
   }
   cout << (int)floor(digit + 1);
   return 0;
}
