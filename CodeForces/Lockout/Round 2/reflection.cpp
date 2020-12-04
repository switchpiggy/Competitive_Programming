#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string l, r;

string rev(string x) {
    string res;
    for(ll i = 0; i < (ll)x.length(); ++i) res += (9 - (x[i] - '0') + '0');

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> r;

    ll ans = 0;
    ans = max(ans, stoll(l) * stoll(rev(l)));
    ans = max(ans, stoll(r) * stoll(rev(r)));

    ll cur = 1;
    for(ll i = 0; i <= (ll)r.length(); ++i) {
        ll c = 5 * cur;
        string k = to_string(c); 
        cur *= 10;
        if(stoll(l) <= c && c <= stoll(r)) ans = max(ans, stoll(k) * stoll(rev(k)));
    }

    cout << ans << '\n';
    return 0;
}