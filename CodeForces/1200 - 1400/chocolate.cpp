#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    cin >> n;
    ll ans = 1;
    ll prev = -1;

    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < n; ++i) {
        if(a[i] == 1) {
            if(prev == -1) prev = i;
            else {
                ans *= i - prev;
                prev = i;
            }
        }
    }

    if(prev == -1) ans = 0;

    cout << ans << endl;
    return 0;
}