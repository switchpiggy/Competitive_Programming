#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
ll x = 2;

ll lcd(ll x, ll y) {
    return (x * y)/(__gcd(x, y));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 3; i <= n; ++i) x = lcd(x, i);
    cout << x + 1 << '\n';
    return 0;
}