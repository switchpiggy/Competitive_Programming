#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll maxn = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) maxn = max(maxn, i->second);

    cout << (((maxn + k - 1)/k) * k * (ll)occ.size()) - n << '\n';
    return 0;
}