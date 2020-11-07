#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[1000007], m, l, r, cnt[10000007], pref[10000007];
bool composite[10000007];

void sieve() {
    for(ll i = 1; i <= n; ++i) cnt[x[i]]++;
    for(ll i = 2; i <= 10000000; ++i) {
        if(composite[i]) continue;
        pref[i] = cnt[i];
        for(ll j = i * 2; j <= 10000000; j += i) {
            composite[j] = 1;
            pref[i] += cnt[j];
        }
    }

    for(ll i = 1; i <= 10000000; ++i) pref[i] += pref[i - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> x[i];
    cin >> m;

    sieve();

    for(ll i = 0; i < m; ++i) {
        cin >> l >> r;
        cout << pref[min(10000000ll, r)] - pref[min(10000000ll, l) - 1] << '\n';
    }

    return 0;
}