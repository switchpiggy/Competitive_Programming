#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007];
bool v[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll g = a[0];
    for(ll i = 1; i < n; ++i) g = __gcd(g, a[i]);

    ll cur = 0;
    for(ll i = 0; i <= k; ++i) {
        v[cur%k] = 1;
        cur = (cur + g)%k;
    }

    vector<ll> res;
    for(ll i = 0; i < k; ++i) if(v[i]) res.push_back(i);

    cout << (ll)res.size() << '\n';
    for(ll i : res) cout << i << ' ';
    cout << '\n';
    return 0;
}