#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        ll ans = 0;
        for(ll i = 1; i < (ll)s.length(); ++i) {
            if(s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
                ans++;
                s[i] = '.';
            }
        }

        cout << ans << '\n';
    }
}