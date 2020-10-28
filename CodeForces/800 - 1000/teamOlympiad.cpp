#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> v[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        v[a - 1].push_back(i);
    }

    ll res = min((ll)v[0].size(), min((ll)v[1].size(), (ll)v[2].size()));
    cout << res << '\n';
    for(ll i = 0; i < res; ++i) {
        cout << v[0][i] + 1 << ' ' << v[1][i] + 1 << ' ' << v[2][i] + 1 << '\n';
    }

    return 0;
}