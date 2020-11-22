#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll ans = 0;
    while(t) {
        ll cost = 0, cur = 0;
        for(ll i = 0; i < n; ++i) if(cost + a[i] <= t) {
            cost += a[i];
            cur++;
        }

        if(!cost) break;
        ans += cur * (t/cost);
        t %= cost;
    }

    cout << ans << '\n';

    return 0;
}