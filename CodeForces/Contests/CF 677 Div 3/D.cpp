#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[5007];
bool v[5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            if(i && a[i] != a[i - 1]) ok = 1;
        }

        if(!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        ll lowest = -1;
        for(ll i = 1; i < n; ++i) {
            if(a[i] == a[0]) continue;
            if(lowest = -1) lowest = i;
            cout << i + 1 << ' ' << 1 << '\n'; 
        }

        for(ll i = 1; i < n; ++i) {
            if(a[i] == a[0]) cout << i + 1 << ' ' << lowest + 1 << '\n';
        }
    }

    return 0;
}