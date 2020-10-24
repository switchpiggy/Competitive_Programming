#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i == j) continue;
            occ[a[i] + a[j]]++;
        }
    }

    ll res = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) res = max(res, i->second);

    cout << res/2 << '\n';
    return 0;
}