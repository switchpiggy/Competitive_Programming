#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
    cin >> a >> b;
    ll ans = 0;
    for(ll i = 0; i <= 30; ++i) {
        if((a & (1 << i)) == (b & (1 << i)) && (a & (1 << i))) ans += (1 << i);
    }

    ll res = (a^ans) + (b^ans);
    //cout << ans << '\n';
    cout << res << '\n';
    }

    return 0;
}