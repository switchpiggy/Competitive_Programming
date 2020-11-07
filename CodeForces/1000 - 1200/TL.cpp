#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[107], b[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];

    //ll ans = -1;
    for(ll i = 1; i <= 100; ++i) {
        bool ok = 1, ok2 = 0;
        for(ll j = 0; j < n; ++j) {
            if(2 * a[j] <= i) ok2 = 1;
            if(a[j] > i) {
                ok = 0;
                break;
            }
        }

        for(ll j = 0; j < m; ++j) {
            if(b[j] <= i) {
                ok = 0;
                break;
            }
        }

        if(ok2 && ok) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}