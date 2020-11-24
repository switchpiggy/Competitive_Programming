#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
map<ll, ll> occ;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        occ.clear();
        v.clear();
        vector<ll> f(107, 1);
        cin >> n;

        ll nn = n;
        for(ll i = 2; i * i <= n; ++i) {
            if(nn%i == 0) {
                while(nn%i == 0) {
                    nn /= i;
                    occ[i]++;
                }
            }
        }

        if(nn) occ[nn]++;

        for(auto i = occ.begin(); i != occ.end(); ++i) v.push_back({i->second, i->first});
        sort(v.begin(), v.end(), greater<pair<ll, ll>>());
        ll maxn = 0;
        for(ll i = 0; i < (ll)v.size(); ++i) {
            maxn = max(maxn, v[i].first);
            for(ll j = 0; j < v[i].first; ++j) f[j] *= v[i].second;
        }

        cout << maxn << '\n';
        for(ll i = 0; i < maxn; ++i) cout << f[maxn - i - 1] << ' ';
        cout << '\n';
    }

    return 0;
}