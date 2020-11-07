#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, nr, ng, nb, r[100007], g[100007], b[100007];

ll calc(ll x, ll y, ll z) {
    if(x < 0 || y < 0 || z < 0) return LONG_LONG_MAX;
    return abs(r[x] - g[y]) * abs(r[x] - g[y]) + abs(g[y] - b[z]) * abs(g[y] - b[z]) + abs(r[x] - b[z]) * abs(r[x] - b[z]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> nr >> ng >> nb;
        for(ll i = 0; i < nr; ++i) cin >> r[i];
        for(ll i = 0; i < ng; ++i) cin >> g[i];
        for(ll i = 0; i < nb; ++i) cin >> b[i];

        sort(r, r + nr);
        sort(g, g + ng);
        sort(b, b + nb);

        ll ans = LONG_LONG_MAX;
        for(ll j = 0; j < ng; ++j) {
            ll i = upper_bound(r, r + nr, g[j]) - r - 1;
            ll k = lower_bound(b, b + nb, g[j]) - b;
            if(k >= nb) k--;
            if(i >= nr) i--;
            i = max(0ll, i);

            ans = min(ans, calc(i, j, k));

            i = lower_bound(r, r + nr, g[j]) - r;
            k = upper_bound(b, b + nb, g[j]) - b - 1;
            if(i >= nr) i--;
            if(k >= nb) k--;
            k = max(0ll, k);

            ans = min(ans, calc(i, j, k));
        }

        for(ll i = 0; i < nr; ++i) {
            ll j = upper_bound(g, g + ng, r[i]) - g - 1;
            ll k = lower_bound(b, b + nb, r[i]) - b;
            if(k >= nb) k--;
            if(j >= ng) j--;
            j = max(0ll, j);

            ans = min(ans, calc(i, j, k));

            j = lower_bound(g, g + ng, r[i]) - g;
            k = upper_bound(b, b + nb, r[i]) - b - 1;
            if(k >= nb) k--;
            if(j >= ng) j--;
            k = max(0ll, k);

            ans = min(ans, calc(i, j, k));
        }

        for(ll k = 0; k < nb; ++k) {
            ll i = lower_bound(r, r + nr, b[k]) - r;
            ll j = upper_bound(g, g + ng, b[k]) - g - 1;
            if(i >= nr) i--;
            if(j >= ng) j--;
            j = max(0ll, j);

            ans = min(ans, calc(i, j, k));

            i = upper_bound(r, r + nr, b[k]) - r - 1;
            j = lower_bound(g, g + ng, b[k]) - g;
            if(i >= nr) i--;
            if(j >= ng) j--;
            i = max(0ll, i);

            ans = min(ans, calc(i, j, k));
        }

        cout << ans << '\n';
    }

    return 0;
}