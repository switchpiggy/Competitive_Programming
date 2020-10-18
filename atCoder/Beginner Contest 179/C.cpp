#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ll k = n/i;
        ans += k - (n%i == 0);
    }

    cout << ans << '\n';
    return 0;
}