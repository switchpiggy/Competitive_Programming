#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> n;
        ll temp;

        occ.clear();
        for(ll i = 0; i < n; ++i) {
            cin >> temp;
            occ[temp]++;
        }

        for(ll i = 0; i <= 10; ++i) {
            ll cur = (1 << i);
            if(occ[cur] >= 2) {
                occ[cur * 2] += occ[cur]/2;
            }
        }

        if(occ[2048]) cout << "YES" << '\n';
        else cout << "NO\n";
    }

    return 0;
}