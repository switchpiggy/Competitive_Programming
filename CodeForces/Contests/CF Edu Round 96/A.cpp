#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;

        bool ok = 0;

        for(ll i = 0; i <= n/7; ++i) {
            for(ll j = 0; j <= n/5; ++j) {
                if(i * 7 + j * 5 <= n && (n - (i * 7 + j * 5))%3 == 0) {
                    ok = 1;
                    cout << (n - (i * 7 + j * 5))/3 << ' ' << j << ' ' << i  << '\n';
                    break;
                }
            }

            if(ok) break;
        }

        if(!ok) cout << -1 << '\n';
    }
}