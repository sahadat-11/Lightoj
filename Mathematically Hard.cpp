//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 5e6 + 7;
int phi[N];
ull prephi[N];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= N; i++) phi[i] = i;
    for(int i = 2; i <= N; i++) {
    	if(phi[i] == i) {
    		for(int j = i; j <= N; j += i) {
    			//phi[j] /= i;
    			//phi[j] *= (i - 1);
    			phi[j] -= phi[j] / i;
    		}
    	}
    }
    //for(int i = 1; i <= 20; i++) cout << phi[i] << "\n";
    prephi[1] = (ull)0;
    for(int i = 2; i <= N; i++) {
    	prephi[i] = prephi[i - 1] + ((ull)phi[i] * (ull)phi[i]);
    }
    int t; cin >> t;
    while(t--) {
    	int a, b; cin >> a >> b;
    	cout << prephi[b] - prephi[a - 1] << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9;

int spf[N];
unsigned long long pref_sum[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
  for (int i = 1; i < N; i++) {
    int x = i, phi_of_i = 1;
    while (x > 1) {
      int p = spf[x], e = 0, pw = 1;
      while (x % p == 0) {
        e++;
        pw *= p;
        x /= p;
      }
      // pw = p^e
      phi_of_i *= (pw / p) * (p - 1); // p^(e-1) * (p-1)
    }
    pref_sum[i] = pref_sum[i - 1] + 1LL * phi_of_i * phi_of_i;
  }

  int t, cs = 0; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    cout << "Case " << ++cs << ": " << pref_sum[b] - pref_sum[a - 1] << '\n';
  }
  return 0;
}

// https://prnt.sc/KRCCVmtCwyW8
// https://prnt.sc/lRUiaLUepq-q 
// https://prnt.sc/Mxrbud_ZU2RM
// https://prnt.sc/csXVbcf6USav