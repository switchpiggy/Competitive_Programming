#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cout << 2 * ((n - 1)/k) + min(2ll, (n - 1)%k) << '\n';

    ll cur = 2;
    for(ll i = 0; i < k; ++i) {
        ll prev = 1;
        for(ll j = 0; j < (n - 1)/k + (i < (n - 1)%k); ++j) {
            cout << cur << ' ' << prev << '\n';
            prev = cur;
            cur++;
        }
    }

    return 0;
}