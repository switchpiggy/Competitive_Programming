#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x;
ll c[17], p[17][17], t[17], ans = INT_MAX;

int main() {
    scanf("%lld %lld %lld", &n, &m, &x);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &c[i]);
        for(ll j = 0; j < m; ++j) scanf("%lld", &p[i][j]);
    }

    for(ll mask = 0; mask < (1 << n); ++mask) {
        ll cost = 0;
        memset(t, 0, sizeof(t));

        for(ll i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                cost += c[i];
                for(ll j = 0; j < m; ++j) t[j] += p[i][j];
            }
        }

        bool ok = 0;
        for(ll i = 0; i < m; ++i) {
            if(t[i] < x) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            ans = min(cost, ans);
        }
    }

    if(ans == INT_MAX) ans = -1;
    printf("%lld\n", ans);
    return 0;
}