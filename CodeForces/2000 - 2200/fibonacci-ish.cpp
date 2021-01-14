#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, a[1007];
map<ll, ll> occ;
map<ll, ll> occ2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll ans = 2;
    if(occ[0] >= 2) ans = occ[0];

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if((a[i] == 0 && a[j] == 0) || i == j) continue;
            occ2.clear();
            ll e = a[i], f = a[j];
            occ2[e]++;
            occ2[f]++;
            ll cur = 2;
            while(occ[e - f] && occ2[e - f] < occ[e - f]) {
                ll d = e - f;
                e = f;
                f = d;
                occ2[d]++;
                cur++;
            }

            ans = max(ans, cur);
            /*if(cur == 4) {
                e = a[i], f = a[j];
                cout << a[i] << ' ' << a[j] << ' ';
                while(occ[e - f]) {
                    ll d = e - f;
                    cout << d << ' ';
                    e = f; 
                    f = d;
                }
            }*/
        }
    }

    cout << ans << '\n';
    return 0;
}