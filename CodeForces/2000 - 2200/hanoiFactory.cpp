#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, h, dp[100007];
vector<pair<pair<ll, ll>, ll>> v;
map<ll, pair<ll, ll>> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a >> b >> h;
        if(!m[b].first && !m[b].second) {
            m[b] = {a, h};
        } else {
            m[b].first = min(m[b].first, a);
            m[b].second += h;
        }
    }

    for(auto i = m.begin(); i != m.end(); ++i) {
        //cout << i->first << ' ' << i->second.first << ' ' << i->second.second << '\n';
        v.push_back({{i->first, i->second.first}, i->second.second});
    }

    sort(v.begin(), v.end(), greater<pair<pair<ll, ll>, ll>>());

    stack<ll> s;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        dp[i] = v[i].second;
        while(!s.empty() && v[s.top()].first.second >= v[i].first.first) {
            s.pop();
        }

        if(!s.empty()) dp[i] += dp[s.top()];
        s.push(i);
    }

    //for(ll i = 0; i < (ll)v.size() - 1; ++i) cout << dp[i] << ' ';
    ll ans = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) ans = max(ans, dp[i]);
    //cout << dp[(ll)v.size() - 1] << '\n';

    cout << ans << '\n';
    return 0;
}