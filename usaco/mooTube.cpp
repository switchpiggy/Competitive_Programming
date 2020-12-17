#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, p[100007], sz[100007], ans[100007];
vector<pair<ll, pair<ll, ll>>> v;
vector<pair<pair<ll, ll>, ll>> queries;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(sz[x] > sz[y]) swap(x, y);
    p[x] = y;
    sz[y] += sz[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 1; i <= n; ++i) sz[i] = 1;

    for(ll i = 0; i < n - 1; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    for(ll i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        queries.push_back({{a, b}, i});
    }

    sort(v.begin(), v.end(), greater<pair<ll, pair<ll, ll>>>());
    sort(queries.begin(), queries.end(), greater<pair<pair<ll, ll>, ll>>());

    ll cur = 0;
    for(ll i = 0; i < q; ++i) {
        while(cur < (ll)v.size() && v[cur].first >= queries[i].first.first) {
            ll x = v[cur].second.first, y = v[cur].second.second;
            if(get(x) != get(y)) uni(x, y);
            cur++;
        }

        ans[queries[i].second] = sz[get(queries[i].first.second)] - 1;
        //for(ll i = 1; i <= n; ++i) cout << p[i] << ' ';
        //cout << '\n';
    }

    for(ll i = 0; i < q; ++i) cout << ans[i] << '\n';
    return 0;
}