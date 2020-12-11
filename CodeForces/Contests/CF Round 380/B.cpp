#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[1007][1007], lr[1007], rr[1007], lc[1007], rc[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) lr[i]  = rr[i] = -1;
    for(ll i = 0; i < m; ++i) lc[i]  = rc[i] = -1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> a[i][j];
            if(!a[i][j]) continue;
            rr[i] = max(rr[i], j);
            rc[j] = max(rc[j], i);
            if(lr[i] == -1) lr[i] = j;
            else lr[i] = min(lr[i], j);
            if(lc[j] == -1) lc[j] = i;
            else lc[j] = min(lc[j], i);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            if(a[i][j]) continue;
            ans += (j > lr[i] && lr[i] != -1) + (j < rr[i]) + (i < rc[j]) + (i > lc[j] && lc[j] != -1);
        }
    }

    cout << ans << '\n';
    return 0;
}