#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a;
        occ[a]++;
    }

    vector<ll> v;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        v.push_back(i->second);
    }

    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll i = 1; i <= v.back(); ++i) {
        ll cur = i, p = (ll)v.size() - 1, res = 0;
        while(p >= 0 && v[p] >= cur) {
            res += cur;
            if(cur%2 != 0) break;
            cur /= 2;
            --p;
        }

        ans = max(ans, res);
        //if(i == 6) cout << res << '\n';
    }

    cout << ans << '\n';
    return 0;
}