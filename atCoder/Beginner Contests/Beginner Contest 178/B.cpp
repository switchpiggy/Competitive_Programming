
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    if((a < 0 && b < 0 && c > 0 && d > 0) || (a > 0 && b > 0 && c < 0 && d < 0)) cout << min(abs(a), abs(b)) * min(abs(c), abs(d)) * -1 << '\n';
    else cout << max(max(a * c, a * d), max(b * c, b * d)) << '\n';

    return 0;
}