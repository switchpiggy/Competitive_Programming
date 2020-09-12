#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;
map<ll, ll> s, t;
vector<pair<ll, ll>> v;

int main() {
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    } 

    ll x = 0, y = 0;

    for(ll i = 0; i < m; ++i) {
        if(v[i].first != v[0].first && v[i].second != v[0].first) {
            s[v[i].first]++;
            s[v[i].second]++;
        } else x++;

        if(v[i].first != v[0].second && v[i].second != v[0].second) {
            t[v[i].first]++;
            t[v[i].second]++;
        } else y++;
    }

    if(x == m || y == m) {
        cout << "YES\n";
        return 0;
    }

    for(auto i = s.begin(); i != s.end(); ++i) {
        if(i->second == m - x) {
            cout << "YES\n";
            return 0;
        }
    }

    for(auto i = t.begin(); i != t.end(); ++i) {
        if(i->second == m - y) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}