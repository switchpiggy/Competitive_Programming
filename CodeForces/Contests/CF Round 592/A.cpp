#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c, d, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;

    while(t--) {
        cin >> a >> b >> c >> d >> k;
        if((a + c - 1)/c + (b + d - 1)/d <= k) cout << (a + c - 1)/c << ' ' << (b + d - 1)/d << endl;
        else cout << "-1" << endl;
    }

    return 0;
}