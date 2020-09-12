#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[107];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        occ.clear();

        cin >> n;
       for(ll i = 0; i < n; ++i) {
           cin >> a[i];
           occ[a[i]]++;
       }

        ll res = 0;
       for(ll i = 0; i <= 100; ++i) {
           if(occ[i]) {
               occ[i]--;
               res = i + 1;
           } else break;
       }

       ll res2 = 0;
       for(ll i = 0; i <= 100; ++i) {
           if(occ[i]) res2 = i + 1;
           else break;
       }

        //cout << res << ' ' << res2 << '\n';

       cout << res + res2 << '\n';
    }

    return 0;
}