#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll maxn = 0;
        for(ll i = 1; i < n; ++i) {
            ll cur = 1, cnt = 0;

            while(a[i] < a[i - 1]) {
                a[i] += cur;
                cur *= 2;
                cnt++;
            }

            maxn = max(maxn, cnt);
        }

        cout << maxn << endl;
    }

    return 0;
}