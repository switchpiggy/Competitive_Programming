#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, q, a, b, c, d;
vector<pair<pair<ll, ll>, pair<ll, ll>>> v;

int main() {
    cin >> n >> m >> q;
    for(ll i = 0; i < q; ++i) {
        cin >> a >> b >> c >> d;
        v.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
    }

    queue<vector<ll>> q;
    q.push({1});

    ll res = 0;
    while(!q.empty()) {
        vector<ll> f = q.front();
        q.pop();
        //for(ll i = 0; i < f.size(); ++i) cout << f[i] << ' ';
        //cout << endl;

        if(f.size() == n) {
            ll cnt = 0;
            for(ll i = 0; i < v.size(); ++i) {
                if(f[v[i].first.second - 1] - f[v[i].first.first - 1] == v[i].second.first) cnt += v[i].second.second;
            }

            res = max(res, cnt);
        } else {
            for(ll i = f[f.size() - 1]; i <= m; ++i) {
                vector<ll> g(f);
                g.push_back(i);
                q.push(g);
            }
        }
    }

    cout << res << endl;
    return 0;
}