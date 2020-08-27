#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, l, r, d, x, y, pref[100007], a[100007], occ[100007];
vector<pair<pair<ll, ll>, ll>> v;

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld %lld", &l, &r, &d);
        v.push_back(make_pair(make_pair(l, r), d));
    }

    for(ll i = 0; i < k; ++i) {
        scanf("%lld %lld", &x, &y);
        occ[x]++;
        occ[y + 1]--;
    }

    for(ll i = 1; i <= m; ++i) occ[i] += occ[i - 1];

    for(ll itr = 1; itr <= m; ++itr) {
        pair<pair<ll, ll>, ll> p = v[itr - 1];
        pref[p.first.first] += p.second * occ[itr];
        pref[p.first.second + 1] -= p.second * occ[itr];
    }

    for(ll i = 1; i <= n; ++i) pref[i] += pref[i - 1];

    for(ll i = 1; i <= n; ++i) printf("%lld ", a[i] + pref[i]);
    return 0;
}