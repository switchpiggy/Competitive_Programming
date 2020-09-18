#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, r, a[1007], cnt[1007];

int main() {
    cin >> n >> r;
    for(ll i = 0; i < n; ++i)  cin >> a[i];

    for(ll i = 0; i < n; ++i) {
        if(a[i]) {
            for(ll j = max(0ll, i - r + 1); j <= min(n - 1, i + r - 1); ++j) cnt[j]++;
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(cnt[i] == 0) {
            cout << -1 <<'\n';
            return 0;
        }       

        if(a[i]) {
            bool ok = 0;
            for(ll j = max(0ll, i - r + 1); j <= min(n - 1, i + r - 1); ++j) {
                if(cnt[j] == 1) {
                    ok = 1;
                    break;
                }
            } 

            if(!ok) {
                a[i] = 0;
                for(ll j = max(0ll, i - r + 1); j <= min(n - 1, i + r - 1); ++j) cnt[j]--;
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) ans += a[i];

    cout << ans << '\n';
    return 0;
}