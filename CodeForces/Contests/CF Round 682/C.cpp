#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, a[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) cin >> a[i][j];
            a[i][m + 1] = 0;
        }

        for(ll i = 1; i <= m; ++i) a[n + 1][m] = 0;

        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) {
                if(i%2 == j%2) {
                    if(a[i][j]%2 == 0) a[i][j]++;
                } else {
                    if(a[i][j]%2 == 1) a[i][j]++;
                }

                cout << a[i][j] << ' ';
            }

            cout << '\n';
        }
    }

    return 0;
}