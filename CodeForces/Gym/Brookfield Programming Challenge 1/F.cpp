#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> u;
    v.push_back({0, 0});
    for(ll i = 0; i < u; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({n + 1, n + 1});

    sort(v.begin(), v.end());

    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(v[i + 1].first - v[i].second >= 2) {
            cout << v[i].second + 1 << '\n';
            return 0;
        }
    }
}