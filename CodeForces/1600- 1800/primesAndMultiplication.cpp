#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x;
const ll MOD = 1000000007;
vector<ll> p;

void prime(ll a) {
    for(ll i = 2; i * i <= a; ++i) {
        if(a%i == 0) {
            p.push_back(i);
            while(a%i == 0) a /= i;
        }
    }

    if(a > 1) p.push_back(a);
    return;
}

ll fastpow(ll a, ll b) {
    if(b == 0) return 1;
    ll recurse = fastpow(a, b/2)%MOD;
    if(b%2 == 0) return (recurse * recurse)%MOD;
    return ((recurse * recurse)%MOD * a)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> n;
    prime(x);

    ll ans = 1;
    for(ll i = 0; i < (ll)p.size(); ++i) {
        //cout << p[i] << ' ';
        ll pow = 0, nn = n;
        while(p[i] <= nn) {
            pow += nn/p[i];
            nn /= p[i];
        }

        ans = (ans%MOD * fastpow(p[i], pow)%MOD)%MOD;
    }

    cout << ans << '\n';
    return 0;
}