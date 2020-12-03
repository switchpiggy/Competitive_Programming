#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, c[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> c[i][j];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll mins = INT_MAX;
        for(ll j = 0; j < m; ++j) mins = min(mins, c[i][j]);
        ans = max(ans, mins);
    }

    cout << ans << '\n';
    return 0;
}