#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;

        if(n < 4) {
            cout << -1 << '\n';
            continue;
        }

        for(ll i = n - (n%2 == 0); i >= 1; i -= 2) cout << i << ' ';
        cout << 4 << ' ' << 2 << ' ';
        for(ll i = 6; i <= n; i += 2) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}