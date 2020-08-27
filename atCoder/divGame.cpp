#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ll ans = 0;
    cin >> n;
    ll m = n;

    for(ll i = 2; i * i <= m; ++i) {
        if(n%i != 0) continue;
        //cout << i << endl;
        ll cnt = 0;
        while(n%i == 0) {
            cnt++;
            n /= i;
        }

        ll res = 0;
        for(ll j = 1; j <= cnt; ++j) {
            cnt -= j;
            res++;
            if(cnt - (j + 1) < 0) break;
        }

        ans += res;
    }

    if(!ans && n > 1) ans++;

    cout << ans << endl;
    return 0;
}