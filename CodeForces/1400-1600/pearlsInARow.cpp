#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007];
map<ll, ll> p;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; ++i) {
        if(p[a[i]]) {
            v.push_back({p[a[i]] - 1, i});
        }

        p[a[i]] = i + 1;
    }

    sort(v.begin(), v.end(), cmp);

    ll pr = -1;
    vector<pair<ll, ll>> ans;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        //cout << v[i].first << ' ' << v[i].second << '\n';
        if(v[i].first > pr) {
            ans.push_back({v[i].first, v[i].second});
            pr = v[i].second;
            //cout << "y\n";
        }
    }

    if(ans.empty()) {
        cout << "-1\n";
        return 0;
    }

    cout << (ll)ans.size() << '\n';
    for(ll i = 0; i < (ll)ans.size(); ++i) {
        //cout << ans[i].first << ' ' << ans[i].second << '\n';
        if(i == 0) cout << 1 << ' ';
        else cout << ans[i].first + 1 << ' ';
        if(i == (ll)ans.size() - 1) cout << n << ' ';
        else cout << ans[i + 1].first << ' ';
        cout << '\n';
    }

    return 0;
}