#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
set<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        v.insert(a[i]);
    }

    ll ans = 0;
    sort(a, a + n);

    ll cur = n - 2;
    for(ll i = n - 1; i >= 0; --i) {
        while(cur >= 0 && a[i] <= a[cur]) cur--;
        if(cur < 0) break;

        if(a[i] > a[cur]) {
            ans++;
            cur--;
        }
    }

    cout << ans << '\n';
    return 0;
}