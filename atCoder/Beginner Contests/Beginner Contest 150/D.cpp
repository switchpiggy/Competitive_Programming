#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[100007];
map<ll, ll> occ;

ll lcd(ll x, ll y) {
    return (x * y)/(__gcd(x, y));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll lcm = 1;
    for(ll i = 0; i < n; ++i) {
        lcm = lcd(lcm, a[i]/2);
        ll cur = 0;
        while(a[i]%2 == 0) {
            cur++;
            a[i] /= 2;
        }

        occ[cur]++;
    }

    if(occ.size() > 1) {
        cout << "0\n";
        return 0;
    }
    cout << (m/lcm)/2 + (m/lcm)%2 << '\n';
    return 0;
}