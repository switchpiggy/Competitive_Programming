#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, b[1007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        occ.clear();
        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            cin >> b[i];
            if(occ[b[i]]) ok = 0;
            occ[b[i]]++;
        }

        if(!ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}