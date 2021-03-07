#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

ll choose(ll x, ll y) {
    ll ans = 1;
    for(ll i = 1; i <= y; ++i) {
        ans *= x - y + i;
        ans /= i;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << choose(n - 1, 11) << '\n';
}