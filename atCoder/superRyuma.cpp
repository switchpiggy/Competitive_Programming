#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    ll ans = 3;
    if(a == c && b == d) ans = 0;
    else if(a + b == c + d || a - b == c - d || abs(b - d) + abs(a - c) <= 3) ans = 1;
    else if(abs(a + b)%2 == abs(c + d)%2) ans = 2;
    cout << ans << '\n';
    return 0;
}