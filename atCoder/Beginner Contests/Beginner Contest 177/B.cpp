#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;

    ll ans = t.length();
    for(ll i = 0; i < s.length() - t.length() + 1; ++i) {
        ll cnt = 0;

        for(ll j = 0; j < t.length(); ++j) {
            if(s[i + j] == t[j]) cnt++;
        }

        ans = min(ans, (ll)t.length() - cnt);
    }

    cout << ans << endl;
    return 0;
}