#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll a, b, pref[1000007], suff[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> a >> b;

    pref[0] = (s[0] - '0')%a;
    for(ll i = 1; i < (ll)s.length(); ++i) {
        pref[i] = ((10 * pref[i - 1])%a + (s[i] - '0')%a)%a;
    }

    suff[(ll)s.length() - 1] = (s[(ll)s.length() - 1] - '0')%b;
    ll cur = 10;
    for(ll i = (ll)s.length() - 2; i >= 0; --i) {
        suff[i] = (suff[i + 1] + (cur * (s[i] - '0'))%b)%b;
        cur *= 10;
        cur %= b;
    }

    for(ll i = 0; i < (ll)s.length() - 1; ++i) {
        if(s[i + 1] == '0') continue;
        if(!pref[i] && !suff[i + 1]) {
            cout << "YES\n";
            cout << s.substr(0, i + 1) << '\n' << s.substr(i + 1) << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}