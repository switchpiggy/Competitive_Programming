#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(abs(x.first) == abs(y.first)) return abs(x.second) < abs(y.second);
    return abs(x.first) < abs(y.first);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);
    ll ans = 2 * (ll)v.size();
    for(ll i = 0; i < n; ++i) {
        if(v[i].first == 0 || v[i].second == 0) ans += 2;
        else ans += 4;
    }

    cout << ans << '\n';
    for(ll i = 0; i < n; ++i) {
        if(v[i].first != 0) {
            cout << 1 << ' ' << abs(v[i].first) << ' ' << (v[i].first > 0 ? 'R' : 'L') << '\n';
        }

        if(v[i].second != 0) {
            cout << 1 << ' ' << abs(v[i].second) << ' ' << (v[i].second > 0 ? 'U' : 'D') << '\n';
        }
        cout << "2\n";
        
        if(v[i].first != 0) {
            cout << 1 << ' ' << abs(v[i].first) << ' ' << (v[i].first > 0 ? 'L' : 'R') << '\n';
        }
        if(v[i].second != 0) {
            cout << 1 << ' ' << abs(v[i].second) << ' ' << (v[i].second > 0 ? 'D' : 'U') << '\n';
        }

        cout << 3 << '\n';
    }

    return 0;
}