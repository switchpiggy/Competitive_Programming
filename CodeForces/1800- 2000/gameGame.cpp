#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[1000007], occ[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        memset(occ, 0, sizeof(occ));
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            for(ll j = 0; j < 30; ++j) {
                if(a[i] & (1ll << j)) occ[j]++;
            }
        }

        bool ok = 1;
        for(ll i = 29; i >= 0; --i) {
            if(occ[i]%2 == 0) continue;
            ok = 0;
            if(occ[i]%4 == 3 && (n - occ[i])%2 == 0) cout << "LOSE\n";
            else cout << "WIN\n";
            break;
        }

        if(ok) cout << "DRAW\n";
    }
}