#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], pref[100007];
map<ll, ll> occ;

int main() {
    cin >> n;

    ll maxn = INT_MIN, x = 1, y = n;

    for(ll i = 1; i <= n; ++i) cin >> a[i];

    for(ll i = 1; i <= n; ++i) {
        for(ll j = i + 1; j <= n; ++j) {
            if(a[i] != a[j]) continue;
            ll cnt = 0;
            for(ll k = i + 1; k <= j - 1; ++k) {
                if(a[k] >= 0) {
                    cnt += a[k];
                }
            }

            cnt += a[j], cnt += a[i];

            if(cnt > maxn) {
                maxn = cnt;
                x = i;              
                y = j;
            }
            //cout << maxn << endl;
        }
    }

    ll negcount = 0;
    for(ll i = x + 1; i <= y - 1; ++i) if(a[i] < 0) negcount++;

    cout << maxn << ' ' << n - (y - x + 1) + negcount << endl;
    for(ll i = 1; i <= n; ++i) if((a[i] < 0 && i != x && i != y) || i < x || i > y) cout << i << ' ';

    return 0;
}