#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<pair<ll, ll>> v;
ll n, m, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for(ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    ll maxn = n;
    if(v[0].first >= n) {
        cout << "No\n";
        return 0;
    }

    n -= v[0].first;

    v.push_back({t, t});
    //cout << n << '\n';
    for(ll i = 0; i < m; ++i) {
        n = min(maxn, n + v[i].second - v[i].first);
        //cout << n << '\n';
        if(n <= v[i + 1].first - v[i].second || (i == m - 1 && v[i + 1].first - v[i].second >= n)) {
            cout << "No\n";
            //cout << n << '\n';
            return 0;
        }
        n -= v[i + 1].first - v[i].second;
        //cout << n << '\n';
    }

    cout << "Yes\n";
    return 0;
}