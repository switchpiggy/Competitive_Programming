#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = INT_MAX;
    for(ll i = 1; i < k; ++i) {
        if(n%i != 0) continue;
        ans = min(ans, (n/i) * k + i);
    }

    cout << ans << '\n';
    return 0;
}