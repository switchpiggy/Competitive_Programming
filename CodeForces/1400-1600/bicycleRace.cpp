#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;

int main() {
    cin >> n;
    for(ll i = 0; i <= n; ++i) cin >> x >> y;

    cout << (n - 4)/2 << '\n';
    return 0;
}