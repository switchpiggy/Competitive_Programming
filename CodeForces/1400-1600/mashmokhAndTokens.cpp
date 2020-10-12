#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, x[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    for(ll i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for(ll i = 0; i < n; ++i) {
        cout << x[i] - ((((x[i] * a)/b) * b + a - 1)/a) << ' ';
    }

    cout << '\n';
    return 0;
}