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