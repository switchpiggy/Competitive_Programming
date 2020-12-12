#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, b, e, w, r[200007], p[200007], ans = 0;
vector<pair<ll, pair<ll, ll>>> v;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);

    p[x] = y;
}

void kruskals() {
    sort(v.begin(), v.end());
    for(ll i = 0; i < (ll)v.size(); ++i) {
        ll x = v[i].second.first, y = v[i].second.second;
        if(get(x) != get(y)) {
            ans += v[i].first;
            uni(x, y);
        }
    }   
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    iota(p + 1, p + n + 1, 1);
    for(ll i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        v.push_back({w, {b, e}});
    }

    kruskals();
    cout << ans << '\n';
    return 0;
}