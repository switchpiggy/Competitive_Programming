#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> x;
    ll l = 0, r = 1000000001, ans = 0;
    while(l < r) {
        ll m = (l + r)/2;
        if(a * m + b * ((ll)(log10(m)) + 1) <= x) {
            ans = max(ans, m);
            l = m + 1;
        } else r = m;
    }

    cout << ans << '\n';
    return 0;
}