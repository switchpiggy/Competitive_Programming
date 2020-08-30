#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll n, m, temp, a[2007], b[2007], ans = INT_MAX;
 
int main() {
    cin >> n >> m;
    
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(b, b + n);

    ll cur = b[0];
    vector<ll> v;

    for(ll i = 0; i < n; ++i) {
        ll diff = (cur - a[i] + m)%m;
        v.clear();

        for(ll i = 0; i < n; ++i) v.push_back((a[i] + diff)%m);

        sort(v.begin(), v.end());

        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(b[i] != v[i]) {
                ok = 0;
                break;
            }            
        }

        if(ok) {
            ans = min(ans, diff);
        }
    }
    
    cout << ans << endl;
    return 0;
}