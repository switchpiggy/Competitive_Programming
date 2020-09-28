#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
vector<pair<pair<ll, ll>, pair<ll, ll>>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        v.clear();

        bool ok = 0;

        for(ll i = 0; i < n; ++i) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            v.push_back(make_pair(make_pair(a, b), make_pair(c, d)));

            if(b == c) ok = 1;
        }

        if(m%2 == 1) ok = 0;

        if(!ok) {
            cout << "NO\n";
            continue;
        }

        bool ok2 = 0;

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                if(v[i].first.first == v[j].first.first && v[i].second.second == v[j].second.second && v[i].first.second == v[j].second.first && v[i].second.first == v[j].first.second) {
                    ok2 = 1;
                    break;
                }
            }

            if(ok2) break;
        }

        if(ok2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}