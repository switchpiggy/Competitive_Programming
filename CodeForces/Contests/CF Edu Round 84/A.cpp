#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, t;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll res = k + (2 * (k * (k - 1))/2);

        if(n >= res && (n - res)%2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}