#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    ll ans = 0, cur = 0, place = 1;
    for(ll i = (ll)s.length() - 1; i >= 0; --i) {
        ll k = ((((i * (i + 1))/2)%MOD * place)%MOD + cur%MOD)%MOD;
        cur = ((place * ((ll)s.length() - i)) + cur)%MOD;
        place = (place * 10)%MOD;
        ans = (ans + ((s[i] - '0') * k)%MOD)%MOD;
    }

    cout << ans << '\n';
}