#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
ll total = INT_MAX, BC = INT_MAX, AC = INT_MAX, AB = INT_MAX, a = INT_MAX, b = INT_MAX, c = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        ll k;
        cin >> k >> s;
        if((ll)s.length() == 3) total = min(total, k);
        else if((ll)s.length() == 1) {
            if(s[0] == 'A') a = min(a, k);
            if(s[0] == 'B') b = min(b, k);
            if(s[0] == 'C') c = min(c, k);
        } else {
            if(s[0] != 'B' && s[1] != 'B') AC = min(AC, k);
            if(s[0] != 'C' && s[1] != 'C') AB = min(AB, k);
            if(s[0] != 'A' && s[1] != 'A') BC = min(BC, k);
        }
    }

    ll ans = min(total, min(BC + a, min(AC + b, min(AB + c, a + b + c))));
    ans = min(ans, min(BC + AC, min(BC + AB, AB + AC)));
    if(ans >= INT_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}