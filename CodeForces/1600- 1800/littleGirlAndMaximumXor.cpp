#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l >> r;

    if(l == 1 && r == 1) {
        cout << 0 << '\n';
        return 0;
    }

    ll cnt = 1;
    while(cnt * 2 <= r) cnt *= 2;
    
    if(cnt < l) {
        cout << cnt - 1 << '\n';
        return 0;
    }

    ll ans = cnt^(cnt - 1);
    cout << ans << '\n';

    return 0;
}