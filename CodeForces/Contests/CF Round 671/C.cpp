#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        //memset(pref, 0, sizeof(pref));

        cin >> n >> x;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        sort(a, a + n);

        ll cnt = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == x) cnt++;
        }

        if(a[0] == a[n - 1] && a[0] == x) {
            cout << 0 << '\n';
            continue;
        }

        if(cnt >= 1) {
            cout << 1 << '\n';
            continue;
        }

        ll sum = 0;        
        for(ll i = 0; i < n; ++i) sum += a[i];

        if(sum == n * x) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}