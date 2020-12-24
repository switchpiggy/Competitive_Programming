#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0, maxn = 0;
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            maxn = max(maxn, a[i]);
            sum += a[i];
        }

        cout << ((sum%2 == 1 || maxn > sum/2) ? "T\n" : "HL\n");
    }

    return 0;
}