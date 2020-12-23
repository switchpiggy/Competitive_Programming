#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll m;

ll calc(ll x) {
    ll ans = 0;
    for(ll i = 2; i * i * i <= x; ++i) {
        ans += x/(i * i * i);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;

    ll l = 0, r = LLONG_MAX, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2, x = calc(mid);
        if(x == m) {
            ans = mid;
            r = mid;
        } else if(x > m) r = mid;
        else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}