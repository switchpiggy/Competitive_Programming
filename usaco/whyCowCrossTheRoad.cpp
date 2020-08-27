#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, m;
vector<pair<ll, ll>> v;
vector<ll> c;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a);
        c.push_back(a);
    }

    sort(c.begin(), c.end());

    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    ll ans = 0;
    
    for(ll i = 0; i < n; ++i) {
        if(!v.size()) break;
        ll cur = c[i];

        for(ll j = 0; j < v.size(); ++j) {
            if(c[i] >= v[j].first && c[i] <= v[j].second) {
                ans++;
                v.erase(v.begin() + j);
                break;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}