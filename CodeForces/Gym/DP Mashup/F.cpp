#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

ll choose(ll x, ll y) {
    ll ans = 1;
    for(ll i = 1; i <= y; ++i) {
        ans *= x - y + i;
    }

    for(ll i = 1; i <= y; ++i) ans /= i;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    ll ans = 0;
    if(k >= 2) ans += choose(n, 2);
    if(k >= 3) ans += 2 * choose(n, 3);
    if(k >= 4) ans += 9 * choose(n, 4);

    cout << ans + 1 << '\n';
    return 0;
}