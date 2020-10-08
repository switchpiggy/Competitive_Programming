#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll MOD = 1000000007;
map<char, ll> ascii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(char i = '0'; i <= '9'; ++i) ascii[i] = i - '0';
    for(char a = 'a'; a <= 'z'; ++a) ascii[a] = a - 'a' + 36;
    for(char a = 'A'; a <= 'Z'; ++a) ascii[a] = a - 'A' + 10;
    ascii['-'] = 62, ascii['_'] = 63;

    cin >> s;

    //cout << ascii['V'] << ' ' << ascii['_'] << '\n';

    //cout << s << '\n';

    ll ans = 1;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        ll cur = ascii[s[i]];

        for(ll j = 0; j < 6; ++j) {
            if((cur & (1 << j)) == 0) ans *= 3;
            ans %= MOD;
        }        
    }

    cout << ans << '\n';
    return 0;
}