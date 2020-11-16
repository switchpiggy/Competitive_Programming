#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, d, c[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    ll w = n;
    for(ll i = 0; i < m; ++i) {
        cin >> c[i];
        w -= c[i];
    }

    if(w/(m + 1) + (w%(m + 1) > 0) >= d) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    ll j = 0, cur = 1;
    for(ll i = 0; i < m + 1; ++i) {
        ll b = w/(m + 1);
        if(i < (w%(m + 1))) w++;
        for(ll k = 0; k < b; ++k) cout << 0 << ' ';
        if(j == m) break;
        for(ll k = 0; k < c[j]; ++k) cout << cur << ' ';
        j++;
        cur++;
    }

    cout << '\n';
    return 0;
}