#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
ll p[200007];

bool check(ll x) {
    string temp = s;
    for(ll i = 1; i <= x; ++i) temp[p[i] - 1] = '-';

    string v;
    for(ll i = 0; i < (ll)temp.size(); ++i) if(temp[i] != '-') v.push_back(temp[i]);

    ll cnt = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(v[i] == t[cnt]) cnt++;
        if(cnt == (ll)t.size()) return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    for(ll i = 1; i <= (ll)s.length(); ++i) cin >> p[i];

    ll l = 0, r = (ll)s.length() + 1;
    ll ans = 0;
    while(l < r) {
        ll m = (l + r)/2;
        //cout << check(m) << ' ' << m << '\n';
        if(check(m)) {
            ans = m;
            l = m + 1;
        } else r = m;
    }

    cout << ans << '\n';
    return 0;
}