#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll ans = -1, prev = -1;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            ans = max(ans, i - prev);
            prev = i;
        }
    }

    if(prev != -1) ans = max(ans, (ll)s.length() - prev);

    if(ans == -1 && prev == -1) cout << (ll)s.length() + 1 << '\n';
    else cout << ans << '\n';
    return 0;
}