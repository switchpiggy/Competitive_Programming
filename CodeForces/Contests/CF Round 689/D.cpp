#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, q, a[100007], s;
set<ll> x;

void solve(ll l, ll r) {
    //if(l < 1 || r > n) return;
    //if(cnt == q) return;
    if(r < l) return;
    if(r == l) {
        x.insert(a[l]);
        return;
    }

    ll m = 0, sum = 0;
    //cout << (a[l] + a[r])/2 << '\n';
    for(ll i = l; i <= r; ++i) {
        if(a[i] > (a[l] + a[r])/2) {
            m = i;
            break;
        }
    }

    for(ll i = l; i <= r; ++i) {
        sum += a[i];
        //cout << a[i] << ' ';
    }

    //cout << '\n';

    x.insert(sum);
    //cout << m << '\n';
    if(!m) return;

    solve(l, m - 1);
    solve(m, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;
        x.clear();
        //memset(pref, 0, sizeof(pref));
        for(ll i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);
        solve(1, n);
        //for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';

        for(ll i = 0; i < q; ++i) {
            cin >> s;
            cout << ((x.count(s) > 0) ? "Yes\n" : "No\n");
        }
    }

    return 0;
}