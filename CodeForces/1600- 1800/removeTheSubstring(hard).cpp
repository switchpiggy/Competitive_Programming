#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
map<ll, ll> pref, suf;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    pref[0] = -1;
    suf[0] = (ll)s.length();
    ll cur = 0;
    for(ll i = 1; i <= (ll)t.length(); ++i) suf[i] = pref[i] = -1;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == t[cur]) {
            cur++;
            if(pref[cur] == -1) pref[cur] = i;
        }

        if(cur > (ll)t.length()) break;
    }

    cur = (ll)t.length() - 1;
    for(ll i = (ll)s.length() - 1; i >= 0; --i) {
        if(s[i] == t[cur]) {
            cur--;
            if(suf[(ll)t.length() - 1 - cur] == -1) suf[(ll)t.length() - 1 - cur] = i;
        }

        if(cur < 0) break;
    }

    ll ans = 0;
    for(ll i = 0; i <= (ll)t.length(); ++i) {
        if((i == 0 || pref[i] != -1) && suf[(ll)t.length() - i] != -1) {
            ans = max(ans, suf[(ll)t.length() - i] - pref[i] - 1);
            //cout << pref[i] << ' ' << suf[(ll)t.length() - i] << '\n';
        }
    }

    cout << ans << '\n';
}