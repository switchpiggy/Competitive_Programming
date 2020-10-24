#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;

    if(c && !(a && d)) {
        cout << 0 << '\n';
        return 0;
    }

    if(a == d) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}