#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll ans = 0;
    for(ll i = 0; i < (ll)s.length()/2; ++i) {
        if(s[i] != s[(ll)s.length() - i - 1]) ans++;
    }

    cout << ans << '\n';
    return 0;
}