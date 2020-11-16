#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
multiset<ll> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) {
        ll f;
        cin >> f;
        s.insert(f);
    }

    for(ll i = 0; i < n; ++i) {
        auto k = s.lower_bound(n - a[i]);
        if(k == s.end()) k = s.begin();

        cout << (a[i] + *k)%n << ' ';
        s.erase(k);
    }

    return 0;
}