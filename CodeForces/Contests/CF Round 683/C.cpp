#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, w;
pair<ll, ll> a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> w;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(a[i].first >= (w + 1)/2 && a[i].first <= w) {
                cout << 1 << '\n';
                cout << a[i].second + 1 << '\n';
                ok = 1;
                break;
            }
        }

        if(ok) continue;

        sort(a, a + n);

        ll cur = 0;
        for(ll i = 0; i < n; ++i) {
            cur += a[i].first;
            if(cur > w) {
                cout << "-1\n";
                ok = 1;
                break;
            }

            if(cur <= w && cur >= (w + 1)/2) {
                cout << i + 1 << '\n';
                for(ll j = 0; j <= i; ++j) cout << a[j].second + 1 << ' ';
                cout << '\n';
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "-1\n";
    }

    return 0;
}