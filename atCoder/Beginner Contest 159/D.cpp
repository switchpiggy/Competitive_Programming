#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll sum = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) sum += (i->second * (i->second - 1))/2;

    for(ll i = 0; i < n; ++i) {
        cout << sum - (occ[a[i]] - 1) << '\n';
    }

    return 0;
}