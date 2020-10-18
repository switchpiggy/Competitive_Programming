#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    ll mins = min(a, b);

    cout << 2 * (mins + c) + (a > mins || b > mins) << '\n';
    return 0;
}