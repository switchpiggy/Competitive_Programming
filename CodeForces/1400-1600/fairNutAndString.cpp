#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
const ll MOD = 1e9 + 7;

int main() {
    cin >> s;
    ll cnt = 0, ans = 1;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] != 'a' && s[i] != 'b') continue;
        if(s[i] == 'a') cnt++;
        else {
            ans *= cnt + 1;
            ans %= MOD;
            cnt = 0;
        }
    }

    ans *= cnt + 1;
    ans %= MOD;

    cout << (ans - 1)%MOD << '\n';
    return 0;
}