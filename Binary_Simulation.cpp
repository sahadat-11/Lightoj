//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
string s;
bool lazy[4 * N];
struct node {
  int one, zeros;
};
node t[4 * N];
void push(int n, int b, int e) { // change this
  if (lazy[n] == false) return;
  swap(t[n].one, t[n].zeros);
  if (b != e) {
    int l = 2 * n, r = 2 * n + 1;
    int mid = (b + e) / 2;
    lazy[l] ^= true;
    lazy[r] ^= true;
  }
  lazy[n] = false;
}
node merge(node l, node r) { // change this
  node ans;
  ans.one = l.one + r.one;
  ans.zeros = l.zeros + r.zeros;
  return ans;
}
void build(int n, int b, int e) {
  lazy[n] = false; // change this
  if (b == e) {
    t[n].one = 0, t[n].zeros = 0;
    if(s[b] == '1') {
      t[n].one += 1;
    }
    else {
      t[n].zeros += 1;
    }
    return;
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = (b + e) / 2;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}
node query(int n, int b, int e, int i, int j) { //(i, j) = range
  push(n, b, e);
  if(b > j or e < i) return {0, 0}; // totally out
  if(b >= i and e <= j) {// totally in
    return t[n];
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = (b + e) / 2;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}
void update(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if (j < b || e < i) return;
  if (i <= b && e <= j) {
    lazy[n] = true; //set lazy
    push(n, b, e);
    return;
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = (b + e) / 2;
  update(l, b, mid, i, j);
  update(r, mid + 1, e, i, j);
  t[n] = merge(t[l], t[r]);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0; cin >> t;
    while(t--) {
      cout << "Case " << ++ cs << ":\n";
      cin >> s;
      int n = s.size();
      build(1, 0, n - 1);
      int q; cin >> q;
      while(q--) {
        char type; cin >> type;
        if(type == 'I') {
          int i, j; cin >> i >> j;
          --i; --j;
          update(1, 0, n - 1, i, j);
        }
        else {
          int i; cin >> i;
          --i;
          node ans = query(1, 0, n - 1, i, i);
          if(ans.one) {
            cout << 1 << "\n";
          }
          else {
            cout << 0 << "\n";
          }
        }
      }
    }
    return 0;
}