#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, d, x;
bool ans[107];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < k; ++i) {
        cin >> d;
        for(ll j = 0; j < d; ++j) {
            cin >> x;
            ans[x] = 1;
        }
    }

    ll cnt = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!ans[i]) cnt++;
    }

    cout << cnt << endl;
    return 0;
}