#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
map<char, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        occ[s[i]]++;
    }

    ll ans = 0;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        ans += i->second * i->second;
    }

    cout << ans << '\n';
    return 0;
}