#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for(ll i = 3 - n%3; (3 * (i * (i + 1))/2) - i <= n; i += 3) {
        ans++;
    }

    cout << ans << '\n';
    return 0;
}