#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll k, f;
        cin >> k >> f;
        v.push_back({k, f});
    }

    ll res = 0;
    for(ll i = 1; i <= 100; ++i) {
        bool ok = 1;
        for(ll j = 0; j < m; ++j) {
            if(v[j].first <= (v[j].second - 1) * i || v[j].first > (v[j].second) * i) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            if(res && res != (n + i - 1)/i)  {
                cout << "-1\n";
                return 0;
            }
            
            res = (n + i - 1)/i;
        }
    }

    if(res) cout << res << '\n';
    else cout << "-1\n";
    return 0;
}