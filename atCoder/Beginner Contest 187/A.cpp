#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

ll s(ll x) {
    string e = to_string(x);
    ll ans = 0;
    for(ll i = 0; i < (ll)e.length(); ++i) ans += e[i] - '0';
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    cout << max(s(a), s(b)) << '\n';
}