#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        bool ok2 = 0;
        for(ll i = 0; i < n; ++i) {
            bool ok = 1;
            for(ll j = 0; j < n; ++j) {
                if(j == i) continue;
                if(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) > k) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                ok2 = 1;
                break;
            }
        }

        cout << (ok2 ? "1\n" : "-1\n");
    }

    return 0;
}