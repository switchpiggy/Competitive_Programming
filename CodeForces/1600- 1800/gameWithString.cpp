#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
vector<ll> v[26];
ll c[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        v[s[i] - 'a'].push_back(i);
    }

    long double ans = 0;

    for(ll i = 0; i < 26; ++i) {
        if(v[i].empty()) continue;
        ll res = 0;
        for(ll d = 1; d < (ll)s.length(); ++d) {
            ll cnt = 0;
            memset(c, 0, sizeof(c));
            for(ll j = 0; j < (ll)v[i].size(); ++j) {
                c[s[(v[i][j] + d)%(ll)s.length()] - 'a']++;
                if(c[s[(v[i][j] + d)%(ll)s.length()] - 'a'] == 1) cnt++;
                else if(c[s[(v[i][j] + d)%(ll)s.length()] - 'a'] == 2) cnt--;
            }

            res = max(res, cnt);
        }
        ans += res;
    }

    //cout << ans << '\n';
    cout << ans/(long double)s.length() << '\n';
}