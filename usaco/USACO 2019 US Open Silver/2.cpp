#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, greater<ll>());

    ll ans = 0, cur = 0;
    for(ll i = 0; i < n; ++i) if(cur <= a[i]) {
        ans++;
        cur++;
    }

    cout << ans << '\n';
    return 0;
}