#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], b[200007];
map<pair<ll, ll>, ll> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> b[i];

    ll zero = 0;

    for(ll i = 0; i < n; ++i) {
        if(a[i] == 0) {
            if(b[i] == 0) zero++;
            continue;
        }

        ll gcf = __gcd(a[i], b[i]);
        pair<ll, ll> p = {-b[i]/gcf, a[i]/gcf};
        res[p]++;
    }

    ll ans = 0;
    for(auto i = res.begin(); i != res.end(); ++i) ans = max(ans, i->second);

    cout << ans + zero << '\n';
    return 0;
}