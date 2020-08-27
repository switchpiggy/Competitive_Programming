#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, p, f, cnts, cntw, s, w;

int main() {
   cin >> t;
   while(t--) {
       cin >> p >> f >> cnts >> cntw >> s >> w;
       if(s > w) {
           swap(cnts, cntw);
           swap(s, w);
       }

       ll ans = 0;

       for(ll i = 0; i <= p/s && i <= cnts; ++i) {
            ll temp = min(cntw, (p - (s * i))/w), temp2 = min(cnts - i, f/s), temp3 = min(cntw - temp, (f - (temp2 * s))/w);
            ans = max(ans, i + temp + temp2 + temp3);
       }

       cout << ans << endl;
   } 

   return 0;
}