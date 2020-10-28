#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll s, n, x, y;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);
    for(ll i = 0; i < n; ++i) {
        if(v[i].first >= s) {
            cout << "NO\n";
            return 0;
        }

        s += v[i].second;
    }

    cout << "YES\n";
    return 0;
}