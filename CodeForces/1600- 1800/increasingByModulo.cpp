#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll l = 0, r = m, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2;
        ll prev = 0;
        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if((a[i] <= prev && prev <= a[i] + mid) || (a[i] <= prev + m && a[i] + mid >= prev + m)) continue;
            if(a[i] < prev) {
                ok = 0;
                break;
            } else prev = a[i];
        }

        if(ok) {
            ans = mid;
            r = mid;
        } else l = mid + 1;
    }

    cout << ans << '\n';
}