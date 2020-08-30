#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

const ll MOD = 1000000007;

ll factorial(ll x) {
    ll ans = 1;
    for(ll i = 2; i <= x; ++i) {
        ans *= i;
        ans %= MOD;
    }

    return ans;
}

int main() {
    cin >> n;

    ll f = factorial(n - 2);

    cout << f << endl;

    ll ans = 0;
    for(ll i = 3; i <= n; ++i) {
        ans += 2 * f * (n - i + 1);
    }

    cout << ans << endl;
    return 0;
}