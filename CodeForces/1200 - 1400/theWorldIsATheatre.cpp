#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, t;

ll choose(ll x, ll y) {
    ll ans = 1;
    for(ll i = 1; i <= y; ++i) {
        ans *= (x - y + i);
        ans /= i;
    }

    return ans;
}

int main() {
    cin >> n >> m >> t;

    ll ans = 0;

    for(ll b = 4; b <= n; ++b) {
        if(t - b < 1) continue;
        ans += choose(n, b) * choose(m, t - b);
    }

    cout << ans << endl;
    return 0;
}