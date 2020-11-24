#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007];
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) {
            occ[a[i]]++;
        }

        bool ok = 0;
        for(auto i = occ.begin(); i != occ.end(); ++i) {
            if(i->second == 1) {
                for(ll j = 0; j < n; ++j) {
                    if(a[j] == i->first) {
                        cout << j + 1 << '\n';
                        break;
                    }
                }
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "-1\n";
    }

    return 0;
}