#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

ll fact(ll x) {
    ll res = 1;
    for(ll i = 1; i <= x; ++i) res *= i;

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << fact(n)/((n/2) * (n/2) * 2) << '\n';

    return 0;
}