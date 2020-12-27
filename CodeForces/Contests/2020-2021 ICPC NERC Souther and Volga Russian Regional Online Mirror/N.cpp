#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, c[4], a[6];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        for(ll i = 1; i <= 3; ++i) cin >> c[i];
        for(ll i = 1; i <= 5; ++i) cin >> a[i];

        bool ok = 1;
        for(ll i = 1; i <= 3; ++i) {
            if(c[i] < a[i]) {
                ok = 0;
                break;
            }
            c[i] -= a[i];
            a[i] = 0;
        }

        if(!ok) {
            cout << "No\n";
            continue;
        }

        a[4] -= min(a[4], c[1]);
        a[5] -= min(a[5], c[2]);

        if(c[3] >= a[4] + a[5]) cout << "Yes\n";
        else cout << "No\n"; 
    }

    return 0;
}