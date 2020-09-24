#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[50000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        bool ok = 0;
        for(ll i = 0; i < n - 1; ++i) {
            if(a[i] <= a[i + 1]) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            cout << "NO\n";
        } else cout << "YES\n";
    }

    return 0;
}