#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        ll sum = 0;
        for(ll i = 0; i < n; ++i) sum += (s[i] == '1');

        ll ans = INT_MAX;
        for(ll i = 0; i < k; ++i) {
            ll dif = 0;
            for(ll j = i; j < n; j += k) {
                if(s[j] == '1') dif++;
                else dif--;
                dif = max(dif, 0ll);
                ans = min(ans, sum - dif);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}