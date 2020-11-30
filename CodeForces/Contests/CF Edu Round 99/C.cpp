#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << x - 1 << ' ' << y << '\n';
    }

    return 0;
}