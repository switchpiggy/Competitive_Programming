#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x[2007], y[2007], n, occ[20000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(occ, 0, sizeof(occ));
    for(ll i = 0; i < n; ++i) cin >> x[i];
    for(ll i = 0; i < n; ++i) cin >> y[i];
    for(ll i = 0; i < n; ++i) {
        occ[x[i]]++;
        occ[y[i]]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i != j && ((x[i]^y[j]) <= 20000000) && occ[(x[i]^y[j])] > 0) {
                ans++;
                //cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }

    for(ll i = 0; i < n; ++i) ans += (((x[i]^y[i]) <= 20000000) && occ[(x[i]^y[i])] > 0);

    cout << (ans%2 ? "Koyomi\n" : "Karen\n");
}