#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007];
bool sieve[15000007];
ll p[15000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll maxn = *max_element(a, a + n);
    for(ll i = 2; i <= maxn; ++i) {
        if(sieve[i]) continue;
        for(ll j = i * 2; j <= maxn; j += i) sieve[j] = 1;
    }

    ll g = a[0];
    for(ll i = 1; i < n; ++i) g = __gcd(g, a[i]);

    for(ll i = 0; i < n; ++i) a[i] /= g;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 2; j <= a[i]; ++j) {
            if(sieve[j] || a[i]%j != 0) continue;
            p[j]++;
            ans = max(ans, p[j]);
            while(a[i]%j == 0) a[i] /= j;
        }
    }

    if(!ans) cout << "-1\n";
    else cout << n - ans << '\n';
    return 0;
}