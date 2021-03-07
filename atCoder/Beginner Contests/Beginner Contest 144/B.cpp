#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = LONG_LONG_MAX;
    for(ll i = 1; i * i <= n; ++i) {
        if(n%i == 0) {
            ans = min(ans, i + n/i - 2);
        }
    }

    cout << ans << '\n';
}