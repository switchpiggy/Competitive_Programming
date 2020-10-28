#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, h[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> h[i];

    ll ans = 0, cur = 0;
    for(ll i = 0; i < n; ++i) {
        ans += h[i] - cur;
        if(i == n - 1) {
            ans++;
            break;
        }
        if(i + 1 < n && h[i] <= h[i + 1]) {
            ans++;
            cur = h[i];
        } else {
            ans += (h[i] - h[i + 1]) + 1;
            cur = h[i + 1];
        }
        ans++;
    }

    cout << ans << '\n';
    return 0;
}