#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, s, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> s >> q;

    ll ans = 0;
    while(s < t) {
        ans++;
        s *= q;
    }

    cout << ans << '\n';
    return 0;
}