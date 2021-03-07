#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> x >> y;
    ll cur = min(x + x, y);

    b = 2 * b + 1;
    a = 2 * a;

    cout << (abs(a - b)/2 * cur + abs(a - b)%2 * x) << '\n';
    return 0;
}