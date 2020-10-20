#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[67];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll first = -1, last = -1;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 1) {
                if(first == -1) first = i;
                last = i;
            }
        }

        if(first == last) {
            cout << 0 << '\n';
            continue;
        }

        ll res = 0;
        for(ll i = first; i <= last; ++i) {
            if(a[i] == 0) res++;
        }

        cout << res << '\n';
    }

    return 0;
}