#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007], q, w, k[300007];
map<ll, ll> occ;
bool comp[300007];

void sieve() {
    for(ll i = 2; i <= 1001; ++i) {
        if(comp[i]) continue;
        for(ll j = 2 * i; j <= 1001; j += i) comp[j] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();

    cin >> t;
    while(t--) {
        cin >> n;
        occ.clear();
        ll maxn = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            ll cur = a[i];
            for(ll j = 2; j * j <= a[i]; ++j) {
                if(comp[j]) continue;
                if(j * j > cur) break;
                while(cur%(j * j) == 0) cur /= j * j;
            }

            //cur = a[i]/(cur * cur);

            k[i] = cur;
            occ[cur]++;
            maxn = max(maxn, occ[cur]);
        }

        ll ans = maxn;

        //for(ll i = 0; i < n; ++i) cout << k[i] << ' ';

        ll cnt = 0;
        for(ll i = 0; i < n; ++i) {
            if(occ[k[i]]%2 == 0 && k[i] != 1) {
                cnt++;
            } else maxn = max(maxn, occ[k[i]]);
        }

        maxn = max(maxn, cnt + occ[1]);

        cin >> q;
        while(q--) {
            cin >> w;
            if(w == 0) cout << ans << '\n';
            else cout << maxn << '\n';
        }
    }

    return 0;
}