#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    vector<ll> v;
    ll cnt = 0, gcf = a[0];

    for(ll i = 1; i < n; ++i) gcf = __gcd(gcf, a[i]);

    if(gcf > 1) {
        cout << "YES\n0\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        if(a[i]%2 == 1) cnt++;
        else {
            v.push_back(cnt);
            cnt = 0;
        }
    }

    if(cnt) v.push_back(cnt);

    ll ans = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        ans += (v[i] + 1)/2 + (v[i]%2);
    }

    cout << "YES\n" << ans << '\n';
    return 0;
}