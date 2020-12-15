#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(n > (k * (k - 1))) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(ll i = 1; i <= k; ++i) {
        for(ll j = i + 1; j <= k; ++j) {
            v.push_back({i, j});
            if((ll)v.size() == n) break;
            v.push_back({j, i});
            if((ll)v.size() == n) break;
        }

        if((ll)v.size() == n) {
            break;
        }
    }

    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(i && (v[i].first == v[i - 1].first || v[i].second == v[i - 1].second)) swap(v[i].first, v[i].second);
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}