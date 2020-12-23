#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r;
const ll MOD = 1e9 + 7;

pair<ll, ll> f(ll x) {
    ll cur = 0, even = 0, odd = 0;
    while(x >= 0) {
        if(cur%2 == 0) odd += min(x, (1ll << cur));
        else even += min(x, (1ll << cur));
        even %= MOD;
        odd %= MOD;
        x -= (1ll << cur);
        cur++;
    }

    return {odd, even};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;
    pair<ll, ll> x = f(r);
    pair<ll, ll> y = f(l - 1);

    cout << (((x.first * x.first)%MOD - (y.first * y.first)%MOD + MOD)%MOD + (x.second * (x.second + 1))%MOD - (y.second * (y.second + 1))%MOD + MOD)%MOD << '\n';
    return 0;
}