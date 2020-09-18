#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, occ[1000007];

ll fastlog2(ll x) {
    ll ans = 0;
    while(x > 1) {
        ans++;
        x /= 2;
    } 

    return ans;
}

void calc(ll x) {
    ll cur = x;
    bool ok = 0;
    for(ll i = 2; i < cur; ++i) {
        if(x%i == 0) {
            while(x%i == 0) {
                occ[i]++;
                x /= i;
            }
            ok = 1;
        }
    }

    if(!ok) {
        cout << cur << ' ' << 0 << '\n';
        exit(0);
    }

    return;
}

int main() {
    cin >> n;

    calc(n);

    ll maxn = *max_element(occ, occ + n);
    //cout << maxn << '\n';
    ll ans = fastlog2(maxn);
    if(((maxn) & (maxn - 1)) != 0) ans++;

    bool ok = 0;
    ll ans2 = 1;
    for(ll i = 0; i < n; ++i) {
        if(occ[i] && occ[i] != (ll)pow(2, ans)) {
            ok = 1;
        }

        if(occ[i]) {
            ans2 *= i;
            //cout << i << ' ';
        }
    }

    cout << ans2 << ' ' << ans + ok << '\n';
    //cout << ans << ' ' << ok << '\n';
    return 0;
}