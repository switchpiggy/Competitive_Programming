#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, rowa[507], rowb[507], cola[507], colb[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            ll temp;
            cin >> temp;
            rowa[i] += temp;
            cola[j] += temp;
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            ll temp;
            cin >> temp;
            rowb[i] += temp;
            colb[j] += temp;
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(rowa[i]%2 != rowb[i]%2) {
            cout << "No\n";
            return 0;
        }
    }

    for(ll i = 0; i < m; ++i) {
        if(cola[i]%2 != colb[i]%2) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}