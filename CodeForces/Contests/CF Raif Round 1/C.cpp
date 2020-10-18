#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> s;

        string res = "";
        for(ll i = 0; i < (ll)s.length(); ++i) {
            //if(s[i] == 'A' && s[i + 1] == 'B') continue;
            if(s[i] == 'B' && !res.empty() && res.back() == 'A') {
                res.pop_back();
            } else {
                res += s[i];
            }
        }

        ll ans = 0, cnt = 0;
        for(ll i = 0; i < (ll)res.length(); ++i) {
            if(res[i] == 'A') {
                ans++;
            }
            else {
                cnt++;
            }
        }

        ans += cnt%2;
        cout << ans << '\n';

    }

    return 0;
}