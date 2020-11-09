#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007], occ[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        memset(occ, 0, sizeof(occ[0]) * (n + 1));
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]]++;
        }

        ll cnt = 0, maxn = 0;
        for(ll i = 1; i <= n; ++i) {
            if(occ[i] > maxn) {
                cnt = 1;
                maxn = occ[i];
            } else if(occ[i] == maxn) {
                cnt++;
            }
        }

        cout << (cnt - 1) + (n - (cnt * maxn))/(maxn - 1) << '\n';
    }

    return 0;
}