#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

ll __lcd(ll x, ll y) {
    return (x * y)/__gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(k > 42) {
        cout << "No\n";
        return 0;
    }

    ll lcm = 1;
    for(ll i = 2; i <= k; ++i) lcm = __lcd(lcm, i);

    //cout << lcm << '\n';
    cout << (((n + 1) >= lcm && (n + 1)%lcm == 0) ? "Yes\n" : "No\n");
}