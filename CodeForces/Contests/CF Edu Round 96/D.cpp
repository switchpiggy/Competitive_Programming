#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s;
        vector<ll> v;

        ll cur = 1;
        for(ll i = 1; i < n; ++i) {
            if(s[i] != s[i - 1]) {
                v.push_back(cur);
                cur = 1;
            } else cur++;
        }

        if(cur) v.push_back(cur);

        ll ans = 0, minus = 0;
        for(ll i = 0; i < (ll)v.size(); ++i) {
            if(v[i] > 1) {
                minus = max(0ll, minus - (v[i] - 2));
            }
            else {
                if(!v[i]) continue;
                if(i + 1 < (ll)v.size()) {
                    minus++;
                }
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}