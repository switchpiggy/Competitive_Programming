#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, x[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a;
    for(ll i = 0; i < n; ++i) cin >> x[i];

    sort(x, x + n);

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = INT_MAX;
    for(ll i = 0; i < 2; ++i) {
        ll cur;
        if((x[i] <= a && x[i + n - 2] <= a) || (x[i] >= a && x[i + n - 2] >= a)) {
            cur = max(abs(x[i] - a), abs(x[i + n - 2] - a));
            ans = min(ans, cur);
        } else {
            cur = min(2 * abs(x[i] - a) + abs(x[i + n - 2] - a), 2 * abs(x[i + n - 2] - a) + abs(x[i] - a));
            ans = min(ans, cur);
        }

        //cout << cur << '\n';
    }

    cout << ans << '\n';
    return 0;
}