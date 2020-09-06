#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], t, pref[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) {
            pref[i] = a[i];
            if(i > 0) pref[i] += pref[i - 1];
        }
        ll minn = INT_MAX;
        for(ll i = 0; i < n; ++i) {
            if(pref[i] < 0) minn = min(pref[i], minn);
        }

        if(minn == INT_MAX) minn = 0;
        cout << minn * -1 << endl;
    }

    return 0;
}