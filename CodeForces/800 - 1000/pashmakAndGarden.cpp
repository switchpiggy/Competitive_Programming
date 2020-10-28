#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y, xx, yy;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> xx >> yy;

    if(x == xx) {
        cout << abs(yy - y) + x << ' ' << y << ' ' << abs(yy - y) + x << ' ' << yy << '\n';
        return 0;
    }

    if(y == yy) {
        cout << x << ' ' << abs(xx - x) + y << ' ' << xx << ' ' << abs(xx - x) + y << '\n';
        return 0;
    }

    if(abs(yy - y) == abs(xx - x)) cout << x << ' ' << yy << ' ' << xx << ' ' << y << '\n';
    else cout << "-1\n";
    return 0;
}