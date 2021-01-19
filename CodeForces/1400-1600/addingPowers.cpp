#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll t, k, n, a[37], powk[67], occ[67];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(powk, 0, sizeof(powk));
        powk[0] = 1;
        ll maxpow = 1;
        for(ll i = 1; i <= 60; ++i) {
            if(powk[i - 1] * i > 1000000000000000000 || powk[i - 1] * i < 0) break;
            powk[i] = powk[i - 1] * k;
            maxpow = i;
        }

        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a, a + n);
        memset(occ, 0, sizeof(occ));
        for(ll i = 0; i < n; ++i) {
            //cout << a[i] << ' ';
            for(ll j = maxpow; j >= 0; --j) {
                if(a[i] >= powk[j]) {
                    //cout << powk[j] << ' ';
                    occ[j]++;
                    a[i] -= powk[j];
                }
            }

            //cout << '\n';
        }

        bool ok = 1;
        for(ll i = 0; i <= maxpow; ++i) {
            if(occ[i] > 1) {
                ok = 0;
                break;
            }
        }

        for(ll i = 0; i < n; ++i) if(a[i]) {
            ok = 0; 
            break;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}