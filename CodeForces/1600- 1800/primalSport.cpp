#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(ll i = 2; i <= 1000000; ++i) {
        ll j;
        for(j = 2; j * j <= i; ++j) {
            if(i%j == 0) break;
        }

        if(j * j > i) p[i] = i;
        else p[i] = max(j, p[i/j]);
    }

    ll ans = LONG_LONG_MAX;
    for(ll i = n; i > n - p[n]; --i) {
        if(p[i] < i) ans = min(ans, i - p[i] + 1);
    }

    cout << ans << '\n';
    return 0;
}