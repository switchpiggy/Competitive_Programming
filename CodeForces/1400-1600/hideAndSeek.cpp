#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, x[100007], maxx[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 1; i <= k; ++i) {
        ll t;
        cin >> t;
        if(!x[t]) x[t] = i;
        maxx[t] = i;
    }

    ll ans = 0;

    for(ll i = 1; i <= n; ++i) {
        if(!x[i]) {
            ans += 3;
            if(i == 1) ans--;
            if(i == n) ans--;
        }
        else {
            if(x[i] > maxx[i - 1] && i > 1) ans++;
            if(x[i] > maxx[i + 1] && i < n) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}