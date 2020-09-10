#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<string, ll> occ;
ll n;
string s, t;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> s >> t;
        if(s.substr(0, 2) == t) continue;
        string u = s.substr(0, 2) + t;
        occ[u]++;
    }

    for(auto i = occ.begin(); i != occ.end(); ++i) {
        string u = i->first.substr(2) + i->first.substr(0, 2);
        //cout << u << ' ' << i->first << '\n';
        ans += occ[u] * i->second;
    }

    cout << ans/2 << endl;
    return 0;
}