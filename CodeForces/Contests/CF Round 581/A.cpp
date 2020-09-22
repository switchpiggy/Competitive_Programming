#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    ll ans = ((ll)s.length() - 1)/2;

    bool ok = 0;
    for(ll i = 1; i < (ll)s.length(); ++i) {
        if(s[i] == '1') {
            ok = 1;
            break;
        }
    }

    if((ll)s.length()%2 == 0) ok = 1;
    cout << ans + ok << '\n';

    return 0;
}