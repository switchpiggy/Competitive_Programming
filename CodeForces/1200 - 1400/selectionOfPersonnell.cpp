#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll choose(ll n, ll r) {
    ll ans = 1;
    for(ll i = 1; i <= r; ++i) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << choose(n, 7) + choose(n, 6) + choose(n, 5) << endl;
    return 0;
}