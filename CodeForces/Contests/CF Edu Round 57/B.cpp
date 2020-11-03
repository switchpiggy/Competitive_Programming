#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    if(s[0] == s.back()) {
        ll pref = 0;
        for(ll i = 0; i < n; ++i) {
            if(s[i] == s[0]) pref = i;
            else break;
        }

        ll suff = n - 1;
        for(ll i = n - 1; i >= 0; --i) {
            if(s[i] == s[n - 1]) suff = i;
            else break;
        }

        cout << ((n - suff + 1)%MOD * (pref + 2)%MOD)%MOD << '\n';
        return 0;
    }

    ll pref = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == s[0]) pref = i;
        else break;
    }

    ll suff = n - 1;
    for(ll i = n - 1; i >= 0; --i) {
        if(s[i] == s[n - 1]) suff = i;
        else break;
    }

    cout << ((n - suff + 1)%MOD + (pref + 2)%MOD)%MOD - 1 << '\n';
    return 0;
}