#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;
string s;
string r = "()";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        string t;
        for(ll i = 0; i < k - 1; ++i) t.append(r);
        t.append(string((n - 2 * (k - 1))/2, '('));
        t.append(string((n - 2 * (k - 1))/2, ')'));

        vector<pair<ll, ll>> v;
        for(ll i = 0; i < n; ++i) {
            if(s[i] == t[i]) continue;
            ll j;
            for(j = i; j < n; ++j) {
                if(s[j] == t[i]) break;
            }

            v.push_back({i, j});
            reverse(s.begin() + i, s.begin() + j + 1);
        }

        cout << (ll)v.size() << '\n';
        for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first + 1 << ' ' << v[i].second + 1 << '\n';
    }

    return 0;
}