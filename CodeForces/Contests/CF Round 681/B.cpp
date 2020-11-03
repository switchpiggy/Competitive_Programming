#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> s;
        vector<ll> v;

        ll fst = s[0] - '0';

        ll cur = 0, ans = 0;
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(i == 0 || s[i] == s[i - 1]) {
                cur++;
            } else {
                if(s[i - 1] == '1') ans += a;
                v.push_back(cur);
                cur = 1;
            }
        }

        if(cur) {
            v.push_back(cur);
            if(s[(ll)s.length() - 1] == '1') ans += a;
        }

        //ll res = 0;
        //for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i] << ' ';
        //cout << '\n';
        for(ll i = fst; i < (ll)v.size(); i += 2) {
            if(v[i] * b <= a && i && i < (ll)v.size() - 1) {
                ans += v[i] * b - a;
                v[i + 1] += v[i] + v[i - 1];
            }    
        }

        cout << ans << '\n';
    }

    return 0;
}