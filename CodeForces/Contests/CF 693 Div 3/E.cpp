#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, w, h, ans[200007];
vector<pair<pair<ll, ll>, ll>> v;

bool cmp(pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y) {
    if(x.first.first == y.first.first) return x.first.second > y.first.second;
    return x.first.first < y.first.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) { 
            ll h, w;
            cin >> h >> w;
            if(h > w) swap(h, w);
            v.push_back({{h, w}, i});
        }

        sort(v.begin(), v.end(), cmp);

        ll mins = LLONG_MAX, cur = 0;
        for(ll i = 0; i < n; ++i) {
            if(v[i].first.second > mins) {
                ans[v[i].second] = cur + 1;
            } else {
                cur = v[i].second;
                mins = v[i].first.second;
                ans[v[i].second] = -1;
            }
        }

        for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}