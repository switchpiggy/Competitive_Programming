#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if(n%2 == 0) cout << n + (2 * k) << endl;
        else {
            ll res = -1;
            for(ll i = 2; i <= sqrt(n); ++i) {
                if(n%i == 0) {
                    res = i;
                    break;
                }
            }

            if(res == -1) res = n;

            cout << n + res + 2 * (k - 1) << endl;
        }
    }

    return 0;
}