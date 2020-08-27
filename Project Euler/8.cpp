#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, k, n;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        ll ans = 0;
        for(ll i = 0; i < n - k + 1; ++i) {
            ll prod = 1;
            for(ll j = i; j <= i + k - 1; ++j) {
                prod *= s[j] - '0';
            }

            ans = max(prod, ans);
        }

        cout << ans << endl;
    }

    return 0;
}