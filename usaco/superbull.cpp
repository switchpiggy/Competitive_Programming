#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[2007], p[2007], r[2007];
vector<pair<ll, ll>> v;

bool comp(pair<ll, ll> x, pair<ll, ll> y) {
    return (a[x.first]^a[x.second]) > (a[y.first]^a[y.second]);
}

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
}

ll mst() {
    sort(v.begin(), v.end(), comp);
    ll ans = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(get(v[i].first) != get(v[i].second)) {
            uni(v[i].first, v[i].second);
            ans += a[v[i].first]^a[v[i].second];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    cin >> n;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            v.push_back({i, j});
        }
    }

    cout << mst() << '\n';
    return 0;
}