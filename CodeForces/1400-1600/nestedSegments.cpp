#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, suff[300007];
vector<pair<pair<ll, ll>, ll>> v;

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    if(a.first.first == b.first.first) return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
    }

    sort(v.begin(), v.end(), cmp);

    ll maxn = v[n - 1].first.second;
    for(ll i = n - 1; i >= 0; --i) {
        maxn = min(maxn, v[i].first.second);
        suff[i] = maxn;
    }

    for(ll i = 0; i < n - 1; ++i) {
        if(suff[i + 1] <= v[i].first.second) {
            for(ll j = i + 1; j < n; ++j) {
                if(v[j].first.second <= v[i].first.second) {
                    cout << v[j].second + 1 << ' ' << v[i].second + 1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "-1 -1\n";
    return 0;
}