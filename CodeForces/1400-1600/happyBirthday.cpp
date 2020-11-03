#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, c[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        for(ll i = 0; i < 10; ++i) cin >> c[i];
        string ans = string(1, '1') + string(c[0] + 1, '0');

        for(ll i = 1; i < 10; ++i) {
            string s = string(c[i] + 1, i + '0');
            if((ll)s.length() > (ll)ans.length()) continue;
            else if((ll)s.length() < (ll)ans.length()) ans = s;
            else ans = min(ans, string(c[i] + 1, i + '0'));
        }

        cout << ans << '\n';
    }

    return  0;
}