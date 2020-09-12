#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = INT_MAX;

    ll cnt = 0;

    for(ll i = 0; i < n; ++i) {
        if(a[i] == 1) cnt++;
        ll gcf = a[i];
        for(ll j = i; j < n; ++j) {
            gcf = __gcd(gcf, a[j]);
            if(gcf == 1) ans = min(ans, j - i + n - 1);
        }
    }

    if(cnt) {
        cout << n - cnt << '\n';
        return 0;
    }

    if(ans == INT_MAX) {
        cout << -1 <<'\n';
        return 0;
    }

    cout << ans << '\n';
    
    return 0;
}