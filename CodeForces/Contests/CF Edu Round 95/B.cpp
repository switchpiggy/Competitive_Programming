#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[107], l[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n; ++i) cin >> l[i];

        vector<ll> v;
        for(ll i = 0; i < n; ++i) {
            if(!l[i]) v.push_back(a[i]);
        }

        sort(v.begin(), v.end(), greater<ll>());
        ll cur = 0;
        for(ll i = 0; i < n; ++i) {
            if(l[i]) cout << a[i] << ' ';
            else {
                cout << v[cur] << ' ';
                cur++;
            }
        }

        cout << '\n';
    }

    return 0;
}