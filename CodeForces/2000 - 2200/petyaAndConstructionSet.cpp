#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;
vector<ll> g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        v.push_back({a, 2 * i - 1});
    }

    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    vector<pair<ll, ll>> res;
    g.push_back(v[0].second);
    for(ll i = 1; i < n; ++i) {
        g.push_back(v[i].second);
        res.push_back({v[i - 1].second, v[i].second});
    }

    for(ll i = 0; i < n; ++i) {
        /*if(i + v[i].first - 1 >= (ll)g.size()) {
            ll d = g[i - v[i].first + 1];
            res.push_back({v[i].second + 1, d});
            if(d == g.front()) {
                g.push_front(v[i].second + 1);
            }
            continue;
        }*/
        ll d = g[i + v[i].first - 1];
        res.push_back({v[i].second + 1, d});
        if(d == g.back()) {
            //cout << d << ' ' << g.back() << '\n';
            g.push_back(v[i].second + 1);
            //cout << d << ' ' << v[i].second << '\n';
        }
    }

    for(pair<ll, ll> i : res) cout << i.first << ' ' << i.second << '\n';
    return 0;
}