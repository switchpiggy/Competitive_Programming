#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[57], b[57];

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(ll i = 0; i < m; ++i) scanf("%lld", &b[i]);

    ll res = 1e18;

    for(ll i = 0; i < n; ++i) {
        ll cur = -1e18;
        for(ll j = 0; j < n; ++j) {
            for(ll k = 0; k < m; ++k) {
                if(i == j) continue;
                cur = max(cur, a[j] * b[k]);
            }
        }

        res = min(cur, res);
    }

    printf("%lld\n", res);
    return 0;
}