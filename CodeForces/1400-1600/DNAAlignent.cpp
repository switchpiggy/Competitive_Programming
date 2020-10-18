#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<char, ll> occ;
string s;

const ll MOD = 1000000007;

ll fastpow(ll x, ll y) {
    if(y == 1) return x;
    if(y == 0) return 1;

    ll recurse = fastpow(x, y/2);
    if(y%2 == 1) return (recurse * recurse * x)%MOD;
    return (recurse * recurse)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        occ[s[i]]++;
    }

    ll ans = 0, maxn = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        if(i->second > maxn) {
            ans = 1;
            maxn = i->second;
        } else if(i->second == maxn) ans++;
        ans %= MOD;
    }

    cout << fastpow(ans, n) << '\n';
    return 0;
}