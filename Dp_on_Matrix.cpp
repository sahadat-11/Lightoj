//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 100, inf = 1e9;
int a[N][N], dp[N][N];
int n, m;
int f(int i, int j) {
	if(i > n or j > m) {
		return inf;
	}
	if(i == n and j == m) {
		return a[i][j];
	}
	int &ans = dp[i][j];
	if(ans != -1) return ans;
	ans = a[i][j] + min(f(i, j + 1), f(i + 1, j));
	return ans;
} 
void print(int i, int j) {
	cout << "(" << i << ", " << j << ") -> ";
  if (i == n and j == m) return;
	int x = f(i + 1, j);
	int y = f(i, j + 1);
	if(x > y) print(i, j + 1);
	else print(i + 1, j);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> m; 
  for(int i = 1; i <= n; i++) {
  	for(int j = 1; j <= m; j++) {
  		cin >> a[i][j];
  	}
  }
  cout << f(1, 1);
  print(1, 1);
  return 0;
}