#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, m, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> d >> m;
        ll ans = 1;

        //bool ok = 0;
        for(ll i = 1; i <= d; i *= 2) {
            ans = (ans * (min(d - i + 1, i * 2 - i) + 1)%m)%m;
        }

        cout << ((ans - 1)%m + m)%m << '\n';
    }

    return 0;
}