#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, t, l, r, res[1007], m, a[1007];
vector<pair<ll, pair<ll, ll>>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> t >> l >> r;
        v.push_back({t, {l, r}});
    }

    sort(v.begin(), v.end());

    for(ll i = 1; i < n; ++i) res[i] = -1;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        //if(v[i].first == -1) continue;
        //cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << '\n';
        if(v[i].first == 1) {
            for(ll j = v[i].second.first; j < v[i].second.second; ++j) res[j] = 0;
        }
    }

    a[1] = n;
    for(ll i = 2; i <= n; ++i) a[i] = a[i - 1] + res[i - 1];
    //for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';

    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(v[i].first != 0) continue;
        bool ok = 0;
        for(ll j = v[i].second.first; j < v[i].second.second; ++j) {
            if(a[j + 1] < a[j]) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}