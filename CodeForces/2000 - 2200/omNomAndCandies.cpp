#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll c, hr, hb, wr, wb;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> hr >> hb >> wr >> wb;
    ll ans = 0;
    if(wb * wb >= c) {
        for(ll i = 0; i * wb <= c; ++i) {
            ans = max(ans, i * hb + (c - i * wb)/wr * hr);
        }

        cout << ans << '\n';
        return 0;
    }

    if(wr * wr >= c) {
        for(ll i = 0; i * wr <= c; ++i) {
            ans = max(ans, i * hr + (c - i * wr)/wb * hb);
        }

        cout << ans << '\n';
        return 0;
    }

    if(hr * wb <= hb * wr) {
        swap(hb, hr);
        swap(wb, wr);
    }

    for(ll i = 0; i <= wr && i * wb <= c; ++i) {
        ans = max(ans, i * hb + (c - i * wb)/wr * hr);
    }

    cout << ans << '\n';
    return 0;
}