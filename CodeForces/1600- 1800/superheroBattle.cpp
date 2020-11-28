#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, n, d[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> n;
    ll mins = LONG_LONG_MAX;
    for(ll i = 1; i <= n; ++i) {
        cin >> d[i];
        d[i] += d[i - 1];
        mins = min(mins, h + d[i]);
    }

    if(mins > 0 && d[n] > 0) {
        cout << "-1\n";
        return 0;
    }

    if(mins <= 0) {
        for(ll i = 1; i <= n; ++i) {
            if(h + d[i] <= 0) {
                cout << i << '\n';
                return 0;
            }
        }
    }
    ll ans = LONG_LONG_MAX;

    for(ll i = 1; i <= n; ++i) {
        ll cur = h + d[i];
        if(cur <= 0) ans = min(ans, i);
        else if(d[n] < 0) ans = min(ans, i + ((cur + -d[n] - 1)/-d[n]) * n);
    }

    if(ans == LONG_LONG_MAX) {
        cout << "-1\n";
        return 0;
    }
    
    cout << ans << '\n';
    //cout << mins << ' ' << minn << ' ' << d[n] << '\n';
    return 0;
}