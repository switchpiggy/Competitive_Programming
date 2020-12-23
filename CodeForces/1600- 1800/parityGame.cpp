#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
string even = string(1007, '0');
string odd = '1' + even;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;

    ll a = 0, b = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) a += (s[i] == '1');
    for(ll i = 0; i < (ll)t.length(); ++i) b += (t[i] == '1');

    a += a%2;

    cout << (a >= b ? "YES\n" : "NO\n");
    return 0;
}