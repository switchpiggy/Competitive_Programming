#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll w, h, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> h >> k;
    ll ans = 0;
    for(ll i = 1; i <= w; ++i) {
        for(ll j = 1; j <= h; ++j) {
            if(((h - j)%2 == 0 && (h - j)/2 < k && min(w - i, i - 1) >= h - j) || ((w - i)%2 == 0 && (w - i)/2 < k && min(h - j, j - 1) >= w - i) || ((j - 1)%2 == 0 && (j - 1)/2 < k && min(i - 1, w - i) >= j - 1) || ((i - 1)%2 == 0 && (i - 1)/2 < k && min(h - j, j - 1) >= i - 1)) {
                ans++;
                //cout << j << ' ' << i << '\n';
            }
        }
    }

    cout << ans << '\n';
    return 0;
}