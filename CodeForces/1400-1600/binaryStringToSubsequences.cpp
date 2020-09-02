#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, res[200007];
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll cnt = 0, ans = 0;
        for(ll i = 0; i < n; ++i) {
            if(i && s[i] == s[i - 1]) {
                cnt++;
            } else cnt = 1;

            ans = max(ans, cnt);
            res[i] = cnt;
        }

        cout << ans << endl;
        for(ll i = 0; i < n; ++i) cout << res[i] << ' ';
        cout << endl;
    }

    return 0;
}