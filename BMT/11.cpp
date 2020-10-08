#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ans = 0;
    for(ll i = 1; i <= 999; ++i) {
        ans += __gcd(i, 10 * i + 9);
    }

    cout << ans << '\n';
    return 0;
}