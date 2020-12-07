#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return recurse * recurse * x;
    return recurse * recurse;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n%2 == 1) cout << "0\n";
    else cout << fastpow(2, n/2) << '\n';

    return 0;
}