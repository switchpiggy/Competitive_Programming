#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n[3], sum[3], mins[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 0; i < 3; ++i) cin >> n[i];
    for(ll i = 0; i < 3; ++i) {
        mins[i] = LLONG_MAX;
        for(ll j = 0; j < n[i]; ++j) {
            ll a;
            cin >> a;
            mins[i] = min(mins[i], a);
            sum[i] += a;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < 3; ++i) {
        for(ll j = 0; j < 3; ++j) {
            if(i == j) continue;
            ll k = 3 - (i + j);
            ans = max(ans, mins[k] - (mins[i] + mins[j] - (sum[i] + sum[j] + sum[k] - mins[i] - mins[j] - mins[k])));
        }
    }

    for(ll i = 0; i < 3; ++i) {
        //if(n[i] > 1) continue;
        for(ll j = 0; j < 3; ++j) {
            if(i == j) continue;
            ll k = 3 - (i + j);
            ans = max(ans, mins[i] - (mins[j] - sum[k]) - (sum[j] - mins[j]));
        }
    }

    cout << ans << '\n';
    return 0;
}