#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, d, ans[1007][1007], a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> d;

    bool ok = 0;
    ll res = 1;
    for(ll i = 0; i < d; ++i) {
        res *= k;
        if(res >= n) {
            ok = 1;
        }
    }

    if(!ok) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 1; i < n; ++i) {
        for(ll j = 0; j < d; ++j) ans[i][j] = ans[i - 1][j];
        for(ll j = d - 1; j >= 0; --j) {
            ans[i][j] = (ans[i][j] + 1)%k;
            if(ans[i][j]) break;
        }
    }

    for(ll i = 0; i < d; ++i, cout << '\n') {
        for(ll j = 0; j < n; ++j) cout << ans[j][i] + 1 << ' ';
    }

    return 0;
}