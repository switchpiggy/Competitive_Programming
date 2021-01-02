#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;
vector<pair<pair<ll, ll>, ll>> e;
pair<ll, ll> res[100007];

bool cmp(pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y) {
    if(x.first.first == y.first.first) return x.first.second > y.first.second;
    return x.first.first < y.first.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        e.push_back({{a, b}, i});
    }

    sort(e.begin(), e.end(), cmp);

    //vector<pair<ll, ll>> res;
    ll cnt = 2, l = 2, r = 3;
    for(ll i = 0; i < m; ++i) {
        if(e[i].first.second == 1) {
            res[e[i].second] = {1, cnt};
            cnt++;
        } else {
            if(r >= cnt) {
                cout << "-1\n";
                return 0;
            }

            res[e[i].second] = {l, r};
            l++;
            if(l == r) {
                l = 2;
                r++;
            }
        }
    }

    for(ll i = 0; i < m; ++i) cout << res[i].first << ' ' << res[i].second << '\n';
    return 0;
}