#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n *n; ++i) {
        ll a;
        cin >> a;
        occ[a]++;
    }

    vector<ll> v;
    for(ll i = 1; i <= n; ++i) {
        auto k = occ.rbegin();
        while(!k->second) k++;
        ll a = k->first;
        occ[a]--;
        for(ll j = 0; j < (ll)v.size(); ++j) {
            occ[__gcd(a, v[j])] -= 2;
        }
        v.push_back(a);
        cout << a << ' ';
    }
    
    return 0;
}