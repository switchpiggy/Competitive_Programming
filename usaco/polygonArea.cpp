#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<pair<ll, ll>> v;

ll determinant(ll a, ll b, ll c, ll d) {
    return a * d - b * c;
}

int main() {
    scanf("%lld", &n);
    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        ll cur = 0;
        v.clear();
        scanf("%lld", &k);
        for(ll i = 0; i < k; ++i) {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            v.push_back(make_pair(a, b));
        }
        for(ll i = 0; i < k - 1; ++i) {
            cur += determinant(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
        }
        cur += determinant(v[k - 1].first, v[k - 1].second, v[0].first, v[0].second);
        res = max(res, cur);
    }

    printf("%lld\n", cur);

    return 0;
}