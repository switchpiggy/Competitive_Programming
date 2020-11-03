#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, f, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    ll ans = INT_MIN;
    for(ll i = 0; i < n; ++i) {
        cin >> f >> t;
        if(t <= k) ans = max(ans, f);
        else ans = max(ans, f - (t - k));
    }

    cout << ans << '\n';
    return 0;
}