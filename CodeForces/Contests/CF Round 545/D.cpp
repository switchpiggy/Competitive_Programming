#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
ll p[500007];

ll kmp() {
    ll len = 0, i = 1;
    while(i < (ll)t.length()) {
        if(t[i] == t[len]) {
            len++;
            p[i] = len;
            i++;
        } else {
            if(!len) {
                p[i] = 0;
                i++;
            } else {
                len = p[len - 1];
            }
        }
    }

    ll ans = p[(ll)t.length() - 1];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    ll k = kmp();
    string res = t.substr(k);
    if(!k) res = t;

    ll one = 0, zero = 0, sone = 0, szero = 0;
    for(ll i = 0; i < (ll)t.length(); ++i) {
        if(t[i] == '0') zero++;
        else one++;

        if(i < (ll)res.length()) {
            if(t[i] == '0') szero++;
            else sone++;
        }
    }

    ll ones = 0, zeros = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == '0') zeros++;
        else ones++;
    }

    if(ones < one || zeros < zero) {
        for(ll i = 0; i < ones; ++i) cout << '1';
        for(ll i = 0; i < zeros; ++i) cout << '0';
        cout << '\n';
        return 0;
    }
    
    if(res == t) {
        string ans = "";
        while(ones >= one && zeros >= zero) {
            ones -= one;
            zeros -= zero;
            ans += t;
        }

        cout << ans;
        for(ll i = 0; i < zeros; ++i) cout << 0;
        for(ll i = 0; i < ones; ++i) cout << 1;
        return 0;
    }

    //cout << ones << ' ' << zeros << '\n' << one << ' ' << zero << '\n' << sone << ' ' << szero << '\n';
    //cout << res << '\n';

    
    string ans = t;
    ones -= one;
    zeros -= zero;


    while(ones >= sone && zeros >= szero) {
        ans += res;
        ones -= sone;
        zeros -= szero;
    }

    cout << ans;
    for(ll i = 0; i < ones; ++i) cout << '1';
    for(ll i = 0; i < zeros; ++i) cout << '0';
    cout << '\n';

    return 0;
}