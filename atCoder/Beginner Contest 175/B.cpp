#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, length[107];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> length[i];

    sort(length, length + n);

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            for(ll k = j + 1; k < n; ++k) {
                if(length[i] < length[j] && length[j] < length[k] && length[i] + length[j] > length[k]) {
                    ans++;
                    //cout << i << ' ' << j << ' ' << k << endl;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}