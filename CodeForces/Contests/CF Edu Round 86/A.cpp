#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y, t, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> x >> y >> a >> b;
        cout << min(a * (abs(x) + abs(y)), a * abs(x - y) + b * min(abs(y), abs(x))) << '\n';
    }

    return 0;
}