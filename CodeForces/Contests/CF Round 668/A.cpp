#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, p[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> p[i];
        for(ll i = n - 1; i >= 0; --i) cout << p[i] << ' ';
        cout << endl;
    }

    return 0;
}