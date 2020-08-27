#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107][107];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(!a[i][j] && !a[j][i] && ((j != i && k >= 2) || (j == i && k >= 1))) {
                a[i][j] = 1;
                a[j][i] = 1;
                k -= 1 + (i != j);
            }
        }
    }

    if(k) cout << "-1" << endl;
    else {
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) cout << a[i][j] << ' ';
            cout << endl;
        }
    }

    return 0;
}