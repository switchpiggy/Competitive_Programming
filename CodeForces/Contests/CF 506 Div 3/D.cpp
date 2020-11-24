#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007];
map<ll, ll> mod[11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll place = 1;
        for(ll j = 1; j <= 10; ++j) {
            place = (place * 10)%k;
            mod[j][(a[i] * place)%k]++;
        }
    }

    for(ll i = 0; i < n; ++i) {
        ll len = log10(a[i]) + 1;
        ans += mod[len][(k - a[i]%k)%k];

        ll res = a[i];
        for(ll j = 1; j <= len; ++j) res = (res * 10)%k;
        if((k - res%k)%k == a[i]%k) ans--;
    }

    cout << ans << '\n';
    return 0;
}