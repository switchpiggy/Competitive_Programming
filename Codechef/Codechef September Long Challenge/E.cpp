#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, temp, res[20];

const ll ones = 1048575;

int main() {
    cin >> t;
    while(t--) {
        memset(res, 0, sizeof(res));
        cout << 1 << ' ' << ones << '\n';
        cout.flush();

        ll allOnes;

        cin >> allOnes;

        ll cur = 0;
        for(ll i = 0; i < 19; ++i) {
            cout << 1 << ' ' << ones - cur << '\n';
            cout.flush();

            cin >> temp;
            ll diff = temp - ones;
            res[i] = ((cur * n + diff)/(2 * cur))%2;

            cur *= 2;
        }

        ll ans = 0, place = 1;
        for(ll i = 0; i < 19; ++i) {
            ans += place * res[i];
            place *= 2;
        }

        cout << 2 << ' ' << ans << '\n';                                                                                                                                                                                                                                                                                                                                 
        cout.flush();

        cin >> temp;
        if(temp == -1) return 0;
    }

    return 0;
}