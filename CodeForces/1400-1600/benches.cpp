#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

ll choose(ll n, ll r) {
    ll res = 1;
    for(ll i = n - r + 1; i <= n; ++i) res *= i;
    for(ll i = 1; i <= r; ++i) res /= i;
    return res;
}

int main() {
    cin >> n;
    cout << choose(n, 5) * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) << endl;
}