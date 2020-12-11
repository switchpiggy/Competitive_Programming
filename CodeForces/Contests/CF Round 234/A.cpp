#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, mod[20][13];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(mod, 0, sizeof(mod));
        cin >> s;
        for(ll i = 0; i < 12; ++i) {
            for(ll j = 1; j <= 12; ++j) {
                if(12%j == 0) mod[i%j][j] += (s[i] == 'X');
            }
        }

        vector<ll> v;
        ll ans = 0;
        for(ll j = 1; j <= 12; ++j) {
            bool ok = 0;
            if(12%j != 0) continue;
            for(ll i = 0; i < j; ++i) {
                if(mod[i][j] == 12/j) {
                    ok = 1;
                    break;
                }
            }

            if(ok) v.push_back(j);
        }

        sort(v.begin(), v.end(), greater<ll>());
        cout << (ll)v.size() << ' ';
        for(ll i : v) cout << 12/i << 'x' << i << ' ';
        cout << '\n';
    }
}