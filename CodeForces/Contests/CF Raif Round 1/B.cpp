#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll ans = 0;
        bool right = 1, left = 1;
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] == '>') left = 0;
            if(s[i] == '<') right = 0;
        }

        if(left || right) {
            cout << n << '\n';
            continue;
        }

        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] == '-' || s[(i - 1 + n)%n] == '-') {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}