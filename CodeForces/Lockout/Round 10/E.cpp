#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n, a[100007], l[100007], r[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        r[a[i]] = i + 1;
        if(!l[a[i]]) l[a[i]] = i + 1;
    }

    vector<ll> v;
    for(ll i = 1; i <= 100000; ++i) {
        if(r[i]) v.push_back(r[i]);
    }

    sort(v.begin(), v.end());

    //for(ll i : v) cout << i << '\n';

    ll ans = 0;
    for(ll i = 1; i <= 100000; ++i) {
        if(!l[i]) continue;
        ll k = upper_bound(v.begin(), v.end(), l[i]) - v.begin();
        ans += ((ll)v.size() - k);
    }

    cout << ans << '\n';
    return 0;
}