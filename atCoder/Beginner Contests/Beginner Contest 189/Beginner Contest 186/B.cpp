#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, w, a[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    ll mins = INT_MAX;
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            cin >> a[i][j];
            mins = min(mins, a[i][j]);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            ans += a[i][j] - mins;
        }
    }

    cout << ans << '\n';
    return 0;
}