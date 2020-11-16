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
        cout << n << '\n';
        for(ll i = 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}