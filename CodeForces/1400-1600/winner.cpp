#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;

map<string, ll> m;
map<string, vector<pair<ll, ll>>> v;

int main() {
    cin >> n;

    for(ll i = 0; i < n; ++i) {
        ll temp;
        cin >> s >> temp;
        m[s] += temp;
        v[s].push_back(make_pair(i, m[s]));
    }    

    ll maxn = INT_MIN;
    for(auto i = m.begin(); i != m.end(); ++i) maxn = max(maxn, i->second);

    vector<string> res;
    for(auto i = m.begin(); i != m.end(); ++i) if(i->second == maxn) res.push_back(i->first);

    string ans;
    ll minTime = INT_MAX;

    for(ll i = 0; i < res.size(); ++i) {
        ll cnt;
        for(ll j = 0; j < v[res[i]].size(); ++j) if(v[res[i]][j].second >= maxn) {
            cnt = v[res[i]][j].first;
            break;
        }

        if(cnt < minTime) {
            minTime = cnt;
            ans = res[i];
        }
    }

    cout << ans << endl;
    return 0;
}