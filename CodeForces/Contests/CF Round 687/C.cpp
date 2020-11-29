#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, p, k, mod[100007], x, y;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> p >> k >> s >> x >> y;
        memset(mod, 0, sizeof(mod[0]) * 100007);

        ll ans = INT_MAX;
        for(ll i = (ll)s.length() - 1; i >= 0; --i) {
            if(s[i] == '0') mod[i%k]++;
            if(i >= p - 1) ans = min(ans, mod[i%k] * x + ((i - p + 1) * y));
        }

        cout << ans << '\n';
    }

    return 0;
}