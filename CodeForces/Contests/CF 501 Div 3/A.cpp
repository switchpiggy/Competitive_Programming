#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, d[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        for(ll j = a; j <= b; ++j) d[j]++;
    }

    vector<ll> v;
    for(ll i = 1; i <= m; ++i) {
        if(!d[i]) v.push_back(i);
    }

    cout << (ll)v.size() << '\n';
    for(ll i : v) cout << i << ' ';

    return 0;
}