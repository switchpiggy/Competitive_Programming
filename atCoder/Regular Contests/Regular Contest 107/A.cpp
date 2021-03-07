#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;
const ll m = 998244353;

ll s(ll x) {
    return (x * (x + 1))/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    //cout << a << ' ' << b << ' ' << c << '\n';
    cout << (((a * (a+1) / 2 % 998244353) * (b * (b+1) / 2 % 998244353) % 998244353) *  (c * (c+1) / 2 % 998244353)) % 998244353 << '\n';
}