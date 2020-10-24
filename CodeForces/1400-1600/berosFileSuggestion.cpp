#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q;
string s;
map<string, ll> sub;
map<string, string> sub2;
map<string, bool> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for(ll l = 1; l <= (ll)s.length(); ++l) {
            v.clear();
            for(ll j = 0; j + l - 1 < (ll)s.length(); ++j) {
                string t = s.substr(j, l);
                if(!v[t]) {
                    v[t] = 1;
                    sub[t]++;
                    sub2[t] = s;
                }
            }
        }
    }

    cin >> q;
    for(ll i = 0; i < q; ++i) {
        cin >> s;
        if(!sub[s]) cout << "0 -\n";
        else cout << sub[s] << ' ' << sub2[s] << '\n';
    }

    return 0;
}