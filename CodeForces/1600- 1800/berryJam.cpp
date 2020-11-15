#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> l;
ll t, n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        l.clear();
        l[0] = 0;
        cin >> n;
        ll dif = 0;
        for(ll i = 0; i < 2 * n; ++i) {
            cin >> a[i];
            if(a[i] == 1) dif++;
            else dif--;
        }

        if(!dif) {
            cout << 0 << '\n';
            continue;
        }

        ll cur = 0;
        for(ll i = n - 1; i >= 0; --i) {
            if(a[i] == 1) cur++;
            else cur--;
            if(!l[cur]) l[cur] = n - i;
        }

        cur = 0;
        ll ans = 2 * n;
        if(l[dif]) ans = min(ans, l[dif]);

        for(ll i = n; i < 2 * n; ++i) {
            if(a[i] == 1) cur++;
            else cur--;

            if(l[dif - cur]) ans = min(ans, (i - n + 1) + l[dif - cur]);
            if(cur == dif) ans = min(ans, i - n + 1);
            
        }

        cout << ans << '\n';
    }

    return 0;
}