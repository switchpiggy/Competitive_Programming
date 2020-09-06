#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, l, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        ll minR = INT_MAX, maxL = INT_MIN;
        for(ll i = 0; i < n; ++i) {
            cin >> l >> r;
            maxL = max(maxL, l);
            minR = min(minR, r);
        }

        if(maxL <= minR) {
            cout << 0 << endl;
            continue;
        } else cout << maxL - minR << endl;
    }

    return 0;
}