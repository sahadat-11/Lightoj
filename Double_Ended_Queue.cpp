//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t, cs = 0; cin >> t;
   while(t--) {
      cout << "Case " << ++cs << ":\n";
      int n, q; cin >> n >> q;
      deque<int> de;
      while(q--) {
         string s; cin >> s;
         if(s == "pushLeft") {
         int x; cin >> x;
         if(de.size() < n) {
            de.push_front(x);
            cout << "Pushed in left: " << x << "\n";
         }
         else {
            cout << "The queue is full\n";
         }
      }
      else if(s == "pushRight") {
         int x; cin >> x;
         if(de.size() < n) {
            de.push_back(x);
            cout << "Pushed in right: " << x << "\n";
         }
         else {
            cout << "The queue is full\n";
         }
      }
      else if(s == "popLeft") {
         if(de.empty()) {
            cout << "The queue is empty\n";
         }
         else {
            int x = de.front();
            cout << "Popped from left: " << x << "\n";
            de.pop_front();
         }
      }
      else {
         if(de.empty()) {
            cout << "The queue is empty\n";
         }
         else {
            int x = de.back();
            cout << "Popped from right: " << x << "\n";
            de.pop_back();
         }
       }
      }
   }
   return 0;
}
