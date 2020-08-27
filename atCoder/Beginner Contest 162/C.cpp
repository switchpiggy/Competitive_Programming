#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k;

int main() {
    cin >> k;

    ll ans = 0;
    for(ll a = 1; a <= k; ++a) {
        for(ll b = 1; b <= k; ++b) {
            for(ll c = 1; c <= k; ++c) {
                ans += __gcd(__gcd(a, b), c);
            }
        }
    }

    cout << ans << endl;
    return 0;
}