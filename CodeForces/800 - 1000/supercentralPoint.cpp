#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
bool l[1007], r[1007], u[1007], d[1007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i == j) continue;
            if(v[i].second == v[j].second) {
                if(v[i].first > v[j].first) u[j] = 1;
                else d[j] = 1;
            }

            if(v[i].first == v[j].first) {
                if(v[i].second > v[j].second) l[j] = 1;
                else r[j] = 1;
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(l[i] && r[i] && u[i] && d[i]) ans++;
    }

    cout << ans << '\n';
    return 0;
}