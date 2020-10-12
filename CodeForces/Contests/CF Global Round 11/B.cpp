#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, t;
string s;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return ((2 * (a.second - a.first + 1)) + (a.second != n - 1) - (a.first == 0))*(b.second - b.first + 1) > ((2 * (b.second - b.first + 1)) + (b.second != n - 1) - (b.first == 0))*(a.second - a.first + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k >> s;

        ll cur = 0;
        vector<pair<ll, ll>> v;
        for(ll i = 0; i < n; ++i) {
            if(s[i] == 'L') {
                cur++;
            } else {
                if(cur) v.push_back({i - cur, i - 1});
                cur = 0;
            }
        }

        if(cur) v.push_back({n - cur, n - 1});

        ll ans = 0;
        sort(v.begin(), v.end(), cmp);
        for(ll i = 0; i < (ll)v.size(); ++i) {
            //cout << v[i].first << ' ' << v[i].second << '\n';
            if(k < v[i].second - v[i].first + 1) continue;
            k -= v[i].second - v[i].first + 1;
            for(ll j = v[i].first; j <= v[i].second; ++j) s[j] = 'W';
        }

        for(ll i = 0; i < n; ++i) {
            if(!k) break;
            if(s[i] == 'L' && ((i && s[i - 1] == 'W') && (i + 1 < n && s[i + 1] == 'W'))) {
                k--;
                s[i] = 'W';
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(!k) break;
            if(s[i] == 'L' && (i && s[i - 1] == 'W')) {
                s[i] = 'W';
                k--;
            }
        }

        for(ll i = n - 1; i >= 0; --i) {
            if(!k) break;
            if(s[i] == 'L' && (i + 1 < n && s[i + 1] == 'W')) {
                s[i] = 'W';
                k--;
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(!k) break;
            if(s[i] == 'L') {
                s[i] = 'W';
                k--;
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(s[i] == 'W') {
                if(i && s[i - 1] == 'W') ans++;
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}