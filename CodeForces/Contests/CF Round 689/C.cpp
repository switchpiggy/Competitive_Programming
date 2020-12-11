#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[100007], t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) cin >> a[i];

        ll cur = n;
        while(a[cur] == cur && cur > 0) cur--;
        long double res = (cur > 0);
        for(ll i = 0; i < m; ++i) {
            ll u;
            long double v;
            cin >> u >> v;
            if(u >= cur) res *= 1 - v;
        }

        cout << 1 - res << '\n';
    }

    return 0;
}