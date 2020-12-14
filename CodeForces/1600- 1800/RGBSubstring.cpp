#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, k, d[200007];
string s;
string t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for(ll i = 0; i < 2e5; ++i) t.append("RGB");
    while(q--) {
        cin >> n >> k >> s;
        ll ans = LLONG_MAX;
        for(ll i = 0; i < 3; ++i) {
            memset(d, 0, n * sizeof(d[0]));
            ll cur = 0;
            string v = t.substr(i, n);

            for(ll j = 0; j < n; ++j) {
                d[j] = (s[j] != v[j]);
                cur += d[j];
                if(j >= k) {
                    cur -= d[j - k];
                }

                if(j >= k - 1) ans = min(ans, cur);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}