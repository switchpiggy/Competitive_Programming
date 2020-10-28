#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) cin >> a[i];

    ll cur = 1, ans = 0;
    for(ll i = 0; i < m; ++i) {
        if(a[i] >= cur) ans += a[i] - cur;
        else ans += (n - cur) + a[i];

        cur = a[i];
    }

    cout << ans << '\n';
    return 0;
}