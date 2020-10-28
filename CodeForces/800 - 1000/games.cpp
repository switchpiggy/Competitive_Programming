#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> g;
ll h[37];
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll gest;
        cin >> h[i] >> gest;
        g[gest]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans += g[h[i]];
    }

    cout << ans << '\n';
    return 0;
}