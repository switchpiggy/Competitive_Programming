#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll r, g, b, a[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3, greater<ll>());
    if(a[0] >= 2 * (a[1] + a[2])) {
        cout << a[1] + a[2] << '\n';
    } else cout << (a[0] + a[1] + a[2])/3 << '\n';

    return 0;
}