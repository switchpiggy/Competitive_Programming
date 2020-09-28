#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007], last[300007], cur[300007], ans[300007];
bool v[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(v, 0, sizeof(v));
        cin >> n;

        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            last[i] = 0;
            cur[i] = 0;
            ans[i] = INT_MAX;
        }

        cur[n] = 0;
        last[n] = 0;
        ans[n] = INT_MAX;

        for(ll i = 0; i < n; ++i) {
            cur[a[i]] = max(cur[a[i]], (i - last[a[i]] + (cur[a[i]] == 0)));
            last[a[i]] = i;
            v[a[i]] = 1;
        }

        for(ll i = 0; i < n; ++i) {
            cur[a[i]] = max(cur[a[i]], n - last[a[i]]);
        }

        for(ll i = 0; i < n; ++i) ans[cur[a[i]]] = min(a[i], ans[cur[a[i]]]);
        bool ok = 0;
        for(ll i = 0; i < n - 1; ++i) if(a[i] != a[i + 1]) ok = 1;
        if(!ok) ans[1] = a[0];

        ll mins = ans[1];

        //cout << cur[1] << '\n';

        for(ll i = 1; i <= n; ++i) {
            ans[i] = min(mins, ans[i]);
            mins = min(mins, ans[i]);
        }

        for(ll i = 1; i <= n; ++i) {
            if(ans[i] == INT_MAX) ans[i] = -1;
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}