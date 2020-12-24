#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c[2007], k[2007];
pair<ll, ll> cp[2007];
vector<pair<ll, pair<ll, ll>>> e;
vector<ll> res;
vector<pair<ll, ll>> res2;

ll p[2007], r[2007];

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
}

ll kruskal() {
    sort(e.begin(), e.end());
    ll ans = 0;
    for(ll i = 0; i < (ll)e.size(); ++i) {
        if(get(e[i].second.first) != get(e[i].second.second)) {
            uni(e[i].second.first, e[i].second.second);
            ans += e[i].first;
            if(e[i].second.first == 0) res.push_back(e[i].second.second);
            else res2.push_back({e[i].second.first, e[i].second.second});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 1; i <= n; ++i) {
        cin >> cp[i].first >> cp[i].second;
    }

    for(ll i = 1; i <= n; ++i) {
        cin >> c[i];
        e.push_back({c[i], {0, i}});
    }

    for(ll i = 1; i <= n; ++i) cin >> k[i];

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(i == j) continue;
            e.push_back({(k[i] + k[j]) * (abs(cp[i].first - cp[j].first) + abs(cp[i].second - cp[j].second)), {i, j}});
        }
    }

    cout << kruskal() << '\n';
    cout << (ll)res.size() << '\n';
    for(ll i : res) cout << i << ' ';
    cout << '\n';
    cout << (ll)res2.size() << '\n';
    for(pair<ll, ll> i : res2) cout << i.first << ' ' << i.second << '\n';
    return 0;
}