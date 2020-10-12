#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
vector<pair<char, char>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == t[i]) continue;
        bool ok = 0;
        for(ll j = 0; j < (ll)t.length(); ++j) {
            if(s[i] == t[j] && t[i] == s[j]) {
                v.push_back({s[i], s[j]});
                swap(s[i], s[j]);
                ok = 1;
                break;
            }
        }

        if(!ok) {
            cout << i << '\n';
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << (ll)v.size() << '\n';
    for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << '\n';
    return 0;
}