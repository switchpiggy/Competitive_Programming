#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, b[200007];
map<ll, ll> occ;

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> b[i];

    for(ll i = 1; i <= n; ++i) {
        occ[i - b[i]] += b[i];
    }

    ll maxn = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) maxn = max(maxn, i->second);

    cout << maxn << endl;
    return 0;
}