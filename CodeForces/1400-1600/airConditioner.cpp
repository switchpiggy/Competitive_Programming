#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
vector<pair<ll, pair<ll, ll>>> v;

int main() {
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> m;
        for(ll i = 0; i < n; ++i) {
            ll a, b, c;
            cin >> a >> b >> c;
            v.push_back(make_pair(a, make_pair(b, c)));
        }

        bool ok = 1;
        ll curL = m, curH = m, ti = 0;
        for(ll i = 0; i < n; ++i) {
            curL -= v[i].first - ti;
            curH += v[i].first - ti;
            ti = v[i].first;

            if(curL > v[i].second.second || curH < v[i].second.first) {
                ok = 0;
                cout << "NO" << endl;
                break;
            }

            if(curL < v[i].second.first) curL = v[i].second.first;
            if(curH > v[i].second.second) curH = v[i].second.second;
        }

        if(ok) cout << "YES" << endl;
    }

    return 0;
}