#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t, ans[17][17];

ll pow2(ll x) {
    ll res = 1;
    while(x--) res *= 2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    ans[0][0] = t * pow2(n);
    //cout << ans[0][0] << '\n';

    ll p = pow2(n);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= i; ++j) {
            if(ans[i][j] > p) {
                ll cur = (ans[i][j] - p)/2;
                ans[i + 1][j] += cur;
                ans[i + 1][j + 1] += cur;
                ans[i][j] = p;
            }
        }
    }

    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= i; ++j) {
            //cout << ans[i][j] << ' ';
            if(ans[i][j] >= p) cnt++;
        }

        //cout << '\n';
    }

    cout << cnt << '\n';
    return 0;
}