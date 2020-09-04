#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, s, n;

ll sumdig(ll x) {
    string q = to_string(x);
    ll ans = 0;
    for(ll i = 0; i < q.length(); ++i) ans += q[i] - '0';

    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;

        ll place = 1, ans = 0;
        while(sumdig(n) > s) {
            while((n/place)%10 != 0) {
                ans += place;
                n += place;
            }

            place *= 10;
        }

        cout << ans << endl;
    }

    return 0;
}