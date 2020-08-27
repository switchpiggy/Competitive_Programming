#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, k, occ[100007];

int main() {
    cin >> n;
    memset(occ, -1, sizeof(occ));

    for(ll i = 0; i < n; ++i) {
        cin >> x >> k;
        if(occ[k] == x - 1 || occ[k] >= x) {
            occ[k] = max(occ[k], x);
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}