#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y, x2, y2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> x >> y >> x2 >> y2;
        if(abs(x - x2) == 0 || abs(y - y2) == 0) {
            cout << abs(x - x2) + abs(y - y2) << '\n';
            continue;
        }

        cout << 2 + abs(x - x2) + abs(y - y2) << '\n';
    }

    return 0;
}