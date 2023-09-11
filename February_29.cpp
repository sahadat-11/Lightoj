//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll range(ll year) {
   ll ans = year / 4;
   ans -= year / 100;
   ans += year / 400;
   return ans;
} 
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t, cs = 0; cin >> t;
   while(t--) {
      string strmonth; int strdate, stryear; char c;
      cin >> strmonth >> strdate >> c >> stryear;
      string endmonth; int enddate, endyear;
      cin >> endmonth >> enddate >> c >> endyear;
     // cout << strmonth << strdate << stryear << endl;
      if(strmonth != "January" and strmonth != "February") stryear++;
      if(endmonth == "January" or (endmonth == "February" and enddate < 29)) endyear--;
     // cout << stryear << " " << endyear << endl;
      cout << "Case " << ++cs << ": ";
      cout << range(endyear) - range(stryear - 1) << "\n";
   
   }

   return 0;
}
//https://prnt.sc/WuwpkqZmUs2Y 