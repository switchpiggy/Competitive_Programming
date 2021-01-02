#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x[57];
set<ll> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> x[i];
        sort(x, x + n);
        s.clear();
        for(ll i = 0; i < n; ++i) {
            for(ll j = i + 1; j < n; ++j) {
                s.insert(x[j] - x[i] + 1);
            }
        }

        cout << (ll)s.size() << '\n';
    }

    return 0;
}