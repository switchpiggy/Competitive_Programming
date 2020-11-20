#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        cout << max(1ll, min(n, x + y - n + 1)) << ' ' << min(n, x + y - 1) << '\n';
    }

    return 0;
}