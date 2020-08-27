#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll ans = 1;
map<char, bool> occ;

int main() {
    cin >> s;
    ll cnt = 0, res = 0;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '?') cnt++;
        if(s[i] >= 'A') {
            res += !occ[s[i]];
            occ[s[i]] = 1;
        }
    }

    if(cnt) ans = 10;
    for(ll i = 10; i >= 10 - res + 1; --i) ans *= i;
    if(!isdigit(s[0])) ans = (ans * 9)/10;

    cout << ans;
    for(ll i = 0; i < cnt - 1; ++i) cout << 0;
    return 0;
}