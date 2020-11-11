#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    ll a = 0, b = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) a = (a * (s[i] - 'A' + 1))%47;
    for(ll i = 0; i < (ll)t.length(); ++i) b += (b * (t[i] - 'A' + 1))%47;

    if(a%47 == b%47) cout << "GO\n";
    else cout << "STAY\n";

    return 0;
}