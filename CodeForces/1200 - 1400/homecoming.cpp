#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, p, dp[100007];
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> p >> s;
        memset(dp, 0, sizeof(dp));

        dp[(ll)s.length() - 1] = 0;
        for(ll i = (ll)s.length() - 2; i >= 0; --i) {
            if(s[i + 1] != s[i]) {
                if(s[i] == 'A') dp[i] = dp[i + 1] + a;
                else dp[i] = dp[i + 1] + b;
            } else {
                if(i == (ll)s.length() - 2) {
                    if(s[i] == 'A') dp[i] = a;
                    else dp[i] = b;
                } else dp[i] = dp[i + 1];
            }
        }

        /*for(ll i = 0; i < (ll)s.length(); ++i) {
            cout << dp[i] << ' ';
        }*/

        //cout << '\n';

        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(dp[i] <= p) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}